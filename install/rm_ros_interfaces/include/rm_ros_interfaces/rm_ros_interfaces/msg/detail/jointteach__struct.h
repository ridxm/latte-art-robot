// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Jointteach.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Jointteach in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Jointteach
{
  /// 示教关节的序号，1~7
  uint8_t num;
  /// 示教方向，0-负方向，1-正方向
  uint8_t direction;
  /// 速度比例1~100，即规划速度和加速度占关节最大线转速和加速度的百分比
  uint8_t speed;
  /// RM_NONBLOCK0-非阻塞，发送后立即返回；RM_BLOCK1-阻塞，等待控制器返回设置成功指令
  bool block;
} rm_ros_interfaces__msg__Jointteach;

// Struct for a sequence of rm_ros_interfaces__msg__Jointteach.
typedef struct rm_ros_interfaces__msg__Jointteach__Sequence
{
  rm_ros_interfaces__msg__Jointteach * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Jointteach__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__STRUCT_H_
