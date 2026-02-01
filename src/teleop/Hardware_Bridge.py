#!/usr/bin/env python3

'''Simplified Realman Hardware Bridge - 12 joints (6 per arm), ROS2 version'''

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from rm_ros_interfaces.msg import Movej, Gripperset
import numpy as np
import time

from DataCollectionConstants import (IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_CHANNELS, ARM_SPEED)
from camera_utils import AsyncCameraReader


class Realman_Hardware_Bridge(Node):
    """Simplified hardware bridge - arms only, ROS2 interface"""

    def __init__(self):
        super().__init__("Realman_Hardware_Bridge")
        self.l_arm_current_angles = [0, 0, 0, 0, 0, 0]
        self.r_arm_current_angles = [0, 0, 0, 0, 0, 0]
        self.l_gripper_state = 0
        self.r_gripper_state = 0

        # 1. Arms subscribers and publishers
        self.joint_state_sub = self.create_subscription(
            JointState, '/joint_states', self.joint_states_callback, 10)
        self.pub_MoveJ_l = self.create_publisher(
            Movej, '/left_arm_controller/rm_driver/movej_cmd', 10)
        self.pub_MoveJ_r = self.create_publisher(
            Movej, '/right_arm_controller/rm_driver/movej_cmd', 10)

        # 2. Gripper publishers
        self.pub_gripper_l = self.create_publisher(
            Gripperset, '/left_arm_controller/rm_driver/set_gripper_position_cmd', 10)
        self.pub_gripper_r = self.create_publisher(
            Gripperset, '/right_arm_controller/rm_driver/set_gripper_position_cmd', 10)

        # 3. Camera setup (3 RGB cameras only)
        self.async_camera_reader = AsyncCameraReader(IMAGE_HEIGHT, IMAGE_WIDTH, timeout_ms=100, slow_speed_threshold=15.0)
        self.async_camera_reader.start_async_reading()
        self._default_black_image = np.zeros((IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_CHANNELS), dtype=np.uint8)


    def get_state(self, include_base=False, phase=None):
        """
        Get current robot state - arms only (12D)
        Returns: numpy array [l_arm(6), r_arm(6)]
        """
        return np.concatenate((
            self.l_arm_current_angles,
            self.r_arm_current_angles
        ))
    
    def _publish_movej(self, publisher, joints, speed=ARM_SPEED, trajectory_connect=0):
        """Build and publish a MoveJ message."""
        msg = Movej()
        # Convert to list of float32
        joint_list = joints.tolist() if hasattr(joints, "tolist") else list(joints)
        msg.joint = [float(j) for j in joint_list]
        msg.speed = int(speed)
        msg.block = False
        msg.trajectory_connect = int(trajectory_connect)
        msg.dof = 6
        publisher.publish(msg)

    def _set_gripper_position(self, publisher, position, block=False, timeout=1000):
        """Set gripper position (0-1000, 0=closed, 1000=open)"""
        msg = Gripperset()
        msg.position = int(position)
        msg.block = block
        msg.timeout = int(timeout)
        publisher.publish(msg)

    def _wait_for_arm_pose(self, target_pose, side="l", tolerance=0.12, timeout=8.0):
        """Block until the specified arm is within tolerance of target or timeout."""
        start_time = time.time()
        while time.time() - start_time < timeout and rclpy.ok():
            current = self.l_arm_current_angles if side == "l" else self.r_arm_current_angles
            current = np.array(current)
            target = np.array(target_pose)
            max_err = np.max(np.abs(current - target))
            if max_err <= tolerance:
                return True
            time.sleep(0.05)
        return False

    def move_to_initial_pose(self):
        """No initial pose - user will manually position arms"""
        self.get_logger().info("Skipping initial pose - manually position arms as needed")
        # Open grippers (1000 = fully open)
        self._set_gripper_position(self.pub_gripper_l, 1000)
        self._set_gripper_position(self.pub_gripper_r, 1000)
        time.sleep(1.0)

    def execute_robot_actions(self, action_dict):
        """Execute arm commands only"""
        try:
            # Execute arm commands
            if action_dict.get('l_arm_joints') is not None:
                self._publish_movej(self.pub_MoveJ_l, action_dict['l_arm_joints'])
            if action_dict.get('r_arm_joints') is not None:
                self._publish_movej(self.pub_MoveJ_r, action_dict['r_arm_joints'])

            time.sleep(0.05)

        except Exception as e:
            self.get_logger().error(f"Error executing robot actions: {e}")

    def joint_states_callback(self, data):
        """Unified callback for /joint_states - filters by joint name prefix"""
        if len(data.name) > 0 and data.name[0].startswith('l_'):
            # Left arm joints
            self.l_arm_current_angles = list(data.position)
        elif len(data.name) > 0 and data.name[0].startswith('r_'):
            # Right arm joints
            self.r_arm_current_angles = list(data.position)

    def get_camera_data(self, wait_for_fresh=True):
        """Get camera data from 3 RGB cameras only

        Args:
            wait_for_fresh: If True, wait for fresh frames from all cameras
                          If False, return cached frames immediately

        Returns: [top_camera, left_wrist, right_wrist]
        Total: 3 RGB cameras only
        """
        try:
            frames = self.async_camera_reader.get_latest_frame(timeout_ms=500, wait_for_fresh=wait_for_fresh)
        except TimeoutError as exc:
            if not hasattr(self, "_warned_camera_timeout"):
                self.get_logger().warn(f"Async camera reader timeout: {exc}")
                self._warned_camera_timeout = True
            frames = {}
        except Exception as exc:
            self.get_logger().error(f"Async camera reader error: {exc}")
            frames = {}

        def _fetch_frame(key):
            frame = frames.get(key)
            if frame is None:
                return self._default_black_image
            return frame

        top_camera = _fetch_frame('top_camera')
        left_wrist = _fetch_frame('left_wrist')
        right_wrist = _fetch_frame('right_wrist')

        return [top_camera, left_wrist, right_wrist]
