// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from servo_interfaces:msg/ServoGetAngle.idl
// generated code does not contain a copyright notice

#ifndef SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__BUILDER_HPP_
#define SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "servo_interfaces/msg/detail/servo_get_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace servo_interfaces
{

namespace msg
{

namespace builder
{

class Init_ServoGetAngle_servo_id
{
public:
  Init_ServoGetAngle_servo_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servo_interfaces::msg::ServoGetAngle servo_id(::servo_interfaces::msg::ServoGetAngle::_servo_id_type arg)
  {
    msg_.servo_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servo_interfaces::msg::ServoGetAngle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::servo_interfaces::msg::ServoGetAngle>()
{
  return servo_interfaces::msg::builder::Init_ServoGetAngle_servo_id();
}

}  // namespace servo_interfaces

#endif  // SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__BUILDER_HPP_
