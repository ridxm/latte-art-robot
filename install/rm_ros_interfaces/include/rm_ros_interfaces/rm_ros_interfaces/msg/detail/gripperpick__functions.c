// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Gripperpick.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/gripperpick__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_ros_interfaces__msg__Gripperpick__init(rm_ros_interfaces__msg__Gripperpick * msg)
{
  if (!msg) {
    return false;
  }
  // speed
  // force
  // block
  // timeout
  return true;
}

void
rm_ros_interfaces__msg__Gripperpick__fini(rm_ros_interfaces__msg__Gripperpick * msg)
{
  if (!msg) {
    return;
  }
  // speed
  // force
  // block
  // timeout
}

bool
rm_ros_interfaces__msg__Gripperpick__are_equal(const rm_ros_interfaces__msg__Gripperpick * lhs, const rm_ros_interfaces__msg__Gripperpick * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // force
  if (lhs->force != rhs->force) {
    return false;
  }
  // block
  if (lhs->block != rhs->block) {
    return false;
  }
  // timeout
  if (lhs->timeout != rhs->timeout) {
    return false;
  }
  return true;
}

bool
rm_ros_interfaces__msg__Gripperpick__copy(
  const rm_ros_interfaces__msg__Gripperpick * input,
  rm_ros_interfaces__msg__Gripperpick * output)
{
  if (!input || !output) {
    return false;
  }
  // speed
  output->speed = input->speed;
  // force
  output->force = input->force;
  // block
  output->block = input->block;
  // timeout
  output->timeout = input->timeout;
  return true;
}

rm_ros_interfaces__msg__Gripperpick *
rm_ros_interfaces__msg__Gripperpick__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Gripperpick * msg = (rm_ros_interfaces__msg__Gripperpick *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Gripperpick), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Gripperpick));
  bool success = rm_ros_interfaces__msg__Gripperpick__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Gripperpick__destroy(rm_ros_interfaces__msg__Gripperpick * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Gripperpick__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Gripperpick__Sequence__init(rm_ros_interfaces__msg__Gripperpick__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Gripperpick * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Gripperpick *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Gripperpick), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Gripperpick__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Gripperpick__fini(&data[i - 1]);
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
rm_ros_interfaces__msg__Gripperpick__Sequence__fini(rm_ros_interfaces__msg__Gripperpick__Sequence * array)
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
      rm_ros_interfaces__msg__Gripperpick__fini(&array->data[i]);
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

rm_ros_interfaces__msg__Gripperpick__Sequence *
rm_ros_interfaces__msg__Gripperpick__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Gripperpick__Sequence * array = (rm_ros_interfaces__msg__Gripperpick__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Gripperpick__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Gripperpick__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Gripperpick__Sequence__destroy(rm_ros_interfaces__msg__Gripperpick__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Gripperpick__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Gripperpick__Sequence__are_equal(const rm_ros_interfaces__msg__Gripperpick__Sequence * lhs, const rm_ros_interfaces__msg__Gripperpick__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Gripperpick__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Gripperpick__Sequence__copy(
  const rm_ros_interfaces__msg__Gripperpick__Sequence * input,
  rm_ros_interfaces__msg__Gripperpick__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Gripperpick);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Gripperpick * data =
      (rm_ros_interfaces__msg__Gripperpick *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Gripperpick__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Gripperpick__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Gripperpick__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
