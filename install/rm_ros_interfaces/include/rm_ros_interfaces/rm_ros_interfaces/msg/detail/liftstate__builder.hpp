// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Liftstate.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__LIFTSTATE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__LIFTSTATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/liftstate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Liftstate_mode
{
public:
  explicit Init_Liftstate_mode(::rm_ros_interfaces::msg::Liftstate & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Liftstate mode(::rm_ros_interfaces::msg::Liftstate::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftstate msg_;
};

class Init_Liftstate_err_flag
{
public:
  explicit Init_Liftstate_err_flag(::rm_ros_interfaces::msg::Liftstate & msg)
  : msg_(msg)
  {}
  Init_Liftstate_mode err_flag(::rm_ros_interfaces::msg::Liftstate::_err_flag_type arg)
  {
    msg_.err_flag = std::move(arg);
    return Init_Liftstate_mode(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftstate msg_;
};

class Init_Liftstate_current
{
public:
  explicit Init_Liftstate_current(::rm_ros_interfaces::msg::Liftstate & msg)
  : msg_(msg)
  {}
  Init_Liftstate_err_flag current(::rm_ros_interfaces::msg::Liftstate::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_Liftstate_err_flag(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftstate msg_;
};

class Init_Liftstate_height
{
public:
  Init_Liftstate_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Liftstate_current height(::rm_ros_interfaces::msg::Liftstate::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Liftstate_current(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftstate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Liftstate>()
{
  return rm_ros_interfaces::msg::builder::Init_Liftstate_height();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__LIFTSTATE__BUILDER_HPP_
