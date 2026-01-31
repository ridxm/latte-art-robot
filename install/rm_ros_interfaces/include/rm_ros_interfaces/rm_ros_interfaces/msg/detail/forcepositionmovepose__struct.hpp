// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Forcepositionmovepose.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__STRUCT_HPP_

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
# define DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovepose __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovepose __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Forcepositionmovepose_
{
  using Type = Forcepositionmovepose_<ContainerAllocator>;

  explicit Forcepositionmovepose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = 0;
      this->mode = 0;
      this->dir = 0;
      this->force = 0;
      this->follow = false;
    }
  }

  explicit Forcepositionmovepose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = 0;
      this->mode = 0;
      this->dir = 0;
      this->force = 0;
      this->follow = false;
    }
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _sensor_type =
    uint8_t;
  _sensor_type sensor;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _dir_type =
    uint8_t;
  _dir_type dir;
  using _force_type =
    int16_t;
  _force_type force;
  using _follow_type =
    bool;
  _follow_type follow;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
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
  Type & set__dir(
    const uint8_t & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__force(
    const int16_t & _arg)
  {
    this->force = _arg;
    return *this;
  }
  Type & set__follow(
    const bool & _arg)
  {
    this->follow = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovepose
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovepose
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovepose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Forcepositionmovepose_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->sensor != other.sensor) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->dir != other.dir) {
      return false;
    }
    if (this->force != other.force) {
      return false;
    }
    if (this->follow != other.follow) {
      return false;
    }
    return true;
  }
  bool operator!=(const Forcepositionmovepose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Forcepositionmovepose_

// alias to use template instance with default allocator
using Forcepositionmovepose =
  rm_ros_interfaces::msg::Forcepositionmovepose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEPOSE__STRUCT_HPP_
