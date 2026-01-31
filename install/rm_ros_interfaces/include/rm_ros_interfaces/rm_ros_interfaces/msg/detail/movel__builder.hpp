// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Movel.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEL__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/movel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Movel_block
{
public:
  explicit Init_Movel_block(::rm_ros_interfaces::msg::Movel & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Movel block(::rm_ros_interfaces::msg::Movel::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movel msg_;
};

class Init_Movel_trajectory_connect
{
public:
  explicit Init_Movel_trajectory_connect(::rm_ros_interfaces::msg::Movel & msg)
  : msg_(msg)
  {}
  Init_Movel_block trajectory_connect(::rm_ros_interfaces::msg::Movel::_trajectory_connect_type arg)
  {
    msg_.trajectory_connect = std::move(arg);
    return Init_Movel_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movel msg_;
};

class Init_Movel_speed
{
public:
  explicit Init_Movel_speed(::rm_ros_interfaces::msg::Movel & msg)
  : msg_(msg)
  {}
  Init_Movel_trajectory_connect speed(::rm_ros_interfaces::msg::Movel::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Movel_trajectory_connect(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movel msg_;
};

class Init_Movel_pose
{
public:
  Init_Movel_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movel_speed pose(::rm_ros_interfaces::msg::Movel::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Movel_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Movel>()
{
  return rm_ros_interfaces::msg::builder::Init_Movel_pose();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEL__BUILDER_HPP_
