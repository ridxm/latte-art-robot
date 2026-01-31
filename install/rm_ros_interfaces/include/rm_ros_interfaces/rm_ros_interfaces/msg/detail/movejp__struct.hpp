// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Movejp.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__MOVEJP__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__MOVEJP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Movejp __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Movejp __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Movejp_
{
  using Type = Movejp_<ContainerAllocator>;

  explicit Movejp_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0;
      this->trajectory_connect = 0;
      this->block = false;
    }
  }

  explicit Movejp_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0;
      this->trajectory_connect = 0;
      this->block = false;
    }
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _speed_type =
    uint8_t;
  _speed_type speed;
  using _trajectory_connect_type =
    uint8_t;
  _trajectory_connect_type trajectory_connect;
  using _block_type =
    bool;
  _block_type block;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__speed(
    const uint8_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__trajectory_connect(
    const uint8_t & _arg)
  {
    this->trajectory_connect = _arg;
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
    rm_ros_interfaces::msg::Movejp_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Movejp_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Movejp_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Movejp_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Movejp
    std::shared_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Movejp
    std::shared_ptr<rm_ros_interfaces::msg::Movejp_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Movejp_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->trajectory_connect != other.trajectory_connect) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    return true;
  }
  bool operator!=(const Movejp_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Movejp_

// alias to use template instance with default allocator
using Movejp =
  rm_ros_interfaces::msg::Movejp_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__MOVEJP__STRUCT_HPP_
