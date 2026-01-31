// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_ros_interfaces:msg/Movec.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_ros_interfaces/msg/detail/movec__rosidl_typesupport_introspection_c.h"
#include "rm_ros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_ros_interfaces/msg/detail/movec__functions.h"
#include "rm_ros_interfaces/msg/detail/movec__struct.h"


// Include directives for member types
// Member `pose_mid`
// Member `pose_end`
#include "geometry_msgs/msg/pose.h"
// Member `pose_mid`
// Member `pose_end`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_ros_interfaces__msg__Movec__init(message_memory);
}

void rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_fini_function(void * message_memory)
{
  rm_ros_interfaces__msg__Movec__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_member_array[6] = {
  {
    "pose_mid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Movec, pose_mid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Movec, pose_end),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Movec, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory_connect",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Movec, trajectory_connect),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "block",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Movec, block),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "loop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces__msg__Movec, loop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_members = {
  "rm_ros_interfaces__msg",  // message namespace
  "Movec",  // message name
  6,  // number of fields
  sizeof(rm_ros_interfaces__msg__Movec),
  rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_member_array,  // message members
  rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_init_function,  // function to initialize message memory (memory has to be allocated)
  rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_type_support_handle = {
  0,
  &rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_ros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_ros_interfaces, msg, Movec)() {
  rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_type_support_handle.typesupport_identifier) {
    rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rm_ros_interfaces__msg__Movec__rosidl_typesupport_introspection_c__Movec_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
