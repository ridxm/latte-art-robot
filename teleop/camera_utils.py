#!/usr/bin/env python3

import cv2
import numpy as np
import time
import threading
from collections import deque
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

import IPython
e = IPython.embed

class AsyncCameraReader:
    """LeRobot-style async camera reader with background thread and timeout handling"""
    
    def __init__(self, image_height, image_width, timeout_ms=200, slow_speed_threshold=15.0):
        self.image_height = image_height
        self.image_width = image_width
        self.timeout_ms = timeout_ms
        self.slow_speed_threshold = slow_speed_threshold
        
        # Threading for async reading
        self.frame_lock = threading.Lock()
        self.latest_frames = {}
        self.timestamps = {}  # ROS header timestamps (secs + nsecs)
        self.cam_last_timestamps = {}  # Track last used timestamp per camera (ALOHA-style)
        self.new_frame_event = threading.Event()
        self.read_thread = None
        self.stop_event = threading.Event()
        
        # Performance monitoring
        self.callback_count = 0
        self.last_performance_check = time.time()
        self.read_errors = 0
        
        # Initialize ROS components
        self.bridge = CvBridge()
        self._setup_subscribers()
    
    def _setup_subscribers(self):
        """Setup ROS subscribers for 3 cameras only: top, left wrist, right wrist"""
        # Camera topic mapping - only 3 RGB cameras
        camera_topics = {
            'top_camera': '/camera_0/color/image_raw',      # Top/overhead camera
            'left_wrist': '/camera_3/color/image_raw',      # Left wrist camera
            'right_wrist': '/camera_4/color/image_raw',     # Right wrist camera
        }

        # Create subscribers with optimized callback
        for cam_name, topic in camera_topics.items():
            rospy.Subscriber(topic, Image, self._optimized_image_callback, cam_name)
    
    def _optimized_image_callback(self, data, cam_name):
        """Optimized callback for RGB cameras only"""
        try:
            # Convert image using CvBridge
            cv_image = self.bridge.imgmsg_to_cv2(data, desired_encoding='passthrough')

            # RGB image - convert BGR to RGB and resize
            cv_image = cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB)
            cv_image = cv2.resize(cv_image, (self.image_width, self.image_height), interpolation=cv2.INTER_AREA)
            
            # Update latest frames thread-safely
            with self.frame_lock:
                self.latest_frames[cam_name] = cv_image
                # Calculate full timestamp as float (ALOHA-style)
                frame_timestamp = data.header.stamp.secs + data.header.stamp.nsecs * 1e-9
                if frame_timestamp <= 0:
                    frame_timestamp = time.time()
                self.timestamps[cam_name] = frame_timestamp
                
                # Initialize last_timestamp tracking if needed
                if cam_name not in self.cam_last_timestamps:
                    self.cam_last_timestamps[cam_name] = 0.0
                
                # Debug: Log first frame from each camera
                if not hasattr(self, f'_logged_{cam_name}'):
                    print(f"✓ First frame received from {cam_name}: shape={cv_image.shape}, dtype={cv_image.dtype}")
                    setattr(self, f'_logged_{cam_name}', True)
            
            # Signal new frame available
            self.new_frame_event.set()
            
            # Performance monitoring
            self.callback_count += 1
            if self.callback_count % 1000 == 0:
                elapsed = time.time() - self.last_performance_check
                rate = 1000 / elapsed if elapsed > 0 else 0
                
                if rate < self.slow_speed_threshold:
                    print(f"AsyncCameraReader: {rate:.1f} callbacks/sec (SLOW)")
                
                self.last_performance_check = time.time()
                self.callback_count = 0
                
        except Exception as e:
            self.read_errors += 1
            print(f"Error in async image callback for {cam_name}: {e}")
    
    def start_async_reading(self):
        """Start the background reading thread"""
        if self.read_thread is not None and self.read_thread.is_alive():
            return  # Already running
        
        self.stop_event.clear()
        self.read_thread = threading.Thread(target=self._read_loop, daemon=True)
        self.read_thread.start()
        print("Async camera reading started")
    
    def stop_async_reading(self):
        """Stop the background reading thread"""
        if self.read_thread is not None:
            self.stop_event.set()
            self.read_thread.join(timeout=2.0)
            self.read_thread = None
            print("Async camera reading stopped")
    
    def _read_loop(self):
        """Background loop for continuous frame reading"""
        while not self.stop_event.is_set():
            try:
                # The actual reading is done in callbacks
                # This loop just monitors and manages the reading process
                time.sleep(0.01)  # Small sleep to prevent CPU spinning
                
            except Exception as e:
                print(f"Error in async read loop: {e}")
                time.sleep(0.1)  # Longer sleep on error
    
    def get_latest_frame(self, timeout_ms=None, wait_for_fresh=True):
        """Get latest frames with timeout and optional freshness check (ALOHA-style)
        
        Args:
            timeout_ms: Maximum time to wait for frames in milliseconds
            wait_for_fresh: If True, wait until ALL cameras have new frames since last call
        """
        if timeout_ms is None:
            timeout_ms = self.timeout_ms
        
        if not wait_for_fresh:
            # Original behavior - return cached frames immediately
            with self.frame_lock:
                if self.latest_frames:
                    if not hasattr(self, '_logged_available_cameras'):
                        available_cams = list(self.latest_frames.keys())
                        print(f"Available cameras: {available_cams}")
                        self._logged_available_cameras = True
                    return self.latest_frames.copy()
        else:
            # ALOHA-style: Wait for fresh frames from ALL cameras
            start_time = time.time()
            timeout_sec = timeout_ms / 1000.0
            
            expected_cameras = ['top_camera', 'left_wrist', 'right_wrist']
            
            while (time.time() - start_time) < timeout_sec:
                with self.frame_lock:
                    # Check if ALL expected cameras have fresh frames
                    all_fresh = True
                    for cam_name in expected_cameras:
                        if cam_name not in self.timestamps:
                            all_fresh = False
                            break
                        # Check if timestamp is newer than last used
                        # Treat zero/invalid stamps as fresh by assigning now; prevents infinite waits
                        if self.timestamps[cam_name] <= 0:
                            self.timestamps[cam_name] = time.time()
                        if self.timestamps[cam_name] <= self.cam_last_timestamps.get(cam_name, 0.0):
                            all_fresh = False
                            break
                    
                    if all_fresh:
                        # All cameras have fresh frames - update last_timestamps and return
                        for cam_name in expected_cameras:
                            self.cam_last_timestamps[cam_name] = self.timestamps[cam_name]
                        
                        if not hasattr(self, '_logged_fresh_sync'):
                            print("✓ Camera synchronization: waiting for fresh frames from all cameras")
                            self._logged_fresh_sync = True
                        
                        return self.latest_frames.copy()
                
                # Not all fresh yet, sleep briefly and check again
                time.sleep(0.00001)  # 10 microseconds like ALOHA
            
            # Timeout - log warning and return what we have
            with self.frame_lock:
                stale_cams = []
                for cam_name in expected_cameras:
                    if cam_name in self.timestamps:
                        ts = self.timestamps[cam_name]
                        if ts <= 0:
                            stale_cams.append(f"{cam_name}(no_stamp)")
                        elif ts <= self.cam_last_timestamps.get(cam_name, 0.0):
                            age_ms = (time.time() - ts) * 1000
                            stale_cams.append(f"{cam_name}({age_ms:.0f}ms)")
                
                if stale_cams and not hasattr(self, '_warned_stale_frames'):
                    print(f"⚠️  Timeout waiting for fresh frames. Stale cameras: {', '.join(stale_cams)}")
                    self._warned_stale_frames = True
                
                # Update timestamps even for stale frames to avoid repeating warnings
                for cam_name in expected_cameras:
                    if cam_name in self.timestamps:
                        self.cam_last_timestamps[cam_name] = self.timestamps[cam_name]
                
                return self.latest_frames.copy() if self.latest_frames else {}
        
        # Fallback: No frames yet, wait for first frame with timeout
        if not self.new_frame_event.wait(timeout=timeout_ms/1000.0):
            thread_alive = self.read_thread is not None and self.read_thread.is_alive()
            raise TimeoutError(
                f"Timed out waiting for camera frames after {timeout_ms} ms. "
                f"Read thread alive: {thread_alive}. Errors: {self.read_errors}"
            )
        
        with self.frame_lock:
            frames = self.latest_frames.copy()
        
        if not frames:
            raise RuntimeError("No frames available")
        
        return frames
    
    def get_performance_stats(self):
        """Get performance statistics"""
        current_time = time.time()
        elapsed = current_time - self.last_performance_check
        rate = self.callback_count / elapsed if elapsed > 0 else 0
        
        return {
            'callback_rate': rate,
            'read_errors': self.read_errors,
            'thread_alive': self.read_thread is not None and self.read_thread.is_alive()
        }

class OptimizedImageRecorder:
    def __init__(self, init_node=False, enable_caching=True, cache_duration=0.1, slow_speed_threshold=15.0):
        # ... existing code ...
        self.bridge = CvBridge()
        self.camera_names = ['cam_base', 'cam_left_wrist', 'cam_right_wrist', 'cam_top_front', 'cam_base_depth', 'cam_left_wrist_depth', 'cam_right_wrist_depth']
        
        # Performance optimizations
        self.enable_caching = enable_caching
        self.cache_duration = cache_duration
        self.image_cache = {}
        self.cache_timestamps = {}
        self.cache_lock = threading.Lock()
        
        # Pre-allocate image storage
        self.images = {cam_name: None for cam_name in self.camera_names}
        self.timestamps = {cam_name: {'secs': None, 'nsecs': None} for cam_name in self.camera_names}
        
        if init_node:
            rospy.init_node('image_recorder', anonymous=True)
            
        # Create a single optimized callback for all cameras
        self._setup_subscribers()
        
        # Performance monitoring
        self.callback_count = 0
        self.last_performance_check = time.time()
        self.slow_speed_threshold = slow_speed_threshold

    def _setup_subscribers(self):
        """Setup ROS subscribers with optimized callbacks"""
        import rospy
        from sensor_msgs.msg import Image
        
        # Camera topic mapping
        camera_topics = {
            'cam_base': '/camera_0/color/image_raw',
            'cam_left_wrist': '/camera_3/color/image_raw', 
            'cam_right_wrist': '/camera_4/color/image_raw',
            'cam_top_front': '/camera0/image_raw',
            'cam_base_depth': '/camera_0/depth/image_raw',
            'cam_left_wrist_depth': '/camera_3/depth/image_raw',
            'cam_right_wrist_depth': '/camera_4/depth/image_raw'
        }
        
        # Create subscribers with optimized callback
        for cam_name, topic in camera_topics.items():
            rospy.Subscriber(topic, Image, self._optimized_image_callback, cam_name)

    def _optimized_image_callback(self, data, cam_name):
        """Optimized callback that handles all cameras"""
        try:
            # Convert image only if caching is disabled or cache is expired
            current_time = time.time()
            
            with self.cache_lock:
                # Check if we need to update the cache
                if (not self.enable_caching or 
                    cam_name not in self.cache_timestamps or 
                    current_time - self.cache_timestamps[cam_name] > self.cache_duration):
                    
                    # Convert image using CvBridge
                    cv_image = self.bridge.imgmsg_to_cv2(data, desired_encoding='passthrough')
                    # Convert BGR to RGB to fix color channel swapping
                    cv_image = cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB)
                    
                    # Update cache
                    self.images[cam_name] = cv_image
                    self.timestamps[cam_name]['secs'] = data.header.stamp.secs
                    self.timestamps[cam_name]['nsecs'] = data.header.stamp.nsecs
                    self.cache_timestamps[cam_name] = current_time
                    
                    # Performance monitoring
                    self.callback_count += 1
                    if self.callback_count % 1000 == 0:
                        elapsed = current_time - self.last_performance_check
                        rate = 1000 / elapsed if elapsed > 0 else 0
                        
                        # Only report speed when it's slower than threshold
                        if rate < self.slow_speed_threshold:
                            print(f"ImageRecorder: {rate:.1f} callbacks/sec (SLOW)")
                        
                        self.last_performance_check = current_time
                        self.callback_count = 0
                        
        except Exception as e:
            print(f"Error in image callback for {cam_name}: {e}")

    def get_images(self):
        """Get current images with optional caching"""
        if self.enable_caching:
            # Return cached images
            with self.cache_lock:
                return {cam_name: self.images[cam_name] for cam_name in self.camera_names}
        else:
            # Return current images (no caching)
            return {cam_name: self.images[cam_name] for cam_name in self.camera_names}

    def get_latest_images(self, timeout=0.1):
        """Get latest images with timeout"""
        import rospy
        
        start_time = rospy.Time.now()
        while (rospy.Time.now() - start_time).to_sec() < timeout:
            images = self.get_images()
            if all(img is not None for img in images.values()):
                return images
            rospy.sleep(0.01)
        
        # Return whatever we have after timeout
        return self.get_images()

    def set_caching(self, enable=True, duration=0.1):
        """Enable/disable image caching"""
        with self.cache_lock:
            self.enable_caching = enable
            self.cache_duration = duration
            if not enable:
                # Clear cache when disabling
                self.cache_timestamps.clear()

    def get_performance_stats(self):
        """Get performance statistics"""
        current_time = time.time()
        elapsed = current_time - self.last_performance_check
        callback_rate = self.callback_count / elapsed if elapsed > 0 else 0
        
        return {
            'callback_count': self.callback_count,
            'callback_rate': callback_rate,
            'caching_enabled': self.enable_caching,
            'cache_duration': self.cache_duration,
            'cached_images': len([k for k, v in self.cache_timestamps.items() if v > 0]),
            'slow_speed_threshold': self.slow_speed_threshold
        }


# Keep the original class for backward compatibility
class ImageRecorder(OptimizedImageRecorder):
    """Backward compatibility wrapper for the original ImageRecorder interface"""
    
    def __init__(self, init_node=False, slow_speed_threshold=15.0):
        super().__init__(init_node=init_node, enable_caching=True, cache_duration=0.1, slow_speed_threshold=slow_speed_threshold)
        
        # Add missing attributes for backward compatibility
        self.callback_count = 0
        self.last_performance_check = time.time()
        self.cache_duration = 0.1  # Default cache duration
        
        # Setup individual callbacks for backward compatibility
        self._setup_individual_callbacks()
    
    def _setup_individual_callbacks(self):
        """Setup individual callbacks for backward compatibility"""
        import rospy
        from sensor_msgs.msg import Image
        
        # Individual callback functions for backward compatibility
        def create_callback(cam_name):
            def callback(data):
                self._optimized_image_callback(data, cam_name)
            return callback
        
        # Create individual callbacks
        self.image_cb_cam_base = create_callback('cam_base')
        self.image_cb_cam_left_wrist = create_callback('cam_left_wrist')
        self.image_cb_cam_right_wrist = create_callback('cam_right_wrist')
        self.image_cb_cam_top_front = create_callback('cam_top_front')
        self.image_cb_cam_base_depth = create_callback('cam_base_depth')
        self.image_cb_cam_left_wrist_depth = create_callback('cam_left_wrist_depth')
        self.image_cb_cam_right_wrist_depth = create_callback('cam_right_wrist_depth')
    
    def image_cb(self, cam_name, data):
        """Legacy callback method"""
        self._optimized_image_callback(data, cam_name)
    
    def set_caching(self, enable=True, duration=0.1):
        """Enable/disable image caching (backward compatibility)"""
        self.enable_caching = enable
        self.cache_duration = duration
        if not enable:
            # Clear cache when disabling
            self.cache_timestamps.clear()
    
    def get_performance_stats(self):
        """Get performance statistics (backward compatibility)"""
        return {
            'callback_count': self.callback_count,
            'caching_enabled': self.enable_caching,
            'cache_duration': self.cache_duration,
            'cached_images': len([k for k, v in self.cache_timestamps.items() if v > 0])
        }