#!/usr/bin/env python3
"""
Heart Latte Art Training Script (for Cloud/H100)
Fine-tunes π0 on your demonstration data

Usage (on cloud instance):
    python scripts/train_cloud.py --dataset your-username/latte-heart-demos
"""

import argparse
import os
import subprocess
import sys
from pathlib import Path


def setup_environment():
    """Set up training environment."""
    print("🔧 Setting up environment...")

    # Check if OpenPi is cloned
    if not Path("openpi").exists():
        print("📥 Cloning OpenPi...")
        subprocess.run([
            "git", "clone", "--recurse-submodules",
            "https://github.com/Physical-Intelligence/openpi.git"
        ], check=True)

    # Install dependencies
    os.chdir("openpi")
    print("📦 Installing dependencies...")
    subprocess.run([
        "pip", "install", "-e", "."
    ], check=True)
    os.chdir("..")

    print("✅ Environment ready")


def download_dataset(repo_id: str):
    """Download dataset from HuggingFace Hub."""
    print(f"📥 Downloading dataset: {repo_id}")

    subprocess.run([
        "huggingface-cli", "download",
        repo_id,
        "--local-dir", f"data/{repo_id.split('/')[-1]}"
    ], check=True)

    print("✅ Dataset downloaded")


def create_training_config(dataset_name: str, output_dir: str):
    """Create training configuration for OpenPi."""
    config = f"""
# Auto-generated config for heart latte training
defaults:
  - pi0_base

# Dataset
data:
  dataset_repo_id: {dataset_name}

# Training
training:
  batch_size: 32
  learning_rate: 1e-4
  num_train_steps: 15000
  save_interval: 2500
  eval_interval: 1000
  log_interval: 100
  warmup_steps: 500
  gradient_clip_norm: 1.0

# Output
output_dir: {output_dir}
exp_name: heart-latte-v1

# Logging
use_wandb: true
wandb_project: latte-art-robot
"""

    config_path = Path("configs/training/heart_latte.yaml")
    config_path.parent.mkdir(parents=True, exist_ok=True)
    config_path.write_text(config)

    print(f"✅ Config written to {config_path}")
    return config_path


def run_training(config_path: str):
    """Launch training."""
    print("\n" + "=" * 50)
    print("🚀 STARTING TRAINING")
    print("=" * 50)
    print("This will take ~1-2 hours on H100")
    print("Monitor with: wandb or tensorboard\n")

    env = os.environ.copy()
    env["XLA_PYTHON_CLIENT_MEM_FRACTION"] = "0.9"

    subprocess.run([
        "python", "openpi/scripts/train.py",
        f"--config={config_path}"
    ], env=env, check=True)


def main():
    parser = argparse.ArgumentParser(description="Train heart latte π0 model")
    parser.add_argument("--dataset", type=str, required=True,
                        help="HuggingFace dataset repo (e.g., username/latte-heart-demos)")
    parser.add_argument("--output-dir", type=str, default="checkpoints",
                        help="Output directory for checkpoints")
    parser.add_argument("--skip-setup", action="store_true",
                        help="Skip environment setup")
    parser.add_argument("--skip-download", action="store_true",
                        help="Skip dataset download")
    args = parser.parse_args()

    print("=" * 50)
    print("🎨 HEART LATTE π0 TRAINING")
    print("=" * 50)
    print(f"Dataset: {args.dataset}")
    print(f"Output: {args.output_dir}")
    print()

    # Setup
    if not args.skip_setup:
        setup_environment()

    # Download data
    if not args.skip_download:
        download_dataset(args.dataset)

    # Create config
    config_path = create_training_config(args.dataset, args.output_dir)

    # Train
    run_training(str(config_path))

    # Done
    print("\n" + "=" * 50)
    print("✅ TRAINING COMPLETE")
    print("=" * 50)
    print(f"\nCheckpoint saved to: {args.output_dir}/heart-latte-v1/")
    print("\nNext steps:")
    print("1. Download checkpoint to robot")
    print("2. Run: python scripts/deploy.py --checkpoint checkpoints/heart-latte-v1/final")


if __name__ == "__main__":
    main()
