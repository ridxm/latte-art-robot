// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Handangle.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Handangle __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Handangle __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Handangle_
{
  using Type = Handangle_<ContainerAllocator>;

  explicit Handangle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int16_t, 6>::iterator, int16_t>(this->hand_angle.begin(), this->hand_angle.end(), 0);
      this->block = false;
    }
  }

  explicit Handangle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hand_angle(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int16_t, 6>::iterator, int16_t>(this->hand_angle.begin(), this->hand_angle.end(), 0);
      this->block = false;
    }
  }

  // field types and members
  using _hand_angle_type =
    std::array<int16_t, 6>;
  _hand_angle_type hand_angle;
  using _block_type =
    bool;
  _block_type block;

  // setters for named parameter idiom
  Type & set__hand_angle(
    const std::array<int16_t, 6> & _arg)
  {
    this->hand_angle = _arg;
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
    rm_ros_interfaces::msg::Handangle_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Handangle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Handangle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Handangle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Handangle
    std::shared_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Handangle
    std::shared_ptr<rm_ros_interfaces::msg::Handangle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Handangle_ & other) const
  {
    if (this->hand_angle != other.hand_angle) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    return true;
  }
  bool operator!=(const Handangle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Handangle_

// alias to use template instance with default allocator
using Handangle =
  rm_ros_interfaces::msg::Handangle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDANGLE__STRUCT_HPP_
