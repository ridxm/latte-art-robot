// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Forcepositionmovepose.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/forcepositionmovepose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Forcepositionmovepose_follow
{
public:
  explicit Init_Forcepositionmovepose_follow(::rm_ros_interfaces::msg::Forcepositionmovepose & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Forcepositionmovepose follow(::rm_ros_interfaces::msg::Forcepositionmovepose::_follow_type arg)
  {
    msg_.follow = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovepose msg_;
};

class Init_Forcepositionmovepose_force
{
public:
  explicit Init_Forcepositionmovepose_force(::rm_ros_interfaces::msg::Forcepositionmovepose & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovepose_follow force(::rm_ros_interfaces::msg::Forcepositionmovepose::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_Forcepositionmovepose_follow(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovepose msg_;
};

class Init_Forcepositionmovepose_dir
{
public:
  explicit Init_Forcepositionmovepose_dir(::rm_ros_interfaces::msg::Forcepositionmovepose & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovepose_force dir(::rm_ros_interfaces::msg::Forcepositionmovepose::_dir_type arg)
  {
    msg_.dir = std::move(arg);
    return Init_Forcepositionmovepose_force(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovepose msg_;
};

class Init_Forcepositionmovepose_mode
{
public:
  explicit Init_Forcepositionmovepose_mode(::rm_ros_interfaces::msg::Forcepositionmovepose & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovepose_dir mode(::rm_ros_interfaces::msg::Forcepositionmovepose::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Forcepositionmovepose_dir(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovepose msg_;
};

class Init_Forcepositionmovepose_sensor
{
public:
  explicit Init_Forcepositionmovepose_sensor(::rm_ros_interfaces::msg::Forcepositionmovepose & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovepose_mode sensor(::rm_ros_interfaces::msg::Forcepositionmovepose::_sensor_type arg)
  {
    msg_.sensor = std::move(arg);
    return Init_Forcepositionmovepose_mode(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovepose msg_;
};

class Init_Forcepositionmovepose_pose
{
public:
  Init_Forcepositionmovepose_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Forcepositionmovepose_sensor pose(::rm_ros_interfaces::msg::Forcepositionmovepose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Forcepositionmovepose_sensor(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovepose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Forcepositionmovepose>()
{
  return rm_ros_interfaces::msg::builder::Init_Forcepositionmovepose_pose();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__BUILDER_HPP_
