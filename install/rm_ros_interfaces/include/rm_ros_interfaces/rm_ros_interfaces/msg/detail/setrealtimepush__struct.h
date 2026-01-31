// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Setrealtimepush.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ip'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Setrealtimepush in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Setrealtimepush
{
  uint16_t cycle;
  uint16_t port;
  uint16_t force_coordinate;
  rosidl_runtime_c__String ip;
  bool hand_enable;
} rm_ros_interfaces__msg__Setrealtimepush;

// Struct for a sequence of rm_ros_interfaces__msg__Setrealtimepush.
typedef struct rm_ros_interfaces__msg__Setrealtimepush__Sequence
{
  rm_ros_interfaces__msg__Setrealtimepush * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Setrealtimepush__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__STRUCT_H_
