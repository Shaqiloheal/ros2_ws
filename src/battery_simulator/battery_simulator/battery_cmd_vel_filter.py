#!/usr/bin/env python3

# Author: Warren Spalding
# Description: This ROS 2 node acts as a command velocity filter that prevents a robot
# from moving when the simulated battery level reaches 0%. It ensures battery-aware 
# motion by gating all velocity commands sent to the turtle.

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist

class BatteryCmdVelFilter(Node):
    def __init__(self):
        super().__init__('battery_cmd_vel_filter')

        # Internal variable to store the current battery level
        self.battery_level = 100.0

        # Subscriber: Receives the battery percentage from battery_node
        self.battery_sub = self.create_subscription(
            Float32,
            '/battery_percentage',
            self.battery_callback,
            10
        )

        # Subscriber: Listens to input velocity commands (can be adapted for custom control topics)
        self.cmd_vel_in_sub = self.create_subscription(
            Twist,
            '/cmd_vel_in',
            self.cmd_vel_callback,
            10
        )

        # Publisher: Sends allowed velocity commands to the actual turtle control topic
        self.cmd_vel_out_pub = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10
        )

        self.get_logger().info('Battery CmdVel Filter started.')

    def battery_callback(self, msg):
        """
        Updates the battery level from the Float32 message received on /battery_percentage.
        """
        self.battery_level = msg.data

    def cmd_vel_callback(self, msg):
        """
        Intercepts velocity commands and checks the battery level before forwarding.
        If battery is empty (≤ 0.0), it suppresses movement by publishing zero velocity.
        """
        if self.battery_level <= 0.0:
            self.get_logger().warn('Battery empty! Blocking movement command.')
            zero_cmd = Twist()  # Zero velocity command
            self.cmd_vel_out_pub.publish(zero_cmd)
        else:
            self.cmd_vel_out_pub.publish(msg)  # Forward original command

def main(args=None):
    rclpy.init(args=args)
    node = BatteryCmdVelFilter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
