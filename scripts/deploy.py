#!/usr/bin/env python3
"""
Heart Latte Art Deployment Script
Runs trained π0 policy on the robot

Usage:
    python scripts/deploy.py --checkpoint checkpoints/pi0_latte/best
"""

import argparse
import time
from pathlib import Path


def load_policy(checkpoint_path: str):
    """Load trained π0 policy from checkpoint."""
    print(f"📦 Loading policy from {checkpoint_path}...")

    try:
        from lerobot.common.policies.pi0.modeling_pi0 import Pi0Policy
        from lerobot.common.policies.pi0.configuration_pi0 import Pi0Config

        config = Pi0Config.from_pretrained(checkpoint_path)
        policy = Pi0Policy.from_pretrained(checkpoint_path)
        policy.eval()

        print("✅ Policy loaded successfully")
        return policy
    except ImportError:
        print("⚠️  LeRobot not found, trying OpenPi...")

        # Fallback to OpenPi loading
        import sys
        sys.path.insert(0, "openpi")
        from openpi.policies import load_policy as openpi_load

        policy = openpi_load(checkpoint_path)
        print("✅ Policy loaded via OpenPi")
        return policy


def connect_robot(config_path: str):
    """Connect to R1D2 robot."""
    print(f"🤖 Connecting to robot...")

    try:
        # Try solo-cli first
        import subprocess
        result = subprocess.run(
            ["solo", "status"],
            capture_output=True,
            text=True,
            timeout=5
        )
        if "ready" in result.stdout.lower() or result.returncode == 0:
            print("✅ Robot connected via solo-cli")
            return "solo"
    except Exception as e:
        print(f"⚠️  solo-cli connection failed: {e}")

    # Fallback to direct LeRobot connection
    try:
        from lerobot.common.robot_devices.robots.factory import make_robot
        import yaml

        with open(config_path) as f:
            robot_config = yaml.safe_load(f)

        robot = make_robot(robot_config)
        robot.connect()
        print("✅ Robot connected via LeRobot")
        return robot
    except Exception as e:
        print(f"❌ Failed to connect: {e}")
        return None


def get_observation(robot):
    """Get current observation from robot."""
    if robot == "solo":
        import subprocess
        import json

        result = subprocess.run(
            ["solo", "robo", "--get-state", "--json"],
            capture_output=True,
            text=True
        )
        state = json.loads(result.stdout)
        return {
            "observation.images.wrist": state.get("wrist_image"),
            "observation.images.overhead": state.get("overhead_image"),
            "observation.state": state.get("joint_positions")
        }
    else:
        return robot.get_observation()


def send_action(robot, action):
    """Send action to robot."""
    if robot == "solo":
        import subprocess
        import json

        subprocess.run([
            "solo", "robo", "--set-joints",
            "--positions", json.dumps(action.tolist())
        ])
    else:
        robot.send_action(action)


def run_inference(policy, robot, max_steps: int = 500, fps: int = 50):
    """Run policy inference loop."""
    print("\n" + "=" * 50)
    print("☕ RUNNING HEART LATTE POUR")
    print("=" * 50)
    print(f"Max steps: {max_steps}")
    print(f"Control frequency: {fps} Hz")
    print("\n⚠️  SAFETY: Press Ctrl+C to stop at any time")

    input("\n>>> Press ENTER when cup is in position...")

    dt = 1.0 / fps
    step = 0

    print("\n🎬 Starting pour...")

    try:
        start_time = time.time()

        while step < max_steps:
            loop_start = time.time()

            # Get observation
            obs = get_observation(robot)

            # Run policy
            with torch.no_grad():
                action = policy.select_action(obs)

            # Send to robot
            send_action(robot, action)

            step += 1

            # Maintain control frequency
            elapsed = time.time() - loop_start
            sleep_time = dt - elapsed
            if sleep_time > 0:
                time.sleep(sleep_time)

            # Progress
            if step % 50 == 0:
                print(f"  Step {step}/{max_steps} ({step * dt:.1f}s)")

        print("\n✅ Pour complete!")

    except KeyboardInterrupt:
        print("\n\n⚠️  Stopped by user")

    finally:
        total_time = time.time() - start_time
        print(f"\nTotal time: {total_time:.1f}s")
        print(f"Steps executed: {step}")


def main():
    parser = argparse.ArgumentParser(description="Deploy heart latte policy")
    parser.add_argument("--checkpoint", type=str, required=True,
                        help="Path to trained checkpoint")
    parser.add_argument("--robot-config", type=str,
                        default="configs/robot/r1d2.yaml",
                        help="Robot configuration file")
    parser.add_argument("--max-steps", type=int, default=500,
                        help="Maximum inference steps")
    parser.add_argument("--fps", type=int, default=50,
                        help="Control frequency (Hz)")
    parser.add_argument("--dry-run", action="store_true",
                        help="Test without robot connection")
    args = parser.parse_args()

    print("=" * 50)
    print("🎨 HEART LATTE ART DEPLOYMENT")
    print("=" * 50)

    # Load policy
    policy = load_policy(args.checkpoint)

    if args.dry_run:
        print("\n🧪 DRY RUN MODE - no robot connection")
        print("Policy loaded successfully, ready for deployment")
        return

    # Connect robot
    robot = connect_robot(args.robot_config)
    if robot is None:
        print("❌ Cannot proceed without robot connection")
        return

    # Run inference loop
    while True:
        run_inference(policy, robot, args.max_steps, args.fps)

        again = input("\n\nRun another pour? [y/N]: ").lower().strip()
        if again != 'y':
            break

    print("\n👋 Done!")


if __name__ == "__main__":
    import torch
    main()
