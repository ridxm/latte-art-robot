// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rm_ros_interfaces:msg/Armoriginalstate.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rm_ros_interfaces/msg/detail/armoriginalstate__struct.hpp"
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

void Armoriginalstate_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rm_ros_interfaces::msg::Armoriginalstate(_init);
}

void Armoriginalstate_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rm_ros_interfaces::msg::Armoriginalstate *>(message_memory);
  typed_message->~Armoriginalstate();
}

size_t size_function__Armoriginalstate__joint(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Armoriginalstate__joint(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__Armoriginalstate__joint(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__Armoriginalstate__joint(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Armoriginalstate__joint(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Armoriginalstate__joint(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Armoriginalstate__joint(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__Armoriginalstate__joint(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Armoriginalstate__pose(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__Armoriginalstate__pose(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__Armoriginalstate__pose(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__Armoriginalstate__pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Armoriginalstate__pose(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Armoriginalstate__pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Armoriginalstate__pose(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Armoriginalstate_message_member_array[5] = {
  {
    "joint",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Armoriginalstate, joint),  // bytes offset in struct
    nullptr,  // default value
    size_function__Armoriginalstate__joint,  // size() function pointer
    get_const_function__Armoriginalstate__joint,  // get_const(index) function pointer
    get_function__Armoriginalstate__joint,  // get(index) function pointer
    fetch_function__Armoriginalstate__joint,  // fetch(index, &value) function pointer
    assign_function__Armoriginalstate__joint,  // assign(index, value) function pointer
    resize_function__Armoriginalstate__joint  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Armoriginalstate, pose),  // bytes offset in struct
    nullptr,  // default value
    size_function__Armoriginalstate__pose,  // size() function pointer
    get_const_function__Armoriginalstate__pose,  // get_const(index) function pointer
    get_function__Armoriginalstate__pose,  // get(index) function pointer
    fetch_function__Armoriginalstate__pose,  // fetch(index, &value) function pointer
    assign_function__Armoriginalstate__pose,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "arm_err",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Armoriginalstate, arm_err),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sys_err",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Armoriginalstate, sys_err),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "dof",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_ros_interfaces::msg::Armoriginalstate, dof),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Armoriginalstate_message_members = {
  "rm_ros_interfaces::msg",  // message namespace
  "Armoriginalstate",  // message name
  5,  // number of fields
  sizeof(rm_ros_interfaces::msg::Armoriginalstate),
  Armoriginalstate_message_member_array,  // message members
  Armoriginalstate_init_function,  // function to initialize message memory (memory has to be allocated)
  Armoriginalstate_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Armoriginalstate_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Armoriginalstate_message_members,
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
get_message_type_support_handle<rm_ros_interfaces::msg::Armoriginalstate>()
{
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Armoriginalstate_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rm_ros_interfaces, msg, Armoriginalstate)() {
  return &::rm_ros_interfaces::msg::rosidl_typesupport_introspection_cpp::Armoriginalstate_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
