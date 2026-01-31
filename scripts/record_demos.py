#!/usr/bin/env python3
"""
Heart Latte Art Demo Recording Script
Records teleoperated demonstrations for training π0

Usage:
    python scripts/record_demos.py --num-episodes 50
"""

import argparse
import subprocess
import sys
from pathlib import Path
from datetime import datetime


def check_solo_cli():
    """Verify solo-cli is installed and configured."""
    try:
        result = subprocess.run(
            ["solo", "status"],
            capture_output=True,
            text=True,
            timeout=10
        )
        if "Configuration file not found" in result.stdout:
            print("❌ Solo CLI not configured. Run 'solo setup' first.")
            return False
        print("✅ Solo CLI ready")
        return True
    except FileNotFoundError:
        print("❌ Solo CLI not installed. Run 'pip install solo-cli'")
        return False
    except subprocess.TimeoutExpired:
        print("❌ Solo CLI timeout - check robot connection")
        return False


def calibrate_robot():
    """Run robot calibration."""
    print("\n🔧 Starting calibration...")
    print("Move each joint through its full range of motion when prompted.\n")

    subprocess.run(["solo", "robo", "--calibrate", "all"])


def record_episode(episode_num: int, dataset_name: str):
    """Record a single demonstration episode."""
    print(f"\n☕ Episode {episode_num}")
    print("=" * 40)
    print("Instructions:")
    print("  1. Place espresso cup in position")
    print("  2. Fill creamer pitcher")
    print("  3. Press ENTER to start recording")
    print("  4. Teleop: Pour HEART pattern (~15-20 sec)")
    print("  5. Recording auto-stops on completion")
    print("=" * 40)

    input("\n>>> Press ENTER when ready to record...")

    # Start recording
    result = subprocess.run([
        "solo", "robo", "--record",
        "--dataset-name", dataset_name,
        "--episode", str(episode_num)
    ])

    # Get feedback
    print("\nHow was that pour?")
    print("  [g] Good - clear heart shape")
    print("  [o] Okay - recognizable heart")
    print("  [b] Bad - spill or no pattern (will be excluded)")

    while True:
        quality = input("Quality [g/o/b]: ").lower().strip()
        if quality in ['g', 'o', 'b']:
            break
        print("Please enter g, o, or b")

    return quality


def main():
    parser = argparse.ArgumentParser(description="Record heart latte art demos")
    parser.add_argument("--num-episodes", type=int, default=50,
                        help="Target number of episodes to record")
    parser.add_argument("--dataset-name", type=str, default="latte-heart-demos",
                        help="Name for the dataset")
    parser.add_argument("--skip-calibration", action="store_true",
                        help="Skip robot calibration")
    args = parser.parse_args()

    print("=" * 50)
    print("🎨 HEART LATTE ART DEMO RECORDER")
    print("=" * 50)
    print(f"Target episodes: {args.num_episodes}")
    print(f"Dataset name: {args.dataset_name}")
    print()

    # Check prerequisites
    if not check_solo_cli():
        sys.exit(1)

    # Calibration
    if not args.skip_calibration:
        calibrate = input("\nRun robot calibration? [y/N]: ").lower().strip()
        if calibrate == 'y':
            calibrate_robot()

    # Recording session
    print("\n" + "=" * 50)
    print("📹 RECORDING SESSION")
    print("=" * 50)
    print("\nMaterials checklist:")
    print("  [ ] Espresso cups (10+)")
    print("  [ ] Frothed milk/creamer")
    print("  [ ] Creamer pitcher with spout")
    print("  [ ] Paper towels")
    print("  [ ] Consistent lighting")

    input("\n>>> Press ENTER when materials are ready...")

    # Track results
    results = {"good": 0, "okay": 0, "bad": 0}
    episode = 1

    while results["good"] + results["okay"] < args.num_episodes:
        quality = record_episode(episode, args.dataset_name)

        if quality == 'g':
            results["good"] += 1
            print("✅ Good demo recorded!")
        elif quality == 'o':
            results["okay"] += 1
            print("👍 Okay demo recorded!")
        else:
            results["bad"] += 1
            print("❌ Bad demo - will be excluded")

        usable = results["good"] + results["okay"]
        print(f"\nProgress: {usable}/{args.num_episodes} usable demos")
        print(f"  Good: {results['good']}, Okay: {results['okay']}, Bad: {results['bad']}")

        if usable < args.num_episodes:
            cont = input("\nContinue recording? [Y/n]: ").lower().strip()
            if cont == 'n':
                break

        episode += 1

    # Summary
    print("\n" + "=" * 50)
    print("📊 RECORDING COMPLETE")
    print("=" * 50)
    print(f"Total recorded: {episode - 1}")
    print(f"Usable demos: {results['good'] + results['okay']}")
    print(f"  - Good: {results['good']}")
    print(f"  - Okay: {results['okay']}")
    print(f"Excluded: {results['bad']}")

    # Next steps
    print("\n📋 NEXT STEPS:")
    print(f"1. Review demos: solo robo --visualize --dataset {args.dataset_name}")
    print(f"2. Upload to Hub:")
    print(f"   huggingface-cli login")
    print(f"   python -m lerobot.scripts.push_dataset_to_hub \\")
    print(f"       --local-dir data/{args.dataset_name} \\")
    print(f"       --repo-id YOUR_USERNAME/{args.dataset_name}")


if __name__ == "__main__":
    main()
