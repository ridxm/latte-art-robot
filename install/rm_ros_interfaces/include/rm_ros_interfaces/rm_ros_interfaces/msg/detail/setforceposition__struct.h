// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Setforceposition.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Setforceposition in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Setforceposition
{
  uint8_t sensor;
  uint8_t mode;
  uint8_t direction;
  int16_t n;
  bool block;
} rm_ros_interfaces__msg__Setforceposition;

// Struct for a sequence of rm_ros_interfaces__msg__Setforceposition.
typedef struct rm_ros_interfaces__msg__Setforceposition__Sequence
{
  rm_ros_interfaces__msg__Setforceposition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Setforceposition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__STRUCT_H_
