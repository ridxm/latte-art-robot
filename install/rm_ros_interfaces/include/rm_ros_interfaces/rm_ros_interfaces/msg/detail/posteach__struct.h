// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_ros_interfaces:msg/Posteach.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__POSTEACH__STRUCT_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__POSTEACH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Posteach in the package rm_ros_interfaces.
/**
  * POS_TEACH_MODES type  示教类型
  * typedef enum
  * {
  *     X_Dir = 0,       //X轴方向
  *      Y_Dir = 1,       //Y轴方向
  *     Z_Dir = 2,       //Z轴方向
  * }POS_TEACH_MODES;
 */
typedef struct rm_ros_interfaces__msg__Posteach
{
  /// 示教类型 输入0 | 1 | 2
  uint8_t type;
  /// 示教方向，0-负方向，1-正方向
  uint8_t direction;
  /// 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
  uint8_t speed;
  /// RM_NONBLOCK0-非阻塞，发送后立即返回；RM_BLOCK1-阻塞，等待控制器返回设置成功指令
  bool block;
} rm_ros_interfaces__msg__Posteach;

// Struct for a sequence of rm_ros_interfaces__msg__Posteach.
typedef struct rm_ros_interfaces__msg__Posteach__Sequence
{
  rm_ros_interfaces__msg__Posteach * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_ros_interfaces__msg__Posteach__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__POSTEACH__STRUCT_H_
