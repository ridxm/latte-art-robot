// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Movej.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Movej __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Movej __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Movej_
{
  using Type = Movej_<ContainerAllocator>;

  explicit Movej_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0;
      this->block = false;
      this->trajectory_connect = 0;
      this->dof = 0;
    }
  }

  explicit Movej_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0;
      this->block = false;
      this->trajectory_connect = 0;
      this->dof = 0;
    }
  }

  // field types and members
  using _joint_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _joint_type joint;
  using _speed_type =
    uint8_t;
  _speed_type speed;
  using _block_type =
    bool;
  _block_type block;
  using _trajectory_connect_type =
    uint8_t;
  _trajectory_connect_type trajectory_connect;
  using _dof_type =
    uint8_t;
  _dof_type dof;

  // setters for named parameter idiom
  Type & set__joint(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->joint = _arg;
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
  Type & set__trajectory_connect(
    const uint8_t & _arg)
  {
    this->trajectory_connect = _arg;
    return *this;
  }
  Type & set__dof(
    const uint8_t & _arg)
  {
    this->dof = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Movej_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Movej_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Movej_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Movej_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Movej
    std::shared_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Movej
    std::shared_ptr<rm_ros_interfaces::msg::Movej_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Movej_ & other) const
  {
    if (this->joint != other.joint) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    if (this->trajectory_connect != other.trajectory_connect) {
      return false;
    }
    if (this->dof != other.dof) {
      return false;
    }
    return true;
  }
  bool operator!=(const Movej_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Movej_

// alias to use template instance with default allocator
using Movej =
  rm_ros_interfaces::msg::Movej_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEJ__STRUCT_HPP_
