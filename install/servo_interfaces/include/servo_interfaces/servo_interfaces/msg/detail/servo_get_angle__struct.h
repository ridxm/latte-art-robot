// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from servo_interfaces:msg/ServoGetAngle.idl
// generated code does not contain a copyright notice

#ifndef SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__STRUCT_H_
#define SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ServoGetAngle in the package servo_interfaces.
/**
  * 读取舵机角度位置值
 */
typedef struct servo_interfaces__msg__ServoGetAngle
{
  /// 舵机ID
  uint16_t servo_id;
} servo_interfaces__msg__ServoGetAngle;

// Struct for a sequence of servo_interfaces__msg__ServoGetAngle.
typedef struct servo_interfaces__msg__ServoGetAngle__Sequence
{
  servo_interfaces__msg__ServoGetAngle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servo_interfaces__msg__ServoGetAngle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__STRUCT_H_
