#!/usr/bin/env python3
"""
ROS2 Data Collector for Latte Art Robot
Kinesthetic teaching with dual Realman arms
"""

import rclpy
from rclpy.node import Node
from Hardware_Bridge_ROS2 import RealmanHardwareBridgeROS2
from DataRecoder import DataRecoder
from DataCollectionConstants import RATE, MAX_STEPS_PER_EPISODE
import numpy as np
import time
import threading
import queue
import sys
from rclpy.executors import MultiThreadedExecutor


class DataCollectorROS2:
    """ROS2 Data collector with kinesthetic teaching"""

    def __init__(self):
        # Initialize ROS2
        rclpy.init()

        print('Initializing ROS2 hardware bridge...')
        self.hardware = RealmanHardwareBridgeROS2()

        # Create executor and spin in background thread
        self.executor = MultiThreadedExecutor()
        self.executor.add_node(self.hardware)
        self.spin_thread = threading.Thread(target=self.executor.spin, daemon=True)
        self.spin_thread.start()
        
        # Wait for joint states and verify topics
        print('Checking ROS topics...')
        print('Waiting for joint states from both arms...')

        # Wait up to 5 seconds for both arms
        timeout = 5.0
        start = time.time()
        while not self.hardware.is_ready() and (time.time() - start) < timeout:
            time.sleep(0.1)

        # Check joint states
        if not self.hardware.is_ready():
            print('  ⚠ WARNING: Not receiving joint states from both arms!')
            print('    Make sure RM driver is running and both arms are connected')
            if self.hardware._received_l_arm:
                print('    ✓ Left arm OK')
            if self.hardware._received_r_arm:
                print('    ✓ Right arm OK')
        else:
            print('  ✓ Joint states OK - both arms ready')
            l_arm = self.hardware.l_arm_current_angles
            r_arm = self.hardware.r_arm_current_angles
            print(f'    L_arm: [{l_arm[0]:.2f}, {l_arm[1]:.2f}, {l_arm[2]:.2f}, ...]')
            print(f'    R_arm: [{r_arm[0]:.2f}, {r_arm[1]:.2f}, {r_arm[2]:.2f}, ...]')
            print(f'    State dimension: 14D (6 joints + 1 gripper per arm)')

        # Wait for gripper state feedback from RM driver
        print('\n  Waiting for gripper state feedback (2s)...')
        time.sleep(2.0)

        if self.hardware.grippers_ready():
            state = self.hardware.get_state()
            l_grip = state[6] * 1000  # Denormalize
            r_grip = state[13] * 1000
            print(f'    Gripper: ✓ Reading ACTUAL position from hardware (via RM driver)')
            print(f'    L_gripper: {l_grip:.0f}/1000 ({l_grip/10:.1f}%)')
            print(f'    R_gripper: {r_grip:.0f}/1000 ({r_grip/10:.1f}%)')
        else:
            print(f'    Gripper: ⚠ Not receiving gripper state - check RM driver')
            if self.hardware._received_l_gripper:
                print(f'      ✓ Left gripper OK')
            if self.hardware._received_r_gripper:
                print(f'      ✓ Right gripper OK')

        # Check camera topics - wait a moment for subscribers to receive data
        print('\n  Checking camera topics (waiting 2s for data)...')
        time.sleep(2.0)  # Give time for camera callbacks to fire

        cam_data = self.hardware.get_camera_data(wait_for_fresh=False)
        cam_names = ['top_camera', 'left_wrist', 'right_wrist']
        cam_topics = [
            '/camera_0/zed_node/rgb/image_rect_color',
            '/camera_3/color/image_raw',
            '/camera_4/color/image_raw'
        ]

        active_cams = 0
        for i, (name, topic) in enumerate(zip(cam_names, cam_topics)):
            if cam_data[i].sum() != 0:
                print(f'    ✓ {name}: OK ({topic})')
                active_cams += 1
            else:
                print(f'    ✗ {name}: NO DATA ({topic})')

        if active_cams == 3:
            print(f'  ✓ All 3 cameras ready!')
        elif active_cams == 0:
            print('  ⚠ WARNING: No camera data received!')
            print('    Make sure cameras are launched with: python3 launch_drivers.py')
        else:
            print(f'  ⚠ WARNING: Only {active_cams}/3 cameras working!')
            print('    Check that all camera processes are running')

        # Initialize data recorder
        self.recorder = DataRecoder(fps=RATE)

        # Episode tracking
        self.episode_count = 0
        self.collecting = False
        self.pending_save = False
        self.step_count = 0

        # Command queue
        self.command_queue = queue.Queue()
        self.running = True

        print()
        print('=' * 60)
        print('Data collector initialized')
        print(f'  Collection rate: {RATE} Hz')
        print(f'  Max steps per episode: {MAX_STEPS_PER_EPISODE} ({MAX_STEPS_PER_EPISODE/RATE:.1f} seconds)')
        print('=' * 60)

    def start_episode(self):
        """Start collecting data"""
        if self.collecting:
            print('Already collecting! Stop current episode first.')
            return

        # Quick camera check before starting
        cam_data = self.hardware.get_camera_data(wait_for_fresh=False)
        cam_names = ['top_camera', 'left_wrist', 'right_wrist']
        missing_cams = [name for i, name in enumerate(cam_names) if cam_data[i].sum() == 0]

        if missing_cams:
            print(f'  ⚠ WARNING: Missing cameras: {", ".join(missing_cams)}')
            print('    Videos for these cameras will be empty!')
            print('    Press Enter to continue anyway, or Ctrl+C to abort...')
            try:
                input()
            except KeyboardInterrupt:
                print('    Aborted.')
                return

        self.recorder.reset()
        self.collecting = True
        self.step_count = 0

        print()
        print('=' * 60)
        print(f'EPISODE {self.episode_count} - RECORDING')
        print('=' * 60)
        print(f'Recording for {MAX_STEPS_PER_EPISODE} steps ({MAX_STEPS_PER_EPISODE/RATE:.1f}s at {RATE}Hz)')
        print('Move the robot arms AND grippers by hand...')
        print('  ✓ Gripper position auto-tracked from hardware (10Hz)')
        print("Episode controls: 'y'=save, 'n'=discard, 'r'=retry")
        print()

    def collect_step(self):
        """Collect one step of data"""
        if not self.collecting:
            return

        # Get robot state (12D)
        observation = self.hardware.get_state()
        
        # For kinesthetic teaching: action = current position
        action = observation.copy()
        
        # Get camera data
        cameras = self.hardware.get_camera_data(wait_for_fresh=True)
        
        # Record
        self.recorder.write_data_to_buffer(
            observation=observation,
            action=action,
            reward=0.0,
            termination_flag=False,
            cam_data=cameras
        )

        self.step_count += 1

        # Print progress every 10 steps
        if self.step_count % 10 == 0:
            obs = observation
            print(f'  Step {self.step_count}/{MAX_STEPS_PER_EPISODE}')
            # State is now 14D: [l_arm(6), l_gripper(1), r_arm(6), r_gripper(1)]
            print(f'    L_arm: {obs[:6].round(2)} | Gripper: {obs[6]:.2f}')
            print(f'    R_arm: {obs[7:13].round(2)} | Gripper: {obs[13]:.2f}')

        # Auto-stop after max steps reached
        if self.step_count >= MAX_STEPS_PER_EPISODE:
            print(f'\n✓ Reached {MAX_STEPS_PER_EPISODE} steps!')
            # Stop collecting but mark that we're awaiting a save/discard/retry decision
            self.collecting = False
            self.pending_save = True
            print("Save this episode? Type 'y' to save, 'n' to discard, 'r' to retry")

    def stop_episode(self, save: bool):
        """Stop collecting and save or discard"""
        if not (self.collecting or self.pending_save):
            print('Not currently collecting')
            return

        # Clear collecting/pending flags
        self.collecting = False
        self.pending_save = False

        if save:
            print(f'Saving episode {self.episode_count}...')
            self.recorder.dump_buffer_data()
            print(f'Episode {self.episode_count} saved! ({self.step_count} steps)')
            self.episode_count += 1
        else:
            print(f'Episode discarded ({self.step_count} steps)')

        print()
        print('=' * 60)
        print("Type 's' to start, 'r' to retry, or 'q' to quit")
        print('=' * 60)
        print()

    def command_handler(self):
        """Handle user commands in separate thread"""
        while self.running:
            try:
                cmd = input().strip().lower()
                self.command_queue.put(cmd)
            except (EOFError, KeyboardInterrupt):
                self.command_queue.put('q')
                break

    def print_help(self):
        """Print available commands"""
        print()
        print('=' * 60)
        print('COMMANDS:')
        print("  's' - Start new episode")
        print("  'y' - Save current episode")
        print("  'r' - Retry (discard current and start new)")
        print("  'n' - Discard current episode")
        print("  'q' - Quit program")
        print()
        print('GRIPPER: Position auto-tracked from hardware!')
        print('  Just physically move the grippers during demonstration')
        print('=' * 60)
        print()

    def run(self):
        """Main collection loop"""
        print()
        print('=' * 60)
        print('LATTE ART ROBOT - ROS2 DATA COLLECTION')
        print('=' * 60)
        self.print_help()

        # Start command handler thread
        cmd_thread = threading.Thread(target=self.command_handler, daemon=True)
        cmd_thread.start()

        print("Type 's' to start collecting first episode...")
        print()

        dt = 1.0 / RATE

        try:
            while rclpy.ok() and self.running:
                loop_start = time.time()
                
                # Process commands
                while not self.command_queue.empty():
                    cmd = self.command_queue.get()

                    if cmd == 's':
                        if not self.collecting:
                            self.start_episode()
                        else:
                            print("Already collecting! Type 'y' to save or 'n' to discard first.")

                    elif cmd == 'y':
                        # Accept save if we're currently collecting or awaiting save decision
                        if self.collecting or self.pending_save:
                            self.stop_episode(save=True)
                        else:
                            print("Not collecting. Type 's' to start episode.")

                    elif cmd == 'r':
                        # Retry - discard current episode and start a new one
                        # If collecting or awaiting save, discard and start a new episode
                        if self.collecting or self.pending_save:
                            print("Retrying - discarding current episode...")
                            self.stop_episode(save=False)
                            self.start_episode()  # Immediately start new episode
                        else:
                            print("Not collecting. Type 's' to start episode.")

                    elif cmd == 'n':
                        if self.collecting or self.pending_save:
                            self.stop_episode(save=False)
                        else:
                            print("Not collecting. Type 's' to start episode.")

                    elif cmd in ['o', 'f']:
                        # Fully open grippers (100% = 1000)
                        print("Opening grippers to 100%...")
                        self.hardware.set_gripper('left', 1000)
                        self.hardware.set_gripper('right', 1000)

                    elif cmd.isdigit():
                        # Set gripper position 0-9 (0% to 90%)
                        position_pct = int(cmd) * 10
                        position_val = int(cmd) * 100  # 0-900
                        print(f"Setting both grippers to {position_pct}%...")
                        self.hardware.set_gripper('left', position_val)
                        self.hardware.set_gripper('right', position_val)

                    elif cmd.startswith('l') and len(cmd) > 1 and cmd[1].isdigit():
                        # Set left gripper only
                        num = int(cmd[1])
                        position_val = num * 100
                        position_pct = num * 10
                        print(f"Setting LEFT gripper to {position_pct}%...")
                        self.hardware.set_gripper('left', position_val)

                    elif cmd.startswith('r') and len(cmd) > 1 and cmd[1].isdigit():
                        # Set right gripper only
                        num = int(cmd[1])
                        position_val = num * 100
                        position_pct = num * 10
                        print(f"Setting RIGHT gripper to {position_pct}%...")
                        self.hardware.set_gripper('right', position_val)

                    elif cmd == 'q':
                        print('Quitting...')
                        # If collecting or awaiting a save decision, prompt the user
                        if self.collecting or self.pending_save:
                            save_response = input('Save current episode? (y/n): ').strip().lower()
                            self.stop_episode(save=(save_response == 'y'))
                        self.running = False
                        break

                    elif cmd == 'help' or cmd == 'h':
                        self.print_help()

                # Collect data if active
                if self.collecting:
                    self.collect_step()

                # Maintain rate
                elapsed = time.time() - loop_start
                sleep_time = dt - elapsed
                if sleep_time > 0:
                    time.sleep(sleep_time)

        except KeyboardInterrupt:
            print('Interrupted!')
            if self.collecting or self.pending_save:
                try:
                    save_response = input('Save current episode? (y/n): ').strip().lower()
                except KeyboardInterrupt:
                    save_response = 'n'
                self.stop_episode(save=(save_response == 'y'))

        finally:
            self.running = False
            self.executor.shutdown()
            self.hardware.cleanup()
            self.hardware.destroy_node()
            rclpy.shutdown()
            print()
            print(f'Total episodes collected: {self.episode_count}')
            print()


if __name__ == '__main__':
    collector = DataCollectorROS2()
    collector.run()
