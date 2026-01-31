cmake_minimum_required(VERSION 3.5)
#使用python旧规则编译，以去除警告
if(POLICY CMP0148) 
  cmake_policy(SET CMP0148 OLD) 
endif()
project(realsense2_description)

find_package(ament_cmake REQUIRED)

# Install files
install(DIRECTORY 
        launch 
        meshes 
        rviz 
        urdf
        DESTINATION share/${PROJECT_NAME})

ament_package()
