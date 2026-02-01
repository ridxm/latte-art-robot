# CLAUDE.md - Project Context & Decisions

## Project Overview
**Goal**: Robot that pours heart latte art using OpenDroid R1D2 + π0 VLA
**Timeline**: 12-hour hackathon

## Key Decisions

### Model Choice: π0 (Flow Matching VLA)
- **Why**: Smooth 50Hz actions critical for fluid pouring
- **Alternative considered**: ACT (backup if π0 has issues)
- **Pre-trained base**: `lerobot/pi0_base`

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
| Robot | OpenDroid R1D2 | Dual Realman RM65/RM75 arms |
| Teleop | Kinesthetic teaching | Direct manipulation |
| GPU | H100 (cloud) | Fast training ~1-2 hours |
| **Cameras** | **ZED 2i + 2x RealSense D435** | **See camera config below** |

#### Camera Configuration
- **Top/Overhead**: ZED 2i stereo camera → `/camera_0/zed_node/rgb/image_rect_color`
- **Left Wrist**: RealSense D435 (Serial: TBD) → `/camera_3/color/image_raw`
- **Right Wrist**: RealSense D435 (Serial: TBD) → `/camera_4/color/image_raw`
- Resolution: 640x480 @ 30fps
- Format: RGB8

### Framework Stack
- **solo-cli**: Robot control & data recording
- **LeRobot**: Dataset format & training pipelines
- **OpenPi**: π0 fine-tuning
- **HuggingFace Hub**: Dataset & model hosting

## File Structure
```
configs/robot/r1d2.yaml      - Robot servo/camera config
configs/policy/pi0_latte.yaml - Training hyperparameters
scripts/record_demos.py       - Interactive demo recorder
scripts/train_cloud.py        - Cloud training launcher
scripts/deploy.py             - Inference on robot
```

## Training Config
- Batch size: 32 (H100)
- Learning rate: 1e-4
- Steps: 15,000
- Checkpoint every: 2,500 steps

## Git Commit Rules
- **No co-authored lines** - Never include "Co-Authored-By" or "Generated with Claude" in commits
- Keep commit messages short and descriptive

## Open Questions
- [x] R1D2 servo protocol → **Realman arms** (RM65/RM75 series)
- [ ] Exact camera mounting positions
- [ ] Creamer vessel specs (spout angle matters)

## Data Format Issue (CRITICAL)

**Problem**: OpenDroid R1D2 uses Realman arms which don't output LeRobot format natively.

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
- Discovered R1D2 uses Realman arms (RM65/RM75 series)
- Problem: Realman doesn't output LeRobot format natively
- Solution: Custom capture + conversion pipeline
- Created `realman_recorder.py` - captures from Realman SDK + cameras
- Created `convert_to_lerobot.py` - converts raw → LeRobot v2 format
- New workflow: Record raw → Convert → Upload to Hub → Train

### Session 3 (SSH Access Confirmed)
- SSH working from local machine
- Data collection pipeline verified:
  -  - kinesthetic teaching
  - Outputs LeRobot v3 format to 
  - 10Hz, 480x640 cameras, 12D state

## Latte Art Data Collection Protocol

### Before Recording
1. Prepare espresso + frothed milk
2. Position cup in workspace
3. Ensure cameras have good view

### During Recording
```bash
cd ~/ros2_ws/src/daniel-teleop
python3 collect_data.py
```
- Press 's' to start episode
- Guide robot arms to pour heart pattern
- Press 'y' to save, 'n' to discard
- Target: 50 good episodes

### After Recording
```bash
# Edit repo_id in upload_to_hf.py first!
python3 upload_to_hf.py
```

### Session 3 (SSH Access Confirmed)
- SSH working from local machine
- Data collection pipeline verified
- Outputs LeRobot v3 format to Data/
- 10Hz, 480x640 cameras, 12D state

## Latte Art Data Collection Protocol

Before Recording:
1. Prepare espresso + frothed milk
2. Position cup in workspace
3. Ensure cameras have good view

Commands:
  cd ~/ros2_ws/src/teleop
  python3 collect_data_ros2.py
  s = start, y = save, n = discard, q = quit

Target: 50 good episodes

### Session 4 (Camera & Gripper Configuration Fixed)
**Camera Setup:**
- Detected hardware: 1x ZED 2i + 2x RealSense D435
- Camera mapping:
  * Top/overhead: ZED 2i → `/camera_0/zed_node/rgb/image_rect_color`
  * Left wrist: RealSense D435 → `/camera_3/color/image_raw`
  * Right wrist: RealSense D435 → `/camera_4/color/image_raw`
- Created `zed_camera_publisher.py` - simple OpenCV-based ZED publisher (no ZED SDK needed)
- Updated `launch_drivers.py` to launch mixed camera setup
- Updated `camera_utils.py` topic mappings for ZED + RealSense
- Created `test_camera_setup.py` to verify camera topics
- ZED used as V4L2 camera via OpenCV (faster setup than building zed_wrapper)

**Gripper Setup:**
- ✓ **GRIPPER POSITION FEEDBACK WORKING!**
- Integrated Realman Python API (`rm_get_gripper_state()`)
- **Reads actual gripper position** from hardware via `actpos` field
- Added socket-based gripper initialization in `Hardware_Bridge_ROS2.py`:
  * Sets tool voltage to 24V
  * Configures ModbusRTU mode
  * Initializes gripper registers
  * Opens grippers to starting position
- Gripper controls available (optional, for manual adjustment):
  * Numeric controls: 0-9 (0%-90%), 'o' (100%)
  * Individual arm control: 'l5' (left 50%), 'r8' (right 80%)
- **Primary mode**: Physically manipulate grippers during kinesthetic teaching
- Gripper position automatically read and recorded in 14D state vector

**Data Collection State:**
- 14D state: [l_arm(6), l_gripper(1), r_arm(6), r_gripper(1)]
- Gripper normalized to 0-1 range in recorded data
- Ready for kinesthetic teaching with proper gripper control

## Camera Testing & Launch Workflow

### 1. Launch Drivers (Terminal 1):
```bash
cd ~/ros2_ws/src/teleop
python3 launch_drivers.py
```

### 2. Test Camera Setup (Terminal 2):
```bash
cd ~/ros2_ws/src/teleop
python3 test_camera_setup.py  # Verify all 3 cameras publishing
```

### 3. View Camera Feeds (Optional):
```bash
python3 show_cameras.py          # GUI mode
python3 show_cameras.py --headless  # Console only
```

### 4. Collect Data:
```bash
python3 collect_data_ros2.py
```

