// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from servo_interfaces:msg/ServoMove.idl
// generated code does not contain a copyright notice

#ifndef SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__TRAITS_HPP_
#define SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "servo_interfaces/msg/detail/servo_move__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace servo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoMove & msg,
  std::ostream & out)
{
  out << "{";
  // member: servo_id
  {
    out << "servo_id: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_id, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoMove & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: servo_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_id: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_id, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoMove & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace servo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use servo_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const servo_interfaces::msg::ServoMove & msg,
  std::ostream & out, size_t indentation = 0)
{
  servo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use servo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const servo_interfaces::msg::ServoMove & msg)
{
  return servo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<servo_interfaces::msg::ServoMove>()
{
  return "servo_interfaces::msg::ServoMove";
}

template<>
inline const char * name<servo_interfaces::msg::ServoMove>()
{
  return "servo_interfaces/msg/ServoMove";
}

template<>
struct has_fixed_size<servo_interfaces::msg::ServoMove>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<servo_interfaces::msg::ServoMove>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<servo_interfaces::msg::ServoMove>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__TRAITS_HPP_
