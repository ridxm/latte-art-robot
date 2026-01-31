// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Armoriginalstate.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMORIGINALSTATE__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMORIGINALSTATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Armoriginalstate __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Armoriginalstate __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Armoriginalstate_
{
  using Type = Armoriginalstate_<ContainerAllocator>;

  explicit Armoriginalstate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->pose.begin(), this->pose.end(), 0.0f);
      this->arm_err = 0;
      this->sys_err = 0;
      this->dof = 0;
    }
  }

  explicit Armoriginalstate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->pose.begin(), this->pose.end(), 0.0f);
      this->arm_err = 0;
      this->sys_err = 0;
      this->dof = 0;
    }
  }

  // field types and members
  using _joint_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _joint_type joint;
  using _pose_type =
    std::array<float, 6>;
  _pose_type pose;
  using _arm_err_type =
    uint16_t;
  _arm_err_type arm_err;
  using _sys_err_type =
    uint16_t;
  _sys_err_type sys_err;
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
  Type & set__pose(
    const std::array<float, 6> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__arm_err(
    const uint16_t & _arg)
  {
    this->arm_err = _arg;
    return *this;
  }
  Type & set__sys_err(
    const uint16_t & _arg)
  {
    this->sys_err = _arg;
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
    rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Armoriginalstate
    std::shared_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Armoriginalstate
    std::shared_ptr<rm_ros_interfaces::msg::Armoriginalstate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Armoriginalstate_ & other) const
  {
    if (this->joint != other.joint) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->arm_err != other.arm_err) {
      return false;
    }
    if (this->sys_err != other.sys_err) {
      return false;
    }
    if (this->dof != other.dof) {
      return false;
    }
    return true;
  }
  bool operator!=(const Armoriginalstate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Armoriginalstate_

// alias to use template instance with default allocator
using Armoriginalstate =
  rm_ros_interfaces::msg::Armoriginalstate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMORIGINALSTATE__STRUCT_HPP_
