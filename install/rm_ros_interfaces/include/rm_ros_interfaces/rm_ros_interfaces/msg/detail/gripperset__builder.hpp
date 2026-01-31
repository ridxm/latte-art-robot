// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Gripperset.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/gripperset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Gripperset_timeout
{
public:
  explicit Init_Gripperset_timeout(::rm_ros_interfaces::msg::Gripperset & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Gripperset timeout(::rm_ros_interfaces::msg::Gripperset::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperset msg_;
};

class Init_Gripperset_block
{
public:
  explicit Init_Gripperset_block(::rm_ros_interfaces::msg::Gripperset & msg)
  : msg_(msg)
  {}
  Init_Gripperset_timeout block(::rm_ros_interfaces::msg::Gripperset::_block_type arg)
  {
    msg_.block = std::move(arg);
    return Init_Gripperset_timeout(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperset msg_;
};

class Init_Gripperset_position
{
public:
  Init_Gripperset_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gripperset_block position(::rm_ros_interfaces::msg::Gripperset::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Gripperset_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Gripperset msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Gripperset>()
{
  return rm_ros_interfaces::msg::builder::Init_Gripperset_position();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__GRIPPERSET__BUILDER_HPP_
