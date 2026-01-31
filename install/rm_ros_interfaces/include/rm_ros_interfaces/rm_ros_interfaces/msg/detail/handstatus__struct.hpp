// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Handstatus.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Handstatus __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Handstatus __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Handstatus_
{
  using Type = Handstatus_<ContainerAllocator>;

  explicit Handstatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_angle.begin(), this->hand_angle.end(), 0);
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_pos.begin(), this->hand_pos.end(), 0);
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_state.begin(), this->hand_state.end(), 0);
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_force.begin(), this->hand_force.end(), 0);
      this->hand_err = 0;
    }
  }

  explicit Handstatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hand_angle(_alloc),
    hand_pos(_alloc),
    hand_state(_alloc),
    hand_force(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_angle.begin(), this->hand_angle.end(), 0);
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_pos.begin(), this->hand_pos.end(), 0);
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_state.begin(), this->hand_state.end(), 0);
      std::fill<typename std::array<uint16_t, 6>::iterator, uint16_t>(this->hand_force.begin(), this->hand_force.end(), 0);
      this->hand_err = 0;
    }
  }

  // field types and members
  using _hand_angle_type =
    std::array<uint16_t, 6>;
  _hand_angle_type hand_angle;
  using _hand_pos_type =
    std::array<uint16_t, 6>;
  _hand_pos_type hand_pos;
  using _hand_state_type =
    std::array<uint16_t, 6>;
  _hand_state_type hand_state;
  using _hand_force_type =
    std::array<uint16_t, 6>;
  _hand_force_type hand_force;
  using _hand_err_type =
    uint16_t;
  _hand_err_type hand_err;

  // setters for named parameter idiom
  Type & set__hand_angle(
    const std::array<uint16_t, 6> & _arg)
  {
    this->hand_angle = _arg;
    return *this;
  }
  Type & set__hand_pos(
    const std::array<uint16_t, 6> & _arg)
  {
    this->hand_pos = _arg;
    return *this;
  }
  Type & set__hand_state(
    const std::array<uint16_t, 6> & _arg)
  {
    this->hand_state = _arg;
    return *this;
  }
  Type & set__hand_force(
    const std::array<uint16_t, 6> & _arg)
  {
    this->hand_force = _arg;
    return *this;
  }
  Type & set__hand_err(
    const uint16_t & _arg)
  {
    this->hand_err = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Handstatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Handstatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Handstatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Handstatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Handstatus
    std::shared_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Handstatus
    std::shared_ptr<rm_ros_interfaces::msg::Handstatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Handstatus_ & other) const
  {
    if (this->hand_angle != other.hand_angle) {
      return false;
    }
    if (this->hand_pos != other.hand_pos) {
      return false;
    }
    if (this->hand_state != other.hand_state) {
      return false;
    }
    if (this->hand_force != other.hand_force) {
      return false;
    }
    if (this->hand_err != other.hand_err) {
      return false;
    }
    return true;
  }
  bool operator!=(const Handstatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Handstatus_

// alias to use template instance with default allocator
using Handstatus =
  rm_ros_interfaces::msg::Handstatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSTATUS__STRUCT_HPP_
