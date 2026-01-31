// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Handposture.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDPOSTURE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDPOSTURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/handposture__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Handposture_block
{
public:
  explicit Init_Handposture_block(::rm_ros_interfaces::msg::Handposture & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Handposture block(::rm_ros_interfaces::msg::Handposture::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handposture msg_;
};

class Init_Handposture_posture_num
{
public:
  Init_Handposture_posture_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Handposture_block posture_num(::rm_ros_interfaces::msg::Handposture::_posture_num_type arg)
  {
    msg_.posture_num = std::move(arg);
    return Init_Handposture_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handposture msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Handposture>()
{
  return rm_ros_interfaces::msg::builder::Init_Handposture_posture_num();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDPOSTURE__BUILDER_HPP_
