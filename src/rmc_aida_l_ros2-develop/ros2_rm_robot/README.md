## **一.项目介绍**
ros2_rm_robot是对具身双臂升降机器人的ros2双臂封装。实现的功能有：

目前测试：控制器版本是`1.6.5版本`

1. moveit2控制机械臂

还有对各个功能的demo测试案例

## **二.文件结构**
```bash
├── dual_rm_moveit_config        # 双臂升降Moveit配置功能包
│   ├── dual_rm_65b_moveit_config
│   └── dual_rm_75b_moveit_config
├── dual_rm_control                        # 双臂控制器功能包
│   ├── CMakeLists.txt
│   ├── doc                                # 存放资料文件
│   ├── include
│   ├── launch
│   ├── package.xml
│   ├── README_CN.md
│   ├── README.md
│   └── src
├── dual_rm_driver                         # 双臂驱动功能包
│   └── rm_driver  
│       ├── CMakeLists.txt
│       ├── config
│       ├── doc
│       ├── include
│       ├── launch
│       ├── lib                            # 存放库文件
│       ├── package.xml
│       └── src
├── dual_rm_description           # 双臂机器人描述功能包
│   ├── CMakeLists.txt
│   ├── config
│   ├── launch
│   ├── meshes                             # 存放模型meshes文件
│   ├── package.xml
│   ├── README_CN.md
│   ├── README.md
│   └── urdf                               # 存放urdf文件
├── dual_rm_install                        # 安装依赖功能包
│   ├── CMakeLists.txt
│   ├── doc
│   ├── package.xml
│   └── scripts                            # 存放脚本文件
└── dual_rm_ros2_interfaces
    └── rm_ros_interfaces
        ├── CMakeLists.txt
        ├── msg                            # 存放msg文件
        ├── package.xml
        ├── README_CN.md
        └── README.md
```

## **三.编译方法**
```bash
cd rm_dual_arm_robot_ros2/     # 进入工作空间目录
colcon build --packages-select rm_ros_interfaces dual_rm_65b_description dual_rm_75b_description rm_driver dual_rm_control dual_rm_65b_moveit_config dual_rm_75b_moveit_config  
```

## **四.运行指令**

```

Moveit2控制

- 启动整体的ros2功能包launch

​```bash
cd rmc_aida_l_ros2/ 
source install/setup.bash                              # 重新加载下工作空间环境变量
ros2 launch dual_rm_65b_moveit_config demo.launch.py   # 启动Moveit控制
```

拖动rviz2中的末端点击规划和执行，机械臂能够正常规划。

Moveit  C++ API控制

```sh
# 关节控制(启动moveit控制真实的机械臂之后启动以下程序)
ros2 launch dual_rm_moveit_demo rm_65_moveit2_fk.launch.py
# 笛卡尔空间控制
ros2 launch dual_rm_moveit_demo rm_65_moveit2_ik.launch.py
```

Gazebo仿真 (65b)

cd rm_dual_arm_robot_ros2/ 
source install/setup.bash                                         # 重新加载下工作空间环境变量
ros2 launch dual_rm_gazebo dual_rm_65b_gazebo.launch.py           # 启动gazebo仿真环境并加载机器人模型
ros2 launch dual_rm_65b_moveit_config demo.launch.py              # 启动Moveit控制仿真机械臂


Gazebo仿真 (75b)

cd rm_dual_arm_robot_ros2/ 
source install/setup.bash                                         # 重新加载下工作空间环境变量
ros2 launch dual_rm_gazebo dual_rm_75b_gazebo.launch.py           # 启动gazebo仿真环境并加载机器人模型
ros2 launch dual_rm_75b_moveit_config demo.launch.py              # 启动Moveit控制仿真机械臂

