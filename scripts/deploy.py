#!/usr/bin/env python3
"""
Deploy trained pi0 policy on the R2D3 robot with production-grade optimizations.

Key features:
- Temporal ensembling: Overlapping action chunks averaged for smooth motion
- Action smoothing: EMA filter reduces jitter
- Proper normalization: Uses dataset statistics

Usage:
    python deploy.py --model username/pi0-latte-pour --hz 10
"""

import argparse
import time
import numpy as np
import torch
import json
import sys
from pathlib import Path
from collections import deque

# Add teleop directory to path
sys.path.insert(0, str(Path(__file__).parent.parent / "src" / "teleop"))


class ActionSmoother:
    """Exponential moving average filter for smooth actions"""

    def __init__(self, alpha: float = 0.7, action_dim: int = 14):
        """
        Args:
            alpha: Smoothing factor (0-1). Higher = more responsive, lower = smoother
            action_dim: Dimension of action space
        """
        self.alpha = alpha
        self.prev_action = None
        self.action_dim = action_dim

    def smooth(self, action: np.ndarray) -> np.ndarray:
        """Apply EMA smoothing to action"""
        if self.prev_action is None:
            self.prev_action = action.copy()
            return action

        # EMA: smoothed = alpha * current + (1 - alpha) * previous
        smoothed = self.alpha * action + (1 - self.alpha) * self.prev_action
        self.prev_action = smoothed.copy()
        return smoothed

    def reset(self):
        self.prev_action = None


class TemporalEnsembler:
    """Temporal ensembling for overlapping action chunks

    Instead of executing chunks sequentially, we overlap them and
    exponentially weight recent predictions more heavily.
    """

    def __init__(self, chunk_size: int = 10, action_dim: int = 14, decay: float = 0.5):
        """
        Args:
            chunk_size: Number of actions per chunk
            action_dim: Dimension of action space
            decay: Exponential decay for older predictions (0-1)
        """
        self.chunk_size = chunk_size
        self.action_dim = action_dim
        self.decay = decay

        # Store predictions: each entry is (action_chunk, start_timestep)
        self.predictions = deque(maxlen=5)  # Keep last 5 chunks
        self.current_timestep = 0

    def add_chunk(self, action_chunk: np.ndarray):
        """Add a new action chunk prediction"""
        self.predictions.append({
            'chunk': action_chunk,
            'start_t': self.current_timestep
        })

    def get_action(self) -> np.ndarray:
        """Get ensembled action for current timestep"""
        if len(self.predictions) == 0:
            raise ValueError("No predictions available")

        weighted_sum = np.zeros(self.action_dim)
        weight_sum = 0.0

        for pred in self.predictions:
            chunk = pred['chunk']
            start_t = pred['start_t']

            # Index within this chunk
            idx = self.current_timestep - start_t

            if 0 <= idx < len(chunk):
                # Exponential weight: more recent chunks get higher weight
                age = self.current_timestep - start_t
                weight = self.decay ** age

                weighted_sum += weight * chunk[idx]
                weight_sum += weight

        self.current_timestep += 1

        if weight_sum > 0:
            return weighted_sum / weight_sum
        else:
            # Fallback: use most recent chunk
            return self.predictions[-1]['chunk'][0]

    def should_get_new_chunk(self, overlap: int = 5) -> bool:
        """Check if we need a new chunk (based on overlap)"""
        if len(self.predictions) == 0:
            return True

        latest = self.predictions[-1]
        idx = self.current_timestep - latest['start_t']

        # Get new chunk when we're overlap steps into the current one
        return idx >= (self.chunk_size - overlap)

    def reset(self):
        self.predictions.clear()
        self.current_timestep = 0


class StateNormalizer:
    """Normalize/denormalize state and actions using dataset statistics"""

    def __init__(self, stats_path: str):
        with open(stats_path) as f:
            stats = json.load(f)

        # State normalization
        self.state_mean = np.array(stats['observation.state']['mean'])
        self.state_std = np.array(stats['observation.state']['std'])
        self.state_std = np.clip(self.state_std, 1e-6, None)  # Prevent div by zero

        # Action normalization
        self.action_mean = np.array(stats['action']['mean'])
        self.action_std = np.array(stats['action']['std'])
        self.action_std = np.clip(self.action_std, 1e-6, None)

        # Min/max for clipping
        self.action_min = np.array(stats['action']['min'])
        self.action_max = np.array(stats['action']['max'])

    def normalize_state(self, state: np.ndarray) -> np.ndarray:
        """Normalize state to zero mean, unit variance"""
        return (state - self.state_mean) / self.state_std

    def denormalize_action(self, action: np.ndarray) -> np.ndarray:
        """Denormalize action from model output"""
        denorm = action * self.action_std + self.action_mean
        # Clip to valid range with small margin
        margin = 0.1
        return np.clip(denorm,
                       self.action_min - margin * np.abs(self.action_min),
                       self.action_max + margin * np.abs(self.action_max))


class Pi0RobotController:
    """Controller for running pi0 inference on R2D3 robot with optimizations"""

    def __init__(self, model_path: str, device: str = "cuda",
                 use_temporal_ensemble: bool = True,
                 use_action_smoothing: bool = True,
                 smoothing_alpha: float = 0.7):
        import rclpy
        from rclpy.executors import MultiThreadedExecutor
        import threading

        # Initialize ROS2
        rclpy.init()
        self.rclpy = rclpy

        # Import after path setup
        from Hardware_Bridge_ROS2 import RealmanHardwareBridgeROS2
        from DataCollectionConstants import IMAGE_HEIGHT, IMAGE_WIDTH

        self.image_height = IMAGE_HEIGHT
        self.image_width = IMAGE_WIDTH
        self.device = device

        # Load normalization stats
        stats_path = Path(__file__).parent.parent / "data" / "meta" / "stats.json"
        if stats_path.exists():
            print(f"Loading normalization stats from {stats_path}")
            self.normalizer = StateNormalizer(str(stats_path))
        else:
            print("Warning: stats.json not found, skipping normalization")
            self.normalizer = None

        # Load policy
        print(f"Loading pi0 policy from {model_path}...")
        self.policy, self.chunk_size = self._load_policy(model_path, device)

        # Initialize hardware
        print("Initializing hardware bridge...")
        self.hardware = RealmanHardwareBridgeROS2()

        # Setup ROS2 executor
        self.executor = MultiThreadedExecutor()
        self.executor.add_node(self.hardware)
        self.spin_thread = threading.Thread(target=self.executor.spin, daemon=True)
        self.spin_thread.start()

        # Wait for hardware
        print("Waiting for robot state...")
        timeout = 10.0
        start = time.time()
        while not self.hardware.is_ready() and (time.time() - start) < timeout:
            time.sleep(0.1)

        if not self.hardware.is_ready():
            raise RuntimeError("Failed to connect to robot arms")

        print("Waiting for gripper state...")
        start = time.time()
        while not self.hardware.grippers_ready() and (time.time() - start) < timeout:
            time.sleep(0.1)

        print("Robot connected!")

        # Optimization modules
        self.use_temporal_ensemble = use_temporal_ensemble
        self.use_action_smoothing = use_action_smoothing

        if use_temporal_ensemble:
            self.ensembler = TemporalEnsembler(
                chunk_size=self.chunk_size,
                action_dim=14,
                decay=0.5
            )
            print(f"Temporal ensembling: ON (chunk_size={self.chunk_size})")
        else:
            self.ensembler = None
            self.action_buffer = []
            self.action_idx = 0
            print("Temporal ensembling: OFF")

        if use_action_smoothing:
            self.smoother = ActionSmoother(alpha=smoothing_alpha, action_dim=14)
            print(f"Action smoothing: ON (alpha={smoothing_alpha})")
        else:
            self.smoother = None
            print("Action smoothing: OFF")

        # Camera names matching dataset
        self.camera_names = ["top_camera", "left_wrist", "right_wrist"]

    def _load_policy(self, model_path: str, device: str):
        """Load pi0 policy and return (policy, chunk_size)"""
        from lerobot.common.policies.factory import make_policy
        from omegaconf import OmegaConf

        chunk_size = 10  # Default

        # Try to load from HuggingFace first
        if "/" in model_path and not Path(model_path).exists():
            from huggingface_hub import hf_hub_download
            try:
                config_path = hf_hub_download(repo_id=model_path, filename="config.yaml")
                config = OmegaConf.load(config_path)
                chunk_size = config.policy.get('chunk_size', 10)

                policy = make_policy(config.policy, device=device)

                # Load weights
                weights_path = hf_hub_download(repo_id=model_path, filename="model.safetensors")
                from safetensors.torch import load_file
                state_dict = load_file(weights_path)
                policy.load_state_dict(state_dict)
            except Exception as e:
                print(f"Error loading from HuggingFace: {e}")
                raise
        else:
            # Local checkpoint
            checkpoint_path = Path(model_path)
            if checkpoint_path.is_dir():
                checkpoints = list(checkpoint_path.glob("checkpoint_*"))
                if checkpoints:
                    checkpoint_path = max(checkpoints, key=lambda p: int(p.name.split("_")[1]))
                    print(f"Using checkpoint: {checkpoint_path}")

            config_path = checkpoint_path / "config.yaml" if checkpoint_path.is_dir() else checkpoint_path.parent / "config.yaml"

            if config_path.exists():
                config = OmegaConf.load(config_path)
                chunk_size = config.policy.get('chunk_size', 10)
                policy = make_policy(config.policy, device=device)
            else:
                raise FileNotFoundError(f"Config not found at {config_path}")

            weights_path = checkpoint_path / "model.safetensors" if checkpoint_path.is_dir() else checkpoint_path
            if weights_path.exists():
                from safetensors.torch import load_file
                state_dict = load_file(weights_path)
                policy.load_state_dict(state_dict)

        policy.eval()
        return policy, chunk_size

    def get_observation(self) -> dict:
        """Get current observation in LeRobot format"""
        # Get robot state (14D)
        state = self.hardware.get_state()

        # Normalize state if normalizer available
        if self.normalizer:
            state_normalized = self.normalizer.normalize_state(state)
        else:
            state_normalized = state

        # Get camera images
        cam_data = self.hardware.get_camera_data(wait_for_fresh=True)

        # Build observation dict
        observation = {
            "observation.state": torch.tensor(state_normalized, dtype=torch.float32).unsqueeze(0),
        }

        # Add images (normalize to [0, 1] and convert to CHW)
        for i, cam_name in enumerate(self.camera_names):
            img = cam_data[i].astype(np.float32) / 255.0
            img = torch.tensor(img).permute(2, 0, 1).unsqueeze(0)
            observation[f"observation.images.{cam_name}"] = img

        return observation

    def execute_action(self, action: np.ndarray):
        """Execute a 14D action on the robot"""
        # Denormalize action if normalizer available
        if self.normalizer:
            action = self.normalizer.denormalize_action(action)

        # Apply action smoothing
        if self.smoother:
            action = self.smoother.smooth(action)

        # Parse action into components
        l_arm_joints = action[:6]
        l_gripper = action[6]
        r_arm_joints = action[7:13]
        r_gripper = action[13]

        # Send arm commands
        self.hardware.execute_robot_actions({
            'l_arm_joints': l_arm_joints,
            'r_arm_joints': r_arm_joints,
        })

        # Send gripper commands (0.0=closed, 1.0=open -> 0-1000)
        l_grip_cmd = int(np.clip(l_gripper, 0.0, 1.0) * 1000)
        r_grip_cmd = int(np.clip(r_gripper, 0.0, 1.0) * 1000)
        self.hardware.set_gripper('left', l_grip_cmd)
        self.hardware.set_gripper('right', r_grip_cmd)

    @torch.no_grad()
    def run_inference(self) -> np.ndarray:
        """Run single inference step and return action chunk"""
        obs = self.get_observation()
        obs = {k: v.to(self.device) for k, v in obs.items()}

        action_chunk = self.policy.select_action(obs)
        return action_chunk.cpu().numpy()

    def run(self, inference_hz: float = 10.0, max_steps: int = 1000,
            ensemble_overlap: int = 5):
        """Main control loop with temporal ensembling"""
        print(f"\n{'='*60}")
        print("AUTONOMOUS LATTE POURING")
        print(f"{'='*60}")
        print(f"Inference rate: {inference_hz} Hz")
        print(f"Max steps: {max_steps}")
        print(f"Temporal ensemble: {self.use_temporal_ensemble}")
        print(f"Action smoothing: {self.use_action_smoothing}")
        print(f"\nPress Ctrl+C to stop")
        print(f"{'='*60}\n")

        dt = 1.0 / inference_hz
        step = 0
        inference_count = 0

        try:
            while step < max_steps:
                loop_start = time.time()

                if self.use_temporal_ensemble:
                    # Temporal ensembling mode
                    if self.ensembler.should_get_new_chunk(overlap=ensemble_overlap):
                        print(f"Step {step}: Running inference #{inference_count}...")
                        action_chunk = self.run_inference()
                        self.ensembler.add_chunk(action_chunk)
                        inference_count += 1

                    action = self.ensembler.get_action()
                else:
                    # Simple sequential mode
                    if self.action_idx >= len(self.action_buffer):
                        print(f"Step {step}: Running inference...")
                        self.action_buffer = self.run_inference()
                        self.action_idx = 0

                    action = self.action_buffer[self.action_idx]
                    self.action_idx += 1

                # Execute action
                self.execute_action(action)
                step += 1

                # Progress logging
                if step % 20 == 0:
                    state = self.hardware.get_state()
                    print(f"Step {step}: L={state[:3].round(2)} R={state[7:10].round(2)} "
                          f"G=[{state[6]:.2f}, {state[13]:.2f}]")

                # Maintain rate
                elapsed = time.time() - loop_start
                sleep_time = dt - elapsed
                if sleep_time > 0:
                    time.sleep(sleep_time)
                elif elapsed > dt * 1.5:
                    print(f"Warning: Loop took {elapsed*1000:.1f}ms (target: {dt*1000:.1f}ms)")

        except KeyboardInterrupt:
            print("\n\nStopping...")
        finally:
            print(f"\nCompleted {step} steps, {inference_count} inferences")
            self.cleanup()

    def cleanup(self):
        """Release resources"""
        print("Cleaning up...")
        if self.smoother:
            self.smoother.reset()
        if self.ensembler:
            self.ensembler.reset()
        self.hardware.cleanup()
        self.hardware.destroy_node()
        self.executor.shutdown()
        self.rclpy.shutdown()


def main():
    parser = argparse.ArgumentParser(description="Deploy pi0 policy with optimizations")
    parser.add_argument("--model", required=True,
                        help="Path to trained model (local or HF repo)")
    parser.add_argument("--device", default="cuda",
                        help="Device for inference (cuda/cpu)")
    parser.add_argument("--hz", type=float, default=10.0,
                        help="Control frequency in Hz")
    parser.add_argument("--max-steps", type=int, default=400,
                        help="Maximum steps (400 = 40s at 10Hz)")
    parser.add_argument("--no-ensemble", action="store_true",
                        help="Disable temporal ensembling")
    parser.add_argument("--no-smoothing", action="store_true",
                        help="Disable action smoothing")
    parser.add_argument("--smoothing-alpha", type=float, default=0.7,
                        help="Action smoothing factor (0-1, higher=more responsive)")
    parser.add_argument("--overlap", type=int, default=5,
                        help="Chunk overlap for temporal ensembling")

    args = parser.parse_args()

    controller = Pi0RobotController(
        args.model,
        args.device,
        use_temporal_ensemble=not args.no_ensemble,
        use_action_smoothing=not args.no_smoothing,
        smoothing_alpha=args.smoothing_alpha
    )
    controller.run(
        inference_hz=args.hz,
        max_steps=args.max_steps,
        ensemble_overlap=args.overlap
    )


if __name__ == "__main__":
    main()
