// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Handspeed.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSPEED__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSPEED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Handspeed in the package rm_ros_interfaces.
/**
  * 设置灵巧手关节速度
 */
typedef struct rm_ros_interfaces__msg__Handspeed
{
  /// 手指速度，范围：1~1000
  uint16_t hand_speed;
  bool block;
} rm_ros_interfaces__msg__Handspeed;

// Struct for a sequence of rm_ros_interfaces__msg__Handspeed.
typedef struct rm_ros_interfaces__msg__Handspeed__Sequence
{
  rm_ros_interfaces__msg__Handspeed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Handspeed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSPEED__STRUCT_H_
