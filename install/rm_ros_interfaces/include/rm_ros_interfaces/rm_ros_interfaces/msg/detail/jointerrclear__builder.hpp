// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Jointerrclear.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRCLEAR__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRCLEAR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/jointerrclear__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Jointerrclear_block
{
public:
  explicit Init_Jointerrclear_block(::rm_ros_interfaces::msg::Jointerrclear & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Jointerrclear block(::rm_ros_interfaces::msg::Jointerrclear::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointerrclear msg_;
};

class Init_Jointerrclear_joint_num
{
public:
  Init_Jointerrclear_joint_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jointerrclear_block joint_num(::rm_ros_interfaces::msg::Jointerrclear::_joint_num_type arg)
  {
    msg_.joint_num = std::move(arg);
    return Init_Jointerrclear_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Jointerrclear msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Jointerrclear>()
{
  return rm_ros_interfaces::msg::builder::Init_Jointerrclear_joint_num();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__JOINTERRCLEAR__BUILDER_HPP_
