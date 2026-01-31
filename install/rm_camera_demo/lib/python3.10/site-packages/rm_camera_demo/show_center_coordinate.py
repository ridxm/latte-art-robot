#!/usr/bin/env python3

# // Copyright RealMan
# // License(BSD/GPL/...)
# // Author: Lamont
# // 整体demo完成对图像（640*480）中心像素点获取三维坐标。首先通过ROS订阅图像话题和相机参数话题，获取图像数据和相机内参，通过相机内参对齐深度图像和RGB图像，得到可靠的中心像素点深度，再根据内参和深度算出三维坐标，同时可视化深度图像并打印坐标。

import cv2
import pyrealsense2 as rs2
import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image as msg_Image
from sensor_msgs.msg import CameraInfo

 
class pic_pix:
    '''
    像素坐标选定
    '''
    def __init__(self):
        self.pix_x = 320
        self.pix_y = 240
 
class NodeSubscribe(Node):
    '''
    订阅相机图像话题和相机参数话题,通过相机内参对齐深度图像和RGB图像，得到可靠的中心像素点深度，再根据内参和深度算出三维坐标，同时可视化深度图像并打印坐标。
    '''
    def __init__(self,name):
        super().__init__(name)
        self.bridge = CvBridge()
        self.get_logger().info("这是RM的D435相机demo，利用深度对齐图像获取图像中心点坐标值（640*480），按下ctrl+c退出当前demo" )
        self.sub = self.create_subscription(msg_Image, '/camera/depth/image_rect_raw', self.imageDepthCallback, 10)            # 接收图像话题数据
        self.sub_info = self.create_subscription(CameraInfo, '/camera/depth/camera_info', self.imageDepthInfoCallback, 10)     # 接收相机参数话题数据
        self.intrinsics = None
        self.pix_grade = None
        self.pix = pic_pix()
    def imageDepthCallback(self, data):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, data.encoding)                                            # 图像格式转换，ROS话题格式转为CV格式
            print('******************************')
            if self.intrinsics:
                depth = cv_image[self.pix.pix_y, self.pix.pix_x]
                result = rs2.rs2_deproject_pixel_to_point(self.intrinsics, [self.pix.pix_x, self.pix.pix_y], depth)    # 计算像素点三维坐标
                print('图像中心点坐标值(mm):',result)
            cv2.imshow("aligned_depth_to_color_frame" , cv_image)
            key = cv2.waitKey(1)

        except CvBridgeError as e:
            print(e)
            return
        except ValueError as e:
            return

    def imageDepthInfoCallback(self, cameraInfo):
        try:
            if self.intrinsics:
                return
            self.intrinsics = rs2.intrinsics()
            self.intrinsics.width = cameraInfo.width
            self.intrinsics.height = cameraInfo.height
            self.intrinsics.ppx = cameraInfo.k[2]
            self.intrinsics.ppy = cameraInfo.k[5]
            self.intrinsics.fx = cameraInfo.k[0]
            self.intrinsics.fy = cameraInfo.k[4]
            if cameraInfo.distortion_model == 'plumb_bob':
                self.intrinsics.model = rs2.distortion.brown_conrady
            elif cameraInfo.distortion_model == 'equidistant':
                self.intrinsics.model = rs2.distortion.kannala_brandt4
            self.intrinsics.coeffs = [i for i in cameraInfo.d]
        except CvBridgeError as e:
            print(e)
            return
 
def main(args=None):
    rclpy.init()
    # 建立一个节点(Center_Coordinate_node)用来接受图像中心深度值数据
    node = NodeSubscribe("Center_Coordinate_node")
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
