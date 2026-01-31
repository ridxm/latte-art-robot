#include "rclcpp/rclcpp.hpp"
#include "woosh_robot_msgs/msg/battery.hpp"
#include "woosh_robot_msgs/msg/device_state.hpp"
#include "woosh_robot_msgs/msg/device_state_hardware_bit.hpp"
#include "woosh_robot_msgs/msg/device_state_software_bit.hpp"
#include "woosh_robot_msgs/msg/mode.hpp"
#include "woosh_robot_msgs/msg/operation_state.hpp"
#include "woosh_robot_msgs/msg/operation_state_nav_bit.hpp"
#include "woosh_robot_msgs/msg/operation_state_robot_bit.hpp"
#include "woosh_robot_msgs/msg/pose_speed.hpp"
#include "woosh_robot_msgs/msg/robot_state.hpp"
#include "woosh_robot_msgs/msg/scene.hpp"
#include "woosh_robot_msgs/msg/task_proc.hpp"
#include "woosh_robot_msgs/srv/robot_info.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  /// ros run woosh_robot_demo monitor
  auto node = rclcpp::Node::make_shared("monitor");

  woosh_robot_msgs::msg::RobotInfo robot_info;

  // clang-format off
  /// ros2 cli command:
  /// ros2 service call /woosh_robot/robot/RobotInfo woosh_robot_msgs/srv/RobotInfo
  // clang-format on
  // 1. 请求机器人信息
  RCLCPP_INFO(node->get_logger(), "\n\n----------- call service -----------\n");
  auto rinfo_cli = node->create_client<woosh_robot_msgs::srv::RobotInfo>(
      "woosh_robot/robot/RobotInfo");
  while (not rinfo_cli->wait_for_service(std::chrono::seconds(1))) {
    if (not rclcpp::ok()) {
      RCLCPP_ERROR(node->get_logger(), "Waiting for service exception!");
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "Waiting for the service to appear...");
  }
  auto rinfo_req =
      std::make_shared<woosh_robot_msgs::srv::RobotInfo::Request>();
  auto rinfo_future = rinfo_cli->async_send_request(rinfo_req);
  if (rclcpp::spin_until_future_complete(node, rinfo_future) !=
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_ERROR(node->get_logger(), "Requesting robot information failed!");
    // rinfo_cli->remove_pending_request(rinfo_future);
    return 1;
  }
  auto rinfo_ret = rinfo_future.get();
  robot_info = rinfo_ret->info;
  RCLCPP_INFO(node->get_logger(), "Requesting robot information successfully.");
  RCLCPP_INFO(node->get_logger(), "Robot name: %s, ID: %d",
              robot_info.genral.display_model.c_str(),
              robot_info.genral.serial_number);
  RCLCPP_INFO(node->get_logger(), "Robot status: %d", robot_info.state.value);
  RCLCPP_INFO(node->get_logger(), "Robot control mode: %d, Working mode: %d",
              robot_info.mode.ctrl.value, robot_info.mode.work.value);
  RCLCPP_INFO(
      node->get_logger(),
      "Robot position, [x:%f, y:%f, theta:%f], [linear:%f, angular:%f], 累计里程: "
      "%d",
      robot_info.pose_speed.pose.x, robot_info.pose_speed.pose.y,
      robot_info.pose_speed.pose.theta, robot_info.pose_speed.twist.linear,
      robot_info.pose_speed.twist.angular, robot_info.pose_speed.mileage);
  RCLCPP_INFO(node->get_logger(), "Robot charging status: %d, Battery level: %d",
              robot_info.battery.charge_state.value, robot_info.battery.power);
  RCLCPP_INFO(node->get_logger(), "Map of the robot: %s, Map version: %ld",
              robot_info.scene.map_name.c_str(), robot_info.scene.version);
  RCLCPP_INFO(node->get_logger(),
              "Robot mission destination: %s, action: %d, Action status: %d, Task status: %d",
              robot_info.task_proc.dest.c_str(),
              robot_info.task_proc.action.type.value,
              robot_info.task_proc.action.state.value,
              robot_info.task_proc.state.value);
  RCLCPP_INFO(node->get_logger(), "Robot device status hardware: %d, software: %d",
              robot_info.device_state.hardware,
              robot_info.device_state.software);
  RCLCPP_INFO(node->get_logger(), "Robot running state nav: %d, robot: %d",
              robot_info.operation_state.nav, robot_info.operation_state.robot);

  // 2. Subscribe to robot information
  RCLCPP_INFO(node->get_logger(), "\n\n----------- subscription -----------\n");

  // qos transient local
  auto qos = rclcpp::QoS(rclcpp::KeepLast(1)).transient_local();

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/RobotState
  // 2.1 Subscribe to the bot status
  auto rstate_sub =
      node->create_subscription<woosh_robot_msgs::msg::RobotState>(
          "woosh_robot/robot/RobotState", qos,
          [&node,
           &robot_info](woosh_robot_msgs::msg::RobotState::UniquePtr state) {
            RCLCPP_INFO(node->get_logger(), "Robot status update: %d",
                        state->state.value);
            robot_info.state = state->state;
          });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/Mode
  // 2.2 Subscription mode information
  auto rmode_sub = node->create_subscription<woosh_robot_msgs::msg::Mode>(
      "woosh_robot/robot/Mode", qos,
      [&node, &robot_info](woosh_robot_msgs::msg::Mode::UniquePtr mode) {
        RCLCPP_INFO(node->get_logger(),
                    "机器人模式更新, 控制模式: %d, 工作模式: %d",
                    mode->ctrl.value, mode->work.value);
        robot_info.mode = *mode;
      });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/PoseSpeed
  // 2.3 订阅位姿速度
  auto rps_sub = node->create_subscription<woosh_robot_msgs::msg::PoseSpeed>(
      "woosh_robot/robot/PoseSpeed", qos,
      [&node, &robot_info](woosh_robot_msgs::msg::PoseSpeed::UniquePtr ps) {
        RCLCPP_INFO(node->get_logger(),
                    "机器人位姿速度更新, [x:%f, y:%f, theta:%f], [linear:%f, "
                    "angular:%f], 累计里程: %d",
                    ps->pose.x, ps->pose.y, ps->pose.theta, ps->twist.linear,
                    ps->twist.angular, ps->mileage);
        robot_info.pose_speed = *ps;
      });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/Battery
  // 2.4 Subscribe to battery information
  auto rbattery_sub = node->create_subscription<woosh_robot_msgs::msg::Battery>(
      "woosh_robot/robot/Battery", qos,
      [&node, &robot_info](woosh_robot_msgs::msg::Battery::UniquePtr battery) {
        RCLCPP_INFO(node->get_logger(),
                    "Robot power update, Charge status: %d, Battery level: %d",
                    battery->charge_state.value, battery->power);
        robot_info.battery = *battery;
      });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/Scene
  // 2.5 Subscribe to scene information
  auto rscene_sub = node->create_subscription<woosh_robot_msgs::msg::Scene>(
      "woosh_robot/robot/Scene", qos,
      [&node, &robot_info](woosh_robot_msgs::msg::Scene::UniquePtr scene) {
        RCLCPP_INFO(node->get_logger(),
                    "机器人场景更新, 所在地图: %s, 地图版本: %ld",
                    scene->map_name.c_str(), scene->version);
        robot_info.scene = *scene;
      });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/TaskProc
  // 2.5 Subscribe to task progress
  auto rtask_proc_sub =
      node->create_subscription<woosh_robot_msgs::msg::TaskProc>(
          "woosh_robot/robot/TaskProc", qos,
          [&node,
           &robot_info](woosh_robot_msgs::msg::TaskProc::UniquePtr task_proc) {
            RCLCPP_INFO(node->get_logger(),
                        "机器人任务进度更新, 目的地: %s, 动作: %d, 动作状态: "
                        "%d, 任务状态: %d",
                        task_proc->dest.c_str(), task_proc->action.type.value,
                        task_proc->action.state.value, task_proc->state.value);
            robot_info.task_proc = *task_proc;
            if (task_proc->state.value ==
                woosh_task_msgs::msg::State::K_COMPLETED) {
              RCLCPP_INFO(node->get_logger(), "任务完成.");
            }
          });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/DeviceState
  // 2.6 Subscribe to device status
  auto rdstate_sub =
      node->create_subscription<woosh_robot_msgs::msg::DeviceState>(
          "woosh_robot/robot/DeviceState", qos,
          [&node,
           &robot_info](woosh_robot_msgs::msg::DeviceState::UniquePtr dstate) {
            RCLCPP_INFO(node->get_logger(),
                        "机器人设备状态更新, hardware: %d, software: %d",
                        dstate->hardware, dstate->software);
            robot_info.device_state = *dstate;
            if (dstate->hardware &
                woosh_robot_msgs::msg::DeviceStateHardwareBit::K_EMG_BTN) {
              RCLCPP_INFO(node->get_logger(), "急停触发!");
            }
            if (dstate->software &
                woosh_robot_msgs::msg::DeviceStateSoftwareBit::K_LOCATION) {
              RCLCPP_INFO(node->get_logger(), "定位准确.");
            }
          });

  /// ros2 cli command:
  /// ros2 topic echo /woosh_robot/robot/OperationState
  // 2.7 Subscribe to run status
  auto rostate_sub =
      node->create_subscription<woosh_robot_msgs::msg::OperationState>(
          "woosh_robot/robot/OperationState", qos,
          [&node, &robot_info](
              woosh_robot_msgs::msg::OperationState::UniquePtr ostate) {
            RCLCPP_INFO(node->get_logger(),
                        "机器人运行状态更新, nav: %d, robot: %d", ostate->nav,
                        ostate->robot);
            robot_info.operation_state = *ostate;
            if (ostate->nav &
                woosh_robot_msgs::msg::OperationStateNavBit::K_IMPEDE) {
              RCLCPP_INFO(node->get_logger(), "遇到障碍物!");
            }
            if (ostate->robot &
                woosh_robot_msgs::msg::OperationStateRobotBit::K_TASKABLE) {
              RCLCPP_INFO(node->get_logger(), "可接任务.");
            }
          });

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
