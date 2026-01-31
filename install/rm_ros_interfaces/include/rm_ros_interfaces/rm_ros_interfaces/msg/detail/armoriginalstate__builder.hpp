// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Armoriginalstate.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMORIGINALSTATE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMORIGINALSTATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/armoriginalstate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Armoriginalstate_dof
{
public:
  explicit Init_Armoriginalstate_dof(::rm_ros_interfaces::msg::Armoriginalstate & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Armoriginalstate dof(::rm_ros_interfaces::msg::Armoriginalstate::_dof_type arg)
  {
    msg_.dof = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armoriginalstate msg_;
};

class Init_Armoriginalstate_sys_err
{
public:
  explicit Init_Armoriginalstate_sys_err(::rm_ros_interfaces::msg::Armoriginalstate & msg)
  : msg_(msg)
  {}
  Init_Armoriginalstate_dof sys_err(::rm_ros_interfaces::msg::Armoriginalstate::_sys_err_type arg)
  {
    msg_.sys_err = std::move(arg);
    return Init_Armoriginalstate_dof(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armoriginalstate msg_;
};

class Init_Armoriginalstate_arm_err
{
public:
  explicit Init_Armoriginalstate_arm_err(::rm_ros_interfaces::msg::Armoriginalstate & msg)
  : msg_(msg)
  {}
  Init_Armoriginalstate_sys_err arm_err(::rm_ros_interfaces::msg::Armoriginalstate::_arm_err_type arg)
  {
    msg_.arm_err = std::move(arg);
    return Init_Armoriginalstate_sys_err(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armoriginalstate msg_;
};

class Init_Armoriginalstate_pose
{
public:
  explicit Init_Armoriginalstate_pose(::rm_ros_interfaces::msg::Armoriginalstate & msg)
  : msg_(msg)
  {}
  Init_Armoriginalstate_arm_err pose(::rm_ros_interfaces::msg::Armoriginalstate::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Armoriginalstate_arm_err(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armoriginalstate msg_;
};

class Init_Armoriginalstate_joint
{
public:
  Init_Armoriginalstate_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Armoriginalstate_pose joint(::rm_ros_interfaces::msg::Armoriginalstate::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_Armoriginalstate_pose(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armoriginalstate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Armoriginalstate>()
{
  return rm_ros_interfaces::msg::builder::Init_Armoriginalstate_joint();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMORIGINALSTATE__BUILDER_HPP_
