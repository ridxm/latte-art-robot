cmake_minimum_required(VERSION 3.5)
project(joystick_step_control)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(woosh_ros_msgs REQUIRED)
find_package(woosh_robot_msgs REQUIRED)


# Create executable
add_executable(joystick_step_control_node 
  src/joystick_step_control_node.cpp
)

ament_target_dependencies(joystick_step_control_node
  rclcpp
  rclcpp_action
  geometry_msgs
  woosh_ros_msgs
)

# Install executable
install(TARGETS 
  joystick_step_control_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

# Install config files
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

ament_package()
