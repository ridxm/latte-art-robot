// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Jointpos.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTPOS__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTPOS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Jointpos in the package rm_ros_interfaces.
/**
  * control arm joints without planning
 */
typedef struct rm_ros_interfaces__msg__Jointpos
{
  rosidl_runtime_c__float__Sequence joint;
  bool follow;
  float expand;
  uint8_t dof;
} rm_ros_interfaces__msg__Jointpos;

// Struct for a sequence of rm_ros_interfaces__msg__Jointpos.
typedef struct rm_ros_interfaces__msg__Jointpos__Sequence
{
  rm_ros_interfaces__msg__Jointpos * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Jointpos__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTPOS__STRUCT_H_
