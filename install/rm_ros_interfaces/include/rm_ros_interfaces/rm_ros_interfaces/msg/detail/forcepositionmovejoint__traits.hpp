// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Forcepositionmovejoint.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/forcepositionmovejoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Forcepositionmovejoint & msg,
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

  // member: sensor
  {
    out << "sensor: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: dir
  {
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << ", ";
  }

  // member: force
  {
    out << "force: ";
    rosidl_generator_traits::value_to_yaml(msg.force, out);
    out << ", ";
  }

  // member: follow
  {
    out << "follow: ";
    rosidl_generator_traits::value_to_yaml(msg.follow, out);
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
  const Forcepositionmovejoint & msg,
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

  // member: sensor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor, out);
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

  // member: dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << "\n";
  }

  // member: force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force: ";
    rosidl_generator_traits::value_to_yaml(msg.force, out);
    out << "\n";
  }

  // member: follow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "follow: ";
    rosidl_generator_traits::value_to_yaml(msg.follow, out);
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

inline std::string to_yaml(const Forcepositionmovejoint & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Forcepositionmovejoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Forcepositionmovejoint & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Forcepositionmovejoint>()
{
  return "rm_ros_interfaces::msg::Forcepositionmovejoint";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Forcepositionmovejoint>()
{
  return "rm_ros_interfaces/msg/Forcepositionmovejoint";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Forcepositionmovejoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Forcepositionmovejoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rm_ros_interfaces::msg::Forcepositionmovejoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__TRAITS_HPP_
