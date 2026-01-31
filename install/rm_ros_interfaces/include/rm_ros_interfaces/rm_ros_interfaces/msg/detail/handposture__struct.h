// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Handposture.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDPOSTURE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDPOSTURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Handposture in the package rm_ros_interfaces.
/**
  * 设置灵巧手手势
 */
typedef struct rm_ros_interfaces__msg__Handposture
{
  /// 预先保存在灵巧手内的手势序号，范围：1~40
  uint16_t posture_num;
  bool block;
} rm_ros_interfaces__msg__Handposture;

// Struct for a sequence of rm_ros_interfaces__msg__Handposture.
typedef struct rm_ros_interfaces__msg__Handposture__Sequence
{
  rm_ros_interfaces__msg__Handposture * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Handposture__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDPOSTURE__STRUCT_H_
