// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Jointpos.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/jointpos__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rm_ros_interfaces__msg__Jointpos__init(rm_ros_interfaces__msg__Jointpos * msg)
{
  if (!msg) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint, 0)) {
    rm_ros_interfaces__msg__Jointpos__fini(msg);
    return false;
  }
  // follow
  // expand
  // dof
  return true;
}

void
rm_ros_interfaces__msg__Jointpos__fini(rm_ros_interfaces__msg__Jointpos * msg)
{
  if (!msg) {
    return;
  }
  // joint
  rosidl_runtime_c__float__Sequence__fini(&msg->joint);
  // follow
  // expand
  // dof
}

bool
rm_ros_interfaces__msg__Jointpos__are_equal(const rm_ros_interfaces__msg__Jointpos * lhs, const rm_ros_interfaces__msg__Jointpos * rhs)
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
  // follow
  if (lhs->follow != rhs->follow) {
    return false;
  }
  // expand
  if (lhs->expand != rhs->expand) {
    return false;
  }
  // dof
  if (lhs->dof != rhs->dof) {
    return false;
  }
  return true;
}

bool
rm_ros_interfaces__msg__Jointpos__copy(
  const rm_ros_interfaces__msg__Jointpos * input,
  rm_ros_interfaces__msg__Jointpos * output)
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
  // follow
  output->follow = input->follow;
  // expand
  output->expand = input->expand;
  // dof
  output->dof = input->dof;
  return true;
}

rm_ros_interfaces__msg__Jointpos *
rm_ros_interfaces__msg__Jointpos__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Jointpos * msg = (rm_ros_interfaces__msg__Jointpos *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Jointpos), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Jointpos));
  bool success = rm_ros_interfaces__msg__Jointpos__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Jointpos__destroy(rm_ros_interfaces__msg__Jointpos * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Jointpos__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Jointpos__Sequence__init(rm_ros_interfaces__msg__Jointpos__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Jointpos * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Jointpos *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Jointpos), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Jointpos__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Jointpos__fini(&data[i - 1]);
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
rm_ros_interfaces__msg__Jointpos__Sequence__fini(rm_ros_interfaces__msg__Jointpos__Sequence * array)
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
      rm_ros_interfaces__msg__Jointpos__fini(&array->data[i]);
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

rm_ros_interfaces__msg__Jointpos__Sequence *
rm_ros_interfaces__msg__Jointpos__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Jointpos__Sequence * array = (rm_ros_interfaces__msg__Jointpos__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Jointpos__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Jointpos__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Jointpos__Sequence__destroy(rm_ros_interfaces__msg__Jointpos__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Jointpos__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Jointpos__Sequence__are_equal(const rm_ros_interfaces__msg__Jointpos__Sequence * lhs, const rm_ros_interfaces__msg__Jointpos__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Jointpos__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Jointpos__Sequence__copy(
  const rm_ros_interfaces__msg__Jointpos__Sequence * input,
  rm_ros_interfaces__msg__Jointpos__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Jointpos);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Jointpos * data =
      (rm_ros_interfaces__msg__Jointpos *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Jointpos__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Jointpos__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Jointpos__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
