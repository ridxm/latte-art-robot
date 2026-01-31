// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Cartepos.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__CARTEPOS__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__CARTEPOS__STRUCT_H_

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

/// Struct defined in msg/Cartepos in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Cartepos
{
  geometry_msgs__msg__Pose pose;
  bool follow;
} rm_ros_interfaces__msg__Cartepos;

// Struct for a sequence of rm_ros_interfaces__msg__Cartepos.
typedef struct rm_ros_interfaces__msg__Cartepos__Sequence
{
  rm_ros_interfaces__msg__Cartepos * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Cartepos__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__CARTEPOS__STRUCT_H_
