// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Jointerrorcode.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/jointerrorcode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Jointerrorcode & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_error
  {
    if (msg.joint_error.size() == 0) {
      out << "joint_error: []";
    } else {
      out << "joint_error: [";
      size_t pending_items = msg.joint_error.size();
      for (auto item : msg.joint_error) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: dof
  {
    out << "dof: ";
    rosidl_generator_traits::value_to_yaml(msg.dof, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Jointerrorcode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_error.size() == 0) {
      out << "joint_error: []\n";
    } else {
      out << "joint_error:\n";
      for (auto item : msg.joint_error) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: dof
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dof: ";
    rosidl_generator_traits::value_to_yaml(msg.dof, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Jointerrorcode & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Jointerrorcode & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Jointerrorcode & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Jointerrorcode>()
{
  return "rm_ros_interfaces::msg::Jointerrorcode";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Jointerrorcode>()
{
  return "rm_ros_interfaces/msg/Jointerrorcode";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Jointerrorcode>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Jointerrorcode>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rm_ros_interfaces::msg::Jointerrorcode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__TRAITS_HPP_
