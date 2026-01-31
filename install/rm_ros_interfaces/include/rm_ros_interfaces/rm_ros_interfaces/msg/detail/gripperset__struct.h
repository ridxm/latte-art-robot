// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Gripperset.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Gripperset in the package rm_ros_interfaces.
/**
  * 设置手爪到固定位置，手爪到位置后或者所受力超过阈值后停止
 */
typedef struct rm_ros_interfaces__msg__Gripperset
{
  /// 手爪目标位置，范围：1～1000,代表手爪开口度：0～70mm
  uint16_t position;
  bool block;
  /// timeout 设置返回超时时间，阻塞模式生效
  uint16_t timeout;
} rm_ros_interfaces__msg__Gripperset;

// Struct for a sequence of rm_ros_interfaces__msg__Gripperset.
typedef struct rm_ros_interfaces__msg__Gripperset__Sequence
{
  rm_ros_interfaces__msg__Gripperset * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Gripperset__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__STRUCT_H_
