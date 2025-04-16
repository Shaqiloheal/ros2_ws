#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from turtlesim.msg import Pose
from datetime import datetime

class BatterySimulator(Node):
    def __init__(self):
        super().__init__('battery_simulator')

        self.battery_pub = self.create_publisher(Float32, '/battery_percentage', 10)

        self.charging_state_sub = self.create_subscription(
            Bool, '/battery_charging_state', self.charging_state_callback, 10)

        self.solar_state_sub = self.create_subscription(
            Bool, '/solar_charging_state', self.solar_charging_callback, 10)

        self.pose_sub = self.create_subscription(
            Pose, '/turtle1/pose', self.pose_callback, 10)

        self.battery_level = 100.0
        self.is_charging = False
        self.solar_charging = False
        self.is_moving = False
        self.last_pose = None

        self.timer = self.create_timer(1.0, self.timer_callback)

        self.get_logger().info('Battery simulator node has started.')

    def charging_state_callback(self, msg):
        self.is_charging = msg.data
        if self.is_charging:
            self.get_logger().info('Charging started.')
        else:
            self.get_logger().info('Charging stopped.')

    def solar_charging_callback(self, msg):
        self.solar_charging = msg.data

    def pose_callback(self, msg):
        if self.last_pose is None:
            self.last_pose = msg
            self.is_moving = False
            return

        dx = abs(msg.x - self.last_pose.x)
        dy = abs(msg.y - self.last_pose.y)

        self.is_moving = dx > 0.01 or dy > 0.01
        self.last_pose = msg

    def timer_callback(self):
        now = datetime.now()
        is_peak_sun = 12 <= now.hour < 15

        if self.is_charging:
            self.battery_level += 5.0
        elif self.solar_charging and not self.is_moving:
            self.battery_level += 0.25 if is_peak_sun else 0.1
        elif self.is_moving:
            self.battery_level -= 5.0  # Increased drain when moving

        self.battery_level = max(0.0, min(100.0, self.battery_level))

        msg = Float32()
        msg.data = self.battery_level
        self.battery_pub.publish(msg)

        self.get_logger().info(
            f'Published battery level: {self.battery_level:.2f}% '
            f'(Moving: {self.is_moving}, Solar: {self.solar_charging})'
        )

def main(args=None):
    rclpy.init(args=args)
    node = BatterySimulator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
