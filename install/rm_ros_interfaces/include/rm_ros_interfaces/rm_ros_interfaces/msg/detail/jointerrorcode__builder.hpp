// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Jointerrorcode.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/jointerrorcode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Jointerrorcode_dof
{
public:
  explicit Init_Jointerrorcode_dof(::rm_ros_interfaces::msg::Jointerrorcode & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Jointerrorcode dof(::rm_ros_interfaces::msg::Jointerrorcode::_dof_type arg)
  {
    msg_.dof = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointerrorcode msg_;
};

class Init_Jointerrorcode_joint_error
{
public:
  Init_Jointerrorcode_joint_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jointerrorcode_dof joint_error(::rm_ros_interfaces::msg::Jointerrorcode::_joint_error_type arg)
  {
    msg_.joint_error = std::move(arg);
    return Init_Jointerrorcode_dof(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointerrorcode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Jointerrorcode>()
{
  return rm_ros_interfaces::msg::builder::Init_Jointerrorcode_joint_error();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__BUILDER_HPP_
