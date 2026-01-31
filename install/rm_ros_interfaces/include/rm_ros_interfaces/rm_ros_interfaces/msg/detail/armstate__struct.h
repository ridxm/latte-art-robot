// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Armstate.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMSTATE__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMSTATE__STRUCT_H_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Armstate in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Armstate
{
  rosidl_runtime_c__float__Sequence joint;
  geometry_msgs__msg__Pose pose;
  uint16_t arm_err;
  uint16_t sys_err;
  uint8_t dof;
} rm_ros_interfaces__msg__Armstate;

// Struct for a sequence of rm_ros_interfaces__msg__Armstate.
typedef struct rm_ros_interfaces__msg__Armstate__Sequence
{
  rm_ros_interfaces__msg__Armstate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Armstate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMSTATE__STRUCT_H_
