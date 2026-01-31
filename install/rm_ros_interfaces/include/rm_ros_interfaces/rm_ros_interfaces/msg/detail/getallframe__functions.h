// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rm_ros_interfaces:msg/Getallframe.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__FUNCTIONS_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rm_ros_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rm_ros_interfaces/msg/detail/getallframe__struct.h"

/// Initialize msg/Getallframe message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rm_ros_interfaces__msg__Getallframe
 * )) before or use
 * rm_ros_interfaces__msg__Getallframe__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Getallframe__init(rm_ros_interfaces__msg__Getallframe * msg);

/// Finalize msg/Getallframe message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Getallframe__fini(rm_ros_interfaces__msg__Getallframe * msg);

/// Create msg/Getallframe message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rm_ros_interfaces__msg__Getallframe__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
rm_ros_interfaces__msg__Getallframe *
rm_ros_interfaces__msg__Getallframe__create();

/// Destroy msg/Getallframe message.
/**
 * It calls
 * rm_ros_interfaces__msg__Getallframe__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Getallframe__destroy(rm_ros_interfaces__msg__Getallframe * msg);

/// Check for msg/Getallframe message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Getallframe__are_equal(const rm_ros_interfaces__msg__Getallframe * lhs, const rm_ros_interfaces__msg__Getallframe * rhs);

/// Copy a msg/Getallframe message.
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
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Getallframe__copy(
  const rm_ros_interfaces__msg__Getallframe * input,
  rm_ros_interfaces__msg__Getallframe * output);

/// Initialize array of msg/Getallframe messages.
/**
 * It allocates the memory for the number of elements and calls
 * rm_ros_interfaces__msg__Getallframe__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Getallframe__Sequence__init(rm_ros_interfaces__msg__Getallframe__Sequence * array, size_t size);

/// Finalize array of msg/Getallframe messages.
/**
 * It calls
 * rm_ros_interfaces__msg__Getallframe__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Getallframe__Sequence__fini(rm_ros_interfaces__msg__Getallframe__Sequence * array);

/// Create array of msg/Getallframe messages.
/**
 * It allocates the memory for the array and calls
 * rm_ros_interfaces__msg__Getallframe__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
rm_ros_interfaces__msg__Getallframe__Sequence *
rm_ros_interfaces__msg__Getallframe__Sequence__create(size_t size);

/// Destroy array of msg/Getallframe messages.
/**
 * It calls
 * rm_ros_interfaces__msg__Getallframe__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Getallframe__Sequence__destroy(rm_ros_interfaces__msg__Getallframe__Sequence * array);

/// Check for msg/Getallframe message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Getallframe__Sequence__are_equal(const rm_ros_interfaces__msg__Getallframe__Sequence * lhs, const rm_ros_interfaces__msg__Getallframe__Sequence * rhs);

/// Copy an array of msg/Getallframe messages.
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
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Getallframe__Sequence__copy(
  const rm_ros_interfaces__msg__Getallframe__Sequence * input,
  rm_ros_interfaces__msg__Getallframe__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GETALLFRAME__FUNCTIONS_H_
