// Copyright RealMan
// License(BSD/GPL/...)
// Author: Starry

#include "rclcpp/rclcpp.hpp"
#include "servo_interfaces/msg/servo_move.hpp"

class SendControlCmd : public rclcpp::Node
{
public:
  SendControlCmd() : Node("send_control_cmd_node")
  {
    RCLCPP_INFO(this->get_logger(), "send control servo cmd demo!");

    publisher_ = this->create_publisher<servo_interfaces::msg::ServoMove>("/servo_control/move", 1);

    // Create timer: call publish_msg() every 500 ms
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(300),
      std::bind(&SendControlCmd::publish_msg, this)
    );
  }

private:
  int horiz_angle = 0;
  int vert_angle = 0;

  void publish_msg()
  {
    auto msg = servo_interfaces::msg::ServoMove();

    msg.servo_id = 2;
    msg.angle = horiz_angle;
    RCLCPP_INFO(this->get_logger(), "send msg: servo_id = %d, angle = %d", msg.servo_id, msg.angle);
    publisher_->publish(msg);

    msg.servo_id = 1;
    msg.angle = vert_angle;
    RCLCPP_INFO(this->get_logger(), "send msg: servo_id = %d, angle = %d", msg.servo_id, msg.angle);
    publisher_->publish(msg);

    // Increment angles
    horiz_angle += 100;
    vert_angle += 100;

    if (horiz_angle > 1000) horiz_angle = 0;
    if (vert_angle > 1000) vert_angle = 0;
  }

  rclcpp::Publisher<servo_interfaces::msg::ServoMove>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SendControlCmd>());
  rclcpp::shutdown();
  return 0;
}


// // Copyright RealMan
// // License(BSD/GPL/...)
// // Author: Starry

// // 通过话题/servo_control/move控制头部舵机转动响应的角度  舵机1可设置范围400-600 舵机2可设置的范围200-800

// #include "rclcpp/rclcpp.hpp"
// #include "servo_interfaces/msg/servo_move.hpp"

// // 自定义节点类
// class SendControlCmd : public rclcpp::Node
// {
// public:
//   int horiz_angle = 0;
//   int vert_angle = 0;
//   SendControlCmd() : Node("send_control_cmd_node")
//   {
//     RCLCPP_INFO(this->get_logger(), "send control servo cmd  demo!");
//     // 创建舵机控制发布方
//     publisher_ = this->create_publisher<servo_interfaces::msg::ServoMove>("/servo_control/move", 1);
//   }

//   void publish_msg()
//   {
//     rclcpp::sleep_for(std::chrono::milliseconds(500));
//     auto msg = servo_interfaces::msg::ServoMove();
//     msg.servo_id = 2;     // 舵机ID
//     msg.angle = horiz_angle;      // 舵机角度
//     RCLCPP_INFO(this->get_logger(), "send msg: servo_id = %d,angle = %d", msg.servo_id, msg.angle);
//     // 发布消息
//     publisher_->publish(msg);

//     msg.servo_id = 1;     // 舵机ID
//     msg.angle = vert_angle;      // 舵机角度
//     RCLCPP_INFO(this->get_logger(), "send msg: servo_id = %d,angle = %d", msg.servo_id, msg.angle);
//     // 发布消息
//     publisher_->publish(msg);

//     if (horiz_angle == 1000){
//       horiz_angle = 0;
//     }
//     else {
//       horiz_angle += 100;
//     }
//     if (vert_angle == 1000){
//       vert_angle = 0;
//     }
//     else {
//       vert_angle += 100;
//     }


//   }

// private:
//   // 声明舵机控制发布器
//   rclcpp::Publisher<servo_interfaces::msg::ServoMove>::SharedPtr publisher_; 
// };

// int main(int argc, char *argv[])
// {
//   // 初始化 ROS2 客户端
//   rclcpp::init(argc, argv);
//   // Call the spin function and pass in the node object pointer
//   auto node = std::make_shared<SendControlCmd>();
//   node->publish_msg();
//   rclcpp::spin(node);
//   //Release resources
//   rclcpp::shutdown();
//   return 0;
// }