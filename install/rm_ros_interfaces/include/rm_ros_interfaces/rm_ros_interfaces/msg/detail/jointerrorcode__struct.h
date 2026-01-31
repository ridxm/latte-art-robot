// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Jointerrorcode.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_error'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Jointerrorcode in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Jointerrorcode
{
  /// 每个关节报错信息
  rosidl_runtime_c__uint16__Sequence joint_error;
  uint8_t dof;
} rm_ros_interfaces__msg__Jointerrorcode;

// Struct for a sequence of rm_ros_interfaces__msg__Jointerrorcode.
typedef struct rm_ros_interfaces__msg__Jointerrorcode__Sequence
{
  rm_ros_interfaces__msg__Jointerrorcode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Jointerrorcode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__STRUCT_H_
