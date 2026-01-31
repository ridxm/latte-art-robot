// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Forcepositionmovepose.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Forcepositionmovepose in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Forcepositionmovepose
{
  geometry_msgs__msg__Pose pose;
  uint8_t sensor;
  uint8_t mode;
  uint8_t dir;
  int16_t force;
  bool follow;
} rm_ros_interfaces__msg__Forcepositionmovepose;

// Struct for a sequence of rm_ros_interfaces__msg__Forcepositionmovepose.
typedef struct rm_ros_interfaces__msg__Forcepositionmovepose__Sequence
{
  rm_ros_interfaces__msg__Forcepositionmovepose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Forcepositionmovepose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__STRUCT_H_
