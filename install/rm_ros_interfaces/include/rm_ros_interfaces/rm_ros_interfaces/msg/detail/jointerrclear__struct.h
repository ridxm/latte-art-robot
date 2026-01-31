// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Jointerrclear.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRCLEAR__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRCLEAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Jointerrclear in the package rm_ros_interfaces.
/**
  * 对指定关节进行使能操作
 */
typedef struct rm_ros_interfaces__msg__Jointerrclear
{
  /// 对应关节序号，从基座到机械臂手爪端，序号依次为1～6
  uint8_t joint_num;
  /// true-阻塞，false-不阻塞
  bool block;
} rm_ros_interfaces__msg__Jointerrclear;

// Struct for a sequence of rm_ros_interfaces__msg__Jointerrclear.
typedef struct rm_ros_interfaces__msg__Jointerrclear__Sequence
{
  rm_ros_interfaces__msg__Jointerrclear * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Jointerrclear__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRCLEAR__STRUCT_H_
