// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_ros_interfaces:msg/Handstatus.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__TRAITS_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_ros_interfaces/msg/detail/handstatus__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_ros_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Handstatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: hand_angle
  {
    if (msg.hand_angle.size() == 0) {
      out << "hand_angle: []";
    } else {
      out << "hand_angle: [";
      size_t pending_items = msg.hand_angle.size();
      for (auto item : msg.hand_angle) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hand_pos
  {
    if (msg.hand_pos.size() == 0) {
      out << "hand_pos: []";
    } else {
      out << "hand_pos: [";
      size_t pending_items = msg.hand_pos.size();
      for (auto item : msg.hand_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hand_state
  {
    if (msg.hand_state.size() == 0) {
      out << "hand_state: []";
    } else {
      out << "hand_state: [";
      size_t pending_items = msg.hand_state.size();
      for (auto item : msg.hand_state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hand_force
  {
    if (msg.hand_force.size() == 0) {
      out << "hand_force: []";
    } else {
      out << "hand_force: [";
      size_t pending_items = msg.hand_force.size();
      for (auto item : msg.hand_force) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hand_err
  {
    out << "hand_err: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_err, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Handstatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hand_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hand_angle.size() == 0) {
      out << "hand_angle: []\n";
    } else {
      out << "hand_angle:\n";
      for (auto item : msg.hand_angle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: hand_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hand_pos.size() == 0) {
      out << "hand_pos: []\n";
    } else {
      out << "hand_pos:\n";
      for (auto item : msg.hand_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: hand_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hand_state.size() == 0) {
      out << "hand_state: []\n";
    } else {
      out << "hand_state:\n";
      for (auto item : msg.hand_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: hand_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hand_force.size() == 0) {
      out << "hand_force: []\n";
    } else {
      out << "hand_force:\n";
      for (auto item : msg.hand_force) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: hand_err
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_err: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_err, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Handstatus & msg, bool use_flow_style = false)
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
  const rm_ros_interfaces::msg::Handstatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_ros_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_ros_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_ros_interfaces::msg::Handstatus & msg)
{
  return rm_ros_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_ros_interfaces::msg::Handstatus>()
{
  return "rm_ros_interfaces::msg::Handstatus";
}

template<>
inline const char * name<rm_ros_interfaces::msg::Handstatus>()
{
  return "rm_ros_interfaces/msg/Handstatus";
}

template<>
struct has_fixed_size<rm_ros_interfaces::msg::Handstatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_ros_interfaces::msg::Handstatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_ros_interfaces::msg::Handstatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__TRAITS_HPP_
