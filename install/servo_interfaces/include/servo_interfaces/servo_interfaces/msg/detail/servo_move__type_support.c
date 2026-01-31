// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from servo_interfaces:msg/ServoMove.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "servo_interfaces/msg/detail/servo_move__rosidl_typesupport_introspection_c.h"
#include "servo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "servo_interfaces/msg/detail/servo_move__functions.h"
#include "servo_interfaces/msg/detail/servo_move__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  servo_interfaces__msg__ServoMove__init(message_memory);
}

void servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_fini_function(void * message_memory)
{
  servo_interfaces__msg__ServoMove__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_member_array[2] = {
  {
    "servo_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(servo_interfaces__msg__ServoMove, servo_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(servo_interfaces__msg__ServoMove, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_members = {
  "servo_interfaces__msg",  // message namespace
  "ServoMove",  // message name
  2,  // number of fields
  sizeof(servo_interfaces__msg__ServoMove),
  servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_member_array,  // message members
  servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_init_function,  // function to initialize message memory (memory has to be allocated)
  servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_type_support_handle = {
  0,
  &servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_servo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, servo_interfaces, msg, ServoMove)() {
  if (!servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_type_support_handle.typesupport_identifier) {
    servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &servo_interfaces__msg__ServoMove__rosidl_typesupport_introspection_c__ServoMove_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
