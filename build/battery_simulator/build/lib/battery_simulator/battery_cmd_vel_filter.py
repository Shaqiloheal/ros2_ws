#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist

class BatteryCmdVelFilter(Node):
    def __init__(self):
        super().__init__('battery_cmd_vel_filter')

        self.battery_level = 100.0

        # Subscribe to battery percentage
        self.battery_sub = self.create_subscription(
            Float32,
            '/battery_percentage',
            self.battery_callback,
            10
        )

        # Subscribe to incoming command velocities (replace this with your control topic later if needed)
        self.cmd_vel_in_sub = self.create_subscription(
            Twist,
            '/cmd_vel_in',
            self.cmd_vel_callback,
            10
        )

        # Publish filtered velocities to the real turtle
        self.cmd_vel_out_pub = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10
        )

        self.get_logger().info('Battery CmdVel Filter started.')

    def battery_callback(self, msg):
        self.battery_level = msg.data

    def cmd_vel_callback(self, msg):
        if self.battery_level <= 0.0:
            self.get_logger().warn('Battery empty! Blocking movement command.')
            # Block movement by publishing zero velocity
            zero_cmd = Twist()
            self.cmd_vel_out_pub.publish(zero_cmd)
        else:
            # Forward the incoming command to the turtle
            self.cmd_vel_out_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = BatteryCmdVelFilter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
