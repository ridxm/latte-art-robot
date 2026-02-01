#!/usr/bin/env python3
"""
Test camera setup for latte art robot
Verifies ZED 2i top camera + 2x RealSense wrist cameras
"""

import rclpy
from rclpy.node import Node
import time

def test_camera_topics():
    """Check if camera topics are publishing"""

    rclpy.init()
    node = Node('camera_topic_checker')

    print("\n" + "="*60)
    print("CAMERA TOPIC VERIFICATION")
    print("="*60)
    print("\nChecking for camera topics...\n")

    # Expected topics for our setup
    expected_topics = {
        'ZED 2i Top Camera': '/camera_0/zed_node/rgb/image_rect_color',
        'RealSense Left Wrist': '/camera_3/color/image_raw',
        'RealSense Right Wrist': '/camera_4/color/image_raw',
    }

    # Get all available topics
    available_topics = dict(node.get_topic_names_and_types())

    # Check each expected topic
    results = {}
    for name, topic in expected_topics.items():
        if topic in available_topics:
            msg_types = available_topics[topic]
            # Check if it's an Image topic
            if 'sensor_msgs/msg/Image' in msg_types:
                print(f"✓ {name}")
                print(f"  Topic: {topic}")
                print(f"  Type: {msg_types[0]}")
                results[name] = True
            else:
                print(f"✗ {name}")
                print(f"  Topic: {topic}")
                print(f"  Wrong type: {msg_types}")
                results[name] = False
        else:
            print(f"✗ {name}")
            print(f"  Topic: {topic}")
            print(f"  Status: NOT FOUND")
            results[name] = False
        print()

    # Summary
    print("="*60)
    successful = sum(results.values())
    total = len(results)

    if successful == total:
        print(f"✓ SUCCESS: All {total} cameras are publishing!")
        print("\nYou can now run data collection:")
        print("  cd ~/ros2_ws/src/teleop")
        print("  python3 collect_data_ros2.py")
    else:
        print(f"⚠ WARNING: Only {successful}/{total} cameras detected")
        print("\nMissing cameras:")
        for name, success in results.items():
            if not success:
                print(f"  - {name}")
        print("\nTroubleshooting:")
        print("1. Make sure launch_drivers.py is running in another terminal:")
        print("     python3 launch_drivers.py")
        print("2. Check camera connections (USB cables)")
        print("3. Verify ZED SDK and RealSense drivers are installed")
        print("4. Check if zed_wrapper package is installed:")
        print("     ros2 pkg list | grep zed")

    print("="*60 + "\n")

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    test_camera_topics()
