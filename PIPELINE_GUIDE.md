# Latte Art Robot - Data Collection Pipeline

## Your Setup
- **Robot**: Dual-arm (12 DOF - 6 per arm)
- **Cameras**: 3 RGB only
  - Top/overhead camera (`/camera_0/color/image_raw`)
  - Left wrist camera (`/camera_3/color/image_raw`)
  - Right wrist camera (`/camera_4/color/image_raw`)
- **No lift, no base, no head**
- **No initial pose** - manually position arms

## Configuration

### Image Quality (DataCollectionConstants.py)
```python
IMAGE_HEIGHT = 480  # Good for latte art (7x better than 180)
IMAGE_WIDTH = 640
RATE = 10          # Collection frequency (Hz)
```

**For latte art pouring**, 480x640 provides good visual detail for:
- Cup rim positioning
- Pitcher spout control
- Coffee surface detection
- Milk flow patterns

## Complete Workflow

### STEP 1: Data Collection

```bash
cd teleop
python3 collect_data.py
```

**Interactive Commands:**
- `s` - Start new episode
- `y` - Save episode
- `n` - Discard episode (retry!)
- `q` - Quit

**Example Session:**
```
Type 's' to start collecting first episode...

>>> s

============================================================
📹 EPISODE 0 - RECORDING
============================================================
Opening grippers...
✓ Ready! Move the robot arms by hand...
Type 'y' to SAVE or 'n' to DISCARD when done

  📊 Step 10 | L: [0.02 -2.17 -0.57] | R: [0.16 2.22 0.58]
  📊 Step 20 | L: [0.03 -2.15 -0.55] | R: [0.17 2.20 0.56]

>>> y    [Good demo - save it!]

💾 Saving episode 0...
Saved top_camera RGB video to Data/videos/chunk_000/observation.images.top_camera/episode_000.mp4
Saved left_wrist RGB video to Data/videos/chunk_000/observation.images.left_wrist/episode_000.mp4
Saved right_wrist RGB video to Data/videos/chunk_000/observation.images.right_wrist/episode_000.mp4
✓ Episode 0 saved! (45 steps)

>>> s    [Start next episode]

>>> n    [Bad demo - discard!]

🗑 Episode discarded (45 steps)
```

**Data Saved:**
```
Data/
├── data/
│   └── chunk_000/
│       ├── episode_000.parquet  (observations, actions, timestamps)
│       ├── episode_001.parquet
│       └── ...
└── videos/
    └── chunk_000/
        ├── observation.images.top_camera/
        │   ├── episode_000.mp4
        │   └── ...
        ├── observation.images.left_wrist/
        │   ├── episode_000.mp4
        │   └── ...
        └── observation.images.right_wrist/
            ├── episode_000.mp4
            └── ...
```

### STEP 2: Generate LeRobot Metadata

After collecting 50-100 episodes:

```bash
python3 generate_meta.py
```

**Creates:**
```
Data/
├── episodes.jsonl   # Episode metadata
├── info.json        # Dataset info (3 cameras, FPS, dimensions)
├── stats.json       # Statistics for normalization
├── tasks.jsonl      # Task descriptions
├── data/            # Parquet files
└── videos/          # Video files
```

Your dataset is now **LeRobot-compatible**!

### STEP 3: (Optional) Upload to HuggingFace

```bash
python3 upload_to_hf.py
```

## Data Format (LeRobot-Compatible)

### Parquet Columns:
- `observation.state` - 12D joint positions [left_arm(6), right_arm(6)]
- `action` - 12D joint positions (same as observation for kinesthetic)
- `timestamp` - Frame-based timing (frame_index / fps)
- `episode_index` - Episode number
- `frame_index` - Frame within episode
- `index` - Global frame index
- `next.reward` - 0.0
- `next.done` - Episode termination flag
- `task_index` - Task ID

### Camera Data:
- **3 RGB videos** at 640x480 resolution
- **10 FPS** (configurable)
- **MP4 format** for efficient storage

## Tips for Latte Art Data Collection

1. **Lighting**: Keep consistent lighting conditions
2. **Camera views**: Ensure all 3 cameras can see the pour
3. **Variety**: Vary cup positions slightly between episodes
4. **Smooth motions**: Move smoothly during kinesthetic teaching
5. **Episode count**: Aim for 50-100 good demonstrations
6. **Quality over quantity**: Use 'n' to discard bad demos

## File Structure

```
teleop/
├── collect_data.py             # Main collection script (UPDATED)
├── Hardware_Bridge.py          # Hardware control (UPDATED - no lift, 3 cams)
├── DataRecoder.py              # Save data (UPDATED - 3 cams only)
├── DataCollectionConstants.py # Configuration (UPDATED)
│
├── camera_utils.py             # Camera reader (UPDATED - 3 cams)
├── gripper.py                  # Gripper control
│
├── generate_meta.py            # Metadata generation
├── MetaRecorder.py             # Metadata logic
└── upload_to_hf.py             # HuggingFace upload
```

## Quick Reference

| File | Purpose |
|------|---------|
| `collect_data.py` | Interactive data collection |
| `Hardware_Bridge.py` | Robot arms + grippers + 3 cameras |
| `DataRecoder.py` | Save parquet + 3 videos |
| `DataCollectionConstants.py` | Configuration (resolution, FPS) |
| `generate_meta.py` | Create LeRobot metadata |

## What We Removed

- ❌ Base/head control
- ❌ Lift mechanism
- ❌ Initial pose movement (arms stay where you put them)
- ❌ Extra cameras (front, USB)
- ❌ Depth cameras
- ❌ Ctrl+C requirement (now uses 's', 'y', 'n' commands)

## What We Kept

- ✅ Dual arms (12 DOF)
- ✅ Grippers (pneumatic)
- ✅ 3 RGB cameras (top, left wrist, right wrist)
- ✅ LeRobot format compatibility
- ✅ Save/discard episodes
- ✅ Kinesthetic teaching

---

Ready to collect data! 🎨☕
