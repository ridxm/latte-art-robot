// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Setforceposition.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Setforceposition __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Setforceposition __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Setforceposition_
{
  using Type = Setforceposition_<ContainerAllocator>;

  explicit Setforceposition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = 0;
      this->mode = 0;
      this->direction = 0;
      this->n = 0;
      this->block = false;
    }
  }

  explicit Setforceposition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = 0;
      this->mode = 0;
      this->direction = 0;
      this->n = 0;
      this->block = false;
    }
  }

  // field types and members
  using _sensor_type =
    uint8_t;
  _sensor_type sensor;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _direction_type =
    uint8_t;
  _direction_type direction;
  using _n_type =
    int16_t;
  _n_type n;
  using _block_type =
    bool;
  _block_type block;

  // setters for named parameter idiom
  Type & set__sensor(
    const uint8_t & _arg)
  {
    this->sensor = _arg;
    return *this;
  }
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__direction(
    const uint8_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__n(
    const int16_t & _arg)
  {
    this->n = _arg;
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
    rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Setforceposition
    std::shared_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Setforceposition
    std::shared_ptr<rm_ros_interfaces::msg::Setforceposition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Setforceposition_ & other) const
  {
    if (this->sensor != other.sensor) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->n != other.n) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    return true;
  }
  bool operator!=(const Setforceposition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Setforceposition_

// alias to use template instance with default allocator
using Setforceposition =
  rm_ros_interfaces::msg::Setforceposition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SETFORCEPOSITION__STRUCT_HPP_
