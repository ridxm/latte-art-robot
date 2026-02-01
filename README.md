# Latte Art Robot 🎨☕

Website: https://ridxm.github.io/latte-art-robot/

Pour patterns latte art using OpenDroid R2D3 + π0 VLA.

Project for Physical AI Hack 2026, Jan 31st-Feb -01 2026, hosted at Founders Inc https://luma.com/8ca2z1rr 

## Quick Start (Weekend Hackathon)

### Phase 1: Setup (2 hours)

```bash
# 1. Install dependencies (robot + laptop)
pip install lerobot torch

# 2. SSH into the robot
ssh r2d3@172.20.10.5  # password 1234

# 3. Launch Realman arm and camera drivers
cd ~/ros2_ws/src/teleop
python3 launch_drivers.py
```

### Phase 2: Record Demos (3 hours)

```bash
# Teleop + data recorder (Terminal B)
cd ~/ros2_ws/src/teleop
python3 collect_data_ros2.py

# Controls inside collect_data_ros2.py
#   s = start episode (leader arm or backpack drives follower arm)
#   y = save, n = discard, r = retry, q = quit

# Target 30–50 clean heart pours (≈20s/episode)

# Upload finished dataset to HuggingFace
huggingface-cli login
python -m lerobot.scripts.push_dataset_to_hub \
    --local-dir data/latte-heart-demos \
    --repo-id YOUR_USERNAME/latte-heart-demos
```

### Phase 3: Train on Cloud (1 hour)

```bash
# Optionally bootstrap coffee pours first (Unitree Z1 dataset)
python scripts/preprocess_z1_to_r2d3.py \
    --input-dir data/coffee_raw \
    --output-dir data/coffee \
    --overwrite

# Launch π0 fine-tune on H100
python scripts/train_cloud.py --dataset YOUR_USERNAME/latte-heart-demos

# 15k steps ≈ 60–70 minutes on an H100 (track with wandb)
```

### Phase 4: Deploy (1 hour)

```bash
# Download checkpoint from cloud
# Then run on robot:
python scripts/deploy.py --checkpoint checkpoints/heart-latte-v1/final
```

## Data Collection Story

Teaching a robot to pour latte art combines the precision of robotic control with the artistry of barista craft. Our approach uses **kinesthetic teaching** - physically guiding the robot's arms through pouring motions while it records everything it needs to learn.

### The Setup

<p align="center">
  <img src="data-collection-assets/teleop_rig.JPG" width="45%">
  <img src="data-collection-assets/data_collection_props.jpg" width="45%">
</p>

**Left**: The OpenDroid R2D3 robot with dual Realman RM65 arms, equipped with a kinesthetic teaching backpack that allows human demonstrators to guide its movements naturally.

**Right**: Our data collection workspace includes milk pitchers, espresso cups, a milk frother, and all the tools needed to demonstrate dozens of heart pours.

### How It Works

1. **Direct Teaching**: A human demonstrator wears the kinesthetic backpack and guides the robot's arms through a complete heart pour - from picking up the pitcher to the final wrist tilt that creates the pattern
2. **Multi-View Recording**: Three cameras (overhead, left wrist, right wrist) capture the scene at 20Hz, giving the model visual context from multiple angles
3. **Synchronized Data**: The system records joint positions (12D state for both arms), camera frames, and actions simultaneously in LeRobot format
4. **Quality Over Quantity**: We collected 40 demonstrations, keeping even "okay" attempts to show variation, but removing spills and major errors

### See It In Action

<p align="center">
  <img src="data-collection-assets/teleop_pour.gif" width="30%">
  <img src="data-collection-assets/latte_art_pour.gif" width="30%">
  <img src="data-collection-assets/closeup_pour.gif" width="30%">
</p>

**Left to Right**: Kinesthetic teaching demonstration, full latte art pour, closeup of the heart pattern formation.

### The Goal

<p align="center">
  <img src="data-collection-assets/professional-latte-art.JPG" width="60%">
</p>

Professional heart patterns like these require smooth, coordinated pouring - exactly the kind of fluid motion that π0's flow matching architecture excels at learning. The model learns not just the mechanics of pouring, but the subtle wrist movements and timing that create the distinctive heart shape.

### From Demos to Deployment

Each demonstration becomes training data:
- **Visual observations**: 3 camera views (640x480) showing workspace, pitcher position, and cup angle
- **Proprioceptive state**: 12D joint angles from both arms
- **Action trajectories**: Smooth motion sequences the model learns to reproduce

After 15,000 training steps on an H100 GPU (~70 minutes), the model can generate autonomous pouring motions that recreate the demonstrated heart patterns.

## Dataset

Our latte art pouring dataset is publicly available on HuggingFace Hub:

**[ridxm/latte-pour-demos](https://huggingface.co/datasets/ridxm/latte-pour-demos)**

### Dataset Statistics

- **Episodes**: 40 demonstrations
- **Format**: LeRobot v3.0 (Parquet + MP4)
- **Frequency**: 20 Hz
- **Duration**: ~20 seconds per episode

### Data Modalities

| Modality | Specification |
|----------|---------------|
| **Visual** | 3 cameras (top, left_wrist, right_wrist) @ 640×480 |
| **Proprioception** | 12D joint states (dual RM65 arms, 6 DOF each) |
| **Actions** | 12D joint velocities/positions |
| **Frequency** | 20 Hz synchronized capture |

### Usage

```python
from lerobot.common.datasets.lerobot_dataset import LeRobotDataset

# Load dataset
dataset = LeRobotDataset("ridxm/latte-pour-demos")

# Access episode
episode = dataset[0]
print(f"State shape: {episode['observation.state'].shape}")  # [12]
print(f"Action shape: {episode['action'].shape}")           # [12]
print(f"Cameras: {[k for k in episode.keys() if 'image' in k]}")
```

### Training

Use this dataset to fine-tune π0 for latte art pouring:

```bash
python scripts/train.py
```

## Training Pipeline

Our training approach uses **π0 (Pi-Zero)**, a vision-language-action (VLA) model from Physical Intelligence that uses flow matching for smooth, continuous action generation. The training pipeline is designed for replication on cloud GPUs.

### Architecture Overview

**Model**: π0 base (pre-trained on 10k+ hours of robot data)
- **Input**: 3 camera views (640×480) + 12D proprioceptive state
- **Output**: 12D action sequences (chunk_size=20 for 1-second lookahead at 20Hz)
- **Training**: Fine-tuning with bfloat16 precision on H100 GPU

### Training Configuration

The training script (`scripts/train.py`) wraps LeRobot's official training pipeline with our dataset-specific settings:

```python
# Key hyperparameters
--dataset.repo_id=ridxm/latte-pour-demos    # Our demonstration dataset
--policy.type=pi0                            # Pi-Zero policy
--policy.pretrained_path=lerobot/pi0_base   # Pre-trained checkpoint
--policy.chunk_size=20                       # 1s action horizon (20Hz)
--batch_size=32                              # Optimized for H100 80GB
--steps=15000                                # ~70 min on H100
--policy.dtype=bfloat16                      # Mixed precision for speed
```

### Running Training

**Local (if you have a GPU):**
```bash
cd /path/to/latte-art-robot
python scripts/train.py
```

**Cloud (VESSL.ai, Lambda Labs, etc.):**
```bash
# 1. Set up environment
pip install lerobot torch wandb huggingface-hub

# 2. Authenticate
huggingface-cli login
wandb login

# 3. Run training
python scripts/train.py
```

**Training Outputs:**
- Checkpoints saved to `./outputs/pi0_latte/checkpoints/`
- Logs uploaded to W&B project `latte-art-robot-v2`
- Final model pushed to HuggingFace Hub: `ridxm/latte-pi0`

### Data Format Conversion (Optional)

If you collected data in a custom format, use our converter to transform it to LeRobot v3 format:

```bash
python scripts/convert_to_lerobot.py \
    --input-dir data/raw \
    --output-dir data/lerobot \
    --dataset-name latte-heart-demos
```

**Input Format Expected:**
```
data/raw/
├── episode_000000/
│   ├── metadata.json          # Episode metadata (fps, duration)
│   ├── frames.json            # Frame-by-frame data
│   ├── wrist/                 # Wrist camera frames
│   │   ├── frame_000.jpg
│   │   └── ...
│   └── overhead/              # Overhead camera frames
│       ├── frame_000.jpg
│       └── ...
```

**Output Format (LeRobot v3):**
```
data/lerobot/
├── meta/
│   ├── info.json              # Dataset metadata
│   ├── episodes.jsonl         # Episode info
│   └── tasks.jsonl            # Task descriptions
├── data/
│   └── chunk-000/
│       └── episode_*.parquet  # State/action data
└── videos/
    └── chunk-000/
        ├── observation.images.wrist/
        │   └── episode_*.mp4
        └── observation.images.overhead/
            └── episode_*.mp4
```

### Replication Checklist

To replicate our training from scratch:

1. **Data Collection** (3-4 hours)
   - [ ] Set up R2D3 robot with 3 cameras
   - [ ] Collect 30-50 demonstrations using kinesthetic teaching
   - [ ] Each demo: ~20 seconds of pouring motion
   - [ ] Upload to HuggingFace: `python src/teleop/upload_to_hf.py`

2. **Training Setup** (30 min)
   - [ ] Spin up H100 GPU instance (VESSL, Lambda, RunPod)
   - [ ] Install dependencies: `pip install lerobot torch wandb`
   - [ ] Clone repo: `git clone https://github.com/YOUR_USERNAME/latte-art-robot`
   - [ ] Set environment variables: `HF_TOKEN`, `WANDB_API_KEY`

3. **Training** (1-2 hours)
   - [ ] Edit `scripts/train.py` to point to your dataset
   - [ ] Run: `python scripts/train.py`
   - [ ] Monitor training on W&B dashboard
   - [ ] Download final checkpoint from `./outputs/pi0_latte/checkpoints/`

4. **Deployment** (1 hour)
   - [ ] Transfer checkpoint to robot
   - [ ] Run: `python scripts/deploy.py --model ridxm/latte-pi0`
   - [ ] Test pouring with temporal ensembling enabled

### Training Tips

- **Low data regime**: Our 40 episodes benefit from π0's pre-training. For <20 episodes, consider data augmentation
- **Chunk size**: Set to `fps × desired_lookahead_seconds` (we use 20Hz × 1s = 20)
- **Batch size**: Scale based on GPU memory (H100 80GB handles 32 easily)
- **Convergence**: Training typically plateaus around 10k-15k steps
- **Checkpointing**: Save every 2500 steps to catch best model early

## Project Structure

```
Latte-Pouring-Art/
├── configs/
│   ├── robot/r2d3.yaml       # Robot configuration
│   └── policy/pi0_latte.yaml # Training config
├── scripts/
│   ├── record_demos.py       # Demo recording
│   ├── train_cloud.py        # Cloud training
│   └── deploy.py             # Inference
├── data/                     # Local datasets
└── checkpoints/              # Trained models
    └── coffee-pretrain/      # Optional coffee-pour warm start
```

## Hardware Requirements

- **Robot**: OpenDroid R2D3 (6 DOF)
- **Teleop**: LeRobot-compatible wearable kit
- **Cameras**: Wrist + overhead (30fps, 640x480)
- **GPU**: H100 (cloud) for training

## Materials for Demo Recording

- [ ] wide mouth coffee pitcher
- [ ] Milk frother + fresh milk
- [ ] Creamer pitcher with spout
- [ ] Paper towels
- [ ] Consistent lighting

## Key Commands

```bash
# Launch Realman drivers (calibrates both arms)
ros2 launch rm_driver dual_rm_65_driver.launch.py

# Start cameras
python3 launch_drivers.py

# Record demos (teleop backpack or leader arm)
python3 collect_data_ros2.py

# Convert Unitree coffee dataset to Realman layout
python scripts/preprocess_z1_to_r2d3.py --input-dir data/coffee_raw --output-dir data/coffee

# Train π0 (cloud)
python scripts/train_cloud.py --dataset YOUR_USERNAME/latte-heart-demos

# Deploy checkpoint
python scripts/deploy.py --checkpoint checkpoints/heart-latte-v1/final
```

## Model

Using **π0** (Pi-Zero) from Physical Intelligence:
- Flow matching for smooth 50Hz actions
- Pre-trained on 10k+ hours of robot data
- Fine-tuned on ~40 demonstrations

## Links

### Resources
- [LeRobot](https://github.com/huggingface/lerobot) - Framework for robot learning
- [OpenPi](https://github.com/Physical-Intelligence/openpi) - π0 policy implementation
- [solo-cli](https://github.com/GetSoloTech/solo-cli) - Robot teleoperation tools

### Datasets
- [ridxm/latte-pour-demos](https://huggingface.co/datasets/ridxm/latte-pour-demos) - Our latte art dataset (40 episodes)
- [G1 Pouring Dataset](https://huggingface.co/datasets/unitreerobotics/G1_Pouring_Dataset) - Reference pouring dataset
