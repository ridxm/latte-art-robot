// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_ros_interfaces:msg/Getallframe.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_ros_interfaces/msg/detail/getallframe__struct.hpp"
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

void Getallframe_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_ros_interfaces::msg::Getallframe(_init);
}

void Getallframe_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_ros_interfaces::msg::Getallframe *>(message_memory);
  typed_message->~Getallframe();
}

size_t size_function__Getallframe__frame_name(const void * untyped_member)
{
  (void)untyped_member;
  return 10;
}

const void * get_const_function__Getallframe__frame_name(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<std::string, 10> *>(untyped_member);
  return &member[index];
}

void * get_function__Getallframe__frame_name(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<std::string, 10> *>(untyped_member);
  return &member[index];
}

void fetch_function__Getallframe__frame_name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__Getallframe__frame_name(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__Getallframe__frame_name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__Getallframe__frame_name(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Getallframe_message_member_array[1] = {
  {
    "frame_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    10,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Getallframe, frame_name),  // bytes offset in struct
    nullptr,  // default value
    size_function__Getallframe__frame_name,  // size() function pointer
    get_const_function__Getallframe__frame_name,  // get_const(index) function pointer
    get_function__Getallframe__frame_name,  // get(index) function pointer
    fetch_function__Getallframe__frame_name,  // fetch(index, &value) function pointer
    assign_function__Getallframe__frame_name,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Getallframe_message_members = {
  "rm_ros_interfaces::msg",  // message namespace
  "Getallframe",  // message name
  1,  // number of fields
  sizeof(rm_ros_interfaces::msg::Getallframe),
  Getallframe_message_member_array,  // message members
  Getallframe_init_function,  // function to initialize message memory (memory has to be allocated)
  Getallframe_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Getallframe_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Getallframe_message_members,
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
get_message_type_support_handle<rm_ros_interfaces::msg::Getallframe>()
{
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Getallframe_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_ros_interfaces, msg, Getallframe)() {
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Getallframe_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
