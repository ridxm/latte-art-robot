// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Handstatus.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Handstatus in the package rm_ros_interfaces.
typedef struct rm_ros_interfaces__msg__Handstatus
{
  /// 手指角度数组，范围：0~2000.
  uint16_t hand_angle[6];
  /// 手指位置数组，范围：0~1000.
  uint16_t hand_pos[6];
  /// 手指状态,0正在松开，1正在抓取，2位置到位停止，3力到位停止，5电流保护停止，6电缸堵转停止，7电缸故障停止
  uint16_t hand_state[6];
  /// 灵巧手自由度电流，单位mN
  uint16_t hand_force[6];
  /// 灵巧手系统错误，1表示有错误，0表示无错误
  uint16_t hand_err;
} rm_ros_interfaces__msg__Handstatus;

// Struct for a sequence of rm_ros_interfaces__msg__Handstatus.
typedef struct rm_ros_interfaces__msg__Handstatus__Sequence
{
  rm_ros_interfaces__msg__Handstatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Handstatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__STRUCT_H_
