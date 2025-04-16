#!/usr/bin/env python3

# Author: Warren Spalding
# Description:
# This node provides an *online* runtime monitoring capability for a ROS 2 system,
# specifically targeting the `battery_percentage` topic. It acts as an intermediary
# between the running ROS system and an external RML Oracle connected over WebSocket.
# The Oracle returns a verdict (true/false/unknown) for each incoming message, which
# is used to issue runtime warnings or log results for later analysis.

# ==============================
# Imports
# ==============================
import json
import rclpy
import rosidl_runtime_py
import websocket
from rclpy.node import Node
from threading import Lock
from rosmonitoring_interfaces.msg import MonitorError
from std_msgs.msg import Float32, String

# ========================================
# ROSMonitorBatteryOnline class definition
# ========================================
class ROSMonitorBatteryOnline(Node):
    def __init__(self, monitor_name, log, actions):
        """
        Constructor for initializing the online battery monitor node.
        - Establishes WebSocket connection to RML Oracle.
        - Sets up subscribers and publishers for monitored data and verdicts.
        """
        super().__init__(monitor_name)

        self.name = monitor_name
        self.logfn = log
        self.actions = actions
        self.ws_lock = Lock()  # Prevent race conditions when using WebSocket

        # Publishers for verdicts and detected property violations
        self.monitor_publishers = {
            'error': self.create_publisher(MonitorError, f'{self.name}/monitor_error', 10),
            'verdict': self.create_publisher(String, f'{self.name}/monitor_verdict', 10)
        }

        # Subscriber to the topic we want to monitor
        self.subscription = self.create_subscription(
            Float32,
            'battery_percentage',
            self.callback_battery_percentage,
            10
        )

        # Open WebSocket connection to local Oracle instance
        websocket.enableTrace(False)
        self.ws = websocket.WebSocket()
        self.ws.connect('ws://127.0.0.1:8080')
        self.get_logger().info('WebSocket connection to Oracle is open')

        self.get_logger().info(f'Monitor {self.name} started and ready')
        self.get_logger().info(f'Logging events to {self.logfn}')

    def callback_battery_percentage(self, msg):
        """
        Callback for incoming battery percentage updates.
        Sends the message data to the Oracle for verdict evaluation.
        """
        self.get_logger().info(f'Monitor observed battery percentage: {msg.data:.2f}%')

        # Convert message to dictionary for JSON serialization
        event = rosidl_runtime_py.message_to_ordereddict(msg)
        event['topic'] = 'battery_percentage'
        event['time'] = float(self.get_clock().now().to_msg().sec)

        # Send event to Oracle and process response
        self.ws_lock.acquire()
        try:
            self.ws.send(json.dumps(event))
            response = self.ws.recv()
            self.get_logger().info('Event propagated to Oracle')
            self.on_message_from_oracle(response)
        finally:
            self.ws_lock.release()

    def on_message_from_oracle(self, message):
        """
        Process the response from the RML Oracle.
        - Publishes verdict.
        - Triggers a MonitorError message if a property is violated.
        """
        json_dict = json.loads(message)
        verdict = str(json_dict.get('verdict', 'unknown'))

        # Publish verdict as a standard String message
        verdict_msg = String()
        verdict_msg.data = verdict
        self.monitor_publishers['verdict'].publish(verdict_msg)

        # Only trigger error publisher for negative verdicts
        if verdict not in ['true', 'currently_true', 'unknown']:
            error = MonitorError()
            error.m_topic = json_dict.get('topic', '')
            error.m_time = json_dict.get('time', 0.0)
            error.m_property = json_dict.get('spec', '')
            error.m_content = json.dumps({
                k: v for k, v in json_dict.items()
                if k not in ['topic', 'time', 'spec', 'verdict']
            })
            self.monitor_publishers['error'].publish(error)
            self.get_logger().warn('Property violation detected!')

    def logging(self, json_dict):
        """
        Logs the event data to a local file.
        This supports offline inspection and debugging.
        """
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event successfully logged')
        except Exception as e:
            self.get_logger().error(f'Unable to log event: {e}')

# ===========================
# Main entry point for the node
# ===========================
def main(args=None):
    rclpy.init(args=args)
    log = './log_battery.txt'
    actions = {'battery_percentage': ('filter', 0)}  # Send to Oracle instead of logging locally

    monitor = ROSMonitorBatteryOnline('monitor_battery_online', log, actions)

    # Spin node and wait for shutdown
    rclpy.spin(monitor)

    monitor.ws.close()
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
