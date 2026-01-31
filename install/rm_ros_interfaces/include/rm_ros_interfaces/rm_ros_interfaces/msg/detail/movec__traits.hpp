// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Movec.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/movec__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_mid'
// Member 'pose_end'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Movec & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_mid
  {
    out << "pose_mid: ";
    to_flow_style_yaml(msg.pose_mid, out);
    out << ", ";
  }

  // member: pose_end
  {
    out << "pose_end: ";
    to_flow_style_yaml(msg.pose_end, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: trajectory_connect
  {
    out << "trajectory_connect: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_connect, out);
    out << ", ";
  }

  // member: block
  {
    out << "block: ";
    rosidl_generator_traits::value_to_yaml(msg.block, out);
    out << ", ";
  }

  // member: loop
  {
    out << "loop: ";
    rosidl_generator_traits::value_to_yaml(msg.loop, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Movec & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_mid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_mid:\n";
    to_block_style_yaml(msg.pose_mid, out, indentation + 2);
  }

  // member: pose_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_end:\n";
    to_block_style_yaml(msg.pose_end, out, indentation + 2);
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: trajectory_connect
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory_connect: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_connect, out);
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

  // member: loop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loop: ";
    rosidl_generator_traits::value_to_yaml(msg.loop, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Movec & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Movec & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Movec & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Movec>()
{
  return "rm_ros_interfaces::msg::Movec";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Movec>()
{
  return "rm_ros_interfaces/msg/Movec";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Movec>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Movec>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<rm_ros_interfaces::msg::Movec>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__TRAITS_HPP_
