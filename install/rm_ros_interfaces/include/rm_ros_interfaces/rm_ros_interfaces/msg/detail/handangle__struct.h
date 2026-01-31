// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Handangle.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Handangle in the package rm_ros_interfaces.
/**
  * 设置灵巧手角度，灵巧手有 6 个自由度，从 1~6 分别为小拇指，无名指，中指，食指，大拇指弯曲，大拇指旋转
 */
typedef struct rm_ros_interfaces__msg__Handangle
{
  /// 手指角度数组，范围：0~1000.另外，-1 代表该自由度不执行任何操作，保持当前状态
  int16_t hand_angle[6];
  bool block;
} rm_ros_interfaces__msg__Handangle;

// Struct for a sequence of rm_ros_interfaces__msg__Handangle.
typedef struct rm_ros_interfaces__msg__Handangle__Sequence
{
  rm_ros_interfaces__msg__Handangle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Handangle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__STRUCT_H_
