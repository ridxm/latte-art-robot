#!/usr/bin/env python3
"""ROS2 Hardware Bridge for Realman Dual Arms with Gripper State Feedback"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from rm_ros_interfaces.msg import Movej, Gripperset, Gripperstate
import numpy as np
import time
import threading

from DataCollectionConstants import IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_CHANNELS, ARM_SPEED
from camera_utils import AsyncCameraReader


class RealmanHardwareBridgeROS2(Node):
    """ROS2 Hardware bridge for dual Realman arms with gripper state feedback from driver"""

    def __init__(self, left_arm_ip='169.254.128.18', right_arm_ip='169.254.128.19'):
        super().__init__('realman_hardware_bridge')

        # Joint state storage
        self.l_arm_current_angles = None
        self.r_arm_current_angles = None
        self._received_l_arm = False
        self._received_r_arm = False

        # Gripper state storage (from driver feedback)
        self.l_gripper_position = 1000.0  # 0-1000, default open
        self.r_gripper_position = 1000.0
        self._received_l_gripper = False
        self._received_r_gripper = False

        # Subscriber for unified joint states (both arms on same topic)
        self.joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_states_callback,
            10
        )

        # Subscribers for gripper state feedback (from RM driver @ 10Hz)
        self.l_gripper_state_sub = self.create_subscription(
            Gripperstate,
            '/left_arm_controller/rm_driver/gripper_state',
            self.l_gripper_state_callback,
            10
        )
        self.r_gripper_state_sub = self.create_subscription(
            Gripperstate,
            '/right_arm_controller/rm_driver/gripper_state',
            self.r_gripper_state_callback,
            10
        )

        # Publishers for arm commands
        self.l_arm_pub = self.create_publisher(
            Movej,
            '/left_arm_controller/rm_driver/movej_cmd',
            10
        )
        self.r_arm_pub = self.create_publisher(
            Movej,
            '/right_arm_controller/rm_driver/movej_cmd',
            10
        )

        # Publishers for gripper control
        self.l_gripper_pub = self.create_publisher(
            Gripperset,
            '/left_arm_controller/rm_driver/set_gripper_position_cmd',
            10
        )
        self.r_gripper_pub = self.create_publisher(
            Gripperset,
            '/right_arm_controller/rm_driver/set_gripper_position_cmd',
            10
        )

        # Camera setup using AsyncCameraReader (ROS topics)
        self.camera_reader = AsyncCameraReader(
            self, IMAGE_HEIGHT, IMAGE_WIDTH,
            timeout_ms=100, slow_speed_threshold=15.0
        )
        self._default_image = np.zeros((IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_CHANNELS), dtype=np.uint8)

        self.get_logger().info('Hardware bridge initialized')
        self.get_logger().info('  Gripper state: Subscribing to RM driver feedback (10Hz)')

    def joint_states_callback(self, msg):
        """Unified joint states callback - filters by joint name prefix"""
        if len(msg.name) > 0 and len(msg.position) >= 6:
            positions = list(msg.position[:6])

            # Check if we're receiving all zeros (might indicate a problem)
            if all(abs(p) < 0.001 for p in positions):
                return

            if msg.name[0].startswith('l_'):
                self.l_arm_current_angles = positions
                if not self._received_l_arm:
                    self._received_l_arm = True
                    self.get_logger().info(f'✓ Receiving left arm joint states')
            elif msg.name[0].startswith('r_'):
                self.r_arm_current_angles = positions
                if not self._received_r_arm:
                    self._received_r_arm = True
                    self.get_logger().info(f'✓ Receiving right arm joint states')

    def l_gripper_state_callback(self, msg: Gripperstate):
        """Left gripper state callback - reads actual position from hardware"""
        self.l_gripper_position = float(msg.actpos)
        if not self._received_l_gripper:
            self._received_l_gripper = True
            self.get_logger().info(f'✓ Receiving left gripper state (actpos={msg.actpos})')

    def r_gripper_state_callback(self, msg: Gripperstate):
        """Right gripper state callback - reads actual position from hardware"""
        self.r_gripper_position = float(msg.actpos)
        if not self._received_r_gripper:
            self._received_r_gripper = True
            self.get_logger().info(f'✓ Receiving right gripper state (actpos={msg.actpos})')

    def set_gripper(self, arm: str, position: int):
        """Set gripper position

        Args:
            arm: 'left' or 'right'
            position: 0-1000 (0=closed, 1000=open/70mm)
        """
        position = max(0, min(1000, position))

        gripper_msg = Gripperset()
        gripper_msg.position = position
        gripper_msg.block = False
        gripper_msg.timeout = 1000

        if arm == 'left':
            self.l_gripper_pub.publish(gripper_msg)
        else:
            self.r_gripper_pub.publish(gripper_msg)

        self.get_logger().info(f'{arm.capitalize()} gripper -> {position} ({position/10:.0f}%)')

    def open_grippers(self):
        """Open both grippers"""
        self.set_gripper('left', 1000)
        self.set_gripper('right', 1000)

    def close_grippers(self):
        """Close both grippers"""
        self.set_gripper('left', 0)
        self.set_gripper('right', 0)

    def get_state(self):
        """Get current robot state (14D: left arm + gripper + right arm + gripper)

        Reads ACTUAL gripper positions from hardware via RM driver feedback!
        """
        l_arm = self.l_arm_current_angles if self.l_arm_current_angles is not None else [0.0] * 6
        r_arm = self.r_arm_current_angles if self.r_arm_current_angles is not None else [0.0] * 6

        # Normalize gripper position to 0-1 range (from 0-1000)
        l_gripper_norm = self.l_gripper_position / 1000.0
        r_gripper_norm = self.r_gripper_position / 1000.0

        # State: [l_arm(6), l_gripper(1), r_arm(6), r_gripper(1)] = 14D
        return np.concatenate([l_arm, [l_gripper_norm], r_arm, [r_gripper_norm]])

    def is_ready(self):
        """Check if we've received joint states from both arms"""
        return self._received_l_arm and self._received_r_arm

    def grippers_ready(self):
        """Check if we've received gripper state from both arms"""
        return self._received_l_gripper and self._received_r_gripper

    def get_camera_data(self, wait_for_fresh=True):
        """Get camera frames [top, left_wrist, right_wrist]"""
        try:
            frames = self.camera_reader.get_latest_frame(timeout_ms=500, wait_for_fresh=wait_for_fresh)
        except Exception as e:
            self.get_logger().warn(f"Camera read error: {e}")
            frames = {}

        return [
            frames.get('top_camera', self._default_image),
            frames.get('left_wrist', self._default_image),
            frames.get('right_wrist', self._default_image)
        ]

    def move_to_initial_pose(self):
        """Open grippers - no arm movement"""
        self.get_logger().info('Opening grippers for kinesthetic teaching')
        self.open_grippers()
        time.sleep(1.0)

    def execute_robot_actions(self, action_dict):
        """Execute arm commands"""
        try:
            if action_dict.get('l_arm_joints') is not None:
                msg = Movej()
                msg.joint = [float(j) for j in action_dict['l_arm_joints']]
                msg.speed = int(ARM_SPEED * 100)
                msg.block = False
                msg.trajectory_connect = 0
                msg.dof = 6
                self.l_arm_pub.publish(msg)

            if action_dict.get('r_arm_joints') is not None:
                msg = Movej()
                msg.joint = [float(j) for j in action_dict['r_arm_joints']]
                msg.speed = int(ARM_SPEED * 100)
                msg.block = False
                msg.trajectory_connect = 0
                msg.dof = 6
                self.r_arm_pub.publish(msg)
        except Exception as e:
            self.get_logger().error(f"Error executing robot actions: {e}")

    def cleanup(self):
        """Release resources"""
        self.camera_reader.stop_event.set()


def main():
    rclpy.init()
    bridge = RealmanHardwareBridgeROS2()

    try:
        rate = bridge.create_rate(10)
        while rclpy.ok():
            state = bridge.get_state()
            print(f'State: L_arm={state[:3].round(2)} L_grip={state[6]:.2f} | R_arm={state[7:10].round(2)} R_grip={state[13]:.2f}')
            rate.sleep()
    except KeyboardInterrupt:
        pass
    finally:
        bridge.cleanup()
        bridge.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
