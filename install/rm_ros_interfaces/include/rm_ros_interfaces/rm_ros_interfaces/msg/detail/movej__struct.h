// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Movej.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Movej in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Movej
{
  rosidl_runtime_c__float__Sequence joint;
  uint8_t speed;
  bool block;
  /// 0 代表立即规划，1 代表和下一条轨迹一起规划，当为 1 时，轨迹不会立即执行
  uint8_t trajectory_connect;
  uint8_t dof;
} rm_ros_interfaces__msg__Movej;

// Struct for a sequence of rm_ros_interfaces__msg__Movej.
typedef struct rm_ros_interfaces__msg__Movej__Sequence
{
  rm_ros_interfaces__msg__Movej * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Movej__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__STRUCT_H_
