#!/usr/bin/env python3
"""Test gripper control using Realman Python API"""

import sys
import time

# Add Realman API to path
sys.path.insert(0, '/home/r2d3/latest_rm_api/RM_API2/Python')

from Robotic_Arm.rm_robot_interface import *

# Test with LEFT arm
ARM_IP = '169.254.128.18'
ARM_PORT = 8080

print("=" * 50)
print("GRIPPER TEST - Realman Python API")
print("=" * 50)
print(f"Connecting to arm at {ARM_IP}:{ARM_PORT}...")

# Create robot arm instance
arm = RoboticArm(rm_thread_mode_e.RM_TRIPLE_MODE_E)
handle = arm.rm_create_robot_arm(ARM_IP, ARM_PORT)

print(f"Handle ID: {handle.id}")

if handle.id <= 0:
    print("✗ Connection failed!")
    sys.exit(1)

print("✓ Connected!")

# Test gripper
print("\n--- Gripper State Reading Test ---")

try:
    while True:
        # Read gripper state
        result, state = arm.rm_get_gripper_state()

        if result == 0 and 'actpos' in state:
            pos = state['actpos']
            pct = pos / 10
            bar = '█' * int(pct / 5) + '░' * (20 - int(pct / 5))
            print(f"\r  Gripper: [{bar}] {pos:4d}/1000 ({pct:5.1f}%)  ", end='', flush=True)
        else:
            print(f"\r  Read error: {result}  ", end='', flush=True)

        time.sleep(0.1)  # 10Hz

except KeyboardInterrupt:
    print("\n\nStopped by user")

finally:
    # Cleanup
    print("Disconnecting...")
    arm.rm_delete_robot_arm()
    print("Done!")
