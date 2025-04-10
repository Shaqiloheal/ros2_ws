# Author: Warren Spalding
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32

class TemperatureSubscriber(Node):
    def __init__(self):
        super().__init__('temperature_subscriber')  # WS: Node name
        self.subscription = self.create_subscription(
            Float32,
            'temperature',  # WS: Subscribing to the 'temperature' topic
            self.listener_callback,
            10)
        self.subscription  # WS: prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('Received Temperature: %.2f °C' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = TemperatureSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
