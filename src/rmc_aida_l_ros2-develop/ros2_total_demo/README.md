## **一.项目介绍**
ros2_total_demo是对双臂复合机器人封装的总体测试。包括相机、升降机、双臂、头部舵机

## **二.文件结构**
```bash
├── CMakeLists.txt
├── include
│   └── ros2_total_demo
├── launch
│   └── total_demo.launch.py
├── package.xml
├── scripts
│   ├── camera_0.py
│   ├── camera_1.py
│   ├── realsense_camera_0.py
│   ├── realsense_camera_1.py
│   └── realsense_camera_2.py
└── src
    ├── camera.cpp
    ├── dual_arm.cpp
    └── total_demo_node.cpp
```

## **三.编译方法**
```bash
cd rmc_aida_l_ros2/     # 进入工作空间目录
colcon build --packages-select ros2_total_demo
```

## **四.运行指令**

- 1.启动整体ros2功能包的launch

```bash
cd rm_dual_arm_robot_ros2/ 
source install/setup.bash                                  # 重新加载下工作空间环境变量
ros2 launch ros2_total_demo total_demo.launch.py           # 双臂、头部舵机驱动、相机
```

- 2.启动功能包功能的使用案例：

```bash
ros2 run ros2_total_demo total_demo_node                   # 启动总体demo
```

