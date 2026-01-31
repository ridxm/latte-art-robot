// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Gripperset.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Gripperset __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Gripperset __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gripperset_
{
  using Type = Gripperset_<ContainerAllocator>;

  explicit Gripperset_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0;
      this->block = false;
      this->timeout = 0;
    }
  }

  explicit Gripperset_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0;
      this->block = false;
      this->timeout = 0;
    }
  }

  // field types and members
  using _position_type =
    uint16_t;
  _position_type position;
  using _block_type =
    bool;
  _block_type block;
  using _timeout_type =
    uint16_t;
  _timeout_type timeout;

  // setters for named parameter idiom
  Type & set__position(
    const uint16_t & _arg)
  {
    this->position = _arg;
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
    rm_ros_interfaces::msg::Gripperset_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Gripperset_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Gripperset_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Gripperset_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Gripperset
    std::shared_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Gripperset
    std::shared_ptr<rm_ros_interfaces::msg::Gripperset_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripperset_ & other) const
  {
    if (this->position != other.position) {
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
  bool operator!=(const Gripperset_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripperset_

// alias to use template instance with default allocator
using Gripperset =
  rm_ros_interfaces::msg::Gripperset_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__STRUCT_HPP_
