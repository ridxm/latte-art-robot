// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_total_demo:msg/ObjectPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_TOTAL_DEMO__MSG__DETAIL__OBJECT_POSE__STRUCT_H_
#define ROS2_TOTAL_DEMO__MSG__DETAIL__OBJECT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObjectPose in the package ros2_total_demo.
typedef struct ros2_total_demo__msg__ObjectPose
{
  double x;
  double y;
  double z;
} ros2_total_demo__msg__ObjectPose;

// Struct for a sequence of ros2_total_demo__msg__ObjectPose.
typedef struct ros2_total_demo__msg__ObjectPose__Sequence
{
  ros2_total_demo__msg__ObjectPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_total_demo__msg__ObjectPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_TOTAL_DEMO__MSG__DETAIL__OBJECT_POSE__STRUCT_H_
