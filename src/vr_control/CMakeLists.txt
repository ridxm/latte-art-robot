cmake_minimum_required(VERSION 3.5)
project(vr_control)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(rm_ros_interfaces REQUIRED)
find_package(servo_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(Eigen3 REQUIRED)

# Create executable
add_executable(vr_arm_control src/vr_arm_control.cpp)

# Include directories (Eigen and project headers)
target_include_directories(vr_arm_control PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${EIGEN3_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(vr_arm_control
  Eigen3::Eigen
)

# ROS 2 dependencies
ament_target_dependencies(vr_arm_control
  rclcpp
  std_msgs
  rm_ros_interfaces
  sensor_msgs
)

# Install executable
install(TARGETS
  vr_arm_control
  DESTINATION lib/${PROJECT_NAME}
)
add_executable(head_move src/head_move.cpp)

# Include directories
target_include_directories(head_move PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# ROS 2 dependencies
ament_target_dependencies(head_move
  rclcpp
  std_msgs
  servo_interfaces
)

# Install executable
install(TARGETS
  head_move
  DESTINATION lib/${PROJECT_NAME}
)
# Install config and launch folders
install(
  DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

# Install Python scripts
install(PROGRAMS
  ${PROJECT_NAME}/base_move.py
  ${PROJECT_NAME}/get_states_publishers.py
  ${PROJECT_NAME}/vr_control_relay.py
  DESTINATION lib/${PROJECT_NAME}
)

# Python package install
ament_python_install_package(${PROJECT_NAME})

# Tests
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # Uncomment below lines if needed
  # set(ament_cmake_cpplint_FOUND TRUE)
  # set(ament_cmake_copyright_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Finish
ament_package()
