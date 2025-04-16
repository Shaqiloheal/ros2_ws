# Author: Warren Spalding
# Description:
# This launch file initializes a simulated robot environment using the turtlesim package
# alongside custom battery simulation nodes. It launches a turtle simulator, a battery monitor,
# a velocity filter to enforce battery constraints, an action-based charge server, and a solar 
# sensor node that mimics passive solar charging behavior.

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Launch the turtlesim node to simulate a turtle robot in a 2D environment
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim',
            output='screen'
        ),

        # Launch the battery simulation node which publishes battery percentage
        # based on the turtle's motion and charging states
        Node(
            package='battery_simulator',
            executable='battery_node',
            name='battery_simulator',
            output='screen'
        ),

        # Launch a velocity command filter node that blocks movement when the battery is empty
        Node(
            package='battery_simulator',
            executable='battery_cmd_vel_filter',
            name='battery_cmd_vel_filter',
            output='screen'
        ),

        # (Optional) Launch a server that handles battery charging requests via a ROS 2 Action
        Node(
            package='battery_simulator',
            executable='battery_charge_server',
            name='battery_charge_server',
            output='screen'
        ),

        # (Optional) Launch the solar sensor node which simulates solar input during daytime hours
        Node(
            package='battery_simulator',
            executable='solar_sensor_node',
            name='solar_sensor_node',
            output='screen'
        ),
    ])
