// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Jointteach.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Jointteach __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Jointteach __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Jointteach_
{
  using Type = Jointteach_<ContainerAllocator>;

  explicit Jointteach_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
      this->direction = 0;
      this->speed = 0;
      this->block = false;
    }
  }

  explicit Jointteach_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
      this->direction = 0;
      this->speed = 0;
      this->block = false;
    }
  }

  // field types and members
  using _num_type =
    uint8_t;
  _num_type num;
  using _direction_type =
    uint8_t;
  _direction_type direction;
  using _speed_type =
    uint8_t;
  _speed_type speed;
  using _block_type =
    bool;
  _block_type block;

  // setters for named parameter idiom
  Type & set__num(
    const uint8_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__direction(
    const uint8_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__speed(
    const uint8_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__block(
    const bool & _arg)
  {
    this->block = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Jointteach_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Jointteach_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Jointteach_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Jointteach_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Jointteach
    std::shared_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Jointteach
    std::shared_ptr<rm_ros_interfaces::msg::Jointteach_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jointteach_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jointteach_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jointteach_

// alias to use template instance with default allocator
using Jointteach =
  rm_ros_interfaces::msg::Jointteach_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTTEACH__STRUCT_HPP_
