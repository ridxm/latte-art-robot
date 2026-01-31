# Heart Latte Art Robot 🎨☕

Pour beautiful heart patterns in latte art using OpenDroid R1D2 + π0 VLA.

## Quick Start (12-Hour Hackathon)

### Phase 1: Setup (2 hours)

```bash
# 1. Install dependencies
pip install solo-cli lerobot torch

# 2. Connect to robot
ssh r1d2@<robot-ip>

# 3. Calibrate
solo robo --calibrate all

# 4. Test teleop
solo robo --teleop
```

### Phase 2: Record Demos (3 hours)

```bash
# Record 50 heart latte art demonstrations
python scripts/record_demos.py --num-episodes 50

# Upload to HuggingFace
huggingface-cli login
python -m lerobot.scripts.push_dataset_to_hub \
    --local-dir data/latte-heart-demos \
    --repo-id YOUR_USERNAME/latte-heart-demos
```

### Phase 3: Train on Cloud (4 hours)

```bash
# On H100 cloud instance
python scripts/train_cloud.py --dataset YOUR_USERNAME/latte-heart-demos

# Training takes ~1-2 hours, monitoring available via wandb
```

### Phase 4: Deploy (3 hours)

```bash
# Download checkpoint from cloud
# Then run on robot:
python scripts/deploy.py --checkpoint checkpoints/heart-latte-v1/final
```

## Project Structure

```
Latte-Pouring-Art/
├── configs/
│   ├── robot/r1d2.yaml       # Robot configuration
│   └── policy/pi0_latte.yaml # Training config
├── scripts/
│   ├── record_demos.py       # Demo recording
│   ├── train_cloud.py        # Cloud training
│   └── deploy.py             # Inference
├── data/                     # Local datasets
└── checkpoints/              # Trained models
```

## Hardware Requirements

- **Robot**: OpenDroid R1D2 (6 DOF)
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
# Calibrate robot
solo robo --calibrate all

# Start teleop
solo robo --teleop

# Record demos
solo robo --record --dataset-name latte-heart-demos

# Check status
solo status
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
