#!/usr/bin/env python3
"""
Heart Latte Art Training Script
Fine-tunes π0 on demonstration data using LeRobot

Usage:
    python scripts/train.py

    # With custom settings
    python scripts/train.py \
        --steps=10000 \
        --batch_size=32 \
        --wandb.enable=false
"""

import subprocess
import sys
from pathlib import Path


def main():
    # Camera mapping: dataset names -> PI0 expected names
    rename_map = {
        "observation.images.top_camera": "observation.images.base_0_rgb",
        "observation.images.left_wrist": "observation.images.left_wrist_0_rgb",
        "observation.images.right_wrist": "observation.images.right_wrist_0_rgb",
    }

    # Build the lerobot-train command with our defaults
    cmd = [
        "lerobot-train",
        # Dataset: Realman dual-arm demo data
        "--dataset.repo_id=dwux/test_data_realman",
        # Policy: π0 base model
        "--policy.path=lerobot/pi0_base",
        "--policy.repo_id=ridxm/latte-pi0",
        "--policy.push_to_hub=false",
        # Camera name mapping
        f"--rename_map={rename_map}".replace("'", '"'),
        # Policy overrides for our robot (dual arms, 10Hz data)
        "--policy.chunk_size=10",  # 10 actions at 10Hz = 1 second lookahead
        "--policy.n_action_steps=10",
        "--policy.dtype=bfloat16",  # H100 bf16 optimization
        # Training defaults (can be overridden via CLI)
        "--batch_size=32",
        "--steps=15000",
        "--save_freq=2500",
        "--eval_freq=5000",
        "--log_freq=100",
        # "--output_dir=./outputs",
        # Wandb logging
        # "--wandb.enable=true",
        # "--wandb.project=latte-art-robot",
        # Workers for dataloader
        "--num_workers=4",
    ]

    # Pass through all CLI arguments
    cmd.extend(sys.argv[1:])

    print("=" * 60)
    print("🎨 HEART LATTE π0 TRAINING")
    print("=" * 60)
    print(f"Command: {' '.join(cmd)}")
    print()

    # Run training
    result = subprocess.run(cmd)

    if result.returncode == 0:
        print("\n" + "=" * 60)
        print("✅ TRAINING COMPLETE")
        print("=" * 60)
        print("\nNext steps:")
        print("1. Download checkpoint from outputs/")
        print("2. Deploy: python scripts/deploy.py --checkpoint outputs/<run>/checkpoints/last/")
    else:
        print("\n❌ Training failed")
        sys.exit(result.returncode)


if __name__ == "__main__":
    main()
