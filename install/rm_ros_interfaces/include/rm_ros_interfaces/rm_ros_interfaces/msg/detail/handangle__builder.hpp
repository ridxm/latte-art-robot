// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Handangle.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/handangle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Handangle_block
{
public:
  explicit Init_Handangle_block(::rm_ros_interfaces::msg::Handangle & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Handangle block(::rm_ros_interfaces::msg::Handangle::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handangle msg_;
};

class Init_Handangle_hand_angle
{
public:
  Init_Handangle_hand_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Handangle_block hand_angle(::rm_ros_interfaces::msg::Handangle::_hand_angle_type arg)
  {
    msg_.hand_angle = std::move(arg);
    return Init_Handangle_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handangle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Handangle>()
{
  return rm_ros_interfaces::msg::builder::Init_Handangle_hand_angle();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__BUILDER_HPP_
