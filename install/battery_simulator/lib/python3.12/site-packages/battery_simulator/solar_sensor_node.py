#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from datetime import datetime

class SolarSensorNode(Node):
    def __init__(self):
        super().__init__('solar_sensor_node')
        self.solar_charging_pub = self.create_publisher(Bool, '/solar_charging_state', 10)
        self.timer = self.create_timer(1.0, self.publish_solar_charge)

    def publish_solar_charge(self):
        now = datetime.now()
        hour = now.hour
        is_daytime = 6 <= hour < 18  # Charge only from 6 AM to 6 PM
        is_peak = 12 <= hour < 15    # Strong sun from 12 PM to 3 PM

        msg = Bool()
        msg.data = is_daytime  # Send TRUE only if sun is up
        self.solar_charging_pub.publish(msg)

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
