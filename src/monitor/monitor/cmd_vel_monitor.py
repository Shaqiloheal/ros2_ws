#!/usr/bin/env python3

# Imports
import json
import rclpy
import rosidl_runtime_py
from rclpy.node import Node
from threading import Lock
from geometry_msgs.msg import Twist  # <- from geometry_msgs
from std_msgs.msg import String
from rosmonitoring_interfaces.msg import MonitorError


class ROSMonitorCmdVel(Node):
    def __init__(self, monitor_name, log, actions):
        super().__init__(monitor_name)

        self.name = monitor_name
        self.logfn = log
        self.actions = actions
        self.ws_lock = Lock()

        self.monitor_publishers = {
            'error': self.create_publisher(MonitorError, self.name + '/monitor_error', 10),
            'verdict': self.create_publisher(String, self.name + '/monitor_verdict', 10)
        }

        # Subscribe to cmd_vel_in
        self.subscription = self.create_subscription(
            Twist,
            'cmd_vel_in',
            self.callback_cmd_vel_in,
            10
        )

        self.get_logger().info(f'Monitor {self.name} started and ready')
        self.get_logger().info(f'Logging at {self.logfn}')

    def callback_cmd_vel_in(self, msg):
        self.get_logger().info(f'Monitor observed movement command: {msg}')
        
        data_dict = {
            'movement': rosidl_runtime_py.message_to_ordereddict(msg),
            'topic': 'cmd_vel_in',
            'time': float(self.get_clock().now().to_msg().sec)
        }

        with self.ws_lock:
            self.logging(data_dict)

        self.get_logger().info("Movement command event successfully logged")

    def logging(self, json_dict):
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event logged')
        except Exception as e:
            self.get_logger().info(f'Unable to log event: {e}')

def main(args=None):
    rclpy.init(args=args)
    log = './log_battery.txt'
    actions = {}
    actions['cmd_vel_in'] = ('log', 0)
    monitor = ROSMonitorCmdVel('monitor_cmd_vel', log, actions)
    rclpy.spin(monitor)
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
