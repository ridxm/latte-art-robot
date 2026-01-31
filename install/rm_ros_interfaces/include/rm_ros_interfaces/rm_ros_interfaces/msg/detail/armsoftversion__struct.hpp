// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_ros_interfaces:msg/Armsoftversion.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__STRUCT_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_ros_interfaces__msg__Armsoftversion __attribute__((deprecated))
#else
# define DEPRECATED__rm_ros_interfaces__msg__Armsoftversion __declspec(deprecated)
#endif

namespace rm_ros_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Armsoftversion_
{
  using Type = Armsoftversion_<ContainerAllocator>;

  explicit Armsoftversion_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->planversion = "";
      this->ctrlversion = "";
      this->kernal1 = "";
      this->kernal2 = "";
      this->productversion = "";
    }
  }

  explicit Armsoftversion_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : planversion(_alloc),
    ctrlversion(_alloc),
    kernal1(_alloc),
    kernal2(_alloc),
    productversion(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->planversion = "";
      this->ctrlversion = "";
      this->kernal1 = "";
      this->kernal2 = "";
      this->productversion = "";
    }
  }

  // field types and members
  using _planversion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _planversion_type planversion;
  using _ctrlversion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ctrlversion_type ctrlversion;
  using _kernal1_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _kernal1_type kernal1;
  using _kernal2_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _kernal2_type kernal2;
  using _productversion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _productversion_type productversion;

  // setters for named parameter idiom
  Type & set__planversion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->planversion = _arg;
    return *this;
  }
  Type & set__ctrlversion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ctrlversion = _arg;
    return *this;
  }
  Type & set__kernal1(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->kernal1 = _arg;
    return *this;
  }
  Type & set__kernal2(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->kernal2 = _arg;
    return *this;
  }
  Type & set__productversion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->productversion = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_ros_interfaces__msg__Armsoftversion
    std::shared_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_ros_interfaces__msg__Armsoftversion
    std::shared_ptr<rm_ros_interfaces::msg::Armsoftversion_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Armsoftversion_ & other) const
  {
    if (this->planversion != other.planversion) {
      return false;
    }
    if (this->ctrlversion != other.ctrlversion) {
      return false;
    }
    if (this->kernal1 != other.kernal1) {
      return false;
    }
    if (this->kernal2 != other.kernal2) {
      return false;
    }
    if (this->productversion != other.productversion) {
      return false;
    }
    return true;
  }
  bool operator!=(const Armsoftversion_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Armsoftversion_

// alias to use template instance with default allocator
using Armsoftversion =
  rm_ros_interfaces::msg::Armsoftversion_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__STRUCT_HPP_
