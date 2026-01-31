// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Armsoftversion.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/armsoftversion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Armsoftversion_productversion
{
public:
  explicit Init_Armsoftversion_productversion(::rm_ros_interfaces::msg::Armsoftversion & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Armsoftversion productversion(::rm_ros_interfaces::msg::Armsoftversion::_productversion_type arg)
  {
    msg_.productversion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armsoftversion msg_;
};

class Init_Armsoftversion_kernal2
{
public:
  explicit Init_Armsoftversion_kernal2(::rm_ros_interfaces::msg::Armsoftversion & msg)
  : msg_(msg)
  {}
  Init_Armsoftversion_productversion kernal2(::rm_ros_interfaces::msg::Armsoftversion::_kernal2_type arg)
  {
    msg_.kernal2 = std::move(arg);
    return Init_Armsoftversion_productversion(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armsoftversion msg_;
};

class Init_Armsoftversion_kernal1
{
public:
  explicit Init_Armsoftversion_kernal1(::rm_ros_interfaces::msg::Armsoftversion & msg)
  : msg_(msg)
  {}
  Init_Armsoftversion_kernal2 kernal1(::rm_ros_interfaces::msg::Armsoftversion::_kernal1_type arg)
  {
    msg_.kernal1 = std::move(arg);
    return Init_Armsoftversion_kernal2(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armsoftversion msg_;
};

class Init_Armsoftversion_ctrlversion
{
public:
  explicit Init_Armsoftversion_ctrlversion(::rm_ros_interfaces::msg::Armsoftversion & msg)
  : msg_(msg)
  {}
  Init_Armsoftversion_kernal1 ctrlversion(::rm_ros_interfaces::msg::Armsoftversion::_ctrlversion_type arg)
  {
    msg_.ctrlversion = std::move(arg);
    return Init_Armsoftversion_kernal1(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armsoftversion msg_;
};

class Init_Armsoftversion_planversion
{
public:
  Init_Armsoftversion_planversion()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Armsoftversion_ctrlversion planversion(::rm_ros_interfaces::msg::Armsoftversion::_planversion_type arg)
  {
    msg_.planversion = std::move(arg);
    return Init_Armsoftversion_ctrlversion(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Armsoftversion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Armsoftversion>()
{
  return rm_ros_interfaces::msg::builder::Init_Armsoftversion_planversion();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__ARMSOFTVERSION__BUILDER_HPP_
