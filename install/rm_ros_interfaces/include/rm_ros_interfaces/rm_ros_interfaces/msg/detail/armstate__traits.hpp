// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Armstate.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMSTATE__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMSTATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/armstate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Armstate & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint
  {
    if (msg.joint.size() == 0) {
      out << "joint: []";
    } else {
      out << "joint: [";
      size_t pending_items = msg.joint.size();
      for (auto item : msg.joint) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: arm_err
  {
    out << "arm_err: ";
    rosidl_generator_traits::value_to_yaml(msg.arm_err, out);
    out << ", ";
  }

  // member: sys_err
  {
    out << "sys_err: ";
    rosidl_generator_traits::value_to_yaml(msg.sys_err, out);
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
  const Armstate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint.size() == 0) {
      out << "joint: []\n";
    } else {
      out << "joint:\n";
      for (auto item : msg.joint) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: arm_err
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arm_err: ";
    rosidl_generator_traits::value_to_yaml(msg.arm_err, out);
    out << "\n";
  }

  // member: sys_err
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sys_err: ";
    rosidl_generator_traits::value_to_yaml(msg.sys_err, out);
    out << "\n";
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

inline std::string to_yaml(const Armstate & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Armstate & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Armstate & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Armstate>()
{
  return "rm_ros_interfaces::msg::Armstate";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Armstate>()
{
  return "rm_ros_interfaces/msg/Armstate";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Armstate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Armstate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rm_ros_interfaces::msg::Armstate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMSTATE__TRAITS_HPP_
