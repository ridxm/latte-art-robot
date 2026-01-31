// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Getallframe.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'frame_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Getallframe in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Getallframe
{
  rosidl_runtime_c__String frame_name[10];
} rm_ros_interfaces__msg__Getallframe;

// Struct for a sequence of rm_ros_interfaces__msg__Getallframe.
typedef struct rm_ros_interfaces__msg__Getallframe__Sequence
{
  rm_ros_interfaces__msg__Getallframe * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Getallframe__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__STRUCT_H_
