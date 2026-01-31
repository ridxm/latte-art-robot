// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Gripperpick.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Gripperpick in the package rm_ros_interfaces.
/**
  * 手爪以设定的速度力控夹取，当受力超过设定力后，停止运动
 */
typedef struct rm_ros_interfaces__msg__Gripperpick
{
  /// 1~1000,代表手爪开合速度，无量纲
  uint16_t speed;
  /// 1～1000,代表手爪夹持力，最大1.5kg
  uint16_t force;
  bool block;
  /// timeout 设置返回超时时间，阻塞模式生效
  uint16_t timeout;
} rm_ros_interfaces__msg__Gripperpick;

// Struct for a sequence of rm_ros_interfaces__msg__Gripperpick.
typedef struct rm_ros_interfaces__msg__Gripperpick__Sequence
{
  rm_ros_interfaces__msg__Gripperpick * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Gripperpick__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__STRUCT_H_
