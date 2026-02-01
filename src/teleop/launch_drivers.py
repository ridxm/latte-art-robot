#!/usr/bin/env python3
"""
Simple script to launch RM drivers and cameras for data collection
"""

import subprocess
import sys
import time
import os
import socket

# Fixed RealSense serial numbers for consistent camera mapping
# Update these if you swap cameras
REALSENSE_LEFT_WRIST_SERIAL = "153122071961"   # camera_3
REALSENSE_RIGHT_WRIST_SERIAL = "153122075019"  # camera_4

# Arm IP addresses
LEFT_ARM_IP = "192.168.1.18"
RIGHT_ARM_IP = "192.168.1.19"


def initialize_gripper(arm_ip, arm_name):
    """Initialize gripper via socket commands BEFORE starting RM driver"""
    print(f"  Initializing {arm_name} gripper ({arm_ip})...")
    try:
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.settimeout(3.0)
        client.connect((arm_ip, 8080))

        # Set tool voltage to 24V
        cmd = '{"command":"set_tool_voltage","voltage_type":3}\r\n'
        client.send(cmd.encode('utf-8'))
        time.sleep(0.3)

        # Configure ModbusRTU mode for gripper
        cmd = '{"command":"set_modbus_mode","port":1,"baudrate":115200,"timeout":2}\r\n'
        client.send(cmd.encode('utf-8'))
        time.sleep(0.3)

        # Initialize gripper (write to control register)
        cmd = '{"command":"write_single_register","port":1,"address":256,"data":1,"device":1}\r\n'
        client.send(cmd.encode('utf-8'))
        time.sleep(0.3)

        # Open gripper to starting position (1000 = fully open)
        cmd = '{"command":"write_single_register","port":1,"address":259,"data":1000,"device":1}\r\n'
        client.send(cmd.encode('utf-8'))
        time.sleep(0.5)

        client.close()
        print(f"    ✓ {arm_name} gripper initialized and opened")
        return True
    except Exception as e:
        print(f"    ⚠ {arm_name} gripper init failed: {e}")
        return False


def get_connected_cameras():
    """Detect connected RealSense cameras using rs-enumerate-devices"""
    try:
        result = subprocess.run(
            ['rs-enumerate-devices', '-s'],
            capture_output=True,
            text=True,
            timeout=5
        )

        # Parse serial numbers from output
        # Format: "Intel RealSense D435          153122071961        5.17.0.10"
        serials = []
        for line in result.stdout.split('\n'):
            # Skip header line and empty lines
            if 'Intel RealSense' in line:
                parts = line.split()
                # Serial is typically the 4th element (after "Intel RealSense D435")
                for part in parts:
                    if part.isdigit() and len(part) >= 10:  # Serial numbers are long digit strings
                        serials.append(part)
                        break

        return serials
    except Exception as e:
        print(f"Warning: Could not detect cameras: {e}")
        return []

def launch_drivers():
    """Launch RM arm drivers, ZED 2i top camera, and RealSense wrist cameras"""

    processes = []

    print("=" * 60)
    print("LAUNCHING DATA COLLECTION DRIVERS")
    print("=" * 60)

    # IMPORTANT: Initialize grippers BEFORE starting RM driver
    # Once the driver starts, it holds the socket connection
    print("\n[0/4] Initializing grippers (must be done before RM driver)...")
    left_ok = initialize_gripper(LEFT_ARM_IP, "Left")
    right_ok = initialize_gripper(RIGHT_ARM_IP, "Right")

    if left_ok and right_ok:
        print("  ✓ Both grippers initialized successfully!")
    else:
        print("  ⚠ Some grippers failed to initialize - they may not respond to commands")

    time.sleep(1)

    # Launch RM dual arm driver
    print("\n[1/4] Launching RM dual arm driver...")
    try:
        rm_driver = subprocess.Popen([
            'ros2', 'launch',
            '/home/r2d3/ros2_ws/src/rmc_aida_l_ros2-develop/ros2_rm_robot/dual_rm_driver/rm_driver/launch/dual_rm_65_driver.launch.py'
        ])
        processes.append(('RM Driver', rm_driver))
        time.sleep(2)
    except Exception as e:
        print(f"  ✗ Failed to launch RM driver: {e}")
        return

    # Launch ZED 2i camera as top/overhead camera (camera_0)
    print("\n[2/4] Launching ZED 2i top camera...")
    try:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        zed_script = os.path.join(script_dir, 'zed_camera_publisher.py')

        # Show ZED output to help debug issues
        zed_launch = subprocess.Popen([
            '/usr/bin/python3', zed_script
        ])
        processes.append(('ZED 2i Top Camera', zed_launch))
        time.sleep(3)  # Give ZED camera time to initialize
        print("  ✓ ZED camera publisher started")
        print("    Topic: /camera_0/zed_node/rgb/image_rect_color")
    except Exception as e:
        print(f"  ✗ Failed to launch ZED camera: {e}")

    # Detect RealSense cameras
    print("\n  Detecting RealSense wrist cameras...")
    camera_serials = get_connected_cameras()

    if not camera_serials:
        print("  ⚠ No RealSense cameras detected")
    else:
        print(f"  ✓ Found {len(camera_serials)} RealSense camera(s):")
        for serial in camera_serials:
            print(f"    - {serial}")

    # Launch left wrist camera (camera_3) with explicit serial
    # Note: serial_no needs double-quote escaping to be treated as string, not integer
    print("\n[3/4] Launching left wrist camera (camera_3)...")
    if REALSENSE_LEFT_WRIST_SERIAL in camera_serials:
        try:
            cam_proc = subprocess.Popen(
                f'ros2 launch realsense2_camera rs_launch.py '
                f'camera_name:=camera_3 '
                f'serial_no:="\'{REALSENSE_LEFT_WRIST_SERIAL}\'" '
                f'enable_depth:=false '
                f'rgb_camera.profile:=640x480x30 '
                f'enable_infra:=false enable_infra1:=false enable_infra2:=false',
                shell=True
            )
            processes.append((f'camera_3 (left wrist, {REALSENSE_LEFT_WRIST_SERIAL})', cam_proc))
            time.sleep(5)  # More time for USB initialization
            print(f"  ✓ Left wrist camera started (serial: {REALSENSE_LEFT_WRIST_SERIAL})")
            print("    Topic: /camera_3/color/image_raw")
        except Exception as e:
            print(f"  ✗ Failed to launch left wrist camera: {e}")
    else:
        print(f"  ⚠ Left wrist camera not found (expected serial: {REALSENSE_LEFT_WRIST_SERIAL})")

    # Launch right wrist camera (camera_4) with explicit serial
    # Extra delay to let camera_3 fully initialize and avoid USB conflicts
    print("\n[4/4] Launching right wrist camera (camera_4)...")
    print("  Waiting for camera_3 to stabilize...")
    time.sleep(5)

    if REALSENSE_RIGHT_WRIST_SERIAL in camera_serials:
        try:
            cam_proc = subprocess.Popen(
                f'ros2 launch realsense2_camera rs_launch.py '
                f'camera_name:=camera_4 '
                f'serial_no:="\'{REALSENSE_RIGHT_WRIST_SERIAL}\'" '
                f'enable_depth:=false '
                f'rgb_camera.profile:=640x480x30 '
                f'enable_infra:=false enable_infra1:=false enable_infra2:=false',
                shell=True
            )
            processes.append((f'camera_4 (right wrist, {REALSENSE_RIGHT_WRIST_SERIAL})', cam_proc))
            time.sleep(5)  # More time for USB initialization
            print(f"  ✓ Right wrist camera started (serial: {REALSENSE_RIGHT_WRIST_SERIAL})")
            print("    Topic: /camera_4/color/image_raw")
        except Exception as e:
            print(f"  ✗ Failed to launch right wrist camera: {e}")
    else:
        print(f"  ⚠ Right wrist camera not found (expected serial: {REALSENSE_RIGHT_WRIST_SERIAL})")

    print("\n" + "=" * 60)
    print("✓ ALL DRIVERS LAUNCHED")
    print("=" * 60)
    print("\nWaiting for everything to initialize...")
    time.sleep(3)

    # Check if any process failed
    print("\nChecking driver status...")
    failed = []
    for name, p in processes:
        if p.poll() is not None:
            failed.append(name)
            print(f"  ✗ {name} failed (exit code: {p.returncode})")
        else:
            print(f"  ✓ {name} running (PID: {p.pid})")

    if failed:
        print(f"\n⚠ Warning: {len(failed)} driver(s) failed: {', '.join(failed)}")
        print("Check if cameras are connected and ROS2 is sourced")
    else:
        print("\n✓ All drivers running successfully!")

    print("\nIn another terminal, run:")
    print("  cd ~/ros2_ws/src/teleop")
    print("  python3 collect_data_ros2.py")
    print("\nPress Ctrl+C to stop all drivers\n")

    try:
        # Wait for all processes
        for name, p in processes:
            p.wait()
    except KeyboardInterrupt:
        print("\n\nStopping all drivers...")
        for name, p in processes:
            p.terminate()
        time.sleep(1)
        for name, p in processes:
            if p.poll() is None:
                p.kill()
        print("✓ All drivers stopped")

if __name__ == '__main__':
    launch_drivers()
