#!/usr/bin/env python3

# Author: Warren Spalding
# Description:
# This ROS 2 node is a runtime monitor designed to observe feedback and result messages
# from a Charge Action server. It logs these messages to a local file in JSON format
# for traceability and offline verification. This is useful for ensuring that
# action-based robotic behaviors can be evaluated post hoc for specification violations
# or unexpected runtime conditions.

# ========================================
# Import required modules
# ========================================

import json
import rosidl_runtime_py
import rclpy
from rclpy.node import Node
from threading import Lock

# Custom monitoring message interfaces
from rosmonitoring_interfaces.msg import MonitorError
from std_msgs.msg import String

# Import Charge Action and its internal message types
from custom_action_interfaces.action import Charge
from custom_action_interfaces.action._charge import Charge_FeedbackMessage
from custom_action_interfaces.action._charge import Charge_GetResult_Response

# ========================================
# Charge Action Monitor Node
# ========================================

class ROSMonitor_monitor_charge(Node):
    """
    ROS 2 Node for monitoring the Charge Action.
    Observes both feedback and result topics, converts them to JSON,
    and logs them locally for runtime monitoring or offline inspection.
    """

    def __init__(self, monitor_name, log, actions, action_namespace):
        """
        Initializes the monitoring node with publishers and subscribers.

        Args:
            monitor_name (str): Name of the monitor node.
            log (str): Log file path to store feedback and result events.
            actions (dict): Dictionary of actions being monitored (for compatibility).
            action_namespace (str): Namespace used by the Charge action server.
        """
        super().__init__(monitor_name)

        self.name = monitor_name
        self.logfn = log
        self.actions = actions
        self.action_namespace = action_namespace

        self.monitor_publishers = {}
        self.ws_lock = Lock()  # Lock to avoid race conditions in logging

        # Monitor verdict and error publishers
        self.monitor_publishers['error'] = self.create_publisher(
            MonitorError, self.name + '/monitor_error', 10)
        self.monitor_publishers['verdict'] = self.create_publisher(
            String, self.name + '/monitor_verdict', 10)

        # Feedback subscriber from the Charge action server
        self.feedback_subscriber = self.create_subscription(
            Charge_FeedbackMessage,
            f"{self.action_namespace}/_action/feedback",
            self.feedback_callback,
            10
        )

        # Result subscriber from the Charge action server
        self.result_subscriber = self.create_subscription(
            Charge_GetResult_Response,
            f"{self.action_namespace}/_action/result/response",
            self.result_callback,
            10
        )

        self.get_logger().info(f"Monitor '{self.name}' started and ready")
        self.get_logger().info(f"Logging events to {self.logfn}")

    def feedback_callback(self, feedback_msg):
        """
        Callback that handles feedback messages from the Charge action.

        Args:
            feedback_msg (Charge_FeedbackMessage): Feedback message containing progress.
        """
        self.get_logger().info(f"Monitor observed feedback: {str(feedback_msg)}")

        feedback = feedback_msg.feedback
        data_dict = {
            'feedback': rosidl_runtime_py.message_to_ordereddict(feedback),
            'action': self.action_namespace,
            'time': float(self.get_clock().now().seconds_nanoseconds()[0])
        }

        # Lock while writing to the log to avoid concurrency issues
        with self.ws_lock:
            self.logging(data_dict)

        self.get_logger().info("Feedback event successfully logged")

    def result_callback(self, result_msg):
        """
        Callback that handles result messages from the Charge action.

        Args:
            result_msg (Charge_GetResult_Response): Final result of the charge process.
        """
        self.get_logger().info(f"Monitor observed result: {str(result_msg)}")

        result = result_msg.result
        data_dict = {
            'result': rosidl_runtime_py.message_to_ordereddict(result),
            'action': self.action_namespace,
            'time': float(self.get_clock().now().seconds_nanoseconds()[0])
        }

        with self.ws_lock:
            self.logging(data_dict)

        self.get_logger().info("Result event successfully logged")

    def logging(self, json_dict):
        """
        Write a dictionary of data to a log file in JSON format.

        Args:
            json_dict (dict): Dictionary representing the event data.
        """
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event successfully written to log')
        except Exception as e:
            self.get_logger().info(f'Unable to log the event: {str(e)}')

# ========================================
# Main function
# ========================================

def main(args=None):
    """
    Entry point for running the Charge action monitor node.
    """
    rclpy.init(args=args)

    # === Monitor configuration ===
    log = './log_battery.txt'
    actions = {'/charge_battery': ('log', 0)}
    action_namespace = '/charge_battery'

    # Launch the monitor
    monitor = ROSMonitor_monitor_charge('charge_monitor', log, actions, action_namespace)
    rclpy.spin(monitor)

    # Clean shutdown
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
