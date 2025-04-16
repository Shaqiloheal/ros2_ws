#!/usr/bin/env python3

# Author: Warren Spalding
# Description:
# This node monitors the `/battery_percentage` topic in a ROS 2 system and logs relevant data 
# to a local JSON file. It is designed to support runtime verification tools such as RML oracles 
# for battery safety properties. The node uses standard ROS 2 publisher/subscriber mechanisms and 
# logs events including timestamps and topic context.

# =======================
# Import Required Modules
# =======================
import json
import sys
import rclpy
import rosidl_runtime_py
from rclpy.node import Node
from threading import Lock
from rosmonitoring_interfaces.msg import MonitorError
from std_msgs.msg import Float32, String
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup

# ======================
# Battery Monitoring Node
# ======================
class ROSMonitorBattery(Node):
    def __init__(self, monitor_name, log, actions):
        super().__init__(monitor_name)

        # Initialize internal attributes
        self.name = monitor_name
        self.logfn = log
        self.actions = actions
        self.ws_lock = Lock()
        self.monitor_publishers = {}
        self.config_publishers = {}
        self.config_subscribers = {}
        self.topics_info = {}

        # Publisher for runtime verification error reporting
        self.monitor_publishers['error'] = self.create_publisher(
            MonitorError, f'{self.name}/monitor_error', 10)

        # Publisher for verdicts from RML Oracle/Monitor
        self.monitor_publishers['verdict'] = self.create_publisher(
            String, f'{self.name}/monitor_verdict', 10)

        # Topic monitoring registration (battery_percentage)
        self.topics_info['battery_percentage'] = {
            'package': 'std_msgs.msg',
            'type': 'Float32'
        }

        # Subscriber for battery percentage updates
        self.config_subscribers['battery_percentage'] = self.create_subscription(
            Float32,
            'battery_percentage',
            self.callback_battery_percentage,
            10
        )

        self.get_logger().info(f'Monitor {self.name} started and ready')
        self.get_logger().info(f'Logging at {self.logfn}')

    def callback_battery_percentage(self, data):
        # Callback triggered on receiving battery percentage updates
        self.get_logger().info("Monitor observed battery percentage: " + str(data))
        
        # Convert message to ordered dict for logging and oracle compatibility
        dict = rosidl_runtime_py.message_to_ordereddict(data)
        dict['topic'] = 'battery_percentage'
        dict['time'] = float(self.get_clock().now().to_msg().sec)

        # Synchronized write to log
        self.ws_lock.acquire()
        self.logging(dict)
        self.ws_lock.release()
        self.get_logger().info("Event successfully logged")

    def logging(self, json_dict):
        # Log the monitored data to the specified log file
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event logged')
        except Exception:
            self.get_logger().warn('Unable to log the event')

# ============================
# Main Function to Run the Node
# ============================
def main(args=None):
    rclpy.init(args=args)
    log = './log_battery.txt'
    actions = {'battery_percentage': ('log', 0)}
    
    # Start battery monitor node
    monitor = ROSMonitorBattery('monitor_battery', log, actions)
    rclpy.spin(monitor)

    # Shutdown procedures
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
