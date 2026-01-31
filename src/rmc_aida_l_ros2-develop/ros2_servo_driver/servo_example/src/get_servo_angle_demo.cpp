// Copyright RealMan
// License(BSD/GPL/...)
// Author: Starry

// 实时获取舵机角度

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "servo_interfaces/msg/servo_get_angle.hpp"

using std::placeholders::_1;

// 自定义节点类
class GetServoAngle : public rclcpp::Node
{
public:
  GetServoAngle() : Node("servo_angle_node")
  {
    // 创建订阅方，并绑定回调函数
    sub_ = this->create_subscription<std_msgs::msg::Int64>("/servo_angle", 10,
                                                           std::bind(&GetServoAngle::callback, this, _1));
    pub_ = this->create_publisher<servo_interfaces::msg::ServoGetAngle>("/servo_control/get_angle",10);

  }

  void publish_msg_1()
  {
    rclcpp::sleep_for(std::chrono::milliseconds(300));
    auto msg = servo_interfaces::msg::ServoGetAngle();
    msg.servo_id = 1;
    pub_->publish(msg);
    rclcpp::sleep_for(std::chrono::milliseconds(300));
    msg.servo_id = 2;
    pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "servo id: %d", msg.servo_id);
  }
private:
  // 打印订阅到的消息。
  void callback(const std_msgs::msg::Int64::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "servo angle: %d", msg->data);
  }
  rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr sub_;   // 声明订阅器
  rclcpp::Publisher<servo_interfaces::msg::ServoGetAngle>::SharedPtr pub_; 
};

int main(int argc, char *argv[])
{
  // 初始化 ROS2 客户端
  rclcpp::init(argc, argv);
  // 调用spin函数，并传入节点对象指针
  auto node = std::make_shared<GetServoAngle>();
  node->publish_msg_1();
  rclcpp::spin(node);
  // 释放资源
  rclcpp::shutdown();
  return 0;
}