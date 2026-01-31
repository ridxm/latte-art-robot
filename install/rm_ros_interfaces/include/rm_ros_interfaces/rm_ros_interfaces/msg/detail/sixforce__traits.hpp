// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Sixforce.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/sixforce__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Sixforce & msg,
  std::ostream & out)
{
  out << "{";
  // member: force_fx
  {
    out << "force_fx: ";
    rosidl_generator_traits::value_to_yaml(msg.force_fx, out);
    out << ", ";
  }

  // member: force_fy
  {
    out << "force_fy: ";
    rosidl_generator_traits::value_to_yaml(msg.force_fy, out);
    out << ", ";
  }

  // member: force_fz
  {
    out << "force_fz: ";
    rosidl_generator_traits::value_to_yaml(msg.force_fz, out);
    out << ", ";
  }

  // member: force_mx
  {
    out << "force_mx: ";
    rosidl_generator_traits::value_to_yaml(msg.force_mx, out);
    out << ", ";
  }

  // member: force_my
  {
    out << "force_my: ";
    rosidl_generator_traits::value_to_yaml(msg.force_my, out);
    out << ", ";
  }

  // member: force_mz
  {
    out << "force_mz: ";
    rosidl_generator_traits::value_to_yaml(msg.force_mz, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Sixforce & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: force_fx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_fx: ";
    rosidl_generator_traits::value_to_yaml(msg.force_fx, out);
    out << "\n";
  }

  // member: force_fy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_fy: ";
    rosidl_generator_traits::value_to_yaml(msg.force_fy, out);
    out << "\n";
  }

  // member: force_fz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_fz: ";
    rosidl_generator_traits::value_to_yaml(msg.force_fz, out);
    out << "\n";
  }

  // member: force_mx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_mx: ";
    rosidl_generator_traits::value_to_yaml(msg.force_mx, out);
    out << "\n";
  }

  // member: force_my
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_my: ";
    rosidl_generator_traits::value_to_yaml(msg.force_my, out);
    out << "\n";
  }

  // member: force_mz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_mz: ";
    rosidl_generator_traits::value_to_yaml(msg.force_mz, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Sixforce & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Sixforce & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Sixforce & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Sixforce>()
{
  return "rm_ros_interfaces::msg::Sixforce";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Sixforce>()
{
  return "rm_ros_interfaces/msg/Sixforce";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Sixforce>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Sixforce>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_ros_interfaces::msg::Sixforce>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__TRAITS_HPP_
