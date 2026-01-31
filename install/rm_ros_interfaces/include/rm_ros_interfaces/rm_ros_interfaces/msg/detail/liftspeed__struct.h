// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Liftspeed.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__LIFTSPEED__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__LIFTSPEED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Liftspeed in the package rm_ros_interfaces.
/**
  * 升降机构速度开环控制
  * Speed < 0:升降机构向下运动
  * Speed > 0:升降机构向上运动
  * Speed = 0:升降机构停止运动
 */
typedef struct rm_ros_interfaces__msg__Liftspeed
{
  /// 速度百分比，-100~100
  int16_t speed;
} rm_ros_interfaces__msg__Liftspeed;

// Struct for a sequence of rm_ros_interfaces__msg__Liftspeed.
typedef struct rm_ros_interfaces__msg__Liftspeed__Sequence
{
  rm_ros_interfaces__msg__Liftspeed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Liftspeed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__LIFTSPEED__STRUCT_H_
