//
// Created by ubuntu on 23-11-28.
//
#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <unistd.h>
#include <thread>
#include "rclcpp/rclcpp.hpp"
#include "rm_ros_interfaces/msg/movejp.hpp"
#include "rm_ros_interfaces/msg/cartepos.hpp"
#include "std_msgs/msg/bool.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

/****************************************创建类************************************/ 
class MoveJPDemo: public rclcpp::Node
{
  public:
    MoveJPDemo();                                                                                 //构造函数
    void movejp_demo();                                                                           //movejp运动规划函数
    void MoveJPDemo_Callback(const std_msgs::msg::Bool::SharedPtr msg);                                    //结果回调函数
  
  private:
    rclcpp::Publisher<rm_ros_interfaces::msg::Cartepos>::SharedPtr movejp_publisher_;               //声明发布器
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr movejp_subscription_;                    //声明订阅器
};


/******************************接收到订阅的机械臂执行状态消息后，会进入消息回调函数**************************/ 
void MoveJPDemo::MoveJPDemo_Callback(const std_msgs::msg::Bool::SharedPtr msg)
{
    // 将接收到的消息打印出来，显示是否执行成功
    if(msg->data)
    {
        RCLCPP_INFO (this->get_logger(),"*******MoveJP succeeded\n");
    } else {
        RCLCPP_INFO (this->get_logger(),"*******MoveJP Failed\n");
    }
}   
/***********************************************end**************************************************/

/*******************************************获取位姿函数****************************************/
void MoveJPDemo::movejp_demo()
{

  
    rm_ros_interfaces::msg::Cartepos moveJ_P_TargetPose;
    moveJ_P_TargetPose.pose.position.x = 0.3366649854183197;
    moveJ_P_TargetPose.pose.position.y = -0.23942899703979492;
    moveJ_P_TargetPose.pose.position.z = -0.04869299918413162;
    moveJ_P_TargetPose.pose.orientation.x = 2.5859999656677246;
    moveJ_P_TargetPose.pose.orientation.y = 0.04600000008940697;
    moveJ_P_TargetPose.pose.orientation.z = 1.2230000495910645;
    moveJ_P_TargetPose.pose.orientation.w = 1.0;
    // moveJ_P_TargetPose.speed = 50;
    // moveJ_P_TargetPose.block = false;
    moveJ_P_TargetPose.follow = true;
    
    rm_ros_interfaces::msg::Cartepos moveJ_P_TargetPose2;
    moveJ_P_TargetPose2.pose.position.x = 0.3566649854183197;
    moveJ_P_TargetPose2.pose.position.y = -0.25942899703979492;
    moveJ_P_TargetPose2.pose.position.z = -0.03869299918413162;
    moveJ_P_TargetPose2.pose.orientation.x = 2.5859999656677246;
    moveJ_P_TargetPose2.pose.orientation.y = 0.04600000008940697;
    moveJ_P_TargetPose2.pose.orientation.z = 1.2230000495910645;
    moveJ_P_TargetPose2.pose.orientation.w = 1.0;
    // moveJ_P_TargetPose2.speed = 50;
    // moveJ_P_TargetPose2.block = false;
    moveJ_P_TargetPose.follow = true;

    this->movejp_publisher_->publish(moveJ_P_TargetPose);
    this->movejp_publisher_->publish(moveJ_P_TargetPose2);
}
/***********************************************end**************************************************/

/***********************************构造函数，初始化发布器订阅器****************************************/
MoveJPDemo::MoveJPDemo():rclcpp::Node("Movejp_demo_node")
{

  movejp_subscription_ = this->create_subscription<std_msgs::msg::Bool>("/left_arm_controller/rm_driver/movej_p_result", rclcpp::ParametersQoS(), std::bind(&MoveJPDemo::MoveJPDemo_Callback, this,_1));
  movejp_publisher_ = this->create_publisher<rm_ros_interfaces::msg::Cartepos>("/left_arm_controller/rm_driver/movep_canfd_cmd", rclcpp::ParametersQoS());
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  movejp_demo();
}
/***********************************************end**************************************************/

/******************************************************主函数*********************************************/
int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MoveJPDemo>());
  rclcpp::shutdown();
  return 0;
}
