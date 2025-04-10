#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool

class BatterySimulator(Node):
    def __init__(self):
        super().__init__('battery_simulator')

        # Publisher for battery percentage
        self.battery_pub = self.create_publisher(Float32, '/battery_percentage', 10)

        # Subscriber for charging state
        self.charging_state_sub = self.create_subscription(
            Bool,
            '/battery_charging_state',
            self.charging_state_callback,
            10
        )

        # Internal state
        self.battery_level = 100.0
        self.is_charging = False

        # Timer for periodic update
        self.timer = self.create_timer(1.0, self.timer_callback)

        self.get_logger().info('Battery simulator node has started.')

    def charging_state_callback(self, msg):
        self.is_charging = msg.data
        if self.is_charging:
            self.get_logger().info('Charging started.')
        else:
            self.get_logger().info('Charging stopped, resuming discharge.')

    def timer_callback(self):
        if self.is_charging:
            # Charging logic
            if self.battery_level < 100.0:
                self.battery_level += 1.0
                if self.battery_level > 100.0:
                    self.battery_level = 100.0
        else:
            # Discharging logic
            if self.battery_level > 0.0:
                self.battery_level -= 1.0
                if self.battery_level < 0.0:
                    self.battery_level = 0.0

        # Publish battery level
        msg = Float32()
        msg.data = self.battery_level
        self.battery_pub.publish(msg)

        self.get_logger().info(f'Published battery level: {self.battery_level:.2f}%')

def main(args=None):
    rclpy.init(args=args)
    node = BatterySimulator()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
