#!/usr/bin/env python3
"""
Interactive data collector using ROS joint states
- Kinesthetic teaching (move robot by hand)
- Interactive commands without Ctrl+C
- Save or discard episodes easily
"""

from Hardware_Bridge import Realman_Hardware_Bridge
from DataRecoder import DataRecoder
from DataCollectionConstants import RATE
import numpy as np
import time
import rospy
import threading
import queue


class SimpleDataCollector:
    """Interactive data collector with kinesthetic teaching"""

    def __init__(self):
        # Initialize hardware
        print("Initializing hardware bridge...")
        self.hardware = Realman_Hardware_Bridge()

        # Initialize data recorder
        self.recorder = DataRecoder(fps=RATE)

        # Episode tracking
        self.episode_count = 0
        self.collecting = False
        self.step_count = 0

        # Command queue for thread-safe communication
        self.command_queue = queue.Queue()
        self.running = True

        print("\n" + "="*60)
        print("✓ Data collector initialized")
        print(f"  Collection rate: {RATE} Hz")
        print(f"  Data saved to: Data/")
        print("="*60)

    def start_episode(self):
        """Start collecting data"""
        if self.collecting:
            print("\n⚠ Already collecting! Stop current episode first.")
            return

        self.recorder.reset()
        self.collecting = True
        self.step_count = 0

        # Prepare for recording (no auto-positioning, just open grippers)
        print(f"\n{'='*60}")
        print(f"📹 EPISODE {self.episode_count} - RECORDING")
        print(f"{'='*60}")
        print("Opening grippers...")
        self.hardware.move_to_initial_pose()  # Just opens grippers, no movement
        print("✓ Ready! Move the robot arms by hand...")
        print(f"Type 'y' to SAVE or 'n' to DISCARD when done\n")

    def collect_step(self):
        """Collect one step of data"""
        if not self.collecting:
            return

        # Get observation (current robot state from ROS)
        observation = self.hardware.get_state()  # 12D [l_arm(6), r_arm(6)]

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
            print(f"  📊 Step {self.step_count} | L: {observation[:3].round(2)} | R: {observation[6:9].round(2)}")

    def stop_episode(self, save: bool):
        """Stop collecting and save or discard"""
        if not self.collecting:
            print("\n⚠ Not currently collecting")
            return

        self.collecting = False

        if save:
            print(f"\n💾 Saving episode {self.episode_count}...")
            self.recorder.dump_buffer_data()
            print(f"✓ Episode {self.episode_count} saved! ({self.step_count} steps)")
            self.episode_count += 1
        else:
            print(f"\n🗑 Episode discarded ({self.step_count} steps)")

        print(f"\n{'='*60}")
        print("Type 's' to start next episode, or 'q' to quit")
        print(f"{'='*60}\n")

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
        print("\n" + "="*60)
        print("COMMANDS:")
        print("  's' - Start new episode")
        print("  'y' - Save current episode")
        print("  'n' - Discard current episode")
        print("  'q' - Quit program")
        print("="*60 + "\n")

    def run(self):
        """Main collection loop"""
        print("\n" + "="*60)
        print("🤖 LATTE ART ROBOT - DATA COLLECTION")
        print("="*60)
        self.print_help()

        # Start command handler thread
        cmd_thread = threading.Thread(target=self.command_handler, daemon=True)
        cmd_thread.start()

        print("Type 's' to start collecting first episode...\n")

        rate = rospy.Rate(RATE)

        try:
            while not rospy.is_shutdown() and self.running:
                # Process commands
                while not self.command_queue.empty():
                    cmd = self.command_queue.get()

                    if cmd == 's':
                        if not self.collecting:
                            self.start_episode()
                        else:
                            print("\n⚠ Already collecting! Type 'y' to save or 'n' to discard first.")

                    elif cmd == 'y':
                        if self.collecting:
                            self.stop_episode(save=True)
                        else:
                            print("\n⚠ Not collecting. Type 's' to start episode.")

                    elif cmd == 'n':
                        if self.collecting:
                            self.stop_episode(save=False)
                        else:
                            print("\n⚠ Not collecting. Type 's' to start episode.")

                    elif cmd == 'q':
                        print("\n👋 Quitting...")
                        if self.collecting:
                            print("Current episode in progress.")
                            save_response = input("Save it? (y/n): ").strip().lower()
                            self.stop_episode(save=(save_response == 'y'))
                        self.running = False
                        break

                    elif cmd == 'help' or cmd == 'h':
                        self.print_help()

                    elif cmd != '':
                        print(f"\n⚠ Unknown command: '{cmd}'. Type 'help' for commands.")

                # Collect data if active
                if self.collecting:
                    self.collect_step()

                rate.sleep()

        except KeyboardInterrupt:
            print("\n\n⚠ Interrupted!")
            if self.collecting:
                save_response = input("Save current episode? (y/n): ").strip().lower()
                self.stop_episode(save=(save_response == 'y'))

        finally:
            self.running = False
            print("\n✓ Shutdown complete")
            print(f"Total episodes collected: {self.episode_count}\n")


if __name__ == "__main__":
    collector = SimpleDataCollector()
    collector.run()
