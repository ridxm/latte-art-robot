// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Setforceposition.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/setforceposition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Setforceposition_block
{
public:
  explicit Init_Setforceposition_block(::rm_ros_interfaces::msg::Setforceposition & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Setforceposition block(::rm_ros_interfaces::msg::Setforceposition::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Setforceposition msg_;
};

class Init_Setforceposition_n
{
public:
  explicit Init_Setforceposition_n(::rm_ros_interfaces::msg::Setforceposition & msg)
  : msg_(msg)
  {}
  Init_Setforceposition_block n(::rm_ros_interfaces::msg::Setforceposition::_n_type arg)
  {
    msg_.n = std::move(arg);
    return Init_Setforceposition_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Setforceposition msg_;
};

class Init_Setforceposition_direction
{
public:
  explicit Init_Setforceposition_direction(::rm_ros_interfaces::msg::Setforceposition & msg)
  : msg_(msg)
  {}
  Init_Setforceposition_n direction(::rm_ros_interfaces::msg::Setforceposition::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Setforceposition_n(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Setforceposition msg_;
};

class Init_Setforceposition_mode
{
public:
  explicit Init_Setforceposition_mode(::rm_ros_interfaces::msg::Setforceposition & msg)
  : msg_(msg)
  {}
  Init_Setforceposition_direction mode(::rm_ros_interfaces::msg::Setforceposition::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Setforceposition_direction(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Setforceposition msg_;
};

class Init_Setforceposition_sensor
{
public:
  Init_Setforceposition_sensor()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Setforceposition_mode sensor(::rm_ros_interfaces::msg::Setforceposition::_sensor_type arg)
  {
    msg_.sensor = std::move(arg);
    return Init_Setforceposition_mode(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Setforceposition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Setforceposition>()
{
  return rm_ros_interfaces::msg::builder::Init_Setforceposition_sensor();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__BUILDER_HPP_
