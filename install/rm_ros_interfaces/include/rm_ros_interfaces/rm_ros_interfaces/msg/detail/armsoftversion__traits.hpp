// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Armsoftversion.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/armsoftversion__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Armsoftversion & msg,
  std::ostream & out)
{
  out << "{";
  // member: planversion
  {
    out << "planversion: ";
    rosidl_generator_traits::value_to_yaml(msg.planversion, out);
    out << ", ";
  }

  // member: ctrlversion
  {
    out << "ctrlversion: ";
    rosidl_generator_traits::value_to_yaml(msg.ctrlversion, out);
    out << ", ";
  }

  // member: kernal1
  {
    out << "kernal1: ";
    rosidl_generator_traits::value_to_yaml(msg.kernal1, out);
    out << ", ";
  }

  // member: kernal2
  {
    out << "kernal2: ";
    rosidl_generator_traits::value_to_yaml(msg.kernal2, out);
    out << ", ";
  }

  // member: productversion
  {
    out << "productversion: ";
    rosidl_generator_traits::value_to_yaml(msg.productversion, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Armsoftversion & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: planversion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "planversion: ";
    rosidl_generator_traits::value_to_yaml(msg.planversion, out);
    out << "\n";
  }

  // member: ctrlversion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ctrlversion: ";
    rosidl_generator_traits::value_to_yaml(msg.ctrlversion, out);
    out << "\n";
  }

  // member: kernal1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kernal1: ";
    rosidl_generator_traits::value_to_yaml(msg.kernal1, out);
    out << "\n";
  }

  // member: kernal2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kernal2: ";
    rosidl_generator_traits::value_to_yaml(msg.kernal2, out);
    out << "\n";
  }

  // member: productversion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "productversion: ";
    rosidl_generator_traits::value_to_yaml(msg.productversion, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Armsoftversion & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Armsoftversion & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Armsoftversion & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Armsoftversion>()
{
  return "rm_ros_interfaces::msg::Armsoftversion";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Armsoftversion>()
{
  return "rm_ros_interfaces/msg/Armsoftversion";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Armsoftversion>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Armsoftversion>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rm_ros_interfaces::msg::Armsoftversion>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__TRAITS_HPP_
