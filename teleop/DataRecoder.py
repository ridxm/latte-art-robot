#!/usr/bin/env python3

import os
import io
import numpy as np
import pandas as pd
import pyarrow as pa
import pyarrow.parquet as pq
import imageio
from PIL import Image
import threading
import time
import queue
from collections import deque
import mediapy as media

from DataCollectionConstants import SAVE_DIRECTORY_PATH_DATA, LEROBOT_DATASET_COLUMN_HEADER

SAVE_DIR = SAVE_DIRECTORY_PATH_DATA


class DataRecoder:
    def __init__(self, fps=30, slow_speed_threshold=15.0):
        self.log_dir = SAVE_DIR + "data/chunk_000/"
        self.video_dir = SAVE_DIR + "videos/chunk_000/"
        
        # Create directories if they don't exist
        if not os.path.exists(self.log_dir):
            os.makedirs(self.log_dir)
        if not os.path.exists(self.video_dir):
            os.makedirs(self.video_dir)
        
        # Performance optimization options
        self.buffer_size = 100
        
        # Pre-allocate data structures for better performance
        self.data_buffer = deque(maxlen=self.buffer_size)
        self.image_buffer = deque(maxlen=self.buffer_size)
        
        # Threading for async operations
        self.processing_thread = None
        self.processing_queue = deque(maxlen=50)
        self.processing_lock = threading.Lock()
        
        # Performance monitoring
        self.processing_times = []
        self.last_performance_check = time.time()
        self.slow_speed_threshold = slow_speed_threshold
        
        # LeRobot-style frame-based timestamp tracking
        self.episode_start_time = None
        self.episode_index = 120
        self.index = 0
        self.dt = 1.0/fps
        self.fps = int(fps)  # Ensure integer FPS like LeRobot
        self.frame_index = 0  # Frame-based indexing like LeRobot
        self.timestamp = 0.0  # Starts at 0, increments with episode
        
        # Initialize camera buffers before reset (defensive programming)
        # Only 3 RGB cameras: top, left wrist, right wrist
        self.top_camera = []
        self.left_wrist = []
        self.right_wrist = []

        self.reset()

    def reset(self):
        # Use optimized data structures
        self.df = pd.DataFrame(columns=LEROBOT_DATASET_COLUMN_HEADER)

        # RGB camera buffers (3 cameras only)
        self.top_camera = []     # Top/overhead camera
        self.left_wrist = []     # Left wrist camera
        self.right_wrist = []    # Right wrist camera
        
        # Initialize LeRobot-style frame-based timestamps
        self.episode_start_time = time.time()
        self.frame_index = 0  # Reset frame index like LeRobot
        self.column_index = 0
        self.timestamp = 0.0  # Start from 0 for relative timing

    def write_data_to_buffer(self, observation, action, reward, termination_flag, cam_data):
        start_time = time.time()
        
        # Note: timestamp is now calculated in collect_data_step() for accuracy
        
        # Track processing delay (time between collection and writing)
        if hasattr(self, 'collection_timestamp'):
            processing_delay = time.time() - self.collection_timestamp
            if processing_delay > 0.1:  # If delay is more than 100ms
                print(f"Warning: Processing delay of {processing_delay*1000:.1f}ms detected")
        
        # Write data using optimized method (no PNG encoding)
        self._write_data_to_buffer_optimized(observation, action, reward, termination_flag, cam_data)
        
        # Performance monitoring
        processing_time = time.time() - start_time
        self.processing_times.append(processing_time)
        
        # Print performance stats every 100 operations (only when slow)
        if len(self.processing_times) % 100 == 0:
            avg_time = np.mean(self.processing_times[-100:])
            rate = 1.0 / avg_time if avg_time > 0 else 0
            
            # Only report speed when it's slower than threshold
            if rate < self.slow_speed_threshold:
                print(f"DataRecoder: {rate:.1f} writes/sec (SLOW), avg_time={avg_time*1000:.1f}ms")
    
    def _write_data_to_buffer_optimized(self, observation, action, reward, termination_flag, cam_data):
        """
        cam_data format: [top_camera, left_wrist, right_wrist]
        """
        # Debug: Check if cam_data is valid
        if cam_data is None or len(cam_data) < 3:
            print(f"WARNING: Invalid cam_data received: {cam_data}")
            return

        # RGB cameras (3 cameras only)
        # Order from get_camera_data: [top_camera, left_wrist, right_wrist]
        self.top_camera.append(cam_data[0].copy())    # Top/overhead camera
        self.left_wrist.append(cam_data[1].copy())    # Left wrist camera
        self.right_wrist.append(cam_data[2].copy())   # Right wrist camera

        # Store only metadata in DataFrame (PyArrow compatible)
        new_row = {
            'observation.state': observation.tolist(),  # Convert to list for PyArrow compatibility
            'action': action.tolist(),  # Convert to list for PyArrow compatibility
            'timestamp': float(self.timestamp),  # Ensure float type
            'episode_index': int(self.episode_index),  # Ensure int type
            'frame_index': int(self.frame_index),  # Ensure int type
            'index': int(self.index),  # Ensure int type
            'next.reward': float(reward),  # Ensure float type
            'next.done': bool(termination_flag),  # Ensure bool type
            'task_index': 0
        }
        
        # Use concat instead of loc for better performance
        self.df = pd.concat([self.df, pd.DataFrame([new_row])], ignore_index=True)
        
        self.column_index += 1
        self.frame_index += 1
        self.index += 1



    def dump_buffer_data(self):
        # No need to wait for async image writing since we removed individual frame saving
        data_file_name = self._name_helper('episode', '.parquet', self.episode_index)
        self._update_log_dir()
        
        # Ensure log directory exists
        if not os.path.exists(self.log_dir):
            os.makedirs(self.log_dir)

        # Save DataFrame to parquet
        try:
            table = pa.Table.from_pandas(self.df)
            pq.write_table(table, self.log_dir + data_file_name)
            print(f"Saved parquet data to {self.log_dir + data_file_name}")
        except Exception as e:
            print(f"Error saving parquet data: {e}")
            # Fallback: save as CSV if parquet fails
            csv_file = data_file_name.replace('.parquet', '.csv')
            self.df.to_csv(self.log_dir + csv_file, index=False)
            print(f"Saved CSV data to {self.log_dir + csv_file}")

        # Save video data using optimized method
        self._dump_videos_optimized()

        self.episode_index += 1
        print(f"Complete Writing Data. Saved to {self.log_dir + data_file_name}")
        print(f"Videos saved to {self.video_dir}")

    def _dump_videos_optimized(self):
        """Optimized video saving: save numpy arrays as videos directly (3 RGB cameras only)"""
        # RGB cameras (3 cameras only)
        rgb_cams = {
            'top_camera': self.top_camera,        # Top/overhead camera
            'left_wrist': self.left_wrist,        # Left wrist camera
            'right_wrist': self.right_wrist       # Right wrist camera
        }

        # Save RGB videos
        for cam_name, buffer_list in rgb_cams.items():
            if not buffer_list:
                continue
            cam_video_dir = os.path.join(self.video_dir, f'observation.images.{cam_name}')
            if not os.path.exists(cam_video_dir):
                os.makedirs(cam_video_dir)
            video_file = self._name_helper(f'episode', '.mp4', self.episode_index)
            video_path = os.path.join(cam_video_dir, video_file)

            media.write_video(video_path, buffer_list, fps=self.fps)
            print(f"Saved {cam_name} RGB video to {video_path}")
    




    def _write_lossless_depth_mkv(self, output_path, depth_frames):
        """Write depth frames as lossless MKV using FFV1 codec via ffmpeg"""
        import subprocess
        import tempfile
        
        try:
            # Stack all depth frames into a numpy array
            depth_array = np.stack(depth_frames, axis=0)  # Shape: [T, H, W] or [T, H, W, 1]
            
            # Ensure depth is in correct format
            if depth_array.ndim == 3:
                # Add channel dimension if missing: [T, H, W] -> [T, H, W, 1]
                depth_array = depth_array[..., np.newaxis]
            
            # Normalize to uint16 range (0-65535) for maximum precision
            # Clip at 10000mm (10 meters) for reasonable depth range
            depth_normalized = np.clip(depth_array, 0, 10000)
            depth_uint16 = (depth_normalized / 10000.0 * 65535).astype(np.uint16)
            
            # Get dimensions
            num_frames, height, width, channels = depth_uint16.shape
            
            # Create temporary raw file
            with tempfile.NamedTemporaryFile(suffix='.raw', delete=False) as tmp:
                tmp_path = tmp.name
                # Write as raw uint16 grayscale (single channel)
                depth_uint16[:, :, :, 0].tobytes('C')
                tmp.write(depth_uint16[:, :, :, 0].tobytes('C'))
            
            # Use ffmpeg to encode as lossless FFV1 in MKV container
            # FFV1 is a lossless video codec perfect for depth data
            ffmpeg_cmd = [
                'ffmpeg', '-y',  # Overwrite output file
                '-f', 'rawvideo',
                '-pix_fmt', 'gray16le',  # 16-bit grayscale, little-endian
                '-s', f'{width}x{height}',
                '-r', str(self.fps),
                '-i', tmp_path,
                '-c:v', 'ffv1',  # FFV1 lossless codec
                '-level', '3',  # FFV1 level 3 (best compression)
                '-coder', '1',  # Range coder (better compression)
                '-context', '1',  # Large context (better compression)
                '-g', '1',  # All frames are keyframes (for random access)
                '-slices', '24',  # Parallel encoding
                '-slicecrc', '1',  # Error detection
                output_path
            ]
            
            # Run ffmpeg
            result = subprocess.run(ffmpeg_cmd, capture_output=True, text=True)
            
            # Clean up temporary file
            os.unlink(tmp_path)
            
            if result.returncode != 0:
                print(f"FFmpeg error: {result.stderr}")
                raise RuntimeError(f"FFmpeg failed with return code {result.returncode}")
                
        except Exception as e:
            print(f"Error writing lossless depth MKV: {e}")
            print("Falling back to normalized MP4 format...")
            
            # Fallback: save as normalized MP4 if ffmpeg fails
            depth_normalized = []
            for depth_frame in depth_frames:
                normalized = np.clip(depth_frame / 5000.0 * 255, 0, 255).astype(np.uint8)
                depth_rgb = np.stack([normalized, normalized, normalized], axis=-1)
                depth_normalized.append(depth_rgb)
            
            fallback_path = output_path.replace('.mkv', '.mp4')
            media.write_video(fallback_path, depth_normalized, fps=self.fps)
            print(f"Saved fallback MP4 to {fallback_path}")

    def get_performance_stats(self):
        """Get performance statistics"""
        if not self.processing_times:
            return {}
        
        # Calculate current rate
        avg_time = np.mean(self.processing_times[-100:]) if len(self.processing_times) >= 100 else np.mean(self.processing_times)
        current_rate = 1.0 / avg_time if avg_time > 0 else 0
        
        return {
            'avg_processing_time_ms': np.mean(self.processing_times) * 1000,
            'max_processing_time_ms': np.max(self.processing_times) * 1000,
            'min_processing_time_ms': np.min(self.processing_times) * 1000,
            'total_operations': len(self.processing_times),
            'current_rate_hz': current_rate,
            'slow_speed_threshold': self.slow_speed_threshold,
            'episode_start_time': self.episode_start_time,
            'current_timestamp': self.timestamp
        }
    
    def get_episode_info(self):
        """Get episode timing information"""
        if self.episode_start_time is None:
            return {}
        
        current_time = time.time()
        episode_duration = current_time - self.episode_start_time
        
        return {
            'episode_start_time': self.episode_start_time,
            'current_time': current_time,
            'episode_duration': episode_duration,
            'timestamp': self.timestamp,
            'frame_index': self.frame_index,
            'collection_rate_hz': self.frame_index / episode_duration if episode_duration > 0 else 0
        }

    def _update_log_dir(self):
        if self.episode_index < 1000:
            self.log_dir = SAVE_DIR + "data/chunk_000/"
            self.video_dir = SAVE_DIR + "videos/chunk_000/"
        elif 1000 <= self.episode_index < 2000:
            self.log_dir = SAVE_DIR + "data/chunk_001/"
            self.video_dir = SAVE_DIR + "videos/chunk_001/"
        elif 2000 <= self.episode_index < 3000:
            self.log_dir = SAVE_DIR + "data/chunk_002/"
            self.video_dir = SAVE_DIR + "videos/chunk_002/"
        elif 3000 <= self.episode_index < 4000:
            self.log_dir = SAVE_DIR + "data/chunk_003/"
            self.video_dir = SAVE_DIR + "videos/chunk_003/"
        else:
            self.log_dir = SAVE_DIR + "data/chunk_004/"
            self.video_dir = SAVE_DIR + "videos/chunk_004/"

    def _name_helper(self, name, extension, index):
        if index <= 9:
            file_name = f'{str(name)}_00000' + str(index) + str(extension)
        elif 9 < index <= 99:
            file_name = f'{str(name)}_0000' + str(index) + str(extension)
        elif 99 < index <= 999:
            file_name = f'{str(name)}_000' + str(index) + str(extension)
        elif 999 < index <= 9999:
            file_name = f'{str(name)}_00' + str(index) + str(extension)
        else:
            file_name = f'{str(name)}_0' + str(index) + str(extension)

        return file_name