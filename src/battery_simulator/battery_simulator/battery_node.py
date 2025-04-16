#!/usr/bin/env python3

# Author: Warren Spalding
# Description: A ROS 2 node that simulates battery percentage for a robot.
# It accounts for battery drain due to movement, direct charging from an action server,
# and passive solar charging during daytime hours. It uses pose data to infer motion
# and regulates battery level based on system state.

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from turtlesim.msg import Pose
from datetime import datetime

class BatterySimulator(Node):
    def __init__(self):
        super().__init__('battery_simulator')

        # Publisher: Broadcast current battery percentage
        self.battery_pub = self.create_publisher(Float32, '/battery_percentage', 10)

        # Subscriber: Listen for direct charge requests from an action server
        self.charging_state_sub = self.create_subscription(
            Bool, '/battery_charging_state', self.charging_state_callback, 10)

        # Subscriber: Listen for solar charging availability from solar sensor node
        self.solar_state_sub = self.create_subscription(
            Bool, '/solar_charging_state', self.solar_charging_callback, 10)

        # Subscriber: Listen to turtle's pose to determine movement
        self.pose_sub = self.create_subscription(
            Pose, '/turtle1/pose', self.pose_callback, 10)

        # Internal state
        self.battery_level = 100.0            # Battery initialized to 100%
        self.is_charging = False              # Direct charging flag
        self.solar_charging = False           # Solar charging flag
        self.is_moving = False                # Motion detection flag
        self.last_pose = None                 # Stores previous pose to detect movement

        # Timer: Updates battery status every 1 second
        self.timer = self.create_timer(1.0, self.timer_callback)

        self.get_logger().info('Battery simulator node has started.')

    def charging_state_callback(self, msg):
        """Callback for action-based charging."""
        self.is_charging = msg.data
        if self.is_charging:
            self.get_logger().info('Charging started.')
        else:
            self.get_logger().info('Charging stopped.')

    def solar_charging_callback(self, msg):
        """Callback to receive solar charging status from the solar sensor node."""
        self.solar_charging = msg.data

    def pose_callback(self, msg):
        """Determines if the turtle is moving based on position delta."""
        if self.last_pose is None:
            self.last_pose = msg
            self.is_moving = False
            return

        dx = abs(msg.x - self.last_pose.x)
        dy = abs(msg.y - self.last_pose.y)
        self.is_moving = dx > 0.01 or dy > 0.01  # Movement threshold
        self.last_pose = msg

    def timer_callback(self):
        """Performs battery level updates based on charging and motion state."""
        now = datetime.now()
        is_peak_sun = 12 <= now.hour < 15  # Stronger solar gain between 12 PM - 3 PM

        if self.is_charging:
            # Rapid increase due to action-based charging
            self.battery_level += 5.0
        elif self.solar_charging and not self.is_moving:
            # Slow passive increase during solar charging
            self.battery_level += 0.25 if is_peak_sun else 0.1
        elif self.is_moving:
            # Movement consumes battery faster
            self.battery_level -= 5.0

        # Clamp battery between 0% and 100%
        self.battery_level = max(0.0, min(100.0, self.battery_level))

        # Publish battery status
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
