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

# WS: Import ROS2 Python client libraries
import rclpy
from rclpy.node import Node

# WS: Import standard message types
from std_msgs.msg import String
from std_msgs.msg import Int32  # WS: Integer message
from std_msgs.msg import Bool   # WS: Boolean message

# WS: Define the Subscriber Node
class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')  # WS: Initialize Node with name 'minimal_subscriber'

        # WS: Subscribe to 'chatter' topic (String type)
        self.subscription_chatter = self.create_subscription(
            String,
            'chatter',
            self.listener_callback_chatter,
            10)
        self.subscription_chatter  # WS: Prevent "unused variable" warning

        # WS: Subscribe to 'numbers' topic (Int32 type)
        # self.subscription_numbers = self.create_subscription(
        #     Int32,
        #     'numbers',
        #     self.listener_callback_numbers,
        #     10)
        # self.subscription_numbers  # WS: Prevent "unused variable" warning

        # WS: Subscribe to 'status' topic (Bool type)
        # self.subscription_status = self.create_subscription(
        #     Bool,
        #     'status',
        #     self.listener_callback_status,
        #     10)
        # self.subscription_status  # WS: Prevent "unused variable" warning

    # WS: Callback when a message is received on 'chatter'
    def listener_callback_chatter(self, msg):
        self.get_logger().info('I heard on /chatter: "%s"' % msg.data)

    # WS: Callback when a message is received on 'numbers'
    # def listener_callback_numbers(self, msg):
    #     self.get_logger().info('I heard on /numbers: "%d"' % msg.data)

    # WS: Callback when a message is received on 'status'
    # def listener_callback_status(self, msg):
    #     self.get_logger().info('I heard on /status: "%s"' % msg.data)

# WS: Main execution entry point
def main(args=None):
    rclpy.init(args=args)  # WS: Initialize ROS client library

    minimal_subscriber = MinimalSubscriber()  # WS: Create instance of the Node

    rclpy.spin(minimal_subscriber)  # WS: Keep the node alive to process incoming messages

    minimal_subscriber.destroy_node()  # WS: Cleanly destroy node after shutdown
    rclpy.shutdown()  # WS: Shutdown ROS client library

# WS: If this script is run directly, start the main function
if __name__ == '__main__':
    main()
