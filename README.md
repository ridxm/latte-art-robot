# Heart Latte Art Robot 🎨☕

Pour beautiful heart patterns in latte art using OpenDroid R2D3 + π0 VLA.

## Quick Start (12-Hour Hackathon)

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
2. **Multi-View Recording**: Three cameras (overhead, left wrist, right wrist) capture the scene at 10Hz, giving the model visual context from multiple angles
3. **Synchronized Data**: The system records joint positions (12D state for both arms), camera frames, and actions simultaneously in LeRobot format
4. **Quality Over Quantity**: We collected 50+ demonstrations, keeping even "okay" attempts to show variation, but removing spills and major errors

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

- [ ] 15+ espresso cups
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
- Fine-tuned on ~50 demonstrations

## Links

- [LeRobot](https://github.com/huggingface/lerobot)
- [OpenPi](https://github.com/Physical-Intelligence/openpi)
- [solo-cli](https://github.com/GetSoloTech/solo-cli)
- [G1 Pouring Dataset](https://huggingface.co/datasets/unitreerobotics/G1_Pouring_Dataset)
