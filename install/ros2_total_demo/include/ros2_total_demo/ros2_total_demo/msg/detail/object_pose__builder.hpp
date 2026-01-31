// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_total_demo:msg/ObjectPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_TOTAL_DEMO__MSG__DETAIL__OBJECT_POSE__BUILDER_HPP_
#define ROS2_TOTAL_DEMO__MSG__DETAIL__OBJECT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_total_demo/msg/detail/object_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_total_demo
{

namespace msg
{

namespace builder
{

class Init_ObjectPose_z
{
public:
  explicit Init_ObjectPose_z(::ros2_total_demo::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  ::ros2_total_demo::msg::ObjectPose z(::ros2_total_demo::msg::ObjectPose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_total_demo::msg::ObjectPose msg_;
};

class Init_ObjectPose_y
{
public:
  explicit Init_ObjectPose_y(::ros2_total_demo::msg::ObjectPose & msg)
  : msg_(msg)
  {}
  Init_ObjectPose_z y(::ros2_total_demo::msg::ObjectPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ObjectPose_z(msg_);
  }

private:
  ::ros2_total_demo::msg::ObjectPose msg_;
};

class Init_ObjectPose_x
{
public:
  Init_ObjectPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectPose_y x(::ros2_total_demo::msg::ObjectPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ObjectPose_y(msg_);
  }

private:
  ::ros2_total_demo::msg::ObjectPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_total_demo::msg::ObjectPose>()
{
  return ros2_total_demo::msg::builder::Init_ObjectPose_x();
}

}  // namespace ros2_total_demo

#endif  // ROS2_TOTAL_DEMO__MSG__DETAIL__OBJECT_POSE__BUILDER_HPP_
