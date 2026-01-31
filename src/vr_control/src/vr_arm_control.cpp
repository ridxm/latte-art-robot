//
// Created by ubuntu on 23-11-28.
//
#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <unistd.h>
#include <thread>
#include <numeric>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "rm_ros_interfaces/msg/movejp.hpp"
#include "rm_ros_interfaces/msg/cartepos.hpp"
#include "std_msgs/msg/bool.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "rm_ros_interfaces/msg/armstate.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "Eigen/Dense"
#include "Eigen/Geometry"
#include <iostream>
#include <array>

using namespace std::chrono_literals;
using std::placeholders::_1;



class VRArmControl : public rclcpp::Node
{
public:
  static constexpr double sphere_center_x = 0.0;
  static constexpr double sphere_center_y = 0.0;
  static constexpr double sphere_center_z = 0.0;
  static constexpr double sphere_radius = 580.0;

VRArmControl() : Node("vr_arm_control")
  {
    rclcpp::QoS qos(rclcpp::KeepLast(10));
    qos.reliable();
    get_current_state_left = this->create_subscription<rm_ros_interfaces::msg::Armstate>("/left_arm_controller/rm_driver/get_current_arm_state_result", 10, std::bind(&VRArmControl::GetCurrentStateLeft, this,_1));
    get_current_state_right = this->create_subscription<rm_ros_interfaces::msg::Armstate>("/right_arm_controller/rm_driver/get_current_arm_state_result", 10, std::bind(&VRArmControl::GetCurrentStateRight, this,_1));
    get_delta  = this->create_subscription<std_msgs::msg::Float32MultiArray>("/calculated_delta", rclcpp::ParametersQoS(), std::bind(&VRArmControl::GetDelta, this,_1));
    to_move_publisher_left = this->create_publisher<rm_ros_interfaces::msg::Cartepos>("/left_arm_controller/rm_driver/movep_canfd_cmd", qos);
    to_move_publisher_right = this->create_publisher<rm_ros_interfaces::msg::Cartepos>("/right_arm_controller/rm_driver/movep_canfd_cmd", qos);
    

    timer_ = create_wall_timer(0.0143s, std::bind(&VRArmControl::timerCallback, this));
    
  }




  void timerCallback()
  {

    rm_ros_interfaces::msg::Cartepos to_move_pose_left;
    double new_x_left = current_pose_left.position.x + delta_left[0] * 1.5;
    double new_y_left = current_pose_left.position.y + delta_left[1] * 1.5;
    double new_z_left = current_pose_left.position.z + delta_left[2] * 1.5;

    double dx_left = new_x_left - sphere_center_x;
    double dy_left = new_y_left - sphere_center_y;
    double dz_left = new_z_left - sphere_center_z;
    double dist_sq_left = dx_left * dx_left + dy_left * dy_left + dz_left * dz_left;
    double radius_sq = sphere_radius * sphere_radius;

    if (dist_sq_left > radius_sq) {
        double inv_dist = sphere_radius / sqrt(dist_sq_left);
        to_move_pose_left.pose.position.x = sphere_center_x + dx_left * inv_dist;
        to_move_pose_left.pose.position.y = sphere_center_y + dy_left * inv_dist;
        to_move_pose_left.pose.position.z = sphere_center_z + dz_left * inv_dist;
    } else {
        to_move_pose_left.pose.position.x = new_x_left;
        to_move_pose_left.pose.position.y = new_y_left;
        to_move_pose_left.pose.position.z = new_z_left;
    }

    to_move_pose_left.pose.orientation.x = (delta_left[3] != 0.0) ? delta_left[3] : current_pose_left.orientation.x;
    to_move_pose_left.pose.orientation.y = (delta_left[4] != 0.0) ? delta_left[4] : current_pose_left.orientation.y;
    to_move_pose_left.pose.orientation.z = (delta_left[5] != 0.0) ? delta_left[5] : current_pose_left.orientation.z;
    to_move_pose_left.pose.orientation.w = (delta_left[6] != 0.0) ? delta_left[6] : current_pose_left.orientation.w;
    to_move_pose_left.follow = false;

    rm_ros_interfaces::msg::Cartepos to_move_pose_right;
    double new_x_right = current_pose_right.position.x + delta_right[0] * 1.5;
    double new_y_right = current_pose_right.position.y + delta_right[1] * 1.5;
    double new_z_right = current_pose_right.position.z + delta_right[2] * 1.5;

    double dx_right = new_x_right - sphere_center_x;
    double dy_right = new_y_right - sphere_center_y;
    double dz_right = new_z_right - sphere_center_z;
    double dist_sq_right = dx_right * dx_right + dy_right * dy_right + dz_right * dz_right;

    if (dist_sq_right > radius_sq) {
        double inv_dist = sphere_radius / sqrt(dist_sq_right);
        to_move_pose_right.pose.position.x = sphere_center_x + dx_right * inv_dist;
        to_move_pose_right.pose.position.y = sphere_center_y + dy_right * inv_dist;
        to_move_pose_right.pose.position.z = sphere_center_z + dz_right * inv_dist;
    } else {
        to_move_pose_right.pose.position.x = new_x_right;
        to_move_pose_right.pose.position.y = new_y_right;
        to_move_pose_right.pose.position.z = new_z_right;
    }

    to_move_pose_right.pose.orientation.x = (delta_right[3] != 0.0) ? delta_right[3] : current_pose_right.orientation.x;
    to_move_pose_right.pose.orientation.y = (delta_right[4] != 0.0) ? delta_right[4] : current_pose_right.orientation.y;
    to_move_pose_right.pose.orientation.z = (delta_right[5] != 0.0) ? delta_right[5] : current_pose_right.orientation.z;
    to_move_pose_right.pose.orientation.w = (delta_right[6] != 0.0) ? delta_right[6] : current_pose_right.orientation.w;
    to_move_pose_right.follow = false;
 

    // RCLCPP_INFO_STREAM(this->get_logger(), 
    //   "To move left arm: position: [x = " << to_move_pose_left.pose.position.x 
    //   << ", y = " << to_move_pose_left.pose.position.y 
    //   << ", z = " << to_move_pose_left.pose.position.z 
    //   << "], orientation: [x = " << to_move_pose_left.pose.orientation.x 
    //   << ", y = " << to_move_pose_left.pose.orientation.y 
    //   << ", z = " << to_move_pose_left.pose.orientation.z 
    //   << ", w = " << to_move_pose_left.pose.orientation.w 
    //   << "], follow: " << to_move_pose_left.follow);

    // RCLCPP_INFO_STREAM(this->get_logger(), 
    //   "To move right arm: position: [x = " << to_move_pose_right.pose.position.x 
    //   << ", y = " << to_move_pose_right.pose.position.y 
    //   << ", z = " << to_move_pose_right.pose.position.z 
    //   << "], orientation: [x = " << to_move_pose_right.pose.orientation.x 
    //   << ", y = " << to_move_pose_right.pose.orientation.y 
    //   << ", z = " << to_move_pose_right.pose.orientation.z 
    //   << ", w = " << to_move_pose_right.pose.orientation.w 
    //   << "], follow: " << to_move_pose_right.follow);

      // if (std::accumulate(delta_left, delta_left + 7, 0) != 0) 
      // {
      //   to_move_publisher_left->publish(to_move_pose_left);
      // }
      // if (std::accumulate(delta_left, delta_left + 7, 0) != 0) 
      // {
      //   to_move_publisher_right->publish(to_move_pose_right);
      // }

      to_move_publisher_right->publish(to_move_pose_right);
      to_move_publisher_left->publish(to_move_pose_left);
    
    // pub_->publish(message);
  }

private:
  rclcpp::Subscription<rm_ros_interfaces::msg::Armstate>::SharedPtr get_current_state_left;
  rclcpp::Subscription<rm_ros_interfaces::msg::Armstate>::SharedPtr get_current_state_right;
  rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr get_delta;
  rclcpp::Publisher<rm_ros_interfaces::msg::Cartepos>::SharedPtr to_move_publisher_left;
  rclcpp::Publisher<rm_ros_interfaces::msg::Cartepos>::SharedPtr to_move_publisher_right;
  rclcpp::TimerBase::SharedPtr timer_;

  geometry_msgs::msg::Pose current_pose_left;
  geometry_msgs::msg::Pose current_pose_right;
  float delta_left[7] = {0.0f};
  float delta_right[7] = {0.0f};
  

  void GetCurrentStateLeft(const rm_ros_interfaces::msg::Armstate::SharedPtr msg);
  void GetCurrentStateRight(const rm_ros_interfaces::msg::Armstate::SharedPtr msg);
  void GetDelta(const std_msgs::msg::Float32MultiArray::SharedPtr msg);

};


void VRArmControl::GetCurrentStateLeft(const rm_ros_interfaces::msg::Armstate::SharedPtr msg)
{
  // RCLCPP_INFO_STREAM(this->get_logger(), "Current State Heard: " << msg->pose.position.x);
  current_pose_left = msg->pose;
}

void VRArmControl::GetCurrentStateRight(const rm_ros_interfaces::msg::Armstate::SharedPtr msg)
{
  // RCLCPP_INFO_STREAM(this->get_logger(), "Current State Heard: " << msg->pose.position.x);
  current_pose_right = msg->pose;
}

void VRArmControl::GetDelta(const std_msgs::msg::Float32MultiArray::SharedPtr msg)
{
  // RCLCPP_INFO_STREAM(this->get_logger(), "Delta heard: " << msg->data[0]);
  delta_left[0] = msg->data[0];
  delta_left[1] = msg->data[1];
  delta_left[2] = msg->data[2];
  delta_left[3] = msg->data[3];
  delta_left[4] = msg->data[4];
  delta_left[5] = msg->data[5];
  delta_left[6] = msg->data[6];



  delta_right[0] = msg->data[7];
  delta_right[1] = msg->data[8];
  delta_right[2] = msg->data[9];
  delta_right[3] = msg->data[10];
  delta_right[4] = msg->data[11];
  delta_right[5] = msg->data[12];
  delta_right[6] = msg->data[13];

}



int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VRArmControl>());
  rclcpp::shutdown();
  return 0;
}

    // rm_ros_interfaces::msg::Cartepos to_move_pose_left;
    // to_move_pose_left.pose.position.x = current_pose_left.position.x + -(delta_left[2] * 0.02);
    // to_move_pose_left.pose.position.y = current_pose_left.position.y + delta_left[0] * 0.02;
    // to_move_pose_left.pose.position.z = current_pose_left.position.z + -(delta_left[1] * 0.02);
    // to_move_pose_left.pose.orientation.x = current_pose_left.orientation.x + (delta_left[5] * 3);
    // to_move_pose_left.pose.orientation.y = current_pose_left.orientation.y + - (delta_left[3] * 3);
    // to_move_pose_left.pose.orientation.z = current_pose_left.orientation.z + (delta_left[4] * 3);
    // to_move_pose_left.pose.orientation.w = current_pose_left.orientation.w + delta_left[6] * 3;
    // to_move_pose_left.follow = false;
 

    // rm_ros_interfaces::msg::Cartepos to_move_pose_right;
    // to_move_pose_right.pose.position.x = current_pose_right.position.x + -(delta_right[0] * 0.02);
    // to_move_pose_right.pose.position.y = current_pose_right.position.y + -(delta_right[2] * 0.02);
    // to_move_pose_right.pose.position.z = current_pose_right.position.z + -(delta_right[1] * 0.02);
    // to_move_pose_right.pose.orientation.x = current_pose_right.orientation.x + (delta_right[3] * 3);
    // to_move_pose_right.pose.orientation.y = current_pose_right.orientation.y + (delta_right[5] * 3);
    // to_move_pose_right.pose.orientation.z = current_pose_right.orientation.z + (delta_right[4] * 3);
    // to_move_pose_right.pose.orientation.w = current_pose_right.orientation.w + -(delta_right[6] * 3);
    // to_move_pose_right.follow = false;

    // rm_ros_interfaces::msg::Cartepos to_move_pose_left;
    // to_move_pose_left.pose.position.x = current_pose_left.position.x + (delta_left[0] * 1.5);
    // to_move_pose_left.pose.position.y = current_pose_left.position.y + (delta_left[1] * 1.5);
    // to_move_pose_left.pose.position.z = current_pose_left.position.z + (delta_left[2] * 1.5);
    // if(delta_left[3]==0.0)
    // {
    //   to_move_pose_left.pose.orientation.x = current_pose_left.orientation.x;
    // }
    // else
    // {
    //   to_move_pose_left.pose.orientation.x = (delta_left[3]);
    // }
    // if(delta_left[4]==0.0)
    // {
    //   to_move_pose_left.pose.orientation.y = current_pose_left.orientation.y;
    // }
    // else
    // {
    //   to_move_pose_left.pose.orientation.y = (delta_left[4]);
    // }
    // if(delta_left[5]==0.0)
    // {
    //   to_move_pose_left.pose.orientation.z = current_pose_left.orientation.z;
    // }
    // else
    // {
    //   to_move_pose_left.pose.orientation.z = (delta_left[5]);
    // }
    // if(delta_left[6]==0.0)
    // {
    //   to_move_pose_left.pose.orientation.w = current_pose_left.orientation.w;
    // }
    // else
    // {
    //   to_move_pose_left.pose.orientation.w = (delta_left[6]);
    // }
    // // to_move_pose_right.pose.orientation.x = current_pose_right.orientation.x + -(delta_right[5] * 1.5);
    // // to_move_pose_right.pose.orientation.y = current_pose_right.orientation.y + (delta_right[3] * 1.5);
    // // to_move_pose_right.pose.orientation.z = current_pose_right.orientation.z + (delta_right[4] * 1.5);
    // // to_move_pose_right.pose.orientation.w = current_pose_right.orientation.w + -(delta_right[6] * 1.5);
    // to_move_pose_left.follow = false;
 
    // rm_ros_interfaces::msg::Cartepos to_move_pose_right;
    // to_move_pose_right.pose.position.x = current_pose_right.position.x + (delta_right[0]  * 1.5);
    // to_move_pose_right.pose.position.y = current_pose_right.position.y + (delta_right[1]  * 1.5);
    // to_move_pose_right.pose.position.z = current_pose_right.position.z + (delta_right[2]  * 1.5);
    // if(delta_right[3]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.x = current_pose_right.orientation.x;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.x = (delta_right[3]);
    // }
    // if(delta_right[4]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.y = current_pose_right.orientation.y;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.y = (delta_right[4]);
    // }
    // if(delta_right[5]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.z = current_pose_right.orientation.z;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.z = (delta_right[5]);
    // }
    // if(delta_right[6]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.w = current_pose_right.orientation.w;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.w = (delta_right[6]);
    // }
    // // to_move_pose_right.pose.orientation.x = current_pose_right.orientation.x + -(delta_right[5] * 1.5);
    // // to_move_pose_right.pose.orientation.y = current_pose_right.orientation.y + (delta_right[3] * 1.5);
    // // to_move_pose_right.pose.orientation.z = current_pose_right.orientation.z + (delta_right[4] * 1.5);
    // // to_move_pose_right.pose.orientation.w = current_pose_right.orientation.w + -(delta_right[6] * 1.5);
    // to_move_pose_right.follow = false;


    // Eigen::Vector3d pos_rotated(delta_left[0], delta_left[2], delta_left[1]); // Replace with your values
    // Eigen::Quaterniond quat_rotated(delta_left[6], delta_left[3], delta_left[5], delta_left[4]); // [w, x, y, z] — be careful with order!

    // // 2. Define the rotation of the rotated frame (45° about Y-axis)
    // double angle_rad = M_PI / 4.0; // 45 degrees in radians
    // Eigen::AngleAxisd rotation_y(angle_rad, Eigen::Vector3d::UnitY());
    // Eigen::Matrix3d rot_matrix = rotation_y.toRotationMatrix();
    // Eigen::Quaterniond q_rot(rot_matrix); // Rotation of new frame w.r.t base

    // // 3. Create transformation matrix T_rot_to_base
    // Eigen::Isometry3d T_rot_to_base = Eigen::Isometry3d::Identity();
    // T_rot_to_base.rotate(q_rot);
    // // No translation; just rotating the frame

    // // 4. Create the pose as a transform
    // Eigen::Isometry3d T_pose_rotated = Eigen::Isometry3d::Identity();
    // T_pose_rotated.translate(pos_rotated);
    // T_pose_rotated.rotate(quat_rotated);

    // // 5. Transform the pose into the base frame
    // Eigen::Isometry3d T_pose_base = T_rot_to_base * T_pose_rotated;

    // // 6. Extract final position and orientation
    // Eigen::Vector3d pos_base = T_pose_base.translation();
    // Eigen::Quaterniond quat_base(T_pose_base.rotation());

    // rm_ros_interfaces::msg::Cartepos to_move_pose_left;
    // to_move_pose_left.pose.position.x = current_pose_left.position.x + -(pos_base.x() * 0.01);
    // to_move_pose_left.pose.position.y = current_pose_left.position.y + -(pos_base.y() * 0.01);
    // to_move_pose_left.pose.position.z = current_pose_left.position.z + -(pos_base.z() * 0.01);
    // to_move_pose_left.pose.orientation.x = current_pose_left.orientation.x + quat_base.x();
    // to_move_pose_left.pose.orientation.y = current_pose_left.orientation.y + quat_base.y();
    // to_move_pose_left.pose.orientation.z = current_pose_left.orientation.z + quat_base.z();
    // to_move_pose_left.pose.orientation.w = current_pose_left.orientation.w + quat_base.w();
    // to_move_pose_left.follow = false;

     // 1. Define the pose in the rotated frame
    
 
    //  // Output
    //  std::cout << "Transformed position: [" << pos_base.x() << ", " << pos_base.y() << ", " << pos_base.z() << "]\n";
    //  std::cout << "Transformed orientation (quaternion): ["
    //            << quat_base.x() << ", " << quat_base.y() << ", "
    //            << quat_base.z() << ", " << quat_base.w() << "]\n";
       // if(delta_right[3]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.x = current_pose_right.orientation.x;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.x = -(delta_right[3]);
    // }
    // if(delta_right[5]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.y = current_pose_right.orientation.y;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.y = -(delta_right[5]);
    // }
    // if(delta_right[4]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.z = current_pose_right.orientation.z;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.z = -(delta_right[4]);
    // }
    // if(delta_right[6]==0.0)
    // {
    //   to_move_pose_right.pose.orientation.w = current_pose_right.orientation.w;
    // }
    // else
    // {
    //   to_move_pose_right.pose.orientation.w = (delta_right[6]);
    // }
    // to_move_pose_right.pose.orientation.x = current_pose_right.orientation.x;
    // to_move_pose_right.pose.orientation.y = current_pose_right.orientation.y;
    // to_move_pose_right.pose.orientation.z = current_pose_right.orientation.z;
    // to_move_pose_right.pose.orientation.w = current_pose_right.orientation.w;
