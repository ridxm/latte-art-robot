// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from servo_interfaces:msg/ServoMove.idl
// generated code does not contain a copyright notice

#ifndef SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__BUILDER_HPP_
#define SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "servo_interfaces/msg/detail/servo_move__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace servo_interfaces
{

namespace msg
{

namespace builder
{

class Init_ServoMove_angle
{
public:
  explicit Init_ServoMove_angle(::servo_interfaces::msg::ServoMove & msg)
  : msg_(msg)
  {}
  ::servo_interfaces::msg::ServoMove angle(::servo_interfaces::msg::ServoMove::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servo_interfaces::msg::ServoMove msg_;
};

class Init_ServoMove_servo_id
{
public:
  Init_ServoMove_servo_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoMove_angle servo_id(::servo_interfaces::msg::ServoMove::_servo_id_type arg)
  {
    msg_.servo_id = std::move(arg);
    return Init_ServoMove_angle(msg_);
  }

private:
  ::servo_interfaces::msg::ServoMove msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::servo_interfaces::msg::ServoMove>()
{
  return servo_interfaces::msg::builder::Init_ServoMove_servo_id();
}

}  // namespace servo_interfaces

#endif  // SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__BUILDER_HPP_
