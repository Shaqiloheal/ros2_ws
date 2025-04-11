#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose  # <-- import turtle Pose

class BatterySimulator(Node):
    def __init__(self):
        super().__init__('battery_simulator')

        self.battery_pub = self.create_publisher(Float32, '/battery_percentage', 10)
        self.charging_state_sub = self.create_subscription(Bool, '/battery_charging_state', self.charging_state_callback, 10)

        # Subscribe to turtle's pose
        self.pose_sub = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)

        self.battery_level = 100.0
        self.is_charging = False
        self.is_moving = False

        # Store last pose to detect motion
        self.last_pose = None

        self.timer = self.create_timer(1.0, self.timer_callback)

        self.get_logger().info('Battery simulator node has started.')

    def charging_state_callback(self, msg):
        self.is_charging = msg.data
        if self.is_charging:
            self.get_logger().info('Charging started.')
        else:
            self.get_logger().info('Charging stopped.')

    def pose_callback(self, msg):
        if self.last_pose is None:
            self.last_pose = msg
            self.is_moving = False
            return
        
        # Compare current pose to last pose
        dx = abs(msg.x - self.last_pose.x)
        dy = abs(msg.y - self.last_pose.y)

        if dx > 0.01 or dy > 0.01:  # Movement detected
            self.is_moving = True
        else:
            self.is_moving = False

        self.last_pose = msg  # Update last pose

    def timer_callback(self):
        if self.is_charging:
            if self.battery_level < 100.0:
                self.battery_level += 1.0
                if self.battery_level > 100.0:
                    self.battery_level = 100.0
        else:
            if self.is_moving:
                if self.battery_level > 0.0:
                    self.battery_level -= 1.0
                    if self.battery_level < 0.0:
                        self.battery_level = 0.0

        msg = Float32()
        msg.data = self.battery_level
        self.battery_pub.publish(msg)

        self.get_logger().info(f'Published battery level: {self.battery_level:.2f}% (Moving: {self.is_moving})')

def main(args=None):
    rclpy.init(args=args)
    node = BatterySimulator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
