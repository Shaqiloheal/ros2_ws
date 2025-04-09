#!/usr/bin/env python3

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from custom_action_interfaces.action import Battery


class BatteryActionClient(Node):
    def __init__(self):
        super().__init__('battery_action_client')
        self._action_client = ActionClient(self, Battery, 'battery')

    def send_goal(self):
        self._action_client.wait_for_server()

        goal_msg = Battery.Goal()
        goal_msg.cycles = 1  # only needed once to trigger "infinite loop" on server

        self.get_logger().info('Sending initial goal to start battery monitoring.')

        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected.')
            return
        self.get_logger().info('Goal accepted. Waiting for feedback...')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        last = feedback.percentage_log[-1] if feedback.percentage_log else None
        if last is not None:
            self.get_logger().info(f'Battery update: {last:.2f}%')

    def get_result_callback(self, future):
        self.get_logger().info('Battery monitoring ended unexpectedly.')
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    client = BatteryActionClient()
    client.send_goal()
    rclpy.spin(client)


if __name__ == '__main__':
    main()
