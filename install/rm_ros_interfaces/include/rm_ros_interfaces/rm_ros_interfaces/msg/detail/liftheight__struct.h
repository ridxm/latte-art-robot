// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Liftheight.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__LIFTHEIGHT__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__LIFTHEIGHT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Liftheight in the package rm_ros_interfaces.
/**
  * 升降机构运行到指定高度
 */
typedef struct rm_ros_interfaces__msg__Liftheight
{
  /// 目标高度，单位 mm，范围：0~2600
  uint16_t height;
  /// 速度百分比，1~100
  uint16_t speed;
  bool block;
} rm_ros_interfaces__msg__Liftheight;

// Struct for a sequence of rm_ros_interfaces__msg__Liftheight.
typedef struct rm_ros_interfaces__msg__Liftheight__Sequence
{
  rm_ros_interfaces__msg__Liftheight * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Liftheight__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__LIFTHEIGHT__STRUCT_H_
