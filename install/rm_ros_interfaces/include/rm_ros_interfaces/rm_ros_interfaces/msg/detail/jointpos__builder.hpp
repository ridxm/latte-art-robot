// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Jointpos.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTPOS__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTPOS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/jointpos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Jointpos_dof
{
public:
  explicit Init_Jointpos_dof(::rm_ros_interfaces::msg::Jointpos & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Jointpos dof(::rm_ros_interfaces::msg::Jointpos::_dof_type arg)
  {
    msg_.dof = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointpos msg_;
};

class Init_Jointpos_expand
{
public:
  explicit Init_Jointpos_expand(::rm_ros_interfaces::msg::Jointpos & msg)
  : msg_(msg)
  {}
  Init_Jointpos_dof expand(::rm_ros_interfaces::msg::Jointpos::_expand_type arg)
  {
    msg_.expand = std::move(arg);
    return Init_Jointpos_dof(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointpos msg_;
};

class Init_Jointpos_follow
{
public:
  explicit Init_Jointpos_follow(::rm_ros_interfaces::msg::Jointpos & msg)
  : msg_(msg)
  {}
  Init_Jointpos_expand follow(::rm_ros_interfaces::msg::Jointpos::_follow_type arg)
  {
    msg_.follow = std::move(arg);
    return Init_Jointpos_expand(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointpos msg_;
};

class Init_Jointpos_joint
{
public:
  Init_Jointpos_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jointpos_follow joint(::rm_ros_interfaces::msg::Jointpos::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_Jointpos_follow(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointpos msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Jointpos>()
{
  return rm_ros_interfaces::msg::builder::Init_Jointpos_joint();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTPOS__BUILDER_HPP_
