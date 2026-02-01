#!/usr/bin/env python3
"""Show ROS2 camera image topics in a tiled OpenCV window.

Usage examples:
  python3 show_cameras.py                      # auto-detect image topics and display (GUI mode)
  python3 show_cameras.py --headless           # print frame info to console (no display needed)
  python3 show_cameras.py --topics /cam_0 /cam_1 /cam_2  # specify topics explicitly
  python3 show_cameras.py --topics /cam_0 /cam_1 --headless  # explicit topics in headless mode

Controls (GUI mode):
  q - quit

Headless mode:
  Prints camera status every 2 seconds showing which feeds are active
  Press Ctrl+C to quit
"""
import argparse
import math
import time
from typing import Dict, List

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node

IMAGE_W = 320
IMAGE_H = 240


class CameraViewer(Node):
    def __init__(self, topics: List[str] = None):
        super().__init__('camera_viewer')
        self.bridge = CvBridge()
        self.topics = topics or []
        self._subscriptions = []
        self.latest_frames: Dict[str, np.ndarray] = {}

        # If no topics provided, discover image topics
        if not self.topics:
            self.topics = self._discover_image_topics()

        if not self.topics:
            self.get_logger().warn('No image topics found. Exiting.')
            return

        self.get_logger().info(f'Subscribing to {len(self.topics)} topics')
        for t in self.topics:
            try:
                sub = self.create_subscription(
                    rclpy.qos.QoSProfile(depth=1).get_message_type(),
                    t,
                    lambda msg, topic=t: self._image_callback(msg, topic),
                    10,
                )
            except Exception:
                # Fallback to dynamic subscription via sensor_msgs/Image import
                from sensor_msgs.msg import Image

                sub = self.create_subscription(Image, t, lambda msg, topic=t: self._image_callback(msg, topic), 10)

            self._subscriptions.append(sub)

    def _discover_image_topics(self) -> List[str]:
        """Return a list of candidate image topics (sensor_msgs/msg/Image)."""
        topics_and_types = self.get_topic_names_and_types()
        image_type = 'sensor_msgs/msg/Image'
        candidates = []
        for name, types in topics_and_types:
            if image_type in types:
                # Prefer camera/color topics
                if 'color' in name or 'image_raw' in name or 'camera' in name:
                    candidates.append(name)
        # Sort for deterministic ordering
        candidates.sort()
        return candidates

    def _image_callback(self, msg, topic: str):
        try:
            cv_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='rgb8')
        except Exception:
            # fallback to passthrough
            try:
                cv_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
                if cv_img.ndim == 3 and cv_img.shape[2] == 3:
                    cv_img = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
            except Exception as e:
                self.get_logger().error(f'Failed converting image from {topic}: {e}')
                return

        # Resize for tiled display
        frame = cv2.resize(cv_img, (IMAGE_W, IMAGE_H), interpolation=cv2.INTER_AREA)
        self.latest_frames[topic] = frame

    def get_frames_list(self) -> List[np.ndarray]:
        # Return frames in topic order, fill missing with black images
        frames = []
        for t in self.topics:
            if t in self.latest_frames:
                frames.append(self.latest_frames[t])
            else:
                frames.append(np.zeros((IMAGE_H, IMAGE_W, 3), dtype=np.uint8))
        return frames


def tile_images(images: List[np.ndarray]) -> np.ndarray:
    if not images:
        return np.zeros((IMAGE_H, IMAGE_W, 3), dtype=np.uint8)

    n = len(images)
    cols = math.ceil(math.sqrt(n))
    rows = math.ceil(n / cols)

    # Pad images with black frames if needed
    pad = cols * rows - n
    if pad > 0:
        black = np.zeros_like(images[0])
        images = images + [black] * pad

    rows_imgs = []
    for r in range(rows):
        row_imgs = images[r * cols:(r + 1) * cols]
        rows_imgs.append(np.hstack(row_imgs))

    tiled = np.vstack(rows_imgs)
    return tiled


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--topics', nargs='*', help='List of image topics to display')
    parser.add_argument('--headless', action='store_true', help='Run in headless mode (print frame info instead of displaying)')
    args = parser.parse_args()

    rclpy.init()
    node = CameraViewer(args.topics)
    if not node.topics:
        rclpy.shutdown()
        return

    print(f"\n✓ Detected {len(node.topics)} camera topic(s):")
    for i, t in enumerate(node.topics):
        print(f"  [{i}] {t}")
    print()

    if args.headless:
        # Headless mode - just print frame info
        print("Running in headless mode (no display). Streaming frame info...\n")
        frame_count = 0
        last_print_time = time.time()
        
        try:
            while rclpy.ok():
                rclpy.spin_once(node, timeout_sec=0.05)
                frames = node.get_frames_list()
                frame_count += 1
                
                # Print status every 2 seconds
                current_time = time.time()
                if current_time - last_print_time >= 2.0:
                    print(f"[{frame_count} frames] Receiving from {len([f for f in frames if f is not None and f.sum() > 0])} camera(s)")
                    for i, (t, frame) in enumerate(zip(node.topics, frames)):
                        if frame is not None and frame.sum() > 0:
                            print(f"  ✓ {t}: shape={frame.shape}, min={frame.min()}, max={frame.max()}")
                        else:
                            print(f"  ✗ {t}: no data yet")
                    last_print_time = current_time
                
                time.sleep(0.01)
        except KeyboardInterrupt:
            pass
    else:
        # GUI mode with display
        window_name = 'Camera Viewer'
        try:
            cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)
        except cv2.error as e:
            print(f"Display not available: {e}")
            print("Run with --headless mode instead:")
            print(f"  python3 {__file__} --headless")
            node.destroy_node()
            rclpy.shutdown()
            return

        try:
            while rclpy.ok():
                # Allow ROS to process callbacks
                rclpy.spin_once(node, timeout_sec=0.05)

                frames = node.get_frames_list()
                tiled = tile_images(frames)

                # convert RGB->BGR for OpenCV display
                try:
                    disp = cv2.cvtColor(tiled, cv2.COLOR_RGB2BGR)
                except Exception:
                    disp = tiled

                cv2.imshow(window_name, disp)
                key = cv2.waitKey(1) & 0xFF
                if key == ord('q'):
                    break
                time.sleep(0.01)

        except KeyboardInterrupt:
            pass
        finally:
            cv2.destroyAllWindows()
    
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
