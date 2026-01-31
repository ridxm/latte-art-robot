// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_ros_interfaces:msg/Handstatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_ros_interfaces/msg/detail/handstatus__struct.hpp"
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

void Handstatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_ros_interfaces::msg::Handstatus(_init);
}

void Handstatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_ros_interfaces::msg::Handstatus *>(message_memory);
  typed_message->~Handstatus();
}

size_t size_function__Handstatus__hand_angle(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__Handstatus__hand_angle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__Handstatus__hand_angle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__Handstatus__hand_angle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__Handstatus__hand_angle(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__Handstatus__hand_angle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__Handstatus__hand_angle(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

size_t size_function__Handstatus__hand_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__Handstatus__hand_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__Handstatus__hand_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__Handstatus__hand_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__Handstatus__hand_pos(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__Handstatus__hand_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__Handstatus__hand_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

size_t size_function__Handstatus__hand_state(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__Handstatus__hand_state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__Handstatus__hand_state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__Handstatus__hand_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__Handstatus__hand_state(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__Handstatus__hand_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__Handstatus__hand_state(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

size_t size_function__Handstatus__hand_force(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__Handstatus__hand_force(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__Handstatus__hand_force(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__Handstatus__hand_force(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__Handstatus__hand_force(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__Handstatus__hand_force(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__Handstatus__hand_force(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Handstatus_message_member_array[5] = {
  {
    "hand_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handstatus, hand_angle),  // bytes offset in struct
    nullptr,  // default value
    size_function__Handstatus__hand_angle,  // size() function pointer
    get_const_function__Handstatus__hand_angle,  // get_const(index) function pointer
    get_function__Handstatus__hand_angle,  // get(index) function pointer
    fetch_function__Handstatus__hand_angle,  // fetch(index, &value) function pointer
    assign_function__Handstatus__hand_angle,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hand_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handstatus, hand_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__Handstatus__hand_pos,  // size() function pointer
    get_const_function__Handstatus__hand_pos,  // get_const(index) function pointer
    get_function__Handstatus__hand_pos,  // get(index) function pointer
    fetch_function__Handstatus__hand_pos,  // fetch(index, &value) function pointer
    assign_function__Handstatus__hand_pos,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hand_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handstatus, hand_state),  // bytes offset in struct
    nullptr,  // default value
    size_function__Handstatus__hand_state,  // size() function pointer
    get_const_function__Handstatus__hand_state,  // get_const(index) function pointer
    get_function__Handstatus__hand_state,  // get(index) function pointer
    fetch_function__Handstatus__hand_state,  // fetch(index, &value) function pointer
    assign_function__Handstatus__hand_state,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hand_force",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handstatus, hand_force),  // bytes offset in struct
    nullptr,  // default value
    size_function__Handstatus__hand_force,  // size() function pointer
    get_const_function__Handstatus__hand_force,  // get_const(index) function pointer
    get_function__Handstatus__hand_force,  // get(index) function pointer
    fetch_function__Handstatus__hand_force,  // fetch(index, &value) function pointer
    assign_function__Handstatus__hand_force,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hand_err",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Handstatus, hand_err),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Handstatus_message_members = {
  "rm_ros_interfaces::msg",  // message namespace
  "Handstatus",  // message name
  5,  // number of fields
  sizeof(rm_ros_interfaces::msg::Handstatus),
  Handstatus_message_member_array,  // message members
  Handstatus_init_function,  // function to initialize message memory (memory has to be allocated)
  Handstatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Handstatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Handstatus_message_members,
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
get_message_type_support_handle<rm_ros_interfaces::msg::Handstatus>()
{
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Handstatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_ros_interfaces, msg, Handstatus)() {
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Handstatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
