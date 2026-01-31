// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Handspeed.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSPEED__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSPEED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/handspeed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Handspeed_block
{
public:
  explicit Init_Handspeed_block(::rm_ros_interfaces::msg::Handspeed & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Handspeed block(::rm_ros_interfaces::msg::Handspeed::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handspeed msg_;
};

class Init_Handspeed_hand_speed
{
public:
  Init_Handspeed_hand_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Handspeed_block hand_speed(::rm_ros_interfaces::msg::Handspeed::_hand_speed_type arg)
  {
    msg_.hand_speed = std::move(arg);
    return Init_Handspeed_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handspeed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Handspeed>()
{
  return rm_ros_interfaces::msg::builder::Init_Handspeed_hand_speed();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSPEED__BUILDER_HPP_
