from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
import launch_ros.actions
from launch.substitutions import LaunchConfiguration
import os

def generate_launch_description():

    return LaunchDescription([
        DeclareLaunchArgument(
            "port",
            default_value="/dev/rm_servo"
        ),
        launch_ros.actions.Node(
            package="servo_driver",
            executable="servo_driver_node",
            name="servo_driver_node",
            output="screen",
            parameters=[{
                "port":LaunchConfiguration("port")
            }]
        )
    ])