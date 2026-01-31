// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Handforce.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDFORCE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDFORCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Handforce in the package rm_ros_interfaces.
/**
  * 设置灵巧手关节力阈值
 */
typedef struct rm_ros_interfaces__msg__Handforce
{
  /// 手指力，范围：1~1000
  uint16_t hand_force;
  bool block;
} rm_ros_interfaces__msg__Handforce;

// Struct for a sequence of rm_ros_interfaces__msg__Handforce.
typedef struct rm_ros_interfaces__msg__Handforce__Sequence
{
  rm_ros_interfaces__msg__Handforce * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Handforce__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDFORCE__STRUCT_H_
