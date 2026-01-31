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
| Robot | OpenDroid R1D2 | 6 DOF, SSH access |
| Teleop | LeRobot-compatible wearable | No custom drivers needed |
| GPU | H100 (cloud) | Fast training ~1-2 hours |
| Cameras | Wrist + overhead | 30fps, 640x480 |

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
