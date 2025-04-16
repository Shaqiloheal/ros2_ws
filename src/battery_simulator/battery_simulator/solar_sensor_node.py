#!/usr/bin/env python3

# Author: Warren Spalding
# Description:
# This ROS 2 node simulates a solar sensor responsible for publishing whether the robot
# is receiving solar energy for charging. Charging is permitted only during the daytime
# (06:00 to 18:00), with enhanced messages during peak sunlight hours (12:00 to 15:00).
# It publishes a Boolean value to indicate whether solar charging should be active.

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from datetime import datetime

class SolarSensorNode(Node):
    def __init__(self):
        super().__init__('solar_sensor_node')

        # Publisher for solar charging state (True if charging, False otherwise)
        self.solar_charging_pub = self.create_publisher(Bool, '/solar_charging_state', 10)

        # Timer: triggers every 1 second to evaluate time of day and publish status
        self.timer = self.create_timer(1.0, self.publish_solar_charge)

    def publish_solar_charge(self):
        """
        Determines current solar charging eligibility based on system clock.
        Charging is enabled between 6 AM and 6 PM.
        During peak hours (12 PM to 3 PM), an additional log is published.
        """
        now = datetime.now()
        hour = now.hour

        is_daytime = 6 <= hour < 18  # Solar charging window
        is_peak = 12 <= hour < 15    # Peak solar charging period

        msg = Bool()
        msg.data = is_daytime  # Charging allowed only during daytime
        self.solar_charging_pub.publish(msg)

        # Log messages to indicate charging state and period
        if is_daytime:
            if is_peak:
                self.get_logger().info("Solar charging... Peak sun hours (sending charging state TRUE)")
            else:
                self.get_logger().info("Solar charging... Normal daytime (sending charging state TRUE)")
        else:
            self.get_logger().info("Night time... (sending charging state FALSE)")

def main(args=None):
    rclpy.init(args=args)
    node = SolarSensorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
