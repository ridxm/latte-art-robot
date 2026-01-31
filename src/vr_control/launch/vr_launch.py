import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess, RegisterEventHandler
from launch.event_handlers import OnProcessStart

def generate_launch_description():
    ld = LaunchDescription()

    # Step 1: Launch the demo launch file via ExecuteProcess.
    total_demo = ExecuteProcess(
        cmd=['ros2', 'launch', 'ros2_total_demo', 'total_demo.launch.py'],
        output='screen'
    )
    ld.add_action(total_demo)

    # Step 2: Launch the remaining nodes with ExecuteProcess.
    woosh_process = ExecuteProcess(
        cmd=['ros2', 'run', 'woosh_robot_agent', 'agent',
             '--ros-args', '-r', '__ns:=/woosh_robot', '-p', 'ip:=169.254.128.2'],
        output='screen'
    )

    get_states_process = ExecuteProcess(
        cmd=['ros2', 'run', 'vr_control', 'get_states_publishers.py'],
        output='screen'
    )

    vr_control_relay_process = ExecuteProcess(
        cmd=['ros2', 'run', 'vr_control', 'vr_control_relay.py'],
        output='screen'
    )

    vr_arm_control_process = ExecuteProcess(
        cmd=['ros2', 'run', 'vr_control', 'vr_arm_control'],
        output='screen'
    )

    # Step 6: Launch the base_move.py process.
    base_move_process = ExecuteProcess(
        cmd=['ros2', 'run', 'vr_control', 'base_move.py'],
        output='screen'
    )

    # Step 3: Chain the launches using event handlers.
    ld.add_action(RegisterEventHandler(
        OnProcessStart(
            target_action=total_demo,
            on_start=[woosh_process]
        )
    ))
    ld.add_action(RegisterEventHandler(
        OnProcessStart(
            target_action=woosh_process,
            on_start=[get_states_process]
        )
    ))
    ld.add_action(RegisterEventHandler(
        OnProcessStart(
            target_action=get_states_process,
            on_start=[vr_control_relay_process]
        )
    ))
    ld.add_action(RegisterEventHandler(
        OnProcessStart(
            target_action=vr_control_relay_process,
            on_start=[vr_arm_control_process]
        )
    ))

    ld.add_action(RegisterEventHandler(
        OnProcessStart(
            target_action=vr_arm_control_process,
            on_start=[base_move_process]
        )
    ))

    return ld
