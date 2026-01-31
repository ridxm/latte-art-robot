// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Liftspeed.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__LIFTSPEED__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__LIFTSPEED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/liftspeed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Liftspeed_speed
{
public:
  Init_Liftspeed_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_ros_interfaces::msg::Liftspeed speed(::rm_ros_interfaces::msg::Liftspeed::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Liftspeed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Liftspeed>()
{
  return rm_ros_interfaces::msg::builder::Init_Liftspeed_speed();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__LIFTSPEED__BUILDER_HPP_
