// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Getallframe.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/getallframe__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Getallframe_frame_name
{
public:
  Init_Getallframe_frame_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_ros_interfaces::msg::Getallframe frame_name(::rm_ros_interfaces::msg::Getallframe::_frame_name_type arg)
  {
    msg_.frame_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Getallframe msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Getallframe>()
{
  return rm_ros_interfaces::msg::builder::Init_Getallframe_frame_name();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__BUILDER_HPP_
