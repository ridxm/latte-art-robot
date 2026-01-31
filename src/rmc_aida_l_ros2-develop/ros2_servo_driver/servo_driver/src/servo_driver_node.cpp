// Copyright RealMan
// License(BSD/GPL/...)
// Author: Starry

/*
  Servo Encapsulation:
1. Control the servo by sending data through the serial port.
2. Read the servo angle and publish it.
3. Servo 1 range: 400-600, Servo 2 range: 200-800.
*/

#include <iostream>
#include <serial/serial.h>
#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/int64.hpp>
#include "servo_interfaces/msg/servo_move.hpp"
#include "servo_interfaces/msg/servo_get_angle.hpp"

// 自定义节点类
class ServoController : public rclcpp::Node
{
public:
  ServoController() : Node("servo_controller"), s_buffer{}
  {
    this->declare_parameter("port","/dev/ttyUSB0");
    port_ = this->get_parameter("port").as_string();
    // RCLCPP_INFO(this->get_logger(), "port=%s",port_.c_str());

    // 尝试打开串口
    try
    {
      ros_ser.setPort(port_);             // 串口名    
      ros_ser.setBaudrate(9600);          // 波特率
      serial::Timeout to = serial::Timeout::simpleTimeout(1000);
      ros_ser.setTimeout(to);
      ros_ser.open();
    }
    // 捕捉异常
    catch (serial::IOException &e)
    {
      // 打印异常日志
      RCLCPP_ERROR(this->get_logger(), "Unable to open port ");
      rclcpp::shutdown();
      return;
    }

    if (ros_ser.isOpen())
    {
      // 打印打开成功串口日志
      RCLCPP_INFO(this->get_logger(), "Serial Port opened %s",port_.c_str());
    }
    else
    {
      // 打印打开串口失败日志
      RCLCPP_ERROR(this->get_logger(), "Failed to open Serial Port");
      rclcpp::shutdown();
      return;
    }

    // 创建控制订阅方
    sub_servo_move_ = this->create_subscription<servo_interfaces::msg::ServoMove>(
        "/servo_control/move", 10, std::bind(&ServoController::callback_servoMove, 
                                              this, std::placeholders::_1));
    // 创建获取舵机角度订阅方
    sub_servo_get_angle_ = this->create_subscription<servo_interfaces::msg::ServoGetAngle>(
        "/servo_control/get_angle", 10, std::bind(&ServoController::callback_servo_get_angle,
                                                  this, std::placeholders::_1));

    // 创建发布方
    pub_angle_ = this->create_publisher<std_msgs::msg::Int64>("/servo_angle", 10);

    // 创建定时器
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100), std::bind(&ServoController::readSerialData, this));
  }

private:
  static constexpr size_t sBUFFERSIZE = 10; // 发送 buffer size
  unsigned char s_buffer[sBUFFERSIZE];      // 发送 buffer
  std::string port_; 

// 发送串口数据回调函数
void callback_servoMove(const servo_interfaces::msg::ServoMove::SharedPtr msg){
    memset(s_buffer, 0, sizeof(s_buffer));
    s_buffer[0] = 0x55;
    s_buffer[1] = 0x55;
    s_buffer[2] = 0x08;
    s_buffer[3] = 0x03;
    s_buffer[4] = 0x01;
    s_buffer[5] = 0xe8;
    s_buffer[6] = 0x03;
    s_buffer[7] = msg->servo_id;
    s_buffer[8] = msg->angle & 0xFF;
    s_buffer[9] = (msg->angle >> 8) & 0xFF;
    ros_ser.write(s_buffer, sBUFFERSIZE);
    RCLCPP_INFO(this->get_logger(), "Control Servo Move");
}

// 舵机ID设置回调函数
void callback_servo_get_angle(const servo_interfaces::msg::ServoGetAngle::SharedPtr msg){
    memset(s_buffer, 0, sizeof(s_buffer));
    s_buffer[0] = 0x55;
    s_buffer[1] = 0x55;
    s_buffer[2] = 0x04;
    s_buffer[3] = 0x15;
    s_buffer[4] = 0x01;
    s_buffer[5] = msg->servo_id;
    ros_ser.write(s_buffer, 6);
    RCLCPP_INFO(this->get_logger(), "Get Servo Angle");
}

// 读取串口数据
void readSerialData(){
    size_t n = ros_ser.available();
    if (n != 0)
    {
      uint8_t buffer[1024];
      n = ros_ser.read(buffer, n);
      RCLCPP_INFO(this->get_logger(), "Reading from serial port");

      for (size_t i = 0; i < n; i++)
      {
        std::cout << std::hex << (buffer[i] & 0xff) << " ";
      }
      std::cout << std::endl;

      if (n >= 8)
      {
        unsigned char lowByte = buffer[6];
        unsigned char highByte = buffer[7];
        int result_angle = (highByte << 8) | lowByte;
        RCLCPP_INFO(this->get_logger(), "result_angle = %d", result_angle);

        auto msg = std_msgs::msg::Int64();
        msg.data = result_angle;
        pub_angle_->publish(msg);
      }
    }
  }
  serial::Serial ros_ser;                                                                       // 声明串口
  rclcpp::TimerBase::SharedPtr timer_;                                                          // 声明定时器
  rclcpp::Subscription<servo_interfaces::msg::ServoMove>::SharedPtr sub_servo_move_;            // 声明控制舵机订阅器
  rclcpp::Subscription<servo_interfaces::msg::ServoGetAngle>::SharedPtr sub_servo_get_angle_;   // 声明获取舵机实时角度订阅器
  rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr pub_angle_;                                // 声明实时发布角度发布器器
};

int main(int argc, char **argv)
{
  // 初始化ROS2 客户端
  rclcpp::init(argc, argv);
  // 传自定义节点指针
  auto node = std::make_shared<ServoController>();
  // spin循环
  rclcpp::spin(node);
  // 释放资源
  rclcpp::shutdown();
  return 0;
}
