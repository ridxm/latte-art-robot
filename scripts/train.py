#!/usr/bin/env python3
"""
Training script for pi0 policy on latte pouring dataset.
Optimized for low-data regime (20 episodes) with augmentation.

Key optimizations:
- Image augmentation: color jitter, random crops, brightness
- Gradient accumulation for effective larger batch
- Cosine learning rate schedule with warmup
- Proper normalization enabled

Usage:
    python train.py                                    # Use defaults
    python train.py --dataset_repo_id=user/dataset    # Custom dataset
    python train.py --steps=20000                      # More training steps
"""

import argparse
import os
import subprocess
import sys
from pathlib import Path

# Default training parameters optimized for:
# - H100 80GB VRAM
# - 20 episodes (~8000 frames at 20Hz) - LOW DATA REGIME
# - 14D state/action (dual arm + grippers)
# - 3 cameras (480x640)

DEFAULTS = {
    # Dataset
    "dataset_repo_id": "dwux/realman_pour1",

    # Policy configuration
    "policy_type": "pi0",
    "pretrained_path": "lerobot/pi0_base",

    # Training hyperparameters - optimized for 20 episodes
    "batch_size": 16,  # Smaller batch, use grad accumulation
    "grad_accumulation_steps": 4,  # Effective batch = 64
    "steps": 20000,  # More steps for low data
    "lr": 1e-5,  # Lower LR for finetuning
    "warmup_steps": 500,  # Warmup for stability

    # Pi0 specific
    "chunk_size": 10,  # 10 actions = 1s lookahead at 10Hz

    # Regularization for low data
    "weight_decay": 0.01,
    "dropout": 0.1,

    # Logging
    "save_freq": 2500,
    "eval_freq": 1000,
    "log_freq": 50,

    # Output
    "output_dir": "./outputs/pi0_latte",
}

# Image augmentation config for low-data regime
AUGMENTATION_CONFIG = """
# Image augmentation (critical for 20 episodes)
training.image_augmentation.enable=true
training.image_augmentation.color_jitter.enable=true
training.image_augmentation.color_jitter.brightness=0.3
training.image_augmentation.color_jitter.contrast=0.3
training.image_augmentation.color_jitter.saturation=0.3
training.image_augmentation.color_jitter.hue=0.1
training.image_augmentation.random_crop.enable=true
training.image_augmentation.random_crop.scale_min=0.9
training.image_augmentation.random_crop.scale_max=1.0
"""


def build_training_command(args):
    """Build the lerobot train command with all parameters"""

    cmd = [
        "python", "-m", "lerobot.scripts.train",
        # Dataset
        f"--dataset.repo_id={args.dataset_repo_id}",

        # Policy
        f"--policy.type={args.policy_type}",
        f"--policy.chunk_size={args.chunk_size}",

        # Training
        f"--training.batch_size={args.batch_size}",
        f"--training.grad_accumulation_steps={args.grad_accumulation_steps}",
        f"--training.lr={args.lr}",
        f"--training.steps={args.steps}",
        f"--training.warmup_steps={args.warmup_steps}",
        f"--training.weight_decay={args.weight_decay}",
        "--training.lr_scheduler=cosine",

        # Optimization
        "--training.use_amp=true",  # Mixed precision
        "--training.num_workers=4",
        "--device=cuda",

        # Checkpoints
        f"--training.save_freq={args.save_freq}",
        f"--training.eval_freq={args.eval_freq}",
        f"--training.log_freq={args.log_freq}",

        # Output
        f"--output_dir={args.output_dir}",

        # Image augmentation for low-data regime
        "--training.image_augmentation.enable=true",
        "--training.image_augmentation.color_jitter.enable=true",
        "--training.image_augmentation.color_jitter.brightness=0.3",
        "--training.image_augmentation.color_jitter.contrast=0.3",
        "--training.image_augmentation.color_jitter.saturation=0.3",
        "--training.image_augmentation.color_jitter.hue=0.1",
    ]

    # Add pretrained path if specified
    if args.pretrained_path:
        cmd.append(f"--policy.pretrained_path={args.pretrained_path}")

    # Add wandb if configured
    if os.environ.get("WANDB_API_KEY"):
        wandb_project = os.environ.get("WANDB_PROJECT", "latte-pouring")
        cmd.extend([
            "--wandb.enable=true",
            f"--wandb.project={wandb_project}",
            f"--wandb.name={args.run_name}",
        ])

    return cmd


def print_training_info(args):
    """Print training configuration summary"""
    effective_batch = args.batch_size * args.grad_accumulation_steps

    print("=" * 60)
    print("Pi0 Training for Latte Pouring Robot")
    print("=" * 60)
    print(f"\n{'Dataset:':<25} {args.dataset_repo_id}")
    print(f"{'Policy:':<25} {args.policy_type}")
    print(f"{'Pretrained:':<25} {args.pretrained_path}")
    print()
    print("Training Configuration:")
    print(f"  {'Batch size:':<23} {args.batch_size} x {args.grad_accumulation_steps} = {effective_batch} effective")
    print(f"  {'Steps:':<23} {args.steps:,}")
    print(f"  {'Learning rate:':<23} {args.lr}")
    print(f"  {'Warmup steps:':<23} {args.warmup_steps}")
    print(f"  {'Weight decay:':<23} {args.weight_decay}")
    print(f"  {'Chunk size:':<23} {args.chunk_size}")
    print()
    print("Data Augmentation: ENABLED")
    print("  - Color jitter (brightness, contrast, saturation, hue)")
    print("  - Random crops")
    print()
    print(f"{'Output:':<25} {args.output_dir}")
    print("=" * 60)


def main():
    parser = argparse.ArgumentParser(
        description="Train pi0 policy for latte pouring (optimized for 20 episodes)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
    # Train with defaults (optimized for 20 episodes)
    python train.py

    # Train with custom dataset
    python train.py --dataset_repo_id=username/my-dataset

    # Train longer
    python train.py --steps=30000

    # Resume from checkpoint
    python train.py --resume=./outputs/pi0_latte/checkpoint_10000
        """
    )

    # Dataset
    parser.add_argument("--dataset_repo_id", default=DEFAULTS["dataset_repo_id"],
                        help="HuggingFace dataset repository ID")

    # Policy
    parser.add_argument("--policy_type", default=DEFAULTS["policy_type"],
                        help="Policy type (pi0)")
    parser.add_argument("--pretrained_path", default=DEFAULTS["pretrained_path"],
                        help="Pretrained model path")
    parser.add_argument("--chunk_size", type=int, default=DEFAULTS["chunk_size"],
                        help="Action chunk size for pi0")

    # Training
    parser.add_argument("--batch_size", type=int, default=DEFAULTS["batch_size"],
                        help="Training batch size")
    parser.add_argument("--grad_accumulation_steps", type=int,
                        default=DEFAULTS["grad_accumulation_steps"],
                        help="Gradient accumulation steps")
    parser.add_argument("--steps", type=int, default=DEFAULTS["steps"],
                        help="Number of training steps")
    parser.add_argument("--lr", type=float, default=DEFAULTS["lr"],
                        help="Learning rate")
    parser.add_argument("--warmup_steps", type=int, default=DEFAULTS["warmup_steps"],
                        help="Learning rate warmup steps")
    parser.add_argument("--weight_decay", type=float, default=DEFAULTS["weight_decay"],
                        help="Weight decay for regularization")

    # Logging
    parser.add_argument("--save_freq", type=int, default=DEFAULTS["save_freq"],
                        help="Checkpoint save frequency")
    parser.add_argument("--eval_freq", type=int, default=DEFAULTS["eval_freq"],
                        help="Evaluation frequency")
    parser.add_argument("--log_freq", type=int, default=DEFAULTS["log_freq"],
                        help="Logging frequency")

    # Output
    parser.add_argument("--output_dir", default=DEFAULTS["output_dir"],
                        help="Output directory for checkpoints")
    parser.add_argument("--run_name", default="pi0_latte_pour",
                        help="Run name for wandb")

    # Resume
    parser.add_argument("--resume", default=None,
                        help="Path to checkpoint to resume from")

    args = parser.parse_args()

    # Print config
    print_training_info(args)

    # Build command
    cmd = build_training_command(args)

    # Add resume if specified
    if args.resume:
        cmd.append(f"--resume={args.resume}")

    print(f"\nCommand:\n{' '.join(cmd[:10])}...")
    print("  (truncated, full command has augmentation flags)")
    print("\n" + "=" * 60 + "\n")

    # Create output directory
    Path(args.output_dir).mkdir(parents=True, exist_ok=True)

    # Run training
    result = subprocess.run(cmd)

    if result.returncode == 0:
        print("\n" + "=" * 60)
        print("Training completed successfully!")
        print(f"Checkpoints saved to: {args.output_dir}")
        print("=" * 60)
    else:
        print(f"\nTraining failed with exit code {result.returncode}")

    sys.exit(result.returncode)


if __name__ == "__main__":
    main()
