# CLAUDE.md - Project Context & Decisions

## Project Overview
**Goal**: Robot that pours heart latte art using OpenDroid R2D3 + π0 VLA
**Timeline**: 12-hour hackathon

## Key Decisions

### Model Choice: π0 (Flow Matching VLA)
- **Why**: Flow matching produces smooth action trajectories for fluid pouring
- **Alternative considered**: ACT (backup script at `scripts/train_openpi.py`)
- **Pre-trained base**: `lerobot/pi0_base`
- **Inference**: 10Hz (matches data collection rate)

### Pattern: Heart Only
- Simplified scope for hackathon
- Single pattern = more consistent training data
- Can expand to rosetta/tulip later

### Data Strategy
- **Target**: 50 usable demonstrations
- **Record extra**: ~60-70 to account for failures
- **Quality > Quantity**: Keep "okay" attempts, remove spills

### Hardware Setup
| Component | Choice | Notes |
|-----------|--------|-------|
| Robot | OpenDroid R2D3 | Dual Realman RM65 arms (12 DOF total) |
| Teleop | Kinesthetic teaching | Direct arm manipulation via ROS2 |
| GPU | H100 (VESSL.ai) | 80GB VRAM, bf16 training |
| Cameras | 3x USB (top, left_wrist, right_wrist) | 10Hz, 640x480 |

### Framework Stack
- **LeRobot**: Dataset format, π0 policy, training pipeline
- **VESSL.ai**: Cloud GPU training (H100)
- **HuggingFace Hub**: Dataset & model hosting
- **ROS2 Humble**: Robot control on R2D3

## File Structure
```
Dockerfile                    - VESSL H100 training container
vessl.yaml                    - VESSL run configuration
configs/robot/r2d3.yaml       - Dual arm + 3 camera config
configs/policy/pi0_latte.yaml - LeRobot training config
scripts/train.py              - LeRobot training wrapper
scripts/train_openpi.py       - OpenPi training (backup/alternative)
scripts/deploy.py             - Inference on robot
```

## Training Setup (VESSL H100)

### Quick Start
```bash
# 1. Set secrets in VESSL UI: hf-token, wandb-api-key

# 2. Run training
vessl run create -f vessl.yaml

# Or run directly:
python scripts/train.py --dataset.repo_id=username/latte-heart-demos
```

### Training Config
| Parameter | Value | Notes |
|-----------|-------|-------|
| Batch size | 32 | H100 80GB handles this easily |
| Learning rate | 2.5e-5 | π0 default |
| Steps | 15,000 | ~1.5 hours on H100 |
| Chunk size | 10 | 10 actions at 10Hz = 1s lookahead |
| dtype | bfloat16 | H100 optimization |
| Checkpoints | Every 2,500 steps | |

### Key Dimensions
| Data | Shape | Notes |
|------|-------|-------|
| State | 12D | [l_arm(6), r_arm(6)] |
| Action | 12D | [l_arm(6), r_arm(6)] |
| Images | 3x (480, 640, 3) | top, left_wrist, right_wrist |
| Frequency | 10 Hz | Data collection rate |

## Git Commit Rules
- **No co-authored lines** - Never include "Co-Authored-By" or "Generated with Claude" in commits
- Keep commit messages short and descriptive

## Open Questions
- [x] R2D3 servo protocol → **Realman arms** (RM65/RM75 series)
- [ ] Exact camera mounting positions
- [ ] Creamer vessel specs (spout angle matters)

## Data Format Issue (CRITICAL)

**Problem**: OpenDroid R2D3 uses Realman arms which don't output LeRobot format natively.

**Solution**: Custom data capture + conversion pipeline:
1. Capture from Realman Python SDK (`Robotic_Arm` package)
2. Record camera frames separately
3. Convert to LeRobot v2 format (parquet + mp4 + metadata)

### Realman SDK
- Install: `pip install Robotic_Arm`
- GitHub: https://github.com/RealManRobot/RM_API2
- Docs: https://develop.realman-robotics.com/en/robot/apipython/getStarted/
- Supported: RM65, RM75, ECO65, GEN72 series

### LeRobot v2 Format Structure
```
dataset/
├── meta/
│   ├── info.json          # Dataset metadata
│   ├── episodes.jsonl     # Episode info
│   └── tasks.jsonl        # Task descriptions
├── data/
│   └── chunk-000/
│       └── episode_XXXXXX.parquet  # State + action per episode
└── videos/
    └── chunk-000/
        └── observation.images.wrist/
            └── episode_XXXXXX.mp4
```

## Session Log

### Session 1 (Initial Setup)
- Installed solo-cli and uv
- Researched datasets: G1_Pouring_Dataset, DROID, FluidLab
- Decided on π0 over ACT for flow matching benefits
- Created project structure and all scripts
- Simplified to heart pattern only for hackathon scope

### Session 2 (Data Pipeline)
- Discovered R2D3 uses Realman arms (RM65/RM75 series)
- Initially thought we needed custom converter
- Created `realman_recorder.py` and `convert_to_lerobot.py` (may not be needed)

### Session 3 (Robot SSH Access)
- SSH: `ssh r2d3@172.20.10.5` (pass: 1234)
- Working dir: `~/ros2_ws`
- **GOOD NEWS**: Robot already has LeRobot format data collection!
  - `src/teleop/collect_data.py` - kinesthetic teaching collector
  - `src/teleop/DataRecoder.py` - outputs LeRobot v3 format
  - `src/teleop/upload_to_hf.py` - uploads to HuggingFace
- Data collection settings:
  - Rate: 10 Hz
  - Cameras: top, left_wrist, right_wrist (480x640)
  - Observations: 12D [l_arm(6), r_arm(6)]
  - Output: `Data/` folder in LeRobot format
- **Issue found**: Original scripts used ROS1 (rospy), robot has ROS2 Humble
- **Solution**: Created ROS2 versions:
  - `Hardware_Bridge_ROS2.py` - ROS2 hardware interface
  - `collect_data_ros2.py` - ROS2 data collector
- Installed dependencies: pyarrow, pandas, imageio, mediapy

## Robot Commands (On Robot via SSH)

```bash
# SSH into robot
ssh r2d3@172.20.10.5
# password: 1234

cd ~/ros2_ws

# STEP 1: Launch arm drivers (in one terminal)
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch rm_driver dual_rm_65_driver.launch.py

# STEP 2: Start data collection (in another terminal)
source /opt/ros/humble/setup.bash
source install/setup.bash
cd src/teleop
python3 collect_data_ros2.py   # <-- USE ROS2 VERSION

# Commands during collection:
#   's' - Start new episode
#   'y' - Save current episode
#   'n' - Discard current episode
#   'q' - Quit

# STEP 3: Upload to HuggingFace (edit repo_id first!)
python3 upload_to_hf.py
```

## Files on Robot

| File | Purpose |
|------|---------|
| `Hardware_Bridge_ROS2.py` | ROS2 bridge for dual Realman arms |
| `collect_data_ros2.py` | ROS2 kinesthetic teaching collector |
| `DataRecoder.py` | LeRobot v3 format recorder |
| `upload_to_hf.py` | HuggingFace uploader |

### Session 4 (VESSL Training Setup)
- Fixed training pipeline to use LeRobot (was incorrectly using OpenPi)
- Created `Dockerfile` for VESSL H100 container
- Created `vessl.yaml` with resource specs and secrets
- Rewrote `scripts/train.py` as LeRobot wrapper
- Updated configs to match actual robot:
  - 12D state/action (dual arms)
  - 3 cameras (top, left_wrist, right_wrist)
  - 10Hz frequency (chunk_size=10)
  - bf16 dtype for H100
- Kept old OpenPi script as `scripts/train_openpi.py` backup
