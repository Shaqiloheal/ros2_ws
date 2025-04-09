import sys

from example_interfaces.srv import AddTwoInts
import rclpy
from rclpy.node import Node


import random
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(AddTwoInts, 'add_two_ints')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.req = AddTwoInts.Request()
        # Timer to send requests every 2 seconds
        self.timer = self.create_timer(2.0, self.timer_callback)

    def timer_callback(self):
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        self.req.a = a
        self.req.b = b
        future = self.cli.call_async(self.req)
        future.add_done_callback(self.response_callback)
        self.get_logger().info(f'Sent request: {a} + {b}')

    def response_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Result of add_two_ints: {response.sum}')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')

def main():
    rclpy.init()

    minimal_client = MinimalClientAsync()
    rclpy.spin(minimal_client)

    minimal_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
