# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# WS: Import ROS2 Python libraries
import rclpy
from rclpy.node import Node

# WS: Import standard message types
from std_msgs.msg import String
from std_msgs.msg import Int32
from std_msgs.msg import Bool

# WS: Define the Publisher Node
class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')  # WS: Initialize node with name 'minimal_publisher'
        
        # WS: Create publishers for three topics
        self.publisher_chatter = self.create_publisher(String, 'chatter', 10)  # Publish string messages
        # self.publisher_numbers = self.create_publisher(Int32, 'numbers', 10)   # Publish integer messages
        # self.publisher_status = self.create_publisher(Bool, 'status', 10)      # Publish boolean messages
        
        timer_period = 0.5  # WS: Publish every 0.5 seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)  # WS: Attach timer to callback
        
        self.i = 0  # WS: Counter for integer messages

    def timer_callback(self):
        # WS: Publish String to 'chatter' topic
        string_msg = String()
        string_msg.data = 'hello'
        self.publisher_chatter.publish(string_msg)
        self.get_logger().info('Publishing to chatter: "%s"' % string_msg.data)

        # WS: Publish Int32 to 'numbers' topic
        # int_msg = Int32()
        # int_msg.data = self.i
        # self.publisher_numbers.publish(int_msg)
        # self.get_logger().info('Publishing to numbers: "%d"' % int_msg.data)

        # WS: Publish Bool to 'status' topic
        # status_msg = Bool()
        # status_msg.data = (self.i % 2 == 0)  # WS: True if even, False if odd
        # self.publisher_status.publish(status_msg)
        # self.get_logger().info('Publishing to status: "%s"' % status_msg.data)

        # WS: Increment the counter *only once* per timer tick
        # self.i += 1

# WS: Main execution entry point
def main(args=None):
    rclpy.init(args=args)  # WS: Initialize ROS2 communication

    minimal_publisher = MinimalPublisher()  # WS: Create an instance of the publisher node

    rclpy.spin(minimal_publisher)  # WS: Keep the node running, publishing messages

    minimal_publisher.destroy_node()  # WS: Cleanly destroy the node after shutdown
    rclpy.shutdown()  # WS: Shutdown ROS2 system

# WS: If script is run directly, execute main()
if __name__ == '__main__':
    main()
