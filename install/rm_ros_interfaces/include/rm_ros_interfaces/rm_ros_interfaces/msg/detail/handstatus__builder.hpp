// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Handstatus.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/handstatus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Handstatus_hand_err
{
public:
  explicit Init_Handstatus_hand_err(::rm_ros_interfaces::msg::Handstatus & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Handstatus hand_err(::rm_ros_interfaces::msg::Handstatus::_hand_err_type arg)
  {
    msg_.hand_err = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handstatus msg_;
};

class Init_Handstatus_hand_force
{
public:
  explicit Init_Handstatus_hand_force(::rm_ros_interfaces::msg::Handstatus & msg)
  : msg_(msg)
  {}
  Init_Handstatus_hand_err hand_force(::rm_ros_interfaces::msg::Handstatus::_hand_force_type arg)
  {
    msg_.hand_force = std::move(arg);
    return Init_Handstatus_hand_err(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handstatus msg_;
};

class Init_Handstatus_hand_state
{
public:
  explicit Init_Handstatus_hand_state(::rm_ros_interfaces::msg::Handstatus & msg)
  : msg_(msg)
  {}
  Init_Handstatus_hand_force hand_state(::rm_ros_interfaces::msg::Handstatus::_hand_state_type arg)
  {
    msg_.hand_state = std::move(arg);
    return Init_Handstatus_hand_force(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handstatus msg_;
};

class Init_Handstatus_hand_pos
{
public:
  explicit Init_Handstatus_hand_pos(::rm_ros_interfaces::msg::Handstatus & msg)
  : msg_(msg)
  {}
  Init_Handstatus_hand_state hand_pos(::rm_ros_interfaces::msg::Handstatus::_hand_pos_type arg)
  {
    msg_.hand_pos = std::move(arg);
    return Init_Handstatus_hand_state(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handstatus msg_;
};

class Init_Handstatus_hand_angle
{
public:
  Init_Handstatus_hand_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Handstatus_hand_pos hand_angle(::rm_ros_interfaces::msg::Handstatus::_hand_angle_type arg)
  {
    msg_.hand_angle = std::move(arg);
    return Init_Handstatus_hand_pos(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handstatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Handstatus>()
{
  return rm_ros_interfaces::msg::builder::Init_Handstatus_hand_angle();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__BUILDER_HPP_
