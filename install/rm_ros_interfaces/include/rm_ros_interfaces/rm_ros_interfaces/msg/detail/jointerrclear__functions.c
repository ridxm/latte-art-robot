// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Jointerrclear.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/jointerrclear__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_ros_interfaces__msg__Jointerrclear__init(rm_ros_interfaces__msg__Jointerrclear * msg)
{
  if (!msg) {
    return false;
  }
  // joint_num
  // block
  return true;
}

void
rm_ros_interfaces__msg__Jointerrclear__fini(rm_ros_interfaces__msg__Jointerrclear * msg)
{
  if (!msg) {
    return;
  }
  // joint_num
  // block
}

bool
rm_ros_interfaces__msg__Jointerrclear__are_equal(const rm_ros_interfaces__msg__Jointerrclear * lhs, const rm_ros_interfaces__msg__Jointerrclear * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_num
  if (lhs->joint_num != rhs->joint_num) {
    return false;
  }
  // block
  if (lhs->block != rhs->block) {
    return false;
  }
  return true;
}

bool
rm_ros_interfaces__msg__Jointerrclear__copy(
  const rm_ros_interfaces__msg__Jointerrclear * input,
  rm_ros_interfaces__msg__Jointerrclear * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_num
  output->joint_num = input->joint_num;
  // block
  output->block = input->block;
  return true;
}

rm_ros_interfaces__msg__Jointerrclear *
rm_ros_interfaces__msg__Jointerrclear__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Jointerrclear * msg = (rm_ros_interfaces__msg__Jointerrclear *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Jointerrclear), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Jointerrclear));
  bool success = rm_ros_interfaces__msg__Jointerrclear__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Jointerrclear__destroy(rm_ros_interfaces__msg__Jointerrclear * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Jointerrclear__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Jointerrclear__Sequence__init(rm_ros_interfaces__msg__Jointerrclear__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Jointerrclear * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Jointerrclear *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Jointerrclear), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Jointerrclear__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Jointerrclear__fini(&data[i - 1]);
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
rm_ros_interfaces__msg__Jointerrclear__Sequence__fini(rm_ros_interfaces__msg__Jointerrclear__Sequence * array)
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
      rm_ros_interfaces__msg__Jointerrclear__fini(&array->data[i]);
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

rm_ros_interfaces__msg__Jointerrclear__Sequence *
rm_ros_interfaces__msg__Jointerrclear__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Jointerrclear__Sequence * array = (rm_ros_interfaces__msg__Jointerrclear__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Jointerrclear__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Jointerrclear__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Jointerrclear__Sequence__destroy(rm_ros_interfaces__msg__Jointerrclear__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Jointerrclear__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Jointerrclear__Sequence__are_equal(const rm_ros_interfaces__msg__Jointerrclear__Sequence * lhs, const rm_ros_interfaces__msg__Jointerrclear__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Jointerrclear__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Jointerrclear__Sequence__copy(
  const rm_ros_interfaces__msg__Jointerrclear__Sequence * input,
  rm_ros_interfaces__msg__Jointerrclear__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Jointerrclear);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Jointerrclear * data =
      (rm_ros_interfaces__msg__Jointerrclear *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Jointerrclear__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Jointerrclear__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Jointerrclear__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
