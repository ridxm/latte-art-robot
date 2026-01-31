// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Liftheight.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__LIFTHEIGHT__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__LIFTHEIGHT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/liftheight__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Liftheight_block
{
public:
  explicit Init_Liftheight_block(::rm_ros_interfaces::msg::Liftheight & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Liftheight block(::rm_ros_interfaces::msg::Liftheight::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftheight msg_;
};

class Init_Liftheight_speed
{
public:
  explicit Init_Liftheight_speed(::rm_ros_interfaces::msg::Liftheight & msg)
  : msg_(msg)
  {}
  Init_Liftheight_block speed(::rm_ros_interfaces::msg::Liftheight::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Liftheight_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftheight msg_;
};

class Init_Liftheight_height
{
public:
  Init_Liftheight_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Liftheight_speed height(::rm_ros_interfaces::msg::Liftheight::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Liftheight_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftheight msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Liftheight>()
{
  return rm_ros_interfaces::msg::builder::Init_Liftheight_height();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__LIFTHEIGHT__BUILDER_HPP_
