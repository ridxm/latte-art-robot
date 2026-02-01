# Heart Latte Art Robot 🎨☕

Pour beautiful heart patterns in latte art using OpenDroid R2D3 + π0 VLA.

## Quick Start (12-Hour Hackathon)

### Phase 1: Setup (2 hours)

```bash
# 1. Install dependencies (robot + laptop)
pip install lerobot torch

# 2. SSH into the robot
ssh r2d3@172.20.10.5  # password 1234

# 3. Launch Realman arm drivers (Terminal A)
cd ~/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch rm_driver dual_rm_65_driver.launch.py

# 4. Launch cameras (Terminal B)
cd ~/ros2_ws/src/teleop
source /opt/ros/humble/setup.bash
source ../../install/setup.bash
python3 launch_drivers.py
```

### Phase 2: Record Demos (3 hours)

```bash
# Teleop + data recorder (Terminal C)
cd ~/ros2_ws/src/teleop
source /opt/ros/humble/setup.bash
source ../../install/setup.bash
python3 collect_data_ros2.py

# Controls inside collect_data_ros2.py
#   s = start episode (leader arm or backpack drives follower arm)
#   y = save, n = discard, r = retry, q = quit
# Gripper keys 1–9 set 10–90% if you need overrides

# Target 30–50 clean heart pours (≈1.5 min/episode)

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
