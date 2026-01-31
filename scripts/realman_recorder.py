#!/usr/bin/env python3
"""
Realman Arm Data Recorder
Captures joint states, actions, and camera frames from Realman arms (RM65/RM75)
Outputs raw data that can be converted to LeRobot format.

Usage:
    python scripts/realman_recorder.py --robot-ip 192.168.1.18 --episode 0
"""

import argparse
import json
import time
import cv2
import numpy as np
from pathlib import Path
from datetime import datetime
from dataclasses import dataclass, asdict
from typing import Optional
import threading
import queue


@dataclass
class Frame:
    """Single timestep of recorded data."""
    timestamp: float
    joint_positions: list  # 6 or 7 DOF
    joint_velocities: list
    gripper_position: float
    action: list  # Target joint positions
    wrist_image_path: Optional[str] = None
    overhead_image_path: Optional[str] = None


class RealmanRecorder:
    """Records data from Realman robot arm."""

    def __init__(
        self,
        robot_ip: str,
        robot_port: int = 8080,
        wrist_camera_id: int = 0,
        overhead_camera_id: int = 1,
        fps: int = 30,
        output_dir: str = "data/raw"
    ):
        self.robot_ip = robot_ip
        self.robot_port = robot_port
        self.fps = fps
        self.output_dir = Path(output_dir)
        self.output_dir.mkdir(parents=True, exist_ok=True)

        # Robot connection
        self.robot = None
        self.handle = None

        # Cameras
        self.wrist_cam_id = wrist_camera_id
        self.overhead_cam_id = overhead_camera_id
        self.wrist_cam = None
        self.overhead_cam = None

        # Recording state
        self.recording = False
        self.frames = []
        self.frame_queue = queue.Queue()

    def connect_robot(self):
        """Connect to Realman robot."""
        try:
            from Robotic_Arm.rm_robot_interface import RoboticArm, rm_thread_mode_e

            print(f"🤖 Connecting to Realman at {self.robot_ip}:{self.robot_port}...")
            self.robot = RoboticArm(rm_thread_mode_e.RM_TRIPLE_MODE_E)
            self.handle = self.robot.rm_create_robot_arm(self.robot_ip, self.robot_port)

            if self.handle.id == -1:
                raise ConnectionError("Failed to connect to robot")

            print("✅ Robot connected")
            return True

        except ImportError:
            print("❌ Robotic_Arm package not found. Install with: pip install Robotic_Arm")
            return False
        except Exception as e:
            print(f"❌ Robot connection failed: {e}")
            return False

    def connect_cameras(self):
        """Initialize cameras."""
        print("📷 Connecting cameras...")

        self.wrist_cam = cv2.VideoCapture(self.wrist_cam_id)
        if self.wrist_cam.isOpened():
            self.wrist_cam.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            self.wrist_cam.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            self.wrist_cam.set(cv2.CAP_PROP_FPS, self.fps)
            print(f"  ✅ Wrist camera (id={self.wrist_cam_id})")
        else:
            print(f"  ⚠️  Wrist camera not found (id={self.wrist_cam_id})")
            self.wrist_cam = None

        self.overhead_cam = cv2.VideoCapture(self.overhead_cam_id)
        if self.overhead_cam.isOpened():
            self.overhead_cam.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            self.overhead_cam.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            self.overhead_cam.set(cv2.CAP_PROP_FPS, self.fps)
            print(f"  ✅ Overhead camera (id={self.overhead_cam_id})")
        else:
            print(f"  ⚠️  Overhead camera not found (id={self.overhead_cam_id})")
            self.overhead_cam = None

        return self.wrist_cam is not None or self.overhead_cam is not None

    def get_robot_state(self):
        """Get current joint positions and velocities."""
        if self.robot is None:
            return [0.0] * 6, [0.0] * 6, 0.0

        try:
            # Get joint positions (radians)
            joint_state = self.robot.rm_get_joint_degree(self.handle)
            positions = joint_state.joint if hasattr(joint_state, 'joint') else [0.0] * 6

            # Get velocities if available
            velocities = [0.0] * len(positions)  # Placeholder

            # Get gripper state
            gripper_pos = 0.0  # Placeholder - implement based on gripper type

            return positions, velocities, gripper_pos
        except Exception as e:
            print(f"⚠️  Error reading robot state: {e}")
            return [0.0] * 6, [0.0] * 6, 0.0

    def capture_frame(self, episode_dir: Path, frame_idx: int) -> Frame:
        """Capture single frame of data."""
        timestamp = time.time()

        # Robot state
        positions, velocities, gripper = self.get_robot_state()

        # For teleop, action = current position (we're recording demonstrations)
        action = positions.copy()

        # Camera frames
        wrist_path = None
        overhead_path = None

        if self.wrist_cam is not None:
            ret, frame = self.wrist_cam.read()
            if ret:
                wrist_path = f"wrist/frame_{frame_idx:06d}.jpg"
                full_path = episode_dir / wrist_path
                full_path.parent.mkdir(parents=True, exist_ok=True)
                cv2.imwrite(str(full_path), frame)

        if self.overhead_cam is not None:
            ret, frame = self.overhead_cam.read()
            if ret:
                overhead_path = f"overhead/frame_{frame_idx:06d}.jpg"
                full_path = episode_dir / overhead_path
                full_path.parent.mkdir(parents=True, exist_ok=True)
                cv2.imwrite(str(full_path), frame)

        return Frame(
            timestamp=timestamp,
            joint_positions=list(positions),
            joint_velocities=list(velocities),
            gripper_position=gripper,
            action=list(action),
            wrist_image_path=wrist_path,
            overhead_image_path=overhead_path
        )

    def record_episode(self, episode_id: int, max_duration: float = 30.0):
        """Record a single episode."""
        episode_dir = self.output_dir / f"episode_{episode_id:06d}"
        episode_dir.mkdir(parents=True, exist_ok=True)

        print(f"\n📹 Recording episode {episode_id}")
        print(f"   Output: {episode_dir}")
        print(f"   Max duration: {max_duration}s")
        print("   Press 'q' to stop recording\n")

        self.frames = []
        self.recording = True
        dt = 1.0 / self.fps
        frame_idx = 0
        start_time = time.time()

        # Create preview window
        cv2.namedWindow("Recording", cv2.WINDOW_NORMAL)

        try:
            while self.recording:
                loop_start = time.time()

                # Capture frame
                frame = self.capture_frame(episode_dir, frame_idx)
                self.frames.append(frame)

                # Display preview
                if self.wrist_cam is not None:
                    ret, preview = self.wrist_cam.read()
                    if ret:
                        elapsed = time.time() - start_time
                        cv2.putText(
                            preview,
                            f"Episode {episode_id} | Frame {frame_idx} | {elapsed:.1f}s",
                            (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2
                        )
                        cv2.imshow("Recording", preview)

                # Check for stop
                key = cv2.waitKey(1) & 0xFF
                if key == ord('q'):
                    print("\n⏹️  Stopped by user")
                    break

                # Check duration
                if time.time() - start_time >= max_duration:
                    print("\n⏹️  Max duration reached")
                    break

                frame_idx += 1

                # Maintain FPS
                elapsed = time.time() - loop_start
                sleep_time = dt - elapsed
                if sleep_time > 0:
                    time.sleep(sleep_time)

        finally:
            self.recording = False
            cv2.destroyAllWindows()

        # Save metadata
        metadata = {
            "episode_id": episode_id,
            "num_frames": len(self.frames),
            "fps": self.fps,
            "duration": self.frames[-1].timestamp - self.frames[0].timestamp if self.frames else 0,
            "start_time": datetime.now().isoformat(),
            "robot_ip": self.robot_ip
        }

        with open(episode_dir / "metadata.json", "w") as f:
            json.dump(metadata, f, indent=2)

        # Save frames data
        frames_data = [asdict(f) for f in self.frames]
        with open(episode_dir / "frames.json", "w") as f:
            json.dump(frames_data, f, indent=2)

        print(f"\n✅ Episode {episode_id} saved: {len(self.frames)} frames")
        return episode_dir

    def cleanup(self):
        """Clean up resources."""
        if self.wrist_cam is not None:
            self.wrist_cam.release()
        if self.overhead_cam is not None:
            self.overhead_cam.release()
        if self.robot is not None:
            self.robot.rm_delete_robot_arm(self.handle)
        cv2.destroyAllWindows()


def main():
    parser = argparse.ArgumentParser(description="Record from Realman arm")
    parser.add_argument("--robot-ip", type=str, default="192.168.1.18",
                        help="Robot IP address")
    parser.add_argument("--robot-port", type=int, default=8080,
                        help="Robot port")
    parser.add_argument("--episode", type=int, default=0,
                        help="Starting episode number")
    parser.add_argument("--num-episodes", type=int, default=1,
                        help="Number of episodes to record")
    parser.add_argument("--fps", type=int, default=30,
                        help="Recording FPS")
    parser.add_argument("--duration", type=float, default=30.0,
                        help="Max episode duration (seconds)")
    parser.add_argument("--output-dir", type=str, default="data/raw",
                        help="Output directory")
    parser.add_argument("--wrist-camera", type=int, default=0,
                        help="Wrist camera ID")
    parser.add_argument("--overhead-camera", type=int, default=1,
                        help="Overhead camera ID")
    parser.add_argument("--no-robot", action="store_true",
                        help="Record cameras only (no robot connection)")
    args = parser.parse_args()

    print("=" * 50)
    print("🎬 REALMAN ARM RECORDER")
    print("=" * 50)

    recorder = RealmanRecorder(
        robot_ip=args.robot_ip,
        robot_port=args.robot_port,
        wrist_camera_id=args.wrist_camera,
        overhead_camera_id=args.overhead_camera,
        fps=args.fps,
        output_dir=args.output_dir
    )

    # Connect
    if not args.no_robot:
        if not recorder.connect_robot():
            print("⚠️  Continuing without robot (camera only mode)")

    if not recorder.connect_cameras():
        print("❌ No cameras available")
        return

    # Record episodes
    try:
        for i in range(args.num_episodes):
            episode_id = args.episode + i

            input(f"\n>>> Press ENTER to start episode {episode_id}...")
            recorder.record_episode(episode_id, args.duration)

            if i < args.num_episodes - 1:
                cont = input("\nContinue to next episode? [Y/n]: ").lower().strip()
                if cont == 'n':
                    break

    finally:
        recorder.cleanup()

    print("\n📋 Next step: Convert to LeRobot format")
    print(f"   python scripts/convert_to_lerobot.py --input-dir {args.output_dir}")


if __name__ == "__main__":
    main()
