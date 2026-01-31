// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Handforce.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDFORCE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDFORCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/handforce__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Handforce_block
{
public:
  explicit Init_Handforce_block(::rm_ros_interfaces::msg::Handforce & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Handforce block(::rm_ros_interfaces::msg::Handforce::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handforce msg_;
};

class Init_Handforce_hand_force
{
public:
  Init_Handforce_hand_force()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Handforce_block hand_force(::rm_ros_interfaces::msg::Handforce::_hand_force_type arg)
  {
    msg_.hand_force = std::move(arg);
    return Init_Handforce_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handforce msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Handforce>()
{
  return rm_ros_interfaces::msg::builder::Init_Handforce_hand_force();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDFORCE__BUILDER_HPP_
