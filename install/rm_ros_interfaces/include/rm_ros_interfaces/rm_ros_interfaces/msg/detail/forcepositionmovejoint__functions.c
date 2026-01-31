// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_ros_interfaces:msg/Forcepositionmovejoint.idl
// generated code does not contain a copyright notice
#include "rm_ros_interfaces/msg/detail/forcepositionmovejoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rm_ros_interfaces__msg__Forcepositionmovejoint__init(rm_ros_interfaces__msg__Forcepositionmovejoint * msg)
{
  if (!msg) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint, 0)) {
    rm_ros_interfaces__msg__Forcepositionmovejoint__fini(msg);
    return false;
  }
  // sensor
  // mode
  // dir
  // force
  // follow
  // dof
  return true;
}

void
rm_ros_interfaces__msg__Forcepositionmovejoint__fini(rm_ros_interfaces__msg__Forcepositionmovejoint * msg)
{
  if (!msg) {
    return;
  }
  // joint
  rosidl_runtime_c__float__Sequence__fini(&msg->joint);
  // sensor
  // mode
  // dir
  // force
  // follow
  // dof
}

bool
rm_ros_interfaces__msg__Forcepositionmovejoint__are_equal(const rm_ros_interfaces__msg__Forcepositionmovejoint * lhs, const rm_ros_interfaces__msg__Forcepositionmovejoint * rhs)
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
  // sensor
  if (lhs->sensor != rhs->sensor) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // dir
  if (lhs->dir != rhs->dir) {
    return false;
  }
  // force
  if (lhs->force != rhs->force) {
    return false;
  }
  // follow
  if (lhs->follow != rhs->follow) {
    return false;
  }
  // dof
  if (lhs->dof != rhs->dof) {
    return false;
  }
  return true;
}

bool
rm_ros_interfaces__msg__Forcepositionmovejoint__copy(
  const rm_ros_interfaces__msg__Forcepositionmovejoint * input,
  rm_ros_interfaces__msg__Forcepositionmovejoint * output)
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
  // sensor
  output->sensor = input->sensor;
  // mode
  output->mode = input->mode;
  // dir
  output->dir = input->dir;
  // force
  output->force = input->force;
  // follow
  output->follow = input->follow;
  // dof
  output->dof = input->dof;
  return true;
}

rm_ros_interfaces__msg__Forcepositionmovejoint *
rm_ros_interfaces__msg__Forcepositionmovejoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Forcepositionmovejoint * msg = (rm_ros_interfaces__msg__Forcepositionmovejoint *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Forcepositionmovejoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_ros_interfaces__msg__Forcepositionmovejoint));
  bool success = rm_ros_interfaces__msg__Forcepositionmovejoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_ros_interfaces__msg__Forcepositionmovejoint__destroy(rm_ros_interfaces__msg__Forcepositionmovejoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_ros_interfaces__msg__Forcepositionmovejoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__init(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Forcepositionmovejoint * data = NULL;

  if (size) {
    data = (rm_ros_interfaces__msg__Forcepositionmovejoint *)allocator.zero_allocate(size, sizeof(rm_ros_interfaces__msg__Forcepositionmovejoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_ros_interfaces__msg__Forcepositionmovejoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_ros_interfaces__msg__Forcepositionmovejoint__fini(&data[i - 1]);
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
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__fini(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array)
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
      rm_ros_interfaces__msg__Forcepositionmovejoint__fini(&array->data[i]);
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

rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence *
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array = (rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence *)allocator.allocate(sizeof(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__destroy(rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__are_equal(const rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * lhs, const rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_ros_interfaces__msg__Forcepositionmovejoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence__copy(
  const rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * input,
  rm_ros_interfaces__msg__Forcepositionmovejoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_ros_interfaces__msg__Forcepositionmovejoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_ros_interfaces__msg__Forcepositionmovejoint * data =
      (rm_ros_interfaces__msg__Forcepositionmovejoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_ros_interfaces__msg__Forcepositionmovejoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_ros_interfaces__msg__Forcepositionmovejoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_ros_interfaces__msg__Forcepositionmovejoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
