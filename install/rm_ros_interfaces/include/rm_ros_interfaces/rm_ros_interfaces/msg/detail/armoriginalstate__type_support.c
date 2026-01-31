// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_ros_interfaces:msg/Armoriginalstate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_ros_interfaces/msg/detail/armoriginalstate__rosidl_typesupport_introspection_c.h"
#include "rm_ros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_ros_interfaces/msg/detail/armoriginalstate__functions.h"
#include "rm_ros_interfaces/msg/detail/armoriginalstate__struct.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_ros_interfaces__msg__Armoriginalstate__init(message_memory);
}

void rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_fini_function(void * message_memory)
{
  rm_ros_interfaces__msg__Armoriginalstate__fini(message_memory);
}

size_t rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__size_function__Armoriginalstate__joint(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_const_function__Armoriginalstate__joint(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_function__Armoriginalstate__joint(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__fetch_function__Armoriginalstate__joint(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_const_function__Armoriginalstate__joint(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__assign_function__Armoriginalstate__joint(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_function__Armoriginalstate__joint(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__resize_function__Armoriginalstate__joint(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__size_function__Armoriginalstate__pose(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_const_function__Armoriginalstate__pose(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_function__Armoriginalstate__pose(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__fetch_function__Armoriginalstate__pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_const_function__Armoriginalstate__pose(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__assign_function__Armoriginalstate__pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_function__Armoriginalstate__pose(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_member_array[5] = {
  {
    "joint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Armoriginalstate, joint),  // bytes offset in struct
    NULL,  // default value
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__size_function__Armoriginalstate__joint,  // size() function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_const_function__Armoriginalstate__joint,  // get_const(index) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_function__Armoriginalstate__joint,  // get(index) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__fetch_function__Armoriginalstate__joint,  // fetch(index, &value) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__assign_function__Armoriginalstate__joint,  // assign(index, value) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__resize_function__Armoriginalstate__joint  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Armoriginalstate, pose),  // bytes offset in struct
    NULL,  // default value
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__size_function__Armoriginalstate__pose,  // size() function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_const_function__Armoriginalstate__pose,  // get_const(index) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__get_function__Armoriginalstate__pose,  // get(index) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__fetch_function__Armoriginalstate__pose,  // fetch(index, &value) function pointer
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__assign_function__Armoriginalstate__pose,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arm_err",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Armoriginalstate, arm_err),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sys_err",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Armoriginalstate, sys_err),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dof",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Armoriginalstate, dof),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_members = {
  "rm_ros_interfaces__msg",  // message namespace
  "Armoriginalstate",  // message name
  5,  // number of fields
  sizeof(rm_ros_interfaces__msg__Armoriginalstate),
  rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_member_array,  // message members
  rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_init_function,  // function to initialize message memory (memory has to be allocated)
  rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_type_support_handle = {
  0,
  &rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_ros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_ros_interfaces, msg, Armoriginalstate)() {
  if (!rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_type_support_handle.typesupport_identifier) {
    rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rm_ros_interfaces__msg__Armoriginalstate__rosidl_typesupport_introspection_c__Armoriginalstate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
