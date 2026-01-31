#!/usr/bin/env python3

'''Simplified Realman Hardware Bridge - 12 joints (6 per arm), no base, no head'''

import rospy
from sensor_msgs.msg import JointState
from dual_arm_msgs.msg import MoveJ
import numpy as np
from teleop.gripper import Gripper
import time
from std_msgs.msg import Float32

from DataCollectionConstants import (IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_CHANNELS, ARM_SPEED)
from teleop.camera_utils import AsyncCameraReader


class Realman_Hardware_Bridge:
    """Simplified hardware bridge - arms only, no base control"""

    def __init__(self):
        rospy.init_node("Realman_Hardware_Bridge")
        self.l_arm_current_angles = [0, 0, 0, 0, 0, 0]
        self.r_arm_current_angles = [0, 0, 0, 0, 0, 0]
        self.l_gripper_state = 0
        self.r_gripper_state = 0

        # 1. Arms subscribers and publishers
        rospy.Subscriber('/l_arm/joint_states', JointState, self.l_joint_angles_callback)
        rospy.Subscriber('/r_arm/joint_states', JointState, self.r_joint_angles_callback)
        self.pub_MoveJ_l = rospy.Publisher('/l_arm/rm_driver/MoveJ_Cmd', MoveJ, queue_size=1)
        self.pub_MoveJ_r = rospy.Publisher('/r_arm/rm_driver/MoveJ_Cmd', MoveJ, queue_size=1)

        # 2. Grippers subscribers and publishers
        rospy.Subscriber('/gripper_state', Float32, self.r_gripper_callback)
        self.l_gripper = Gripper(ip='169.254.128.18')
        self.r_gripper = Gripper(ip='169.254.128.19')

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
        msg = MoveJ()
        # Allow numpy arrays, lists, tuples, etc.
        msg.joint = joints.tolist() if hasattr(joints, "tolist") else list(joints)
        msg.speed = speed
        msg.trajectory_connect = trajectory_connect
        publisher.publish(msg)

    def _wait_for_arm_pose(self, target_pose, side="l", tolerance=0.12, timeout=8.0):
        """Block until the specified arm is within tolerance of target or timeout."""
        start_time = time.time()
        while time.time() - start_time < timeout and not rospy.is_shutdown():
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
        rospy.loginfo("Skipping initial pose - manually position arms as needed")
        # Open grippers
        self.l_gripper.open()
        self.r_gripper.open()
        rospy.sleep(1.0)

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
            rospy.logerr(f"Error executing robot actions: {e}")

    def r_gripper_callback(self, data):
        self.r_gripper_state = data.data

    def l_joint_angles_callback(self, data):
        self.l_arm_current_angles = data.position

    def r_joint_angles_callback(self, data):
        self.r_arm_current_angles = data.position

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
                rospy.logwarn(f"Async camera reader timeout: {exc}")
                self._warned_camera_timeout = True
            frames = {}
        except Exception as exc:
            rospy.logerr(f"Async camera reader error: {exc}")
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
