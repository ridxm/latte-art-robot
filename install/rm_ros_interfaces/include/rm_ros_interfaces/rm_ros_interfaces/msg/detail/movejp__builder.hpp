// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Movejp.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEJP__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEJP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/movejp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Movejp_block
{
public:
  explicit Init_Movejp_block(::rm_ros_interfaces::msg::Movejp & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Movejp block(::rm_ros_interfaces::msg::Movejp::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movejp msg_;
};

class Init_Movejp_trajectory_connect
{
public:
  explicit Init_Movejp_trajectory_connect(::rm_ros_interfaces::msg::Movejp & msg)
  : msg_(msg)
  {}
  Init_Movejp_block trajectory_connect(::rm_ros_interfaces::msg::Movejp::_trajectory_connect_type arg)
  {
    msg_.trajectory_connect = std::move(arg);
    return Init_Movejp_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movejp msg_;
};

class Init_Movejp_speed
{
public:
  explicit Init_Movejp_speed(::rm_ros_interfaces::msg::Movejp & msg)
  : msg_(msg)
  {}
  Init_Movejp_trajectory_connect speed(::rm_ros_interfaces::msg::Movejp::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Movejp_trajectory_connect(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movejp msg_;
};

class Init_Movejp_pose
{
public:
  Init_Movejp_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movejp_speed pose(::rm_ros_interfaces::msg::Movejp::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Movejp_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movejp msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Movejp>()
{
  return rm_ros_interfaces::msg::builder::Init_Movejp_pose();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEJP__BUILDER_HPP_
