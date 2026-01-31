// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Armstate.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/armstate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
rm_ros_interfaces__msg__Armstate__init(rm_ros_interfaces__msg__Armstate * msg)
{
  if (!msg) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint, 0)) {
    rm_ros_interfaces__msg__Armstate__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    rm_ros_interfaces__msg__Armstate__fini(msg);
    return false;
  }
  // arm_err
  // sys_err
  // dof
  return true;
}

void
rm_ros_interfaces__msg__Armstate__fini(rm_ros_interfaces__msg__Armstate * msg)
{
  if (!msg) {
    return;
  }
  // joint
  rosidl_runtime_c__float__Sequence__fini(&msg->joint);
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // arm_err
  // sys_err
  // dof
}

bool
rm_ros_interfaces__msg__Armstate__are_equal(const rm_ros_interfaces__msg__Armstate * lhs, const rm_ros_interfaces__msg__Armstate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint), &(rhs->joint)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // arm_err
  if (lhs->arm_err != rhs->arm_err) {
    return false;
  }
  // sys_err
  if (lhs->sys_err != rhs->sys_err) {
    return false;
  }
  // dof
  if (lhs->dof != rhs->dof) {
    return false;
  }
  return true;
}

bool
rm_ros_interfaces__msg__Armstate__copy(
  const rm_ros_interfaces__msg__Armstate * input,
  rm_ros_interfaces__msg__Armstate * output)
{
  if (!input || !output) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint), &(output->joint)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // arm_err
  output->arm_err = input->arm_err;
  // sys_err
  output->sys_err = input->sys_err;
  // dof
  output->dof = input->dof;
  return true;
}

rm_ros_interfaces__msg__Armstate *
rm_ros_interfaces__msg__Armstate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Armstate * msg = (rm_ros_interfaces__msg__Armstate *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Armstate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Armstate));
  bool success = rm_ros_interfaces__msg__Armstate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Armstate__destroy(rm_ros_interfaces__msg__Armstate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Armstate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Armstate__Sequence__init(rm_ros_interfaces__msg__Armstate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Armstate * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Armstate *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Armstate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Armstate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Armstate__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rm_ros_interfaces__msg__Armstate__Sequence__fini(rm_ros_interfaces__msg__Armstate__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rm_ros_interfaces__msg__Armstate__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rm_ros_interfaces__msg__Armstate__Sequence *
rm_ros_interfaces__msg__Armstate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Armstate__Sequence * array = (rm_ros_interfaces__msg__Armstate__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Armstate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Armstate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Armstate__Sequence__destroy(rm_ros_interfaces__msg__Armstate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Armstate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Armstate__Sequence__are_equal(const rm_ros_interfaces__msg__Armstate__Sequence * lhs, const rm_ros_interfaces__msg__Armstate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Armstate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Armstate__Sequence__copy(
  const rm_ros_interfaces__msg__Armstate__Sequence * input,
  rm_ros_interfaces__msg__Armstate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Armstate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Armstate * data =
      (rm_ros_interfaces__msg__Armstate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Armstate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Armstate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Armstate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
