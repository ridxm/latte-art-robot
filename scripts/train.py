#!/usr/bin/env python3
"""
Heart Latte Art Training Script
Fine-tunes π0 on demonstration data using LeRobot

Usage:
    python scripts/train.py

    # With custom settings
    python scripts/train.py --steps=10000 --batch_size=16
"""
import subprocess
import sys


def main():
    # Build the lerobot-train command based on official LeRobot docs
    # https://huggingface.co/docs/lerobot/en/pi0
    cmd = [
        "lerobot-train",
        # Dataset
        "--dataset.repo_id=ridxm/latte-pour-demos",
        # Policy type and pretrained model
        "--policy.type=pi0",
        "--policy.pretrained_path=lerobot/pi0_base",
        # Output model repo (set to hub repo or None)
        "--policy.repo_id=ridxm/latte-pi0",
        "--policy.push_to_hub=true",
        # Optimization settings for H100
        "--policy.dtype=bfloat16",
        "--policy.device=cuda",
        # Policy settings (20Hz data, so chunk=20 = 1 second lookahead)
        "--policy.chunk_size=20",
        "--policy.n_action_steps=20",
        # Training hyperparameters
        "--batch_size=32",
        "--steps=15000",
        "--save_freq=2500",
        "--eval_freq=5000",
        "--log_freq=100",
        # Output directory
        "--output_dir=./outputs/pi0_latte",
        # Wandb logging
        "--wandb.enable=true",
        "--wandb.project=latte-art-robot-v2",
        # Dataloader
        "--num_workers=4",
    ]

    # Pass through any additional CLI arguments
    cmd.extend(sys.argv[1:])

    print("=" * 60)
    print("HEART LATTE PI0 TRAINING")
    print("=" * 60)
    print(f"Command: {' '.join(cmd)}")
    print()

    # Run training
    result = subprocess.run(cmd)

    if result.returncode == 0:
        print("\n" + "=" * 60)
        print("TRAINING COMPLETE")
        print("=" * 60)
        print("\nNext steps:")
        print("1. Download checkpoint from outputs/pi0_latte/")
        print("2. Deploy: python scripts/deploy.py --checkpoint outputs/pi0_latte/checkpoints/last/")
    else:
        print("\nTraining failed")
        sys.exit(result.returncode)


if __name__ == "__main__":
    main()
