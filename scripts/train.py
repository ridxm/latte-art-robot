#!/usr/bin/env python3
"""
Heart Latte Art Training Script
Fine-tunes π0 on demonstration data using LeRobot

Usage:
    python scripts/train.py --dataset.repo_id=username/latte-heart-demos

    # With custom settings
    python scripts/train.py \
        --dataset.repo_id=username/latte-heart-demos \
        --steps=10000 \
        --batch_size=32 \
        --wandb.enable=true
"""

import subprocess
import sys
from pathlib import Path


def main():
    # Build the lerobot-train command with our defaults
    cmd = [
        "lerobot-train",
        # Policy: π0 base model
        "--policy.path=lerobot/pi0_base",
        # Policy overrides for our robot (12D dual arms, 10Hz data)
        "--policy.chunk_size=10",  # 10 actions at 10Hz = 1 second lookahead
        "--policy.n_action_steps=10",
        "--policy.dtype=bfloat16",  # H100 bf16 optimization
        # Training defaults (can be overridden via CLI)
        "--batch_size=32",
        "--steps=15000",
        "--save_freq=2500",
        "--eval_freq=5000",
        "--log_freq=100",
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
