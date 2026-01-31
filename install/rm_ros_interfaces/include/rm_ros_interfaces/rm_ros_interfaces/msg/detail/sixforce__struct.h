// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Sixforce.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Sixforce in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Sixforce
{
  float force_fx;
  float force_fy;
  float force_fz;
  float force_mx;
  float force_my;
  float force_mz;
} rm_ros_interfaces__msg__Sixforce;

// Struct for a sequence of rm_ros_interfaces__msg__Sixforce.
typedef struct rm_ros_interfaces__msg__Sixforce__Sequence
{
  rm_ros_interfaces__msg__Sixforce * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Sixforce__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__STRUCT_H_
