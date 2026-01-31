// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Jointteach.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/jointteach__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Jointteach_block
{
public:
  explicit Init_Jointteach_block(::rm_ros_interfaces::msg::Jointteach & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Jointteach block(::rm_ros_interfaces::msg::Jointteach::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointteach msg_;
};

class Init_Jointteach_speed
{
public:
  explicit Init_Jointteach_speed(::rm_ros_interfaces::msg::Jointteach & msg)
  : msg_(msg)
  {}
  Init_Jointteach_block speed(::rm_ros_interfaces::msg::Jointteach::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Jointteach_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointteach msg_;
};

class Init_Jointteach_direction
{
public:
  explicit Init_Jointteach_direction(::rm_ros_interfaces::msg::Jointteach & msg)
  : msg_(msg)
  {}
  Init_Jointteach_speed direction(::rm_ros_interfaces::msg::Jointteach::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Jointteach_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointteach msg_;
};

class Init_Jointteach_num
{
public:
  Init_Jointteach_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jointteach_direction num(::rm_ros_interfaces::msg::Jointteach::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_Jointteach_direction(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointteach msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Jointteach>()
{
  return rm_ros_interfaces::msg::builder::Init_Jointteach_num();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__BUILDER_HPP_
