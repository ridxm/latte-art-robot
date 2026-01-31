// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Cartepos.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__CARTEPOS__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__CARTEPOS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/cartepos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Cartepos_follow
{
public:
  explicit Init_Cartepos_follow(::rm_ros_interfaces::msg::Cartepos & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Cartepos follow(::rm_ros_interfaces::msg::Cartepos::_follow_type arg)
  {
    msg_.follow = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Cartepos msg_;
};

class Init_Cartepos_pose
{
public:
  Init_Cartepos_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cartepos_follow pose(::rm_ros_interfaces::msg::Cartepos::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Cartepos_follow(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Cartepos msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Cartepos>()
{
  return rm_ros_interfaces::msg::builder::Init_Cartepos_pose();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__CARTEPOS__BUILDER_HPP_
