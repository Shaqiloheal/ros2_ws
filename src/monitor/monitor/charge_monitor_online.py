#!/usr/bin/env python3

# Author: Warren Spalding
# Description:
# This ROS 2 monitoring node observes the feedback and result messages
# from a Charge Action server. It filters relevant data fields and forwards them
# to an external runtime verification Oracle over WebSocket. The Oracle replies
# with a verdict which the monitor logs and publishes for further diagnostics.
# This version is intended for online verification during system execution.

# ============================
# Imports
# ============================

import json
import websocket
import rclpy
import rosidl_runtime_py
from rclpy.node import Node
from threading import Lock
from rosmonitoring_interfaces.msg import MonitorError
from std_msgs.msg import String

# Importing the custom Charge action and internal message structures
from custom_action_interfaces.action import Charge
from custom_action_interfaces.action._charge import Charge_FeedbackMessage
from custom_action_interfaces.action._charge import Charge_GetResult_Response

# ============================
# Charge Action Monitor (Online Version)
# ============================

class ROSMonitor_monitor_charge(Node):
    """
    ROS 2 Monitor node for observing Charge Action messages (feedback and result)
    and forwarding them to an online runtime verification Oracle using WebSocket.
    """

    def __init__(self, monitor_name, log, actions, action_namespace):
        """
        Constructor for the charge monitor node.

        Args:
            monitor_name (str): Name of the ROS node.
            log (str): Path to the log file.
            actions (dict): Dictionary of action names and their behavior (unused).
            action_namespace (str): The namespace of the monitored action server.
        """
        super().__init__(monitor_name)

        self.name = monitor_name
        self.logfn = log
        self.actions = actions
        self.action_namespace = action_namespace
        self.ws_lock = Lock()

        # Create monitor publishers
        self.monitor_publishers = {
            'error': self.create_publisher(MonitorError, self.name + '/monitor_error', 10),
            'verdict': self.create_publisher(String, self.name + '/monitor_verdict', 10)
        }

        # Subscribe to feedback messages from the action server
        self.feedback_subscriber = self.create_subscription(
            Charge_FeedbackMessage,
            f"{self.action_namespace}/_action/feedback",
            self.feedback_callback,
            10
        )

        # Subscribe to result messages from the action server
        self.result_subscriber = self.create_subscription(
            Charge_GetResult_Response,
            f"{self.action_namespace}/_action/result/response",
            self.result_callback,
            10
        )

        # Establish a WebSocket connection to the online Oracle
        websocket.enableTrace(False)
        self.ws = websocket.WebSocket()
        self.ws.connect('ws://127.0.0.1:9090')
        self.get_logger().info('WebSocket to Oracle is open')

        self.get_logger().info(f"Monitor '{self.name}' started and ready")
        self.get_logger().info(f"Logging to {self.logfn}")

    def feedback_callback(self, feedback_msg):
        """
        Callback for handling Charge action feedback messages.

        Args:
            feedback_msg (Charge_FeedbackMessage): Contains current battery level.
        """
        self.get_logger().info(f"Observed Charge Feedback: {str(feedback_msg)}")

        # Simplify message content
        feedback = feedback_msg.feedback
        data_dict = {
            'current_percentage': feedback.current_percentage,
            'time': float(self.get_clock().now().to_msg().sec)
        }

        self.send_to_oracle(data_dict)

    def result_callback(self, result_msg):
        """
        Callback for handling Charge action result messages.

        Args:
            result_msg (Charge_GetResult_Response): Contains success status.
        """
        self.get_logger().info(f"Observed Charge Result: {str(result_msg)}")

        result = result_msg.result
        data_dict = {
            'success': result.success,
            'time': float(self.get_clock().now().to_msg().sec)
        }

        self.send_to_oracle(data_dict)

    def send_to_oracle(self, data_dict):
        """
        Sends the processed message dictionary to the runtime verification Oracle.

        Args:
            data_dict (dict): Event to be sent (either feedback or result).
        """
        try:
            with self.ws_lock:
                self.ws.send(json.dumps(data_dict))
                oracle_response = self.ws.recv()
            self.on_message(oracle_response)
        except Exception as e:
            self.get_logger().error(f'Error communicating with Oracle: {str(e)}')

    def on_message(self, message):
        """
        Handles the Oracle's response verdict and publishes it.

        Args:
            message (str): JSON-formatted string returned by the Oracle.
        """
        json_dict = json.loads(message)
        verdict = str(json_dict['verdict'])

        # Publish verdict to a topic
        verdict_msg = String()
        verdict_msg.data = verdict
        self.monitor_publishers['verdict'].publish(verdict_msg)

        if verdict == 'false':
            # Property violation detected
            self.get_logger().warn(f"Property Violation: {message}")

            error = MonitorError()
            error.m_topic = json_dict.get('topic', self.action_namespace)
            error.m_time = json_dict['time']
            error.m_property = json_dict['spec']

            # Strip metadata fields and serialize remaining fields
            json_copy = json_dict.copy()
            for key in ['topic', 'time', 'spec', 'verdict']:
                json_copy.pop(key, None)

            error.m_content = json.dumps(json_copy)
            self.monitor_publishers['error'].publish(error)
        else:
            self.get_logger().info(f"Verdict OK: {message}")

        self.logging(json_dict)

    def logging(self, json_dict):
        """
        Logs the Oracle's verdict and associated event data to a local file.

        Args:
            json_dict (dict): Full dictionary including event and verdict.
        """
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event written to log.')
        except Exception as e:
            self.get_logger().error(f'Unable to log event: {str(e)}')

# ============================
# Main Entry Point
# ============================

def main(args=None):
    """
    Main function to launch the charge action online monitor.
    """
    rclpy.init(args=args)

    # Set monitor configuration
    log = './log_battery.txt'
    actions = {'/charge_battery': ('log', 0)}
    action_namespace = '/charge_battery'

    monitor = ROSMonitor_monitor_charge('charge_monitor_online', log, actions, action_namespace)
    rclpy.spin(monitor)

    # Clean shutdown
    monitor.ws.close()
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
