## **一.项目介绍**
ros2_agv_robot是对具身双臂机器人的ros2底盘封装。实现的功能有：

1. 请求机器人信息
2. 订阅机器人信息
3. 订阅机器人状态
4. 订阅模式信息
5. 订阅位姿速度
6. 订阅电池信息
7. 订阅场景信息
8. 订阅任务进度
9. 订阅设备状态
10. 订阅运行状态
11. 任务执行
12. 等待任务执行结果
13. 任务执行请求
14. 任务执行过程回调
15. 执行预定义任务
16. 步进过程回调
17. 步进执行请求
18. 等待步进执行结果

还有对各个功能的demo测试案例



## **二.文件结构**
```bash
├── ros2_agv_robot           # 底盘功能包
│   ├── CMakeLists.txt       # 编译规则文件
│   ├── lib                  # ros2接口安装包
│   ├── package.xml          # 定义功能包属性文件
│   └── src                  # 测试代码目录

## **三.编译方法**
1.安装底盘ros2接口安装包
cd ~/ros2_agv_robot/lib
sudo ./ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run
2.编译测试demo
```bash
cd ros2_ws/     # 进入工作空间目录
colcon build --packages-select ros2_agv_robot
```

## **四.运行指令**
- 1.启动底盘连接节点

```bash
ros2 run woosh_robot_agent agent --ros-args -r __ns:=/woosh_robot -p ip:="169.254.128.2"
或者
ros2 run woosh_robot_agent agent --ros-args -r __ns:=/woosh_robot
```

- 2.启动功能包功能的使用案例：

```bash
ros2 run ros2_agv_robot monitor  				          	        # 执行monitor节点获取机器人信息
ros2 run ros2_agv_robot exectask --ros-args -p mark_no:=7613B5D     # 到达某个存储位(7613B5D），需要提前创建地图，机器人初始化,创建好存储位后执行
ros2 run ros2_agv_robot exec_pre_task --ros-args -p id:=1735291765  # 执行任务(1735291765)，提前创建好地图，机器人初始化,创建好任务后执行
ros2 run ros2_agv_robot stepctrl                                    # 步进控制
```