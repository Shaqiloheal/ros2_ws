#!/usr/bin/env python3

import json
import websocket
import rclpy
import rosidl_runtime_py
from rclpy.node import Node
from threading import Lock
from rosmonitoring_interfaces.msg import MonitorError
from std_msgs.msg import String

# Import Charge Action
from custom_action_interfaces.action import Charge
from custom_action_interfaces.action._charge import Charge_FeedbackMessage
from custom_action_interfaces.action._charge import Charge_GetResult_Response

class ROSMonitor_monitor_charge(Node):
    def __init__(self, monitor_name, log, actions, action_namespace):
        super().__init__(monitor_name)

        self.name = monitor_name
        self.logfn = log
        self.actions = actions
        self.action_namespace = action_namespace
        self.ws_lock = Lock()

        # Publishers
        self.monitor_publishers = {
            'error': self.create_publisher(MonitorError, self.name + '/monitor_error', 10),
            'verdict': self.create_publisher(String, self.name + '/monitor_verdict', 10)
        }

        # Subscriptions
        self.feedback_subscriber = self.create_subscription(
            Charge_FeedbackMessage,
            f"{self.action_namespace}/_action/feedback",
            self.feedback_callback,
            10
        )

        self.result_subscriber = self.create_subscription(
            Charge_GetResult_Response,
            f"{self.action_namespace}/_action/result/response",
            self.result_callback,
            10
        )

        # WebSocket Connection
        websocket.enableTrace(False)
        self.ws = websocket.WebSocket()
        self.ws.connect('ws://127.0.0.1:9090')
        self.get_logger().info('WebSocket to Oracle is open')

        self.get_logger().info(f"Monitor '{self.name}' started and ready")
        self.get_logger().info(f"Logging to {self.logfn}")

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f"Observed Charge Feedback: {str(feedback_msg)}")

        feedback = feedback_msg.feedback

        # Only send the 'current_percentage'
        data_dict = {
            'current_percentage': feedback.current_percentage,
            'time': float(self.get_clock().now().to_msg().sec)
        }

        self.send_to_oracle(data_dict)

    def result_callback(self, result_msg):
        self.get_logger().info(f"Observed Charge Result: {str(result_msg)}")

        result = result_msg.result

        # Only send the 'success' field
        data_dict = {
            'success': result.success,
            'time': float(self.get_clock().now().to_msg().sec)
        }

        self.send_to_oracle(data_dict)

    def send_to_oracle(self, data_dict):
        try:
            with self.ws_lock:
                self.ws.send(json.dumps(data_dict))
                oracle_response = self.ws.recv()
            self.on_message(oracle_response)
        except Exception as e:
            self.get_logger().error(f'Error communicating with Oracle: {str(e)}')

    def on_message(self, message):
        json_dict = json.loads(message)
        verdict = str(json_dict['verdict'])

        verdict_msg = String()
        verdict_msg.data = verdict
        self.monitor_publishers['verdict'].publish(verdict_msg)

        if verdict == 'false':
            self.get_logger().warn(f"Property Violation: {message}")

            error = MonitorError()
            error.m_topic = json_dict.get('topic', self.action_namespace)
            error.m_time = json_dict['time']
            error.m_property = json_dict['spec']

            json_copy = json_dict.copy()
            for key in ['topic', 'time', 'spec', 'verdict']:
                json_copy.pop(key, None)

            error.m_content = json.dumps(json_copy)
            self.monitor_publishers['error'].publish(error)
        else:
            self.get_logger().info(f"Verdict OK: {message}")

        self.logging(json_dict)

    def logging(self, json_dict):
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event written to log.')
        except Exception as e:
            self.get_logger().error(f'Unable to log event: {str(e)}')

def main(args=None):
    rclpy.init(args=args)

    log = './log_battery.txt'
    actions = {'/charge_battery': ('log', 0)}
    action_namespace = '/charge_battery'

    monitor = ROSMonitor_monitor_charge('charge_monitor_online', log, actions, action_namespace)

    rclpy.spin(monitor)

    monitor.ws.close()
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
