// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Armsoftversion.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'planversion'
// Member 'ctrlversion'
// Member 'kernal1'
// Member 'kernal2'
// Member 'productversion'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Armsoftversion in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Armsoftversion
{
  rosidl_runtime_c__String planversion;
  rosidl_runtime_c__String ctrlversion;
  rosidl_runtime_c__String kernal1;
  rosidl_runtime_c__String kernal2;
  rosidl_runtime_c__String productversion;
} rm_ros_interfaces__msg__Armsoftversion;

// Struct for a sequence of rm_ros_interfaces__msg__Armsoftversion.
typedef struct rm_ros_interfaces__msg__Armsoftversion__Sequence
{
  rm_ros_interfaces__msg__Armsoftversion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Armsoftversion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__STRUCT_H_
