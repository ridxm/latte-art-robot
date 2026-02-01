from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    # Declare launch arguments
    joystick_topic_arg = DeclareLaunchArgument(
        'joystick_topic',
        default_value='/joystick_input',
        description='Topic for joystick input (Vector3: x=linear, y=angular)'
    )
    
    max_linear_speed_arg = DeclareLaunchArgument(
        'max_linear_speed',
        default_value='0.1',
        description='Maximum linear speed in m/s'
    )
    
    max_angular_speed_arg = DeclareLaunchArgument(
        'max_angular_speed',
        default_value='0.1',
        description='Maximum angular speed in rad/s'
    )
    
    action_server_arg = DeclareLaunchArgument(
        'action_server',
        default_value='/woosh_robot/ros/StepControl',
        description='StepControl action server name'
    )
    
    enable_avoidance_arg = DeclareLaunchArgument(
        'enable_avoidance',
        default_value='false',
        description='Enable obstacle avoidance'
    )

    # Create node
    joystick_control_node = Node(
        package='joystick_step_control',
        executable='joystick_step_control_node',
        name='joystick_step_control',
        output='screen',
        parameters=[{
            'joystick_topic': LaunchConfiguration('joystick_topic'),
            'max_linear_speed': LaunchConfiguration('max_linear_speed'),
            'max_angular_speed': LaunchConfiguration('max_angular_speed'),
            'action_server': LaunchConfiguration('action_server'),
            'enable_avoidance': LaunchConfiguration('enable_avoidance'),
            'joystick_max': 10.0,
            'deadzone': 0.5,
            'control_rate': 10.0,
            'step_duration': 0.15,
            'step_mode_linear': 1,
            'step_mode_rotation': 2,
        }]
    )

    return LaunchDescription([
        joystick_topic_arg,
        max_linear_speed_arg,
        max_angular_speed_arg,
        action_server_arg,
        enable_avoidance_arg,
        joystick_control_node,
    ])
