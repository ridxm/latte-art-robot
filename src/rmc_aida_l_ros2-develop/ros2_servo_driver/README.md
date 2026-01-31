## **一.项目介绍**
ros2_servo_driver是对双臂复合机器人的ros2头部舵机封装。实现的功能有：

1. 串口控制头部舵机
1. 实时获取舵机角度

还有对各个功能的demo测试案例

## **二.文件结构**
```bash
├── servo_driver            # 舵机驱动功能包
│   ├── CMakeLists.txt
│   ├── include
│   ├── launch
│   ├── scripts             # 存放udev脚本
│   ├── package.xml
│   └── src
├── servo_example           # 示例功能包
│   ├── CMakeLists.txt
│   ├── include
│   ├── package.xml
│   └── src
└── servo_interfaces        # 舵机消息功能包
    ├── CMakeLists.txt
    ├── include
    ├── msg
    ├── package.xml
    └── src
```

## **三.编译方法**
```bash
cd rm_dual_arm_robot_ros2/ros2_servo_driver/servo_driver/scripts
# 执行udev脚本 执行完毕之后重启设备
sudo bash servo_udev.sh
# 进入工作空间目录
cd rm_dual_arm_robot_ros2/     
colcon build --packages-select servo_interfaces servo_driver servo_example 
```

## **四.运行指令**

- 1.启动整体ros2功能包的launch

```bash
cd rm_dual_arm_robot_ros2/ 
source install/setup.bash                                # 重新加载下工作空间环境变量
ros2 launch servo_driver servo_start.launch.py           # 启动舵机驱动
```

- 2.启动功能包功能的使用案例：

```bash
ros2 run servo_example send_control_cmd_demo              # 控制舵机
ros2 run servo_example get_servo_angle_demo               # 实时获取舵机角度
```

