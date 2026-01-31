// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from servo_interfaces:msg/ServoMove.idl
// generated code does not contain a copyright notice

#ifndef SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__FUNCTIONS_H_
#define SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "servo_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "servo_interfaces/msg/detail/servo_move__struct.h"

/// Initialize msg/ServoMove message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * servo_interfaces__msg__ServoMove
 * )) before or use
 * servo_interfaces__msg__ServoMove__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
bool
servo_interfaces__msg__ServoMove__init(servo_interfaces__msg__ServoMove * msg);

/// Finalize msg/ServoMove message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
void
servo_interfaces__msg__ServoMove__fini(servo_interfaces__msg__ServoMove * msg);

/// Create msg/ServoMove message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * servo_interfaces__msg__ServoMove__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
servo_interfaces__msg__ServoMove *
servo_interfaces__msg__ServoMove__create();

/// Destroy msg/ServoMove message.
/**
 * It calls
 * servo_interfaces__msg__ServoMove__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
void
servo_interfaces__msg__ServoMove__destroy(servo_interfaces__msg__ServoMove * msg);

/// Check for msg/ServoMove message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
bool
servo_interfaces__msg__ServoMove__are_equal(const servo_interfaces__msg__ServoMove * lhs, const servo_interfaces__msg__ServoMove * rhs);

/// Copy a msg/ServoMove message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
bool
servo_interfaces__msg__ServoMove__copy(
  const servo_interfaces__msg__ServoMove * input,
  servo_interfaces__msg__ServoMove * output);

/// Initialize array of msg/ServoMove messages.
/**
 * It allocates the memory for the number of elements and calls
 * servo_interfaces__msg__ServoMove__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
bool
servo_interfaces__msg__ServoMove__Sequence__init(servo_interfaces__msg__ServoMove__Sequence * array, size_t size);

/// Finalize array of msg/ServoMove messages.
/**
 * It calls
 * servo_interfaces__msg__ServoMove__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
void
servo_interfaces__msg__ServoMove__Sequence__fini(servo_interfaces__msg__ServoMove__Sequence * array);

/// Create array of msg/ServoMove messages.
/**
 * It allocates the memory for the array and calls
 * servo_interfaces__msg__ServoMove__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
servo_interfaces__msg__ServoMove__Sequence *
servo_interfaces__msg__ServoMove__Sequence__create(size_t size);

/// Destroy array of msg/ServoMove messages.
/**
 * It calls
 * servo_interfaces__msg__ServoMove__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
void
servo_interfaces__msg__ServoMove__Sequence__destroy(servo_interfaces__msg__ServoMove__Sequence * array);

/// Check for msg/ServoMove message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
bool
servo_interfaces__msg__ServoMove__Sequence__are_equal(const servo_interfaces__msg__ServoMove__Sequence * lhs, const servo_interfaces__msg__ServoMove__Sequence * rhs);

/// Copy an array of msg/ServoMove messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_servo_interfaces
bool
servo_interfaces__msg__ServoMove__Sequence__copy(
  const servo_interfaces__msg__ServoMove__Sequence * input,
  servo_interfaces__msg__ServoMove__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SERVO_INTERFACES__MSG__DETAIL__SERVO_MOVE__FUNCTIONS_H_
