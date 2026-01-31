// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Forcepositionmovejoint.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/forcepositionmovejoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Forcepositionmovejoint_dof
{
public:
  explicit Init_Forcepositionmovejoint_dof(::rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Forcepositionmovejoint dof(::rm_ros_interfaces::msg::Forcepositionmovejoint::_dof_type arg)
  {
    msg_.dof = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

class Init_Forcepositionmovejoint_follow
{
public:
  explicit Init_Forcepositionmovejoint_follow(::rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovejoint_dof follow(::rm_ros_interfaces::msg::Forcepositionmovejoint::_follow_type arg)
  {
    msg_.follow = std::move(arg);
    return Init_Forcepositionmovejoint_dof(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

class Init_Forcepositionmovejoint_force
{
public:
  explicit Init_Forcepositionmovejoint_force(::rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovejoint_follow force(::rm_ros_interfaces::msg::Forcepositionmovejoint::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_Forcepositionmovejoint_follow(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

class Init_Forcepositionmovejoint_dir
{
public:
  explicit Init_Forcepositionmovejoint_dir(::rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovejoint_force dir(::rm_ros_interfaces::msg::Forcepositionmovejoint::_dir_type arg)
  {
    msg_.dir = std::move(arg);
    return Init_Forcepositionmovejoint_force(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

class Init_Forcepositionmovejoint_mode
{
public:
  explicit Init_Forcepositionmovejoint_mode(::rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovejoint_dir mode(::rm_ros_interfaces::msg::Forcepositionmovejoint::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Forcepositionmovejoint_dir(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

class Init_Forcepositionmovejoint_sensor
{
public:
  explicit Init_Forcepositionmovejoint_sensor(::rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
  : msg_(msg)
  {}
  Init_Forcepositionmovejoint_mode sensor(::rm_ros_interfaces::msg::Forcepositionmovejoint::_sensor_type arg)
  {
    msg_.sensor = std::move(arg);
    return Init_Forcepositionmovejoint_mode(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

class Init_Forcepositionmovejoint_joint
{
public:
  Init_Forcepositionmovejoint_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Forcepositionmovejoint_sensor joint(::rm_ros_interfaces::msg::Forcepositionmovejoint::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_Forcepositionmovejoint_sensor(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Forcepositionmovejoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Forcepositionmovejoint>()
{
  return rm_ros_interfaces::msg::builder::Init_Forcepositionmovejoint_joint();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__BUILDER_HPP_
