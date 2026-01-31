// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Posteach.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__POSTEACH__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__POSTEACH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/posteach__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Posteach_block
{
public:
  explicit Init_Posteach_block(::rm_ros_interfaces::msg::Posteach & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Posteach block(::rm_ros_interfaces::msg::Posteach::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Posteach msg_;
};

class Init_Posteach_speed
{
public:
  explicit Init_Posteach_speed(::rm_ros_interfaces::msg::Posteach & msg)
  : msg_(msg)
  {}
  Init_Posteach_block speed(::rm_ros_interfaces::msg::Posteach::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Posteach_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Posteach msg_;
};

class Init_Posteach_direction
{
public:
  explicit Init_Posteach_direction(::rm_ros_interfaces::msg::Posteach & msg)
  : msg_(msg)
  {}
  Init_Posteach_speed direction(::rm_ros_interfaces::msg::Posteach::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Posteach_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Posteach msg_;
};

class Init_Posteach_type
{
public:
  Init_Posteach_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Posteach_direction type(::rm_ros_interfaces::msg::Posteach::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Posteach_direction(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Posteach msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Posteach>()
{
  return rm_ros_interfaces::msg::builder::Init_Posteach_type();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__POSTEACH__BUILDER_HPP_
