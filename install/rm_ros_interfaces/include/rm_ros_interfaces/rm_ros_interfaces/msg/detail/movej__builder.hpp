// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Movej.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/movej__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Movej_dof
{
public:
  explicit Init_Movej_dof(::rm_ros_interfaces::msg::Movej & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Movej dof(::rm_ros_interfaces::msg::Movej::_dof_type arg)
  {
    msg_.dof = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movej msg_;
};

class Init_Movej_trajectory_connect
{
public:
  explicit Init_Movej_trajectory_connect(::rm_ros_interfaces::msg::Movej & msg)
  : msg_(msg)
  {}
  Init_Movej_dof trajectory_connect(::rm_ros_interfaces::msg::Movej::_trajectory_connect_type arg)
  {
    msg_.trajectory_connect = std::move(arg);
    return Init_Movej_dof(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movej msg_;
};

class Init_Movej_block
{
public:
  explicit Init_Movej_block(::rm_ros_interfaces::msg::Movej & msg)
  : msg_(msg)
  {}
  Init_Movej_trajectory_connect block(::rm_ros_interfaces::msg::Movej::_block_type arg)
  {
    msg_.block = std::move(arg);
    return Init_Movej_trajectory_connect(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movej msg_;
};

class Init_Movej_speed
{
public:
  explicit Init_Movej_speed(::rm_ros_interfaces::msg::Movej & msg)
  : msg_(msg)
  {}
  Init_Movej_block speed(::rm_ros_interfaces::msg::Movej::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Movej_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movej msg_;
};

class Init_Movej_joint
{
public:
  Init_Movej_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movej_speed joint(::rm_ros_interfaces::msg::Movej::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_Movej_speed(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Movej msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Movej>()
{
  return rm_ros_interfaces::msg::builder::Init_Movej_joint();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__BUILDER_HPP_
