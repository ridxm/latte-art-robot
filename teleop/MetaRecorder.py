import numpy as np
import pandas as pd
import os
import json

import io
from PIL import Image

from os import listdir
from os.path import isfile, join

import concurrent.futures
import multiprocessing as mp
from tqdm import tqdm

from DataCollectionConstants import SAVE_DIRECTORY_PATH_META, JOINT_NAMES

SAVE_DIR = SAVE_DIRECTORY_PATH_META

class MetaRecorder:
    def __init__(self, data_folder_path, image_size=(256, 256, 3)):
        self.data_folder_path = data_folder_path
        self.tasks = ["Pour the coffee into the cup"]

        self.num_workers = mp.cpu_count()
        self.image_height = image_size[0]
        self.image_width = image_size[1]
        self.image_channel = image_size[2]

        if not os.path.exists(SAVE_DIR):
            os.makedirs(SAVE_DIR)

    def _all_data_path_finder(self):
        all_files = []
        for sub in os.listdir(self.data_folder_path):
            sub_path = self.data_folder_path + '/' + sub
            for file in os.listdir(sub_path):
                f_path = sub_path + '/' + file 
                all_files.append(f_path) 
        all_files.sort()
        return all_files

    
    def generate_episodes_jsonl(self):
        all_files = self._all_data_path_finder()
        jsonl_data = []
        with tqdm(total=len(all_files), desc="Processing episodes", unit="episode") as pbar:
            for file in all_files:
                df = pd.read_parquet(file)
                
                dump_dict = {}
                # print(type(df['episode_index'][0]))
                # print(df['episode_index'][0])
                # print(type(df['episode_index']))
                # exit()

                dump_dict['episode_index'] = int(df['episode_index'][0])
                dump_dict['tasks'] = self.tasks
                dump_dict['length'] = len(df)

                # print(dump_dict)
                # exit()

                jsonl_data.append(dump_dict)
                pbar.update(1)

        self._write_data(jsonl_data, SAVE_DIR+"episodes.jsonl")

    def generate_info_json(self):
        all_files = self._all_data_path_finder()
        total_episodes = len(all_files)
        total_frames = 0
        unique_task_indices = set()
        fps = 0.0
        total_tasks = 0
        sample_features = {}

        data_path = "data/chunk_{episode_chunk:03d}/episode_{episode_index:06d}.parquet"
        video_path = "videos/chunk_{episode_chunk:03d}/{video_key}/episode_{episode_index:06d}.mp4"
        video_path_depth = "videos/chunk_{episode_chunk:03d}/{video_key}/episode_{episode_index:06d}.mkv"

        # just take on df for features since everything is the same
        inference_df = pd.read_parquet(all_files[0])
        for col in inference_df.columns:
            col_pointer = inference_df[col]

            sample = col_pointer.iloc[0]

            if isinstance(sample, (np.ndarray, list, tuple)):
                arr = np.array(sample)
                data_type = str(arr.dtype)
                data_shape = [int(str(arr.shape).split(',')[0].split('(')[1])]
            else:
                data_type = str(inference_df[col].dtype)
                data_shape = [1]
            
            sample_features[col] = {
                'dtype' : data_type,
                'shape' : data_shape,
                'names' : JOINT_NAMES # I think it is easier to manually fill this out since getting the joint name via script will be a pain...
            }
        image_features = {
            'observation.images.top_camera': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            },
            'observation.images.front_camera': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            },
            'observation.images.usb_camera': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            },
            'observation.images.left_camera': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            },
            'observation.images.right_camera': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            },
            'observation.images.top_camera_depth': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            },
            'observation.images.front_camera_depth': {
                'dtype': 'video',
                'shape': [self.image_height, self.image_width, self.image_channel],
                'names': ["height", "width", "channel"]
            }
        }
        
        # Merge image features with other features
        sample_features.update(image_features)
        
        print(f"Available DataFrame columns: {list(inference_df.columns)}")
        print(f"Added image features for video files: {list(image_features.keys())}")
        
        # print(sample_features) 
        # {'observation.images.image': {'dtype': 'object', 'shape': [1], 'names': 'TODO'}, 'observation.state': 
        # {'dtype': 'float32', 'shape': ['45'], 'names': 'TODO'}, 'action': {'dtype': 'float32', 'shape': ['13'], 'names': 'TODO'}, 
        # 'timestamp': {'dtype': 'float64', 'shape': [1], 'names': 'TODO'}, 'episode_index': {'dtype': 'int64', 'shape': [1], 'names': 'TODO'}, 
        # 'frame_index': {'dtype': 'int64', 'shape': [1], 'names': 'TODO'}, 'index': {'dtype': 'int64', 'shape': [1], 'names': 'TODO'}, 
        # 'next.reward': {'dtype': 'float64', 'shape': [1], 'names': 'TODO'}, 'next.done': {'dtype': 'bool', 'shape': [1], 'names': 'TODO'}, 
        # 'task_index': {'dtype': 'int64', 'shape': [1], 'names': 'TODO'}}
        # exit()

        fps_l = []
        with tqdm(total=len(all_files), desc="Processing info", unit="file") as pbar:
            for file in all_files:
                df = pd.read_parquet(file)
                total_frames += len(df)
                unique_task_indices.update(df['task_index'].unique().tolist())
                ts = df['timestamp'].values
                # print(type(ts))
                diffs = np.diff(ts) # type: ignore
                # print(diffs)
                # exit()
                fps_est = 1.0 / np.mean(diffs)
                fps_l.append(fps_est)
                pbar.update(1)

        fps = float(np.mean(fps_l))
        total_tasks = len(unique_task_indices)

        splits = {"train":f"0:{total_episodes}"}

        info = {
            "codebase_version": "v2.1",
            "robot_type": "realmandoor",
            "total_episodes": total_episodes,
            "total_frames": total_frames,
            "total_tasks": total_tasks,
            "total_videos": total_episodes,
            "total_chunks": 1,
            "chunks_size": 1000,
            "fps": fps,
            "splits" : splits,
            "data_path" : data_path,
            "video_path" : video_path,
            "video_path_depth" : video_path_depth,
            "features": sample_features
        }

        out_f_name = SAVE_DIR+'info.json'
        with open(out_f_name, 'w') as f:
            json.dump(info, f, indent=4)
    
        print(f"Successfully generated {out_f_name} to {os.getcwd()}")
        print("WARNING (info.json): \ninfo.json 1) Image data is stored as separate MP4 video files\ninfo.json 2) add joint/motor names (if needed)")

    def generate_stats_json(self):
        all_files = self._all_data_path_finder()

        preprocessed_stats = {}

        processed_file_count = 0

        with tqdm(total=len(all_files), desc="Processing stats", unit="file") as pbar:
            for file in all_files:
                df = pd.read_parquet(file)

                for col in df.columns:
                    # Skip image columns - they are now stored as separate video files
                    if 'observation.images.' in col:
                        continue
                    
                    #first create place holder with sample on top
                    if col not in preprocessed_stats:
                        col_pointer = df[col]
                        sample = col_pointer.iloc[0]
                        # print(sample)
                        # exit()
                        # when we see image in bytes 
                        if isinstance(sample, dict) and 'bytes' in sample:
                            img = Image.open(io.BytesIO(sample['bytes']))
                            img = img.convert("RGB")
                            # i think we should normalize since hugging face sample do that - prob becasuse of how fed into NN by mdp.image
                            arr = np.asarray(img).astype(np.float32) / 255.0
                            C = arr.shape[2]
                            # create place holder
                            preprocessed_stats[col] = {
                                "dt" : "img",
                                "sum" : np.zeros((C,), dtype=np.float64),
                                "sum_sq": np.zeros((C,), dtype=np.float64),
                                "pixel_count" : 0,
                                "min" : np.full((C,), np.inf, dtype=np.float64),
                                "max" : np.full((C,), -np.inf, dtype=np.float64)
                            }
                        # when we see other numerical data
                        else:
                            if isinstance(sample, (list, tuple, np.ndarray)):
                                arr = np.asarray(sample, dtype=np.float64)
                            else:
                                arr = np.array([sample], dtype=np.float64)
                            #print(np.zeros(arr.flatten().shape, dtype=np.float64).shape)
                            #exit()
                            preprocessed_stats[col] = {
                                "dt" : "num",
                                "sum" : np.zeros(arr.flatten().shape, dtype=np.float64),
                                "sum_sq": np.zeros(arr.flatten().shape, dtype=np.float64),
                                "count" : 0,
                                "min" : np.full(arr.flatten().shape, np.inf, dtype=np.float64),
                                "max" : np.full(arr.flatten().shape, -np.inf, dtype=np.float64)
                            }
                    
                    col_dict_point = preprocessed_stats.get(col)
                    #print(col_dict_point)
                    
                    # Skip if this column was not processed (e.g., image columns)
                    if col_dict_point is None:
                        continue
                    
                    df_rows = df[col]

                    # Skip image data processing - images are now stored as separate video files
                    if col_dict_point['dt'] == "img": # type: ignore
                        continue
                    else:
                        for row in df_rows:
                            if isinstance(row, (list, tuple, np.ndarray)):
                                arr = np.asarray(row, dtype=np.float64).flatten()
                            else:
                                arr = np.array([row], dtype=np.float64)

                            col_dict_point["sum"] += arr # type: ignore
                            col_dict_point["sum_sq"] += arr * arr # type: ignore
                            col_dict_point["count"] += 1 # type: ignore

                            col_dict_point['min'] = np.minimum(arr, col_dict_point["min"]) # type: ignore
                            col_dict_point['max'] = np.maximum(arr, col_dict_point["max"]) # type: ignore
                
                processed_file_count += 1
                pbar.update(1)
                pbar.set_postfix({'processed': processed_file_count, 'total': len(all_files)})

        dump_dict = {}
        # print(preprocessed_stats)
        
        # Add note about image data being stored separately
        print("Note: Image data (observation.images.*) is stored as separate MP4 video files, not in DataFrame stats")
        
        # Compute image statistics from video files
        image_stats = self._compute_image_stats_from_videos(all_files)
        dump_dict.update(image_stats)
        
        for key, value in preprocessed_stats.items():
                
            if value['dt'] == 'img':
                pix_count = value["pixel_count"]
                mean = (value["sum"] / pix_count).tolist()
                var = (value["sum_sq"] / pix_count) - np.square(value["sum"] / pix_count)
                var = np.clip(var, a_min=0.0, a_max=None)
                min = value["min"].tolist()
                max = value["max"].tolist()

                dump_dict[key] = {
                    "mean" : self._format_for_RGB(mean),
                    "std" : self._format_for_RGB(np.sqrt(var).tolist()),
                    "min" : self._format_for_RGB(min),
                    "max" : self._format_for_RGB(max),
                }
                # print(dump_dict)
                
            else:
                count = value['count']
                mean = (value["sum"] / count).tolist()
                var = (value["sum_sq"] / count) - np.square(value["sum"] / count)
                var = np.clip(var, a_min=0.0, a_max=None)
                min = value["min"].tolist()
                max = value["max"].tolist()

                dump_dict[key] = {
                    "mean" : mean,
                    "std" : np.sqrt(var).tolist(),
                    "min" : min,
                    "max" : max,
                }
                

        
        #out_f_name = 'episodes_stats.jsonl'
        #with open(out_f_name, 'w') as f:
        #    f.write(json.dumps(dump_dict))
        #    f.write('\n')

        out_f_name = SAVE_DIR+'stats.json'
        with open(out_f_name, 'w') as f:
            json.dump(dump_dict, f, indent=4)
        print("WARNING (stats.jsonl): \nstats.jsonl 1) Need to mannually convert bool min max (REQUIRED)")

    def generate_stats_json_multiprocessing(self):
        all_files = self._all_data_path_finder()

        paths = all_files
        #print(paths)

        # I think this is a very good tutorial: https://www.youtube.com/watch?v=fKl2JW_qrso
        all_stats = []
        with concurrent.futures.ProcessPoolExecutor(max_workers=self.num_workers) as executor:
            ff = [executor.submit(_process_parquet_worker, path) for path in paths]

            counter = 0
            for f in concurrent.futures.as_completed(ff):
                l_stats = f.result()
                all_stats.append(l_stats)
                counter += 1
                print(f"(stats.json): {counter}/{len(all_files)} processed")

        
        preprocessed_stats = {}
        # print(all_stats)
        for stat in all_stats:
            for key, val in stat.items():
                if key not in preprocessed_stats:
                    preprocessed_stats[key] = val.copy()
                else:
                    if val['dt'] =='img':
                        preprocessed_stats[key]["sum"] += val['sum']
                        preprocessed_stats[key]["sum_sq"] += val['sum_sq']
                        preprocessed_stats[key]["pixel_count"] += val['pixel_count']
                        preprocessed_stats[key]["min"] = np.minimum(val['min'], preprocessed_stats[key]["min"])
                        preprocessed_stats[key]["max"] = np.maximum(val['max'], preprocessed_stats[key]["max"])
                    else:
                        preprocessed_stats[key]["sum"] += val['sum']
                        preprocessed_stats[key]["sum_sq"] += val['sum_sq']
                        preprocessed_stats[key]["count"] += val['count']
                        preprocessed_stats[key]["min"] = np.minimum(val['min'], preprocessed_stats[key]["min"])
                        preprocessed_stats[key]["max"] = np.maximum(val['max'], preprocessed_stats[key]["max"])

        dump_dict = {}

        for key, value in preprocessed_stats.items():
            if value['dt'] == 'img':
                pix_count = value["pixel_count"]
                mean = (value["sum"] / pix_count).tolist()
                var = (value["sum_sq"] / pix_count) - np.square(value["sum"] / pix_count)
                var = np.clip(var, a_min=0.0, a_max=None)
                min = value["min"].tolist()
                max = value["max"].tolist()

                dump_dict[key] = {
                    "mean" : self._format_for_RGB(mean),
                    "std" : self._format_for_RGB(np.sqrt(var).tolist()),
                    "min" : self._format_for_RGB(min),
                    "max" : self._format_for_RGB(max),
                }
                # print(dump_dict)
                
            else:
                count = value['count']
                mean = (value["sum"] / count).tolist()
                var = (value["sum_sq"] / count) - np.square(value["sum"] / count)
                var = np.clip(var, a_min=0.0, a_max=None)
                min = value["min"].tolist()
                max = value["max"].tolist()

                dump_dict[key] = {
                    "mean" : mean,
                    "std" : np.sqrt(var).tolist(),
                    "min" : min,
                    "max" : max,
                }

        out_f_name = SAVE_DIR+'stats.json'
        with open(out_f_name, 'w') as f:
            json.dump(dump_dict, f, indent=4)
        
        print("WARNING (stats.jsonl): \nstats.jsonl 1) Need to mannually convert bool min max (REQUIRED)")
        
    def generate_tasks_jsonl(self):
        jsonl_data = []


        for task in self.tasks:
            dump_dict = {}
            
            dump_dict["task_index"] = 0
            dump_dict["task"] = task

            # print(dump_dict)
            # exit()
            
            jsonl_data.append(dump_dict)

        self._write_data(jsonl_data, SAVE_DIR+'tasks.jsonl')

    def _write_data(self, data, f_name):
        with open(f_name, 'w') as f:
            for l in data:
                f.writelines([json.dumps(l)])
                f.writelines('\n')

        print(f"Successfully generated {f_name} to {os.getcwd()}")

    def _format_for_RGB(self, lst):
        """Format RGB values to match the required JSON structure"""
        return [[[v]] for v in lst]
    
    def _compute_image_stats_from_videos(self, all_files):
        """Compute image statistics from video files using multiprocessing"""
        import cv2
        import concurrent.futures
        
        print(f"Processing {len(all_files)} video files with multiprocessing...")
        
        # Use multiprocessing to process videos in parallel
        
        # Initialize camera_stats outside try-except to avoid UnboundLocalError
        # 7 cameras total: 5 RGB (top, front, usb, left, right) + 2 depth (top, front)
        camera_stats = {
            'observation.images.top_camera': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            },
            'observation.images.front_camera': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            },
            'observation.images.usb_camera': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            },
            'observation.images.left_camera': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            },
            'observation.images.right_camera': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            },
            'observation.images.top_camera_depth': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            },
            'observation.images.front_camera_depth': {
                'sum': np.zeros(3, dtype=np.float64),
                'sum_sq': np.zeros(3, dtype=np.float64),
                'pixel_count': 0,
                'min': np.full(3, np.inf, dtype=np.float64),
                'max': np.full(3, -np.inf, dtype=np.float64),
                'count': 0
            }
        }
        
        try:
            print("DEBUG: Attempting multiprocessing...")
            with concurrent.futures.ProcessPoolExecutor(max_workers=self.num_workers) as executor:
                # Submit all video processing tasks
                future_to_file = {executor.submit(_process_video_stats_worker, file, self.data_folder_path): file for file in all_files}
                print("DEBUG: All tasks submitted to multiprocessing executor")
        except Exception as e:
            print(f"DEBUG: Multiprocessing failed, falling back to single-threaded: {e}")
            # Fallback to single-threaded processing
            future_to_file = {file: _process_video_stats_worker(file, self.data_folder_path) for file in all_files}
        
        processed_count = 0
        
        # Handle both multiprocessing and single-threaded cases
        if isinstance(next(iter(future_to_file)), concurrent.futures.Future):
            # Multiprocessing case
            print("DEBUG: Using multiprocessing processing loop")
            with tqdm(total=len(all_files), desc="Processing videos", unit="file") as pbar:
                for future in concurrent.futures.as_completed(future_to_file):
                    file = future_to_file[future]
                    try:
                        episode_stats = future.result()
                        if episode_stats:
                            # Merge episode stats into overall stats
                            for camera_key, stats in episode_stats.items():
                                camera_stats[camera_key]['sum'] += stats['sum']
                                camera_stats[camera_key]['sum_sq'] += stats['sum_sq']
                                camera_stats[camera_key]['pixel_count'] += stats['pixel_count']
                                camera_stats[camera_key]['count'] += stats['count']
                                camera_stats[camera_key]['min'] = np.minimum(stats['min'], camera_stats[camera_key]['min'])
                                camera_stats[camera_key]['max'] = np.maximum(stats['max'], camera_stats[camera_key]['max'])
                        
                        processed_count += 1
                        pbar.update(1)
                        pbar.set_postfix({'processed': processed_count, 'total': len(all_files)})
                        
                    except Exception as e:
                        print(f"Error processing {file}: {e}")
                        pbar.update(1)
                        continue
        else:
            # Single-threaded case
            print("DEBUG: Using single-threaded processing loop")
            with tqdm(total=len(all_files), desc="Processing videos", unit="file") as pbar:
                for file, episode_stats in future_to_file.items():
                    try:
                        if episode_stats:
                            # Merge episode stats into overall stats
                            for camera_key, stats in episode_stats.items():
                                camera_stats[camera_key]['sum'] += stats['sum']
                                camera_stats[camera_key]['sum_sq'] += stats['sum_sq']
                                camera_stats[camera_key]['pixel_count'] += stats['pixel_count']
                                camera_stats[camera_key]['count'] += stats['count']
                                camera_stats[camera_key]['min'] = np.minimum(stats['min'], camera_stats[camera_key]['min'])
                                camera_stats[camera_key]['max'] = np.maximum(stats['max'], camera_stats[camera_key]['max'])
                        
                        processed_count += 1
                        pbar.update(1)
                        pbar.set_postfix({'processed': processed_count, 'total': len(all_files)})
                        
                    except Exception as e:
                        print(f"Error processing {file}: {e}")
                        pbar.update(1)
                        continue
        
        # Convert to final stats format
        final_stats = {}
        for camera_key, stats in camera_stats.items():
            if stats['pixel_count'] > 0:
                mean = (stats['sum'] / stats['pixel_count']).tolist()
                var = (stats['sum_sq'] / stats['pixel_count']) - np.square(stats['sum'] / stats['pixel_count'])
                var = var.tolist()
                
                final_stats[camera_key] = {
                    "min": self._format_for_RGB(stats['min'].tolist()),
                    "max": self._format_for_RGB(stats['max'].tolist()),
                    "mean": self._format_for_RGB(mean),
                    "std": self._format_for_RGB(np.sqrt(var).tolist()),
                    "count": [stats['count']]
                }
            else:
                print(f"Warning: No valid frames found for {camera_key}")
                final_stats[camera_key] = {
                    "min": self._format_for_RGB([0.0, 0.0, 0.0]),
                    "max": self._format_for_RGB([1.0, 1.0, 1.0]),
                    "mean": self._format_for_RGB([0.0, 0.0, 0.0]),
                    "std": self._format_for_RGB([0.0, 0.0, 0.0]),
                    "count": [0]
                }
        
        print("Image statistics computation completed.")
        return final_stats



def _process_video_stats_worker(file, data_folder_path):
    """Standalone worker function for processing video statistics (for multiprocessing)"""
    import cv2
    import os
    import numpy as np
    
    # Extract episode index from parquet filename
    episode_index = int(file.split('episode_')[-1].split('.')[0])
    
    # Determine chunk folder based on episode index
    if episode_index < 1000:
        chunk_folder = "chunk_000"
    elif episode_index < 2000:
        chunk_folder = "chunk_001"
    elif episode_index < 3000:
        chunk_folder = "chunk_002"
    elif episode_index < 4000:
        chunk_folder = "chunk_003"
    else:
        chunk_folder = "chunk_004"
    
    # Initialize episode stats
    # 7 cameras total: 5 RGB (top, front, usb, left, right) + 2 depth (top, front)
    episode_stats = {
        'observation.images.top_camera': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        },
        'observation.images.front_camera': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        },
        'observation.images.usb_camera': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        },
        'observation.images.left_camera': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        },
        'observation.images.right_camera': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        },
        'observation.images.top_camera_depth': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        },
        'observation.images.front_camera_depth': {
            'sum': np.zeros(3, dtype=np.float64),
            'sum_sq': np.zeros(3, dtype=np.float64),
            'pixel_count': 0,
            'min': np.full(3, np.inf, dtype=np.float64),
            'max': np.full(3, -np.inf, dtype=np.float64),
            'count': 0
        }
    }
    
    # Process each camera video (7 cameras: 5 RGB + 2 depth)
    for camera in ['top_camera', 'front_camera', 'usb_camera', 'left_camera', 'right_camera', 'top_camera_depth', 'front_camera_depth']:
        # Construct video path
        video_base = data_folder_path.replace('/data', '/videos')
        video_dir = os.path.join(video_base, chunk_folder, f'observation.images.{camera}')
        # Use .mkv for depth cameras, .mp4 for regular cameras
        video_ext = '.mkv' if 'depth' in camera else '.mp4'
        video_file = f'episode_{episode_index:06d}{video_ext}'
        video_path = os.path.join(video_dir, video_file)
        
        if not os.path.exists(video_path):
            continue
        
        try:
            cap = cv2.VideoCapture(video_path)
            frame_count = 0
            
            # Get total frame count for progress bar
            total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
            
            with tqdm(total=total_frames, desc=f"Processing {camera}", unit="frame", leave=False) as pbar:
                while True:
                    ret, frame = cap.read()
                    if not ret:
                        break
                    
                    frame_count += 1
                    
                    # Convert BGR to RGB and normalize to [0, 1]
                    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                    frame_normalized = frame_rgb.astype(np.float32) / 255.0
                    
                    # Compute statistics
                    H, W, C = frame_normalized.shape
                    flat = frame_normalized.reshape(-1, C)
                    
                    episode_stats[f'observation.images.{camera}']['sum'] += flat.sum(axis=0)
                    episode_stats[f'observation.images.{camera}']['sum_sq'] += (flat * flat).sum(axis=0)
                    episode_stats[f'observation.images.{camera}']['pixel_count'] += (H * W)
                    episode_stats[f'observation.images.{camera}']['count'] += 1
                    
                    episode_stats[f'observation.images.{camera}']['min'] = np.minimum(
                        flat.min(axis=0), episode_stats[f'observation.images.{camera}']['min'])
                    episode_stats[f'observation.images.{camera}']['max'] = np.maximum(
                        flat.max(axis=0), episode_stats[f'observation.images.{camera}']['max'])
                    
                    pbar.update(1)
            
            cap.release()
            
        except Exception as e:
            print(f"Error processing video {video_path}: {e}")
            continue
    
    return episode_stats

def _process_parquet_worker(path):
    # do waht ever did before but no more seen before thing 
    df = pd.read_parquet(path)
    stats = {}

    for col in df.columns:
        col_pointer = df[col]
        sample = col_pointer.iloc[0]

        if isinstance(sample, dict) and 'bytes' in sample:
            img = Image.open(io.BytesIO(sample['bytes']))
            img = img.convert("RGB")
            arr = np.asarray(img).astype(np.float32) / 255.0
            C = arr.shape[2]

            stats[col] = {
                "dt" : "img",
                "sum" : np.zeros((C,), dtype=np.float64),
                "sum_sq": np.zeros((C,), dtype=np.float64),
                "pixel_count" : 0,
                "min" : np.full((C,), np.inf, dtype=np.float64),
                "max" : np.full((C,), -np.inf, dtype=np.float64)
            }

            #unlike before now process that file here
            rows = df[col]
            for row in rows:
                b = row.get('bytes', None) if isinstance(row, dict) else None
                img = Image.open(io.BytesIO(b)) # type: ignore
                img = img.convert("RGB")
                arr = np.asarray(img).astype(np.float32) / 255.0

                H, W, C = arr.shape
                flat = arr.reshape(-1, C)
                sum = flat.sum(axis=0)
                sumsq = (flat * flat).sum(axis=0)
                stats[col]["sum"] += sum # type: ignore
                stats[col]["sum_sq"] += sumsq # type: ignore
                stats[col]["pixel_count"] += (H*W) # type: ignore

                stats[col]['min'] = np.minimum(flat.min(axis=0), stats[col]["min"]) # type: ignore
                stats[col]['max'] = np.maximum(flat.max(axis=0), stats[col]["max"]) # type: ignore

        else:
            if isinstance(sample, (list, tuple, np.ndarray)):
                arr = np.asarray(sample, dtype=np.float64)
            else:
                arr = np.array([sample], dtype=np.float64)
        
            stats[col] = {
                "dt" : "num",
                "sum" : np.zeros(arr.flatten().shape, dtype=np.float64),
                "sum_sq": np.zeros(arr.flatten().shape, dtype=np.float64),
                "count" : 0,
                "min" : np.full(arr.flatten().shape, np.inf, dtype=np.float64),
                "max" : np.full(arr.flatten().shape, -np.inf, dtype=np.float64)
            }

            #unlike before now process that file here
            rows = df[col]

            for row in rows:
                if isinstance(row, (list, tuple, np.ndarray)):
                    arr = np.asarray(row, dtype=np.float64).flatten()
                else:
                    arr = np.array([row], dtype=np.float64)

                stats[col]["sum"] += arr # type: ignore
                stats[col]["sum_sq"] += arr * arr # type: ignore
                stats[col]["count"] += 1 # type: ignore

                stats[col]['min'] = np.minimum(arr, stats[col]["min"]) # type: ignore
                stats[col]['max'] = np.maximum(arr, stats[col]["max"]) # type: ignore

    return stats