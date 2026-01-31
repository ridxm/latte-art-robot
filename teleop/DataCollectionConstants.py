"""

The following constants need to be manually filled out before any of the data collection scripts are executed.

"""

import os
import numpy as np

# Camera resolution - IMPORTANT for task quality!
# Current: 180x240 (low res, fast processing)
# Recommended for pouring: 480x640 (medium res, good detail)
# High quality: 720x1280 (high res, slow processing)
IMAGE_HEIGHT = 480  # Changed from 180 to 480 for better visual detail
IMAGE_WIDTH = 640   # Changed from 240 to 640 for better visual detail
IMAGE_CHANNELS = 3  # RGB images

# Arm joint limits
ARM_JOINT_MIN = np.array([-3.11, -2.27, -2.36, -3.11, -2.23, -6.28])
ARM_JOINT_MAX = np.array([3.11, 2.27, 2.36, 3.11, 2.23, 6.28])

# Robot control settings
ARM_SPEED = 0.5
RATE = 10  # Data collection frequency (Hz)
"""
DataRecoder.py

SAVE_DIRECTORY_PATH_DATA - Path to where the Dataset should be stored
LEROBOT_DATASET_COLUMN_HEADER - LeRobot format columns for data logging
"""
# Save everything in Data folder relative to project root
SAVE_DIRECTORY_PATH_DATA : str = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "Data") + "/"
LEROBOT_DATASET_COLUMN_HEADER : list= ['observation.state', 'action', 'timestamp', 'episode_index', 'frame_index', 'index', 'next.reward', 'next.done', 'task_index']

USE_LOSSLESS_DEPTH_MKV = True 
SUPPORT_LEGACY_MP4_DEPTH = True
DEPTH_MAX_VALUE_MM = 10000.0

"""
policy_inference.py
"""
# This script is an modified version of skrl/play.py script thus you must use the CLI to specify the following:
# --task
# --checkpoint
# --num_envs
# --enable_cameras
# --headless
# for example, python3 scripts/DARoS/skrl_final/collect_data/policy_inference.py --checkpoint=/home/isaac/Documents/Github/IsaacLab/logs/skrl/multidoorman_grasp/trained/best_agent.pt --task=MultiDoorMan-Grasp-Log --enable_cameras --num_envs=1 --headless

"""
MetaRecoder.py

SAVE_DIRECTORY_PATH_META - Path to where the Meta files should be stored
"""
# Save metadata in Data folder
SAVE_DIRECTORY_PATH_META : str = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "Data") + "/"
# Logic for multiple tasks are not yet been implemented! please refer to initializer of MetaRecorder.py
JOINT_NAMES = 'TODO' # place holder for now

"""
generate_meta.py

DATA_FOLDER_PATH - where data is stored (chunks containing the .parquet files)
"""
DATA_FOLDER_PATH = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "Data", "data")

"""
play.py

DIFFUSION_POLICY_PATH - where weights for the diffusion policy is stored
"""