// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Handseq.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/handseq__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Handseq & msg,
  std::ostream & out)
{
  out << "{";
  // member: seq_num
  {
    out << "seq_num: ";
    rosidl_generator_traits::value_to_yaml(msg.seq_num, out);
    out << ", ";
  }

  // member: block
  {
    out << "block: ";
    rosidl_generator_traits::value_to_yaml(msg.block, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Handseq & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: seq_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seq_num: ";
    rosidl_generator_traits::value_to_yaml(msg.seq_num, out);
    out << "\n";
  }

  // member: block
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "block: ";
    rosidl_generator_traits::value_to_yaml(msg.block, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Handseq & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Handseq & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Handseq & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Handseq>()
{
  return "rm_ros_interfaces::msg::Handseq";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Handseq>()
{
  return "rm_ros_interfaces/msg/Handseq";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Handseq>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Handseq>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_ros_interfaces::msg::Handseq>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__TRAITS_HPP_
