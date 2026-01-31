// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_ros_interfaces:msg/Handstatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_ros_interfaces/msg/detail/handstatus__rosidl_typesupport_introspection_c.h"
#include "rm_ros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_ros_interfaces/msg/detail/handstatus__functions.h"
#include "rm_ros_interfaces/msg/detail/handstatus__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_ros_interfaces__msg__Handstatus__init(message_memory);
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_fini_function(void * message_memory)
{
  rm_ros_interfaces__msg__Handstatus__fini(message_memory);
}

size_t rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_angle(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_angle(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_angle(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_angle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_angle(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_angle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_angle(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_pos(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_pos(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_pos(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_pos(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_state(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_state(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_state(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_state(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_state(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_force(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_force(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_force(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_force(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_force(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_force(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_force(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_member_array[5] = {
  {
    "hand_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Handstatus, hand_angle),  // bytes offset in struct
    NULL,  // default value
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_angle,  // size() function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_angle,  // get_const(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_angle,  // get(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_angle,  // fetch(index, &value) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_angle,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Handstatus, hand_pos),  // bytes offset in struct
    NULL,  // default value
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_pos,  // size() function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_pos,  // get_const(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_pos,  // get(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_pos,  // fetch(index, &value) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Handstatus, hand_state),  // bytes offset in struct
    NULL,  // default value
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_state,  // size() function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_state,  // get_const(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_state,  // get(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_state,  // fetch(index, &value) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_state,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_force",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Handstatus, hand_force),  // bytes offset in struct
    NULL,  // default value
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__size_function__Handstatus__hand_force,  // size() function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_const_function__Handstatus__hand_force,  // get_const(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__get_function__Handstatus__hand_force,  // get(index) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__fetch_function__Handstatus__hand_force,  // fetch(index, &value) function pointer
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__assign_function__Handstatus__hand_force,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hand_err",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Handstatus, hand_err),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_members = {
  "rm_ros_interfaces__msg",  // message namespace
  "Handstatus",  // message name
  5,  // number of fields
  sizeof(rm_ros_interfaces__msg__Handstatus),
  rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_member_array,  // message members
  rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_init_function,  // function to initialize message memory (memory has to be allocated)
  rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_type_support_handle = {
  0,
  &rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_ros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_ros_interfaces, msg, Handstatus)() {
  if (!rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_type_support_handle.typesupport_identifier) {
    rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rm_ros_interfaces__msg__Handstatus__rosidl_typesupport_introspection_c__Handstatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
