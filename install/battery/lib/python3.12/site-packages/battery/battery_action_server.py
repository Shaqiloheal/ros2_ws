import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from custom_action_interfaces.action import Battery


class BatteryActionServer(Node):
    def __init__(self):
        super().__init__('battery_action_server')

        self._action_server = ActionServer(
            self,
            Battery,
            'battery',
            self.execute_callback
        )

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        feedback_msg = Battery.Feedback()
        feedback_msg.percentage_log = []

        battery_percentage = 100.0

        while rclpy.ok():
            # Drain battery
            while battery_percentage > 0.0 and rclpy.ok():
                if battery_percentage > 80.0:
                    battery_percentage -= 2.0  # Slow drain
                elif battery_percentage > 20.0:
                    battery_percentage -= 5.0  # Normal drain
                else:
                    battery_percentage -= 1.0  # Slow drain near 0%

                battery_percentage = max(battery_percentage, 0.0)  # Clamp at 0
                feedback_msg.percentage_log.append(battery_percentage)

                self.get_logger().info(f'Draining: {battery_percentage:.2f}%')
                goal_handle.publish_feedback(feedback_msg)
                time.sleep(1)

            # Recharge battery
            self.get_logger().info('Battery fully drained. Starting recharge...')

            while battery_percentage < 80.0 and rclpy.ok():
                if battery_percentage < 20.0:
                    battery_percentage += 0.25  # Very slow recharge up to 20%
                else:
                    battery_percentage += 1.0   # Normal recharge up to 80%

                battery_percentage = min(battery_percentage, 80.0)  # Clamp at 80
                feedback_msg.percentage_log.append(battery_percentage)

                self.get_logger().info(f'Charging: {battery_percentage:.2f}%')
                goal_handle.publish_feedback(feedback_msg)
                time.sleep(1)

            self.get_logger().info('Battery recharged to 80%. Starting drain again.')

        goal_handle.succeed()

        result = Battery.Result()
        result.final_percentage = feedback_msg.percentage_log
        return result


def main(args=None):
    rclpy.init(args=args)
    server = BatteryActionServer()
    rclpy.spin(server)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
