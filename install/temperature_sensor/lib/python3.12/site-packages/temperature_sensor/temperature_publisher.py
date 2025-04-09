# Author: Warren Spalding
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import math

class TemperaturePublisher(Node):
    def __init__(self):
        super().__init__('temperature_publisher') # WS: Node name
        self.publisher_ = self.create_publisher(Float32, 'temperature', 10) # WS: Publisher on /temperature
        self.timer = self.create_timer(1.0, self.timer_callback) # WS: 1 second interval
        self.start_time = self.get_clock().now().to_msg().sec # WS: Capture start time

    def timer_callback(self):
        current_time = self.get_clock().now().to_msg().sec - self.start_time
        # WS: Sine wave temperature simulation, between 20°C and 30°C
        temperature = 25.0 + 35.0 * math.sin(current_time * 0.1)

        msg = Float32()
        msg.data = temperature
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing Temperature: %.2f °C' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = TemperaturePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
