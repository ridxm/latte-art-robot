// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Sixforce.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Sixforce __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Sixforce __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Sixforce_
{
  using Type = Sixforce_<ContainerAllocator>;

  explicit Sixforce_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_fx = 0.0f;
      this->force_fy = 0.0f;
      this->force_fz = 0.0f;
      this->force_mx = 0.0f;
      this->force_my = 0.0f;
      this->force_mz = 0.0f;
    }
  }

  explicit Sixforce_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_fx = 0.0f;
      this->force_fy = 0.0f;
      this->force_fz = 0.0f;
      this->force_mx = 0.0f;
      this->force_my = 0.0f;
      this->force_mz = 0.0f;
    }
  }

  // field types and members
  using _force_fx_type =
    float;
  _force_fx_type force_fx;
  using _force_fy_type =
    float;
  _force_fy_type force_fy;
  using _force_fz_type =
    float;
  _force_fz_type force_fz;
  using _force_mx_type =
    float;
  _force_mx_type force_mx;
  using _force_my_type =
    float;
  _force_my_type force_my;
  using _force_mz_type =
    float;
  _force_mz_type force_mz;

  // setters for named parameter idiom
  Type & set__force_fx(
    const float & _arg)
  {
    this->force_fx = _arg;
    return *this;
  }
  Type & set__force_fy(
    const float & _arg)
  {
    this->force_fy = _arg;
    return *this;
  }
  Type & set__force_fz(
    const float & _arg)
  {
    this->force_fz = _arg;
    return *this;
  }
  Type & set__force_mx(
    const float & _arg)
  {
    this->force_mx = _arg;
    return *this;
  }
  Type & set__force_my(
    const float & _arg)
  {
    this->force_my = _arg;
    return *this;
  }
  Type & set__force_mz(
    const float & _arg)
  {
    this->force_mz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Sixforce_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Sixforce_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Sixforce_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Sixforce_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Sixforce
    std::shared_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Sixforce
    std::shared_ptr<rm_ros_interfaces::msg::Sixforce_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Sixforce_ & other) const
  {
    if (this->force_fx != other.force_fx) {
      return false;
    }
    if (this->force_fy != other.force_fy) {
      return false;
    }
    if (this->force_fz != other.force_fz) {
      return false;
    }
    if (this->force_mx != other.force_mx) {
      return false;
    }
    if (this->force_my != other.force_my) {
      return false;
    }
    if (this->force_mz != other.force_mz) {
      return false;
    }
    return true;
  }
  bool operator!=(const Sixforce_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Sixforce_

// alias to use template instance with default allocator
using Sixforce =
  rm_ros_interfaces::msg::Sixforce_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__SIXFORCE__STRUCT_HPP_
