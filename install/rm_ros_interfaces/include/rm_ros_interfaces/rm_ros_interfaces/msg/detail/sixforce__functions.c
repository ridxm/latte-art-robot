// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Sixforce.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/sixforce__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_ros_interfaces__msg__Sixforce__init(rm_ros_interfaces__msg__Sixforce * msg)
{
  if (!msg) {
    return false;
  }
  // force_fx
  // force_fy
  // force_fz
  // force_mx
  // force_my
  // force_mz
  return true;
}

void
rm_ros_interfaces__msg__Sixforce__fini(rm_ros_interfaces__msg__Sixforce * msg)
{
  if (!msg) {
    return;
  }
  // force_fx
  // force_fy
  // force_fz
  // force_mx
  // force_my
  // force_mz
}

bool
rm_ros_interfaces__msg__Sixforce__are_equal(const rm_ros_interfaces__msg__Sixforce * lhs, const rm_ros_interfaces__msg__Sixforce * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // force_fx
  if (lhs->force_fx != rhs->force_fx) {
    return false;
  }
  // force_fy
  if (lhs->force_fy != rhs->force_fy) {
    return false;
  }
  // force_fz
  if (lhs->force_fz != rhs->force_fz) {
    return false;
  }
  // force_mx
  if (lhs->force_mx != rhs->force_mx) {
    return false;
  }
  // force_my
  if (lhs->force_my != rhs->force_my) {
    return false;
  }
  // force_mz
  if (lhs->force_mz != rhs->force_mz) {
    return false;
  }
  return true;
}

bool
rm_ros_interfaces__msg__Sixforce__copy(
  const rm_ros_interfaces__msg__Sixforce * input,
  rm_ros_interfaces__msg__Sixforce * output)
{
  if (!input || !output) {
    return false;
  }
  // force_fx
  output->force_fx = input->force_fx;
  // force_fy
  output->force_fy = input->force_fy;
  // force_fz
  output->force_fz = input->force_fz;
  // force_mx
  output->force_mx = input->force_mx;
  // force_my
  output->force_my = input->force_my;
  // force_mz
  output->force_mz = input->force_mz;
  return true;
}

rm_ros_interfaces__msg__Sixforce *
rm_ros_interfaces__msg__Sixforce__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Sixforce * msg = (rm_ros_interfaces__msg__Sixforce *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Sixforce), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Sixforce));
  bool success = rm_ros_interfaces__msg__Sixforce__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Sixforce__destroy(rm_ros_interfaces__msg__Sixforce * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Sixforce__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Sixforce__Sequence__init(rm_ros_interfaces__msg__Sixforce__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Sixforce * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Sixforce *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Sixforce), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Sixforce__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Sixforce__fini(&data[i - 1]);
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
rm_ros_interfaces__msg__Sixforce__Sequence__fini(rm_ros_interfaces__msg__Sixforce__Sequence * array)
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
      rm_ros_interfaces__msg__Sixforce__fini(&array->data[i]);
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

rm_ros_interfaces__msg__Sixforce__Sequence *
rm_ros_interfaces__msg__Sixforce__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Sixforce__Sequence * array = (rm_ros_interfaces__msg__Sixforce__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Sixforce__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Sixforce__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Sixforce__Sequence__destroy(rm_ros_interfaces__msg__Sixforce__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Sixforce__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Sixforce__Sequence__are_equal(const rm_ros_interfaces__msg__Sixforce__Sequence * lhs, const rm_ros_interfaces__msg__Sixforce__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Sixforce__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Sixforce__Sequence__copy(
  const rm_ros_interfaces__msg__Sixforce__Sequence * input,
  rm_ros_interfaces__msg__Sixforce__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Sixforce);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Sixforce * data =
      (rm_ros_interfaces__msg__Sixforce *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Sixforce__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Sixforce__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Sixforce__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
