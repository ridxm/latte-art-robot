// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_total_demo:msg/ObjectPose.idl
// generated code does not contain a copyright notice
#include "ros2_total_demo/msg/detail/object_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ros2_total_demo__msg__ObjectPose__init(ros2_total_demo__msg__ObjectPose * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
ros2_total_demo__msg__ObjectPose__fini(ros2_total_demo__msg__ObjectPose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
ros2_total_demo__msg__ObjectPose__are_equal(const ros2_total_demo__msg__ObjectPose * lhs, const ros2_total_demo__msg__ObjectPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
ros2_total_demo__msg__ObjectPose__copy(
  const ros2_total_demo__msg__ObjectPose * input,
  ros2_total_demo__msg__ObjectPose * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

ros2_total_demo__msg__ObjectPose *
ros2_total_demo__msg__ObjectPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_total_demo__msg__ObjectPose * msg = (ros2_total_demo__msg__ObjectPose *)allocator.allocate(sizeof(ros2_total_demo__msg__ObjectPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_total_demo__msg__ObjectPose));
  bool success = ros2_total_demo__msg__ObjectPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_total_demo__msg__ObjectPose__destroy(ros2_total_demo__msg__ObjectPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_total_demo__msg__ObjectPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_total_demo__msg__ObjectPose__Sequence__init(ros2_total_demo__msg__ObjectPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_total_demo__msg__ObjectPose * data = NULL;

  if (size) {
    data = (ros2_total_demo__msg__ObjectPose *)allocator.zero_allocate(size, sizeof(ros2_total_demo__msg__ObjectPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_total_demo__msg__ObjectPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_total_demo__msg__ObjectPose__fini(&data[i - 1]);
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
ros2_total_demo__msg__ObjectPose__Sequence__fini(ros2_total_demo__msg__ObjectPose__Sequence * array)
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
      ros2_total_demo__msg__ObjectPose__fini(&array->data[i]);
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

ros2_total_demo__msg__ObjectPose__Sequence *
ros2_total_demo__msg__ObjectPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_total_demo__msg__ObjectPose__Sequence * array = (ros2_total_demo__msg__ObjectPose__Sequence *)allocator.allocate(sizeof(ros2_total_demo__msg__ObjectPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_total_demo__msg__ObjectPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_total_demo__msg__ObjectPose__Sequence__destroy(ros2_total_demo__msg__ObjectPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_total_demo__msg__ObjectPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_total_demo__msg__ObjectPose__Sequence__are_equal(const ros2_total_demo__msg__ObjectPose__Sequence * lhs, const ros2_total_demo__msg__ObjectPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_total_demo__msg__ObjectPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_total_demo__msg__ObjectPose__Sequence__copy(
  const ros2_total_demo__msg__ObjectPose__Sequence * input,
  ros2_total_demo__msg__ObjectPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_total_demo__msg__ObjectPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_total_demo__msg__ObjectPose * data =
      (ros2_total_demo__msg__ObjectPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_total_demo__msg__ObjectPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_total_demo__msg__ObjectPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_total_demo__msg__ObjectPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
