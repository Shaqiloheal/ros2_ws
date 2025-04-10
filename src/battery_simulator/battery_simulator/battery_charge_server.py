#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse
from custom_action_interfaces.action import Charge
from std_msgs.msg import Bool, Float32
import time

class BatteryChargeServer(Node):
    def __init__(self):
        super().__init__('battery_charge_server')

        self.current_battery = 0.0
        self.target_battery = 100.0
        self.shutdown_timer_started = False

        self.charging_pub = self.create_publisher(Bool, '/battery_charging_state', 10)
        self.battery_sub = self.create_subscription(
            Float32,
            '/battery_percentage',
            self.battery_callback,
            10
        )

        self._action_server = ActionServer(
            self,
            Charge,
            'charge_battery',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback
        )

        self.get_logger().info('Battery charge server has started.')

    def battery_callback(self, msg):
        self.current_battery = msg.data

    def goal_callback(self, goal_request):
        if goal_request.target_percentage <= self.current_battery:
            self.get_logger().warn(f'Rejecting goal: target {goal_request.target_percentage:.2f}% <= current battery {self.current_battery:.2f}%')
            return GoalResponse.REJECT
        self.get_logger().info(f'Accepting goal to charge to {goal_request.target_percentage:.2f}%')
        return GoalResponse.ACCEPT

    async def execute_callback(self, goal_handle):
        self.target_battery = goal_handle.request.target_percentage
        self.get_logger().info(f'Received charge request to {self.target_battery:.2f}%')

        charging_msg = Bool()
        charging_msg.data = True
        self.charging_pub.publish(charging_msg)

        while self.current_battery < self.target_battery and rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.1)

            feedback_msg = Charge.Feedback()
            feedback_msg.current_percentage = self.current_battery
            goal_handle.publish_feedback(feedback_msg)

            self.get_logger().info(f'Charging... {self.current_battery:.2f}%')

            time.sleep(0.9)

        charging_msg.data = False
        self.charging_pub.publish(charging_msg)

        goal_handle.succeed()

        result = Charge.Result()
        result.success = True

        self.get_logger().info('Charging complete.')

        # Instead of shutdown here, start a timer flag
        self.shutdown_timer_started = True
        self.shutdown_timer_start_time = time.time()

        return result

def main(args=None):
    rclpy.init(args=args)
    node = BatteryChargeServer()

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)

            # Check if shutdown timer has started
            if getattr(node, 'shutdown_timer_started', False):
                # Wait 2 seconds after goal is complete
                if (time.time() - node.shutdown_timer_start_time) > 2.0:
                    node.get_logger().info('Auto shutdown after charge complete.')
                    break

    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
