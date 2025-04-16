from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Launch turtlesim
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim',
            output='screen'
        ),

        # Launch the battery simulator node
        Node(
            package='battery_simulator',
            executable='battery_node',
            name='battery_simulator',
            output='screen'
        ),

        # Launch the battery cmd_vel filter
        Node(
            package='battery_simulator',
            executable='battery_cmd_vel_filter',
            name='battery_cmd_vel_filter',
            output='screen'
        ),

        # (Optional) Launch battery charge server too
        Node(
            package='battery_simulator',
            executable='battery_charge_server',
            name='battery_charge_server',
            output='screen'
        ),

        #(Optional) solar sensor
        Node(
            package='battery_simulator',
            executable='solar_sensor_node',
            name='solar_sensor_node',
            output='screen'
        ),
    ])
