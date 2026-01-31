// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Movec.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/movec__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Movec_loop
{
public:
  explicit Init_Movec_loop(::rm_ros_interfaces::msg::Movec & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Movec loop(::rm_ros_interfaces::msg::Movec::_loop_type arg)
  {
    msg_.loop = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movec msg_;
};

class Init_Movec_block
{
public:
  explicit Init_Movec_block(::rm_ros_interfaces::msg::Movec & msg)
  : msg_(msg)
  {}
  Init_Movec_loop block(::rm_ros_interfaces::msg::Movec::_block_type arg)
  {
    msg_.block = std::move(arg);
    return Init_Movec_loop(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movec msg_;
};

class Init_Movec_trajectory_connect
{
public:
  explicit Init_Movec_trajectory_connect(::rm_ros_interfaces::msg::Movec & msg)
  : msg_(msg)
  {}
  Init_Movec_block trajectory_connect(::rm_ros_interfaces::msg::Movec::_trajectory_connect_type arg)
  {
    msg_.trajectory_connect = std::move(arg);
    return Init_Movec_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movec msg_;
};

class Init_Movec_speed
{
public:
  explicit Init_Movec_speed(::rm_ros_interfaces::msg::Movec & msg)
  : msg_(msg)
  {}
  Init_Movec_trajectory_connect speed(::rm_ros_interfaces::msg::Movec::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Movec_trajectory_connect(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movec msg_;
};

class Init_Movec_pose_end
{
public:
  explicit Init_Movec_pose_end(::rm_ros_interfaces::msg::Movec & msg)
  : msg_(msg)
  {}
  Init_Movec_speed pose_end(::rm_ros_interfaces::msg::Movec::_pose_end_type arg)
  {
    msg_.pose_end = std::move(arg);
    return Init_Movec_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movec msg_;
};

class Init_Movec_pose_mid
{
public:
  Init_Movec_pose_mid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movec_pose_end pose_mid(::rm_ros_interfaces::msg::Movec::_pose_mid_type arg)
  {
    msg_.pose_mid = std::move(arg);
    return Init_Movec_pose_end(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movec msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Movec>()
{
  return rm_ros_interfaces::msg::builder::Init_Movec_pose_mid();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__BUILDER_HPP_
