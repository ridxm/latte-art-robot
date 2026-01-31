<div align="left">

[中文简体](./README_CN.md)|
[English](./README.md)

# rmc_aida_l_ros2

<img src="./pic/dual_lift_robot.png" alt="pic" style="zoom:50%;" />

This package primarily provides ROS2 support for the RM dual-arm composite lifting robot. Below are the requirements.

* The supported robotic arm controller version is 1.6.5 or above.
* The Ubuntu version is 20.04.
* The ROS2 version is foxy.

| 具身双臂升降机器人（7轴）                                        |                                                     |                                                              |
| ------------------------------------------------------------ | --------------------------------------------------- | ------------------------------------------------------------ |
| 部件名称                                                     | 硬件版本信息                                        | 软件版本信息                                                 |
| 机械臂                                                       | RM75-B                                              | 控制器V1.6.5及以上，API V4.2.8及以上，ROS2功能包V1.0.1      |
| 相机                                                         | Realsense D435C                                     | ros2_realsense2                                              |
| 主控                                                         | jetson xavier NX                                    | ubuntu20.04 、ros-foxy                                       |
| 底盘                                                         | woosh                                               | API版本0.10.8，socket通信                                    |
| 头部电机/升降机                                              | WHJ30-80关节                                        | 作为机械臂的扩展轴使用，头部关节连接在右臂上作为扩展关节，升降连接在左臂上作为扩展关节 |
| 末端工具（可选）                                             | EG2-4C2夹爪/灵巧手（右手RM56DFX-2R/左手RM56DFX-2L） | 与机械臂API和ROS包集成                                       |
| 语音模块                                                     | 轮趣 M240麦克风阵列                                 | 语音模块资料V5.1（https://pan.baidu.com/e/1nVS8SXqZWn5scmidNqWb7w?_at_=1724069216106） |
| 更多信息参考：https://develop.realman-robotics.com/robot/versionComparisonTable.html ROS包下载：https://github.com/RealManRobot |                                                     |                                                              |

If the robot arm is RM65-B, set [ros2_rm_robot/dual_rm_driver/config/dual_left_config.yaml](./ros2_rm_robot/dual_rm_driver/config/dual_left_config.yaml) and [ros2_rm_robot/dual_rm_ driver/config/dual_right_config.yaml](./ros2_rm_robot/dual_rm_driver/config/dual_right_config.yaml) arm_type, arm_dof parameter 7 is changed to 6, and the arm_joints parameter joint7 is deleted.

For more information about the bot topic service function, see[具身双臂升降ROS2话题服务功能列表](./具身双臂升降ROS2话题服务功能列表.md)|

The following is the installation and use tutorial of the package.

## 1\. Build the environment
---
Before using the package, we first need to do the following operations.

* 1.[Install ROS2](#1.Install_ROS2)
* 2.[Install Moveit2](#Install_Moveit2)
* 3.[Configure the package environment](#Configure_the_package_environment)
* 4.[Compile](#Compile)

### 1.Install_ROS2

----

We provide the installation script for ROS2, `ros2_install.sh`, which is located in the `scripts` folder of the `ros2_rm_robot\dual_rm_install` package. In practice, we need to move to the path and execute the following commands.

```bash
sudo bash ros2_install.sh
```

If you do not want to use the script installation, you can also refer to the website [ROS2_INSTALL](https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html).

### Install_Moveit2

----

We provide the installation script for Moveit2, `moveit2_install.sh`, which is located in the `scripts` folder of the `ros2_rm_robot\dual_rm_install` package. In practice, we need to move to the path and execute the following commands.

```bash
sudo bash moveit2_install.sh
```

If you do not want to use the script installation, you can also refer to the website [Moveit2_INSTALL](https://moveit.ros.org/install-moveit2/binary/).

### Configure_the_package_environment

----

This script is located in the `lib` folder of the` ros2_rm_robot\dual_rm_driver` package. In practice, we need to move to the path and execute the following commands.

```bash
sudo bash lib_install.sh
```

----

Install chassis Ros2 interface installation package
Execute in the path of~/ros_2agv_robot/lib
```bash
sudo ./ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run
```

### Compile

----

After the above execution is successful, execute the following commands to compile the package. First, we need to build a workspace and import the package file into the `src` folder under the workspace, and then use the `colcon build` command to compile.

```bash
mkdir -p ~/ros2_ws/src
cp -r rm_dual_arm_lifting_robot_ros2 ~/ros2_ws/src
cd ~/ros2_ws
colcon build --packages-select rm_ros_interfaces
colcon build --packages-select realsense2_camera_msgs
source ./install/setup.bash
colcon build
```

<img src="./pic/success.png" alt="pic" style="zoom:50%;" />

After the compilation is completed, the package can be run.

For more MoveIt configuration information, see[具身双臂升降ROS2-foxy-moveit2配置教程](./双臂复合升降ROS2-foxy-moveit2配置教程.pdf)|

## 2\. Function running

---

Introduction to the package: The package includes example control of the dual-arm composite lifting robot in ROS2, allowing users to perform ROS2 operations on the dual-arm composite lifting robot. For ease of portability, each part of the dual-arm composite lifting robot is separately split into independent packages, facilitating the reuse and assembly of the packages.

**Note:** The lifting module for the dual-arm lifting is connected to the lifting mechanism of the left arm, and the head rotation is connected to the expansion joint of the right arm.

### 2.1  Demos for Various Components

#### 2.1.1 AGV Demo

#### 2.1.2 Camera Demo

The camera demo is located in the ros2_realsense2 folder, and the realsense2_camera camera node needs to be started first during the demo package (rm_camera_demo) test, and the command is as follows:

```bash
source ~/ros2_ws/install/setup.bash
ros2 launch realsense2_camera rs_launch.py 
```

Note: The original camera node start command is ros2 launch realsense2_camera rs_launch.py, if you need to use depth alignment RGB images, you need to add parameters to get the aligned image topic.

To start the demo visualizing D435 images, use the following command.

```bash
ros2 run rm_camera_demo sub_image_node
```

<img src="./pic/camera_demo.png" alt="pic" style="zoom:50%;" />

Start the demo to get the coordinate value of the center point of the image, and run the following command:

```bash
ros2 run rm_camera_demo Center_Coordinate_node
```

If you want to view the point cloud information of the camera, you can use the demo example provided with the camera driver package with the following command.

```bash
source ~/ros2_ws/install/setup.bash
ros2 launch realsense2_camera demo_pointcloud_launch.py
```

open the first rgb camera
```bash
source ~/ros2_ws/install/setup.bash
ros2 run rm_camera_demo camera_0_node 
```

Open the second rgb camera
```bash
source ~/ros2_ws/install/setup.bash
ros2 run rm_camera_demo camera_1_node 
```

Open the realsense depth camera, and the program will detect all realsense cameras. You can open the specified camera by selecting the device number
```bash
source ~/ros2_ws/install/setup.bash
ros2 run rm_camera_demo open_realsense_node 
```

#### 2.1.3 Voice Module Demo

#### 2.1.4 Overall Linkage Demo

1. Test Demo

start driver

```
source ~/ros2_ws/install/setup.bash
ros2 launch ros2_total_demo total_demo.launch.py
```

start demo node

```
source ~/ros2_ws/install/setup.bash
ros2 run ros2_total_demo total_demo_node
```

2.camera catch Demo（obj bottle）

start driver

```
source ~/ros2_ws/install/setup.bash
ros2 launch ros2_total_demo start.launch.py
```

note：executing the camera node（ros2_total_demo/scripts detect_object.py）will print serial_number，please fill in the correct serial number in the code and compile it for execution

start the visual capture program（遨意灵巧手）

```
source ~/ros2_ws/install/setup.bash
ros2 run ros2_total_demo catch2object_aoyi_hand.py
```

or

start the visual capture program（两指夹爪）

```
source ~/ros2_ws/install/setup.bash
ros2 run ros2_total_demo catch2object_gripper.py
```

Note: The test demo and visual grasping demo cannot be launched simultaneously. The execution script should be selected based on the end effector of the robot

### Safety Tips

----

Please refer to the following operation specifications when using the robotic arm to ensure the user's safety.

* Check the installation of the robotic arm before each use, including whether the mounting screw is loose and whether the robotic arm is vibrating or trembling.
* During the running of the robotic arm, no person shall be in the falling or working range of the robotic arm, nor shall any other object be placed in the robot arm's safety range.
* Place the robotic arm in a safe location when not in use to avoid it from falling down and damaging or injuring other objects during vibration.
* Disconnect the robotic arm from the power supply in time when not in use.

### Version update

| 修订版本                  | 内容更新                                                                       | 生效日期                       |
| ------------------------ | ------------------------------------------------------------------------------ | ----------------------------- |
| V1.0                     |  首次提交代码                                                                   | 2024-11-11                   |
| V1.1                     |  1.修改了driver无法上报UDP信息BUG 2.增加了机械臂gazebo仿真功能                   | 2024-11-25                    |
| V1.1.1 | 1.完善了整体联动demo 2.修改了urdf中左手安装方向bug 3.优化了相机代码 | 2024-12-12 |
| V1.1.2 | 1.增加了视觉抓取Demo | 2024-12-24 |
| V1.1.3 | 1.增加了悟时底盘功能包 | 2025-01-02 |

### Common problem
1. exec:sudo bash ros2_install.sh
error：invalid option line 7: set: -
solution： dos2unix ros2_install.sh
