// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Setrealtimepush.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Setrealtimepush __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Setrealtimepush __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Setrealtimepush_
{
  using Type = Setrealtimepush_<ContainerAllocator>;

  explicit Setrealtimepush_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycle = 0;
      this->port = 0;
      this->force_coordinate = 0;
      this->ip = "";
      this->hand_enable = false;
    }
  }

  explicit Setrealtimepush_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ip(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycle = 0;
      this->port = 0;
      this->force_coordinate = 0;
      this->ip = "";
      this->hand_enable = false;
    }
  }

  // field types and members
  using _cycle_type =
    uint16_t;
  _cycle_type cycle;
  using _port_type =
    uint16_t;
  _port_type port;
  using _force_coordinate_type =
    uint16_t;
  _force_coordinate_type force_coordinate;
  using _ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ip_type ip;
  using _hand_enable_type =
    bool;
  _hand_enable_type hand_enable;

  // setters for named parameter idiom
  Type & set__cycle(
    const uint16_t & _arg)
  {
    this->cycle = _arg;
    return *this;
  }
  Type & set__port(
    const uint16_t & _arg)
  {
    this->port = _arg;
    return *this;
  }
  Type & set__force_coordinate(
    const uint16_t & _arg)
  {
    this->force_coordinate = _arg;
    return *this;
  }
  Type & set__ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ip = _arg;
    return *this;
  }
  Type & set__hand_enable(
    const bool & _arg)
  {
    this->hand_enable = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Setrealtimepush
    std::shared_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Setrealtimepush
    std::shared_ptr<rm_ros_interfaces::msg::Setrealtimepush_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Setrealtimepush_ & other) const
  {
    if (this->cycle != other.cycle) {
      return false;
    }
    if (this->port != other.port) {
      return false;
    }
    if (this->force_coordinate != other.force_coordinate) {
      return false;
    }
    if (this->ip != other.ip) {
      return false;
    }
    if (this->hand_enable != other.hand_enable) {
      return false;
    }
    return true;
  }
  bool operator!=(const Setrealtimepush_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Setrealtimepush_

// alias to use template instance with default allocator
using Setrealtimepush =
  rm_ros_interfaces::msg::Setrealtimepush_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SETREALTIMEPUSH__STRUCT_HPP_
