// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Ortteach.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ORTTEACH__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ORTTEACH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/ortteach__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Ortteach_block
{
public:
  explicit Init_Ortteach_block(::rm_ros_interfaces::msg::Ortteach & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Ortteach block(::rm_ros_interfaces::msg::Ortteach::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Ortteach msg_;
};

class Init_Ortteach_speed
{
public:
  explicit Init_Ortteach_speed(::rm_ros_interfaces::msg::Ortteach & msg)
  : msg_(msg)
  {}
  Init_Ortteach_block speed(::rm_ros_interfaces::msg::Ortteach::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Ortteach_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Ortteach msg_;
};

class Init_Ortteach_direction
{
public:
  explicit Init_Ortteach_direction(::rm_ros_interfaces::msg::Ortteach & msg)
  : msg_(msg)
  {}
  Init_Ortteach_speed direction(::rm_ros_interfaces::msg::Ortteach::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Ortteach_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Ortteach msg_;
};

class Init_Ortteach_type
{
public:
  Init_Ortteach_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ortteach_direction type(::rm_ros_interfaces::msg::Ortteach::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Ortteach_direction(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Ortteach msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Ortteach>()
{
  return rm_ros_interfaces::msg::builder::Init_Ortteach_type();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ORTTEACH__BUILDER_HPP_
