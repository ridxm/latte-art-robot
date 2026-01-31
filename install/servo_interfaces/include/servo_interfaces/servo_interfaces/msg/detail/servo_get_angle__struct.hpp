// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from servo_interfaces:msg/ServoGetAngle.idl
// generated code does not contain a copyright notice

#ifndef SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__STRUCT_HPP_
#define SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__servo_interfaces__msg__ServoGetAngle __attribute__((deprecated))
#else
# define DEPRECATED__servo_interfaces__msg__ServoGetAngle __declspec(deprecated)
#endif

namespace servo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoGetAngle_
{
  using Type = ServoGetAngle_<ContainerAllocator>;

  explicit ServoGetAngle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo_id = 0;
    }
  }

  explicit ServoGetAngle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servo_id = 0;
    }
  }

  // field types and members
  using _servo_id_type =
    uint16_t;
  _servo_id_type servo_id;

  // setters for named parameter idiom
  Type & set__servo_id(
    const uint16_t & _arg)
  {
    this->servo_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    servo_interfaces::msg::ServoGetAngle_<ContainerAllocator> *;
  using ConstRawPtr =
    const servo_interfaces::msg::ServoGetAngle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      servo_interfaces::msg::ServoGetAngle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      servo_interfaces::msg::ServoGetAngle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__servo_interfaces__msg__ServoGetAngle
    std::shared_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__servo_interfaces__msg__ServoGetAngle
    std::shared_ptr<servo_interfaces::msg::ServoGetAngle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoGetAngle_ & other) const
  {
    if (this->servo_id != other.servo_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoGetAngle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoGetAngle_

// alias to use template instance with default allocator
using ServoGetAngle =
  servo_interfaces::msg::ServoGetAngle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace servo_interfaces

#endif  // SERVO_INTERFACES__MSG__DETAIL__SERVO_GET_ANGLE__STRUCT_HPP_
