// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Gripperpick.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Gripperpick __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Gripperpick __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gripperpick_
{
  using Type = Gripperpick_<ContainerAllocator>;

  explicit Gripperpick_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0;
      this->force = 0;
      this->block = false;
      this->timeout = 0;
    }
  }

  explicit Gripperpick_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0;
      this->force = 0;
      this->block = false;
      this->timeout = 0;
    }
  }

  // field types and members
  using _speed_type =
    uint16_t;
  _speed_type speed;
  using _force_type =
    uint16_t;
  _force_type force;
  using _block_type =
    bool;
  _block_type block;
  using _timeout_type =
    uint16_t;
  _timeout_type timeout;

  // setters for named parameter idiom
  Type & set__speed(
    const uint16_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__force(
    const uint16_t & _arg)
  {
    this->force = _arg;
    return *this;
  }
  Type & set__block(
    const bool & _arg)
  {
    this->block = _arg;
    return *this;
  }
  Type & set__timeout(
    const uint16_t & _arg)
  {
    this->timeout = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Gripperpick
    std::shared_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Gripperpick
    std::shared_ptr<rm_ros_interfaces::msg::Gripperpick_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripperpick_ & other) const
  {
    if (this->speed != other.speed) {
      return false;
    }
    if (this->force != other.force) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    if (this->timeout != other.timeout) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripperpick_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripperpick_

// alias to use template instance with default allocator
using Gripperpick =
  rm_ros_interfaces::msg::Gripperpick_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERPICK__STRUCT_HPP_
