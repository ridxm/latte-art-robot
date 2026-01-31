// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Jointerrorcode.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Jointerrorcode __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Jointerrorcode __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Jointerrorcode_
{
  using Type = Jointerrorcode_<ContainerAllocator>;

  explicit Jointerrorcode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dof = 0;
    }
  }

  explicit Jointerrorcode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dof = 0;
    }
  }

  // field types and members
  using _joint_error_type =
    std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>>;
  _joint_error_type joint_error;
  using _dof_type =
    uint8_t;
  _dof_type dof;

  // setters for named parameter idiom
  Type & set__joint_error(
    const std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>> & _arg)
  {
    this->joint_error = _arg;
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
    rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Jointerrorcode
    std::shared_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Jointerrorcode
    std::shared_ptr<rm_ros_interfaces::msg::Jointerrorcode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jointerrorcode_ & other) const
  {
    if (this->joint_error != other.joint_error) {
      return false;
    }
    if (this->dof != other.dof) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jointerrorcode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jointerrorcode_

// alias to use template instance with default allocator
using Jointerrorcode =
  rm_ros_interfaces::msg::Jointerrorcode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRORCODE__STRUCT_HPP_
