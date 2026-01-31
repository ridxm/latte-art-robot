// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Forcepositionmovejoint.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovejoint __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovejoint __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Forcepositionmovejoint_
{
  using Type = Forcepositionmovejoint_<ContainerAllocator>;

  explicit Forcepositionmovejoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = 0;
      this->mode = 0;
      this->dir = 0;
      this->force = 0.0f;
      this->follow = false;
      this->dof = 0;
    }
  }

  explicit Forcepositionmovejoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = 0;
      this->mode = 0;
      this->dir = 0;
      this->force = 0.0f;
      this->follow = false;
      this->dof = 0;
    }
  }

  // field types and members
  using _joint_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _joint_type joint;
  using _sensor_type =
    uint8_t;
  _sensor_type sensor;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _dir_type =
    int16_t;
  _dir_type dir;
  using _force_type =
    float;
  _force_type force;
  using _follow_type =
    bool;
  _follow_type follow;
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
    const int16_t & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__force(
    const float & _arg)
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
  Type & set__dof(
    const uint8_t & _arg)
  {
    this->dof = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovejoint
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Forcepositionmovejoint
    std::shared_ptr<rm_ros_interfaces::msg::Forcepositionmovejoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Forcepositionmovejoint_ & other) const
  {
    if (this->joint != other.joint) {
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
    if (this->dof != other.dof) {
      return false;
    }
    return true;
  }
  bool operator!=(const Forcepositionmovejoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Forcepositionmovejoint_

// alias to use template instance with default allocator
using Forcepositionmovejoint =
  rm_ros_interfaces::msg::Forcepositionmovejoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__FORCEPOSITIONMOVEJOINT__STRUCT_HPP_
