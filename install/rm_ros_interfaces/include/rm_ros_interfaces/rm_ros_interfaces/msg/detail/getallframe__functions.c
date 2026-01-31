// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Getallframe.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/getallframe__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `frame_name`
#include "rosidl_runtime_c/string_functions.h"

bool
rm_ros_interfaces__msg__Getallframe__init(rm_ros_interfaces__msg__Getallframe * msg)
{
  if (!msg) {
    return false;
  }
  // frame_name
  for (size_t i = 0; i < 10; ++i) {
    if (!rosidl_runtime_c__String__init(&msg->frame_name[i])) {
      rm_ros_interfaces__msg__Getallframe__fini(msg);
      return false;
    }
  }
  return true;
}

void
rm_ros_interfaces__msg__Getallframe__fini(rm_ros_interfaces__msg__Getallframe * msg)
{
  if (!msg) {
    return;
  }
  // frame_name
  for (size_t i = 0; i < 10; ++i) {
    rosidl_runtime_c__String__fini(&msg->frame_name[i]);
  }
}

bool
rm_ros_interfaces__msg__Getallframe__are_equal(const rm_ros_interfaces__msg__Getallframe * lhs, const rm_ros_interfaces__msg__Getallframe * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // frame_name
  for (size_t i = 0; i < 10; ++i) {
    if (!rosidl_runtime_c__String__are_equal(
        &(lhs->frame_name[i]), &(rhs->frame_name[i])))
    {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Getallframe__copy(
  const rm_ros_interfaces__msg__Getallframe * input,
  rm_ros_interfaces__msg__Getallframe * output)
{
  if (!input || !output) {
    return false;
  }
  // frame_name
  for (size_t i = 0; i < 10; ++i) {
    if (!rosidl_runtime_c__String__copy(
        &(input->frame_name[i]), &(output->frame_name[i])))
    {
      return false;
    }
  }
  return true;
}

rm_ros_interfaces__msg__Getallframe *
rm_ros_interfaces__msg__Getallframe__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Getallframe * msg = (rm_ros_interfaces__msg__Getallframe *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Getallframe), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Getallframe));
  bool success = rm_ros_interfaces__msg__Getallframe__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Getallframe__destroy(rm_ros_interfaces__msg__Getallframe * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Getallframe__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Getallframe__Sequence__init(rm_ros_interfaces__msg__Getallframe__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Getallframe * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Getallframe *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Getallframe), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Getallframe__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Getallframe__fini(&data[i - 1]);
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
rm_ros_interfaces__msg__Getallframe__Sequence__fini(rm_ros_interfaces__msg__Getallframe__Sequence * array)
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
      rm_ros_interfaces__msg__Getallframe__fini(&array->data[i]);
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

rm_ros_interfaces__msg__Getallframe__Sequence *
rm_ros_interfaces__msg__Getallframe__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Getallframe__Sequence * array = (rm_ros_interfaces__msg__Getallframe__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Getallframe__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Getallframe__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Getallframe__Sequence__destroy(rm_ros_interfaces__msg__Getallframe__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Getallframe__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Getallframe__Sequence__are_equal(const rm_ros_interfaces__msg__Getallframe__Sequence * lhs, const rm_ros_interfaces__msg__Getallframe__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Getallframe__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Getallframe__Sequence__copy(
  const rm_ros_interfaces__msg__Getallframe__Sequence * input,
  rm_ros_interfaces__msg__Getallframe__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Getallframe);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Getallframe * data =
      (rm_ros_interfaces__msg__Getallframe *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Getallframe__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Getallframe__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Getallframe__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
