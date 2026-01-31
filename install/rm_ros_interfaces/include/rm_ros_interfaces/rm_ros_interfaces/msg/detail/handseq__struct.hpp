// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Handseq.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Handseq __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Handseq __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Handseq_
{
  using Type = Handseq_<ContainerAllocator>;

  explicit Handseq_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq_num = 0;
      this->block = false;
    }
  }

  explicit Handseq_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq_num = 0;
      this->block = false;
    }
  }

  // field types and members
  using _seq_num_type =
    uint16_t;
  _seq_num_type seq_num;
  using _block_type =
    bool;
  _block_type block;

  // setters for named parameter idiom
  Type & set__seq_num(
    const uint16_t & _arg)
  {
    this->seq_num = _arg;
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
    rm_ros_interfaces::msg::Handseq_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Handseq_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Handseq_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Handseq_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Handseq
    std::shared_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Handseq
    std::shared_ptr<rm_ros_interfaces::msg::Handseq_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Handseq_ & other) const
  {
    if (this->seq_num != other.seq_num) {
      return false;
    }
    if (this->block != other.block) {
      return false;
    }
    return true;
  }
  bool operator!=(const Handseq_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Handseq_

// alias to use template instance with default allocator
using Handseq =
  rm_ros_interfaces::msg::Handseq_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__STRUCT_HPP_
