// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Gripperpick.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/gripperpick__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Gripperpick_timeout
{
public:
  explicit Init_Gripperpick_timeout(::rm_ros_interfaces::msg::Gripperpick & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Gripperpick timeout(::rm_ros_interfaces::msg::Gripperpick::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperpick msg_;
};

class Init_Gripperpick_block
{
public:
  explicit Init_Gripperpick_block(::rm_ros_interfaces::msg::Gripperpick & msg)
  : msg_(msg)
  {}
  Init_Gripperpick_timeout block(::rm_ros_interfaces::msg::Gripperpick::_block_type arg)
  {
    msg_.block = std::move(arg);
    return Init_Gripperpick_timeout(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperpick msg_;
};

class Init_Gripperpick_force
{
public:
  explicit Init_Gripperpick_force(::rm_ros_interfaces::msg::Gripperpick & msg)
  : msg_(msg)
  {}
  Init_Gripperpick_block force(::rm_ros_interfaces::msg::Gripperpick::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_Gripperpick_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperpick msg_;
};

class Init_Gripperpick_speed
{
public:
  Init_Gripperpick_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gripperpick_force speed(::rm_ros_interfaces::msg::Gripperpick::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Gripperpick_force(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperpick msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Gripperpick>()
{
  return rm_ros_interfaces::msg::builder::Init_Gripperpick_speed();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__BUILDER_HPP_
