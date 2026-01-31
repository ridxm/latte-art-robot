// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_ros_interfaces:msg/Handseq.idl
// generated code does not contain a copyright notice

#ifndef RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__BUILDER_HPP_
#define RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_ros_interfaces/msg/detail/handseq__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_ros_interfaces
{

namespace msg
{

namespace builder
{

class Init_Handseq_block
{
public:
  explicit Init_Handseq_block(::rm_ros_interfaces::msg::Handseq & msg)
  : msg_(msg)
  {}
  ::rm_ros_interfaces::msg::Handseq block(::rm_ros_interfaces::msg::Handseq::_block_type arg)
  {
    msg_.block = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handseq msg_;
};

class Init_Handseq_seq_num
{
public:
  Init_Handseq_seq_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Handseq_block seq_num(::rm_ros_interfaces::msg::Handseq::_seq_num_type arg)
  {
    msg_.seq_num = std::move(arg);
    return Init_Handseq_block(msg_);
  }

private:
  ::rm_ros_interfaces::msg::Handseq msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_ros_interfaces::msg::Handseq>()
{
  return rm_ros_interfaces::msg::builder::Init_Handseq_seq_num();
}

}  // namespace rm_ros_interfaces

#endif  // RM_ROS_INTERFACES__MSG__DETAIL__HANDSEQ__BUILDER_HPP_
