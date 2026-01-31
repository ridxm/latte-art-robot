// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Movec.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_mid'
// Member 'pose_end'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Movec in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Movec
{
  geometry_msgs__msg__Pose pose_mid;
  geometry_msgs__msg__Pose pose_end;
  uint8_t speed;
  uint8_t trajectory_connect;
  bool block;
  uint8_t loop;
} rm_ros_interfaces__msg__Movec;

// Struct for a sequence of rm_ros_interfaces__msg__Movec.
typedef struct rm_ros_interfaces__msg__Movec__Sequence
{
  rm_ros_interfaces__msg__Movec * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Movec__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEC__STRUCT_H_
