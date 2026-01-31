// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Sixforce.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/sixforce__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Sixforce_force_mz
{
public:
  explicit Init_Sixforce_force_mz(::rm_ros_interfaces::msg::Sixforce & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Sixforce force_mz(::rm_ros_interfaces::msg::Sixforce::_force_mz_type arg)
  {
    msg_.force_mz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Sixforce msg_;
};

class Init_Sixforce_force_my
{
public:
  explicit Init_Sixforce_force_my(::rm_ros_interfaces::msg::Sixforce & msg)
  : msg_(msg)
  {}
  Init_Sixforce_force_mz force_my(::rm_ros_interfaces::msg::Sixforce::_force_my_type arg)
  {
    msg_.force_my = std::move(arg);
    return Init_Sixforce_force_mz(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Sixforce msg_;
};

class Init_Sixforce_force_mx
{
public:
  explicit Init_Sixforce_force_mx(::rm_ros_interfaces::msg::Sixforce & msg)
  : msg_(msg)
  {}
  Init_Sixforce_force_my force_mx(::rm_ros_interfaces::msg::Sixforce::_force_mx_type arg)
  {
    msg_.force_mx = std::move(arg);
    return Init_Sixforce_force_my(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Sixforce msg_;
};

class Init_Sixforce_force_fz
{
public:
  explicit Init_Sixforce_force_fz(::rm_ros_interfaces::msg::Sixforce & msg)
  : msg_(msg)
  {}
  Init_Sixforce_force_mx force_fz(::rm_ros_interfaces::msg::Sixforce::_force_fz_type arg)
  {
    msg_.force_fz = std::move(arg);
    return Init_Sixforce_force_mx(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Sixforce msg_;
};

class Init_Sixforce_force_fy
{
public:
  explicit Init_Sixforce_force_fy(::rm_ros_interfaces::msg::Sixforce & msg)
  : msg_(msg)
  {}
  Init_Sixforce_force_fz force_fy(::rm_ros_interfaces::msg::Sixforce::_force_fy_type arg)
  {
    msg_.force_fy = std::move(arg);
    return Init_Sixforce_force_fz(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Sixforce msg_;
};

class Init_Sixforce_force_fx
{
public:
  Init_Sixforce_force_fx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sixforce_force_fy force_fx(::rm_ros_interfaces::msg::Sixforce::_force_fx_type arg)
  {
    msg_.force_fx = std::move(arg);
    return Init_Sixforce_force_fy(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Sixforce msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Sixforce>()
{
  return rm_ros_interfaces::msg::builder::Init_Sixforce_force_fx();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__BUILDER_HPP_
