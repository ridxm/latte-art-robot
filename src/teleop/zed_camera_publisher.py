#!/usr/bin/env python3
"""
Simple ZED 2i camera publisher using OpenCV
Publishes left camera image to /camera_0/zed_node/rgb/image_rect_color
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class ZEDCameraPublisher(Node):
    def __init__(self):
        super().__init__('zed_camera_publisher')

        # Publisher
        self.publisher = self.create_publisher(
            Image,
            '/camera_0/zed_node/rgb/image_rect_color',
            10
        )

        # CV Bridge
        self.bridge = CvBridge()

        # Open ZED camera using V4L2 backend (most reliable for ZED on Linux)
        self.get_logger().info('Opening ZED 2i camera...')

        # Disable GStreamer to avoid conflicts
        import os
        os.environ['OPENCV_VIDEOIO_PRIORITY_GSTREAMER'] = '0'

        # Try V4L2 backend first (most reliable for ZED on Linux)
        self.cap = None
        for device in ['/dev/video6', '/dev/video7', 6, 7]:
            self.get_logger().info(f'Trying device: {device}')
            if isinstance(device, str):
                self.cap = cv2.VideoCapture(device, cv2.CAP_V4L2)
            else:
                self.cap = cv2.VideoCapture(device, cv2.CAP_V4L2)
            if self.cap.isOpened():
                self.get_logger().info(f'Opened device: {device}')
                break
            self.cap.release()

        if self.cap is None or not self.cap.isOpened():
            self.get_logger().error('Failed to open ZED camera')
            return

        # Set camera properties - use 1344x376 which is known to work
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1344)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 376)
        self.cap.set(cv2.CAP_PROP_FPS, 30)

        # Verify settings
        actual_width = self.cap.get(cv2.CAP_PROP_FRAME_WIDTH)
        actual_height = self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
        actual_fps = self.cap.get(cv2.CAP_PROP_FPS)

        self.get_logger().info(f'ZED Camera opened: {int(actual_width)}x{int(actual_height)} @ {actual_fps}fps')

        # Timer for publishing at 30Hz
        self.timer = self.create_timer(1.0 / 30.0, self.timer_callback)
        self.frame_count = 0

    def timer_callback(self):
        ret, frame = self.cap.read()

        if not ret:
            self.get_logger().warn('Failed to read frame from ZED')
            return

        # ZED outputs side-by-side stereo (width is ~2x normal)
        # Extract left camera only (first half)
        height, width = frame.shape[:2]

        # Check if this is side-by-side stereo (width > height * 2)
        if width > height * 2:
            # Side-by-side stereo - take left half
            left_image = frame[:, :width//2]
        else:
            # Already single camera or unexpected format - use as-is
            left_image = frame

        # Resize to 640x480 for consistency with RealSense cameras
        left_image = cv2.resize(left_image, (640, 480), interpolation=cv2.INTER_AREA)

        # Convert BGR to RGB
        rgb_image = cv2.cvtColor(left_image, cv2.COLOR_BGR2RGB)

        # Create ROS Image message
        msg = self.bridge.cv2_to_imgmsg(rgb_image, encoding='rgb8')
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'camera_0_link'

        # Publish
        self.publisher.publish(msg)

        self.frame_count += 1
        if self.frame_count % 300 == 0:  # Log every 10 seconds
            self.get_logger().info(f'Published {self.frame_count} frames')

    def destroy_node(self):
        if hasattr(self, 'cap') and self.cap.isOpened():
            self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ZEDCameraPublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
