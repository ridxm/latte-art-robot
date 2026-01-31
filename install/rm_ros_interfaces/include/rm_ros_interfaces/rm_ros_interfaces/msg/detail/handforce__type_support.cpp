// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_ros_interfaces:msg/Handforce.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_ros_interfaces/msg/detail/handforce__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rm_ros_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Handforce_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_ros_interfaces::msg::Handforce(_init);
}

void Handforce_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_ros_interfaces::msg::Handforce *>(message_memory);
  typed_message->~Handforce();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Handforce_message_member_array[2] = {
  {
    "hand_force",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handforce, hand_force),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "block",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handforce, block),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Handforce_message_members = {
  "rm_ros_interfaces::msg",  // message namespace
  "Handforce",  // message name
  2,  // number of fields
  sizeof(rm_ros_interfaces::msg::Handforce),
  Handforce_message_member_array,  // message members
  Handforce_init_function,  // function to initialize message memory (memory has to be allocated)
  Handforce_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Handforce_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Handforce_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rm_ros_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rm_ros_interfaces::msg::Handforce>()
{
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Handforce_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_ros_interfaces, msg, Handforce)() {
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Handforce_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
