// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Liftstate.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__LIFTSTATE__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__LIFTSTATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/liftstate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Liftstate & msg,
  std::ostream & out)
{
  out << "{";
  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: err_flag
  {
    out << "err_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.err_flag, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Liftstate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: err_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.err_flag, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Liftstate & msg, bool use_flow_style = false)
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

}  // namespace rm_ros_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rm_ros_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rm_ros_interfaces::msg::Liftstate & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Liftstate & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Liftstate>()
{
  return "rm_ros_interfaces::msg::Liftstate";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Liftstate>()
{
  return "rm_ros_interfaces/msg/Liftstate";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Liftstate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Liftstate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_ros_interfaces::msg::Liftstate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__LIFTSTATE__TRAITS_HPP_
