// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_ros_interfaces:msg/Handseq.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_ros_interfaces/msg/detail/handseq__struct.hpp"
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

void Handseq_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_ros_interfaces::msg::Handseq(_init);
}

void Handseq_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_ros_interfaces::msg::Handseq *>(message_memory);
  typed_message->~Handseq();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Handseq_message_member_array[2] = {
  {
    "seq_num",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handseq, seq_num),  // bytes offset in struct
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
    offsetof(rm_ros_interfaces::msg::Handseq, block),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Handseq_message_members = {
  "rm_ros_interfaces::msg",  // message namespace
  "Handseq",  // message name
  2,  // number of fields
  sizeof(rm_ros_interfaces::msg::Handseq),
  Handseq_message_member_array,  // message members
  Handseq_init_function,  // function to initialize message memory (memory has to be allocated)
  Handseq_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Handseq_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Handseq_message_members,
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
get_message_type_support_handle<rm_ros_interfaces::msg::Handseq>()
{
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Handseq_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_ros_interfaces, msg, Handseq)() {
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Handseq_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
