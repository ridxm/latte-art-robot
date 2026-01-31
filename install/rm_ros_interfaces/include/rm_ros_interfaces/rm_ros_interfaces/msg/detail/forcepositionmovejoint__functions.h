// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rm_ros_interfaces:msg/Forcepositionmovejoint.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__FUNCTIONS_H_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rm_ros_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rm_ros_interfaces/msg/detail/forcepositionmovejoint__struct.h"

/// Initialize msg/Forcepositionmovejoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rm_ros_interfaces__msg__Forcepositionmovejoint
 * )) before or use
 * rm_ros_interfaces__msg__Forcepositionmovejoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Forcepositionmovejoint__init(rm_ros_interfaces__msg__Forcepositionmovejoint * msg);

/// Finalize msg/Forcepositionmovejoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Forcepositionmovejoint__fini(rm_ros_interfaces__msg__Forcepositionmovejoint * msg);

/// Create msg/Forcepositionmovejoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rm_ros_interfaces__msg__Forcepositionmovejoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
rm_ros_interfaces__msg__Forcepositionmovejoint *
rm_ros_interfaces__msg__Forcepositionmovejoint__create();

/// Destroy msg/Forcepositionmovejoint message.
/**
 * It calls
 * rm_ros_interfaces__msg__Forcepositionmovejoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Forcepositionmovejoint__destroy(rm_ros_interfaces__msg__Forcepositionmovejoint * msg);

/// Check for msg/Forcepositionmovejoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Forcepositionmovejoint__are_equal(const rm_ros_interfaces__msg__Forcepositionmovejoint * lhs, const rm_ros_interfaces__msg__Forcepositionmovejoint * rhs);

/// Copy a msg/Forcepositionmovejoint message.
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
rm_ros_interfaces__msg__Forcepositionmovejoint__copy(
  const rm_ros_interfaces__msg__Forcepositionmovejoint * input,
  rm_ros_interfaces__msg__Forcepositionmovejoint * output);

/// Initialize array of msg/Forcepositionmovejoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * rm_ros_interfaces__msg__Forcepositionmovejoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__init(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array, size_t size);

/// Finalize array of msg/Forcepositionmovejoint messages.
/**
 * It calls
 * rm_ros_interfaces__msg__Forcepositionmovejoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__fini(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array);

/// Create array of msg/Forcepositionmovejoint messages.
/**
 * It allocates the memory for the array and calls
 * rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence *
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__create(size_t size);

/// Destroy array of msg/Forcepositionmovejoint messages.
/**
 * It calls
 * rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
void
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__destroy(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array);

/// Check for msg/Forcepositionmovejoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_ros_interfaces
bool
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__are_equal(const rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * lhs, const rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * rhs);

/// Copy an array of msg/Forcepositionmovejoint messages.
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
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__copy(
  const rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * input,
  rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__FUNCTIONS_H_
