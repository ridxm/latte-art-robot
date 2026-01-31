#!/usr/bin/env python3
"""
Convert raw Realman recordings to LeRobot v2 format.

Usage:
    python scripts/convert_to_lerobot.py --input-dir data/raw --output-dir data/lerobot
"""

import argparse
import json
import shutil
import subprocess
from pathlib import Path
from typing import List, Dict, Any
import numpy as np

try:
    import pyarrow as pa
    import pyarrow.parquet as pq
except ImportError:
    print("Install pyarrow: pip install pyarrow")
    raise


def load_raw_episode(episode_dir: Path) -> Dict[str, Any]:
    """Load raw episode data."""
    metadata_path = episode_dir / "metadata.json"
    frames_path = episode_dir / "frames.json"

    with open(metadata_path) as f:
        metadata = json.load(f)

    with open(frames_path) as f:
        frames = json.load(f)

    return {
        "metadata": metadata,
        "frames": frames,
        "episode_dir": episode_dir
    }


def frames_to_video(
    image_dir: Path,
    output_path: Path,
    fps: int = 30
) -> bool:
    """Convert frame images to MP4 video."""
    if not image_dir.exists():
        return False

    # Find all frames
    frames = sorted(image_dir.glob("frame_*.jpg"))
    if not frames:
        return False

    output_path.parent.mkdir(parents=True, exist_ok=True)

    # Use ffmpeg to create video
    try:
        cmd = [
            "ffmpeg", "-y",
            "-framerate", str(fps),
            "-pattern_type", "glob",
            "-i", str(image_dir / "frame_*.jpg"),
            "-c:v", "libx264",
            "-pix_fmt", "yuv420p",
            "-crf", "23",
            str(output_path)
        ]
        subprocess.run(cmd, capture_output=True, check=True)
        return True
    except subprocess.CalledProcessError as e:
        print(f"⚠️  ffmpeg error: {e}")
        return False
    except FileNotFoundError:
        print("⚠️  ffmpeg not found, skipping video creation")
        return False


def convert_episode_to_parquet(
    frames: List[Dict],
    output_path: Path,
    episode_index: int
) -> None:
    """Convert episode frames to parquet format."""
    # Build columns
    timestamps = []
    states = []
    actions = []
    episode_indices = []
    frame_indices = []

    start_time = frames[0]["timestamp"] if frames else 0

    for i, frame in enumerate(frames):
        timestamps.append(frame["timestamp"] - start_time)

        # State: joint positions + gripper
        state = frame["joint_positions"] + [frame["gripper_position"]]
        states.append(state)

        # Action: target joint positions + gripper
        action = frame["action"] + [frame["gripper_position"]]
        actions.append(action)

        episode_indices.append(episode_index)
        frame_indices.append(i)

    # Create table
    table = pa.table({
        "timestamp": pa.array(timestamps, type=pa.float64()),
        "observation.state": [pa.array(s, type=pa.float32()) for s in states],
        "action": [pa.array(a, type=pa.float32()) for a in actions],
        "episode_index": pa.array(episode_indices, type=pa.int64()),
        "frame_index": pa.array(frame_indices, type=pa.int64()),
        "task_index": pa.array([0] * len(frames), type=pa.int64()),
    })

    output_path.parent.mkdir(parents=True, exist_ok=True)
    pq.write_table(table, output_path)


def create_info_json(
    output_dir: Path,
    num_episodes: int,
    total_frames: int,
    fps: int,
    state_dim: int = 7,  # 6 joints + gripper
    action_dim: int = 7
) -> None:
    """Create info.json metadata file."""
    info = {
        "codebase_version": "v2.1",
        "robot_type": "realman_rm65",
        "fps": fps,
        "features": {
            "observation.state": {
                "dtype": "float32",
                "shape": [state_dim],
                "names": [
                    "joint_0", "joint_1", "joint_2",
                    "joint_3", "joint_4", "joint_5", "gripper"
                ]
            },
            "observation.images.wrist": {
                "dtype": "video",
                "shape": [480, 640, 3],
                "names": ["height", "width", "channels"],
                "video_info": {
                    "video.fps": fps,
                    "video.codec": "libx264",
                    "video.pix_fmt": "yuv420p"
                }
            },
            "observation.images.overhead": {
                "dtype": "video",
                "shape": [480, 640, 3],
                "names": ["height", "width", "channels"],
                "video_info": {
                    "video.fps": fps,
                    "video.codec": "libx264",
                    "video.pix_fmt": "yuv420p"
                }
            },
            "action": {
                "dtype": "float32",
                "shape": [action_dim],
                "names": [
                    "joint_0", "joint_1", "joint_2",
                    "joint_3", "joint_4", "joint_5", "gripper"
                ]
            }
        },
        "total_episodes": num_episodes,
        "total_frames": total_frames,
        "splits": {"train": f"0:{num_episodes}"}
    }

    with open(output_dir / "meta" / "info.json", "w") as f:
        json.dump(info, f, indent=2)


def create_episodes_jsonl(
    output_dir: Path,
    episodes_info: List[Dict]
) -> None:
    """Create episodes.jsonl file."""
    with open(output_dir / "meta" / "episodes.jsonl", "w") as f:
        for ep in episodes_info:
            f.write(json.dumps(ep) + "\n")


def create_tasks_jsonl(output_dir: Path) -> None:
    """Create tasks.jsonl file."""
    task = {
        "task_index": 0,
        "task": "Pour heart pattern latte art"
    }
    with open(output_dir / "meta" / "tasks.jsonl", "w") as f:
        f.write(json.dumps(task) + "\n")


def convert_dataset(input_dir: Path, output_dir: Path, dataset_name: str) -> None:
    """Convert entire dataset from raw to LeRobot format."""
    print(f"📂 Input: {input_dir}")
    print(f"📂 Output: {output_dir}")

    # Find all episodes
    episode_dirs = sorted(input_dir.glob("episode_*"))
    if not episode_dirs:
        print("❌ No episodes found")
        return

    print(f"📊 Found {len(episode_dirs)} episodes")

    # Create output structure
    output_dir.mkdir(parents=True, exist_ok=True)
    (output_dir / "meta").mkdir(exist_ok=True)
    (output_dir / "data" / "chunk-000").mkdir(parents=True, exist_ok=True)
    (output_dir / "videos" / "chunk-000" / "observation.images.wrist").mkdir(parents=True, exist_ok=True)
    (output_dir / "videos" / "chunk-000" / "observation.images.overhead").mkdir(parents=True, exist_ok=True)

    episodes_info = []
    total_frames = 0

    for idx, episode_dir in enumerate(episode_dirs):
        print(f"\n🔄 Converting episode {idx}: {episode_dir.name}")

        # Load raw data
        data = load_raw_episode(episode_dir)
        frames = data["frames"]
        metadata = data["metadata"]
        fps = metadata.get("fps", 30)

        # Convert to parquet
        parquet_path = output_dir / "data" / "chunk-000" / f"episode_{idx:06d}.parquet"
        convert_episode_to_parquet(frames, parquet_path, idx)
        print(f"  ✅ Parquet: {parquet_path.name}")

        # Convert wrist video
        wrist_images = episode_dir / "wrist"
        wrist_video = output_dir / "videos" / "chunk-000" / "observation.images.wrist" / f"episode_{idx:06d}.mp4"
        if frames_to_video(wrist_images, wrist_video, fps):
            print(f"  ✅ Wrist video: {wrist_video.name}")

        # Convert overhead video
        overhead_images = episode_dir / "overhead"
        overhead_video = output_dir / "videos" / "chunk-000" / "observation.images.overhead" / f"episode_{idx:06d}.mp4"
        if frames_to_video(overhead_images, overhead_video, fps):
            print(f"  ✅ Overhead video: {overhead_video.name}")

        # Track episode info
        episodes_info.append({
            "episode_index": idx,
            "tasks": ["Pour heart pattern latte art"],
            "length": len(frames)
        })
        total_frames += len(frames)

    # Create metadata files
    print("\n📝 Creating metadata files...")
    create_info_json(output_dir, len(episodes_info), total_frames, fps)
    create_episodes_jsonl(output_dir, episodes_info)
    create_tasks_jsonl(output_dir)

    print(f"\n✅ Conversion complete!")
    print(f"   Episodes: {len(episodes_info)}")
    print(f"   Total frames: {total_frames}")
    print(f"   Output: {output_dir}")

    print("\n📋 Next steps:")
    print(f"   1. Validate: python -m lerobot.scripts.visualize_dataset --repo-id {output_dir}")
    print(f"   2. Upload to HuggingFace Hub:")
    print(f"      huggingface-cli login")
    print(f"      python -m lerobot.scripts.push_dataset_to_hub \\")
    print(f"          --local-dir {output_dir} \\")
    print(f"          --repo-id YOUR_USERNAME/{dataset_name}")


def main():
    parser = argparse.ArgumentParser(description="Convert raw data to LeRobot format")
    parser.add_argument("--input-dir", type=str, default="data/raw",
                        help="Input directory with raw episodes")
    parser.add_argument("--output-dir", type=str, default="data/lerobot",
                        help="Output directory for LeRobot dataset")
    parser.add_argument("--dataset-name", type=str, default="latte-heart-demos",
                        help="Dataset name for HuggingFace")
    args = parser.parse_args()

    print("=" * 50)
    print("🔄 RAW → LEROBOT CONVERTER")
    print("=" * 50)

    convert_dataset(
        Path(args.input_dir),
        Path(args.output_dir),
        args.dataset_name
    )


if __name__ == "__main__":
    main()
