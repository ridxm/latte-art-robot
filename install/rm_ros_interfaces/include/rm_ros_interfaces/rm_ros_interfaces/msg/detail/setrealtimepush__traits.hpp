// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Setrealtimepush.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/setrealtimepush__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Setrealtimepush & msg,
  std::ostream & out)
{
  out << "{";
  // member: cycle
  {
    out << "cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.cycle, out);
    out << ", ";
  }

  // member: port
  {
    out << "port: ";
    rosidl_generator_traits::value_to_yaml(msg.port, out);
    out << ", ";
  }

  // member: force_coordinate
  {
    out << "force_coordinate: ";
    rosidl_generator_traits::value_to_yaml(msg.force_coordinate, out);
    out << ", ";
  }

  // member: ip
  {
    out << "ip: ";
    rosidl_generator_traits::value_to_yaml(msg.ip, out);
    out << ", ";
  }

  // member: hand_enable
  {
    out << "hand_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_enable, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Setrealtimepush & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cycle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.cycle, out);
    out << "\n";
  }

  // member: port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "port: ";
    rosidl_generator_traits::value_to_yaml(msg.port, out);
    out << "\n";
  }

  // member: force_coordinate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_coordinate: ";
    rosidl_generator_traits::value_to_yaml(msg.force_coordinate, out);
    out << "\n";
  }

  // member: ip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ip: ";
    rosidl_generator_traits::value_to_yaml(msg.ip, out);
    out << "\n";
  }

  // member: hand_enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_enable, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Setrealtimepush & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Setrealtimepush & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Setrealtimepush & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Setrealtimepush>()
{
  return "rm_ros_interfaces::msg::Setrealtimepush";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Setrealtimepush>()
{
  return "rm_ros_interfaces/msg/Setrealtimepush";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Setrealtimepush>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Setrealtimepush>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rm_ros_interfaces::msg::Setrealtimepush>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__TRAITS_HPP_
