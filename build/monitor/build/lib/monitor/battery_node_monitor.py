#!/usr/bin/env python3

# begin imports
import json
import sys
import rclpy
import rosidl_runtime_py
from rclpy.node import Node
from threading import Lock
from rosmonitoring_interfaces.msg import MonitorError
from std_msgs.msg import Float32, String
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
# done imports

class ROSMonitorBattery(Node):

    def callback_battery_percentage(self, data):
        self.get_logger().info("Monitor observed battery percentage: " + str(data))
        dict = rosidl_runtime_py.message_to_ordereddict(data)
        dict['topic'] = 'battery_percentage'
        dict['time'] = float(self.get_clock().now().to_msg().sec)

        self.ws_lock.acquire()
        self.logging(dict)
        self.ws_lock.release()
        self.get_logger().info("Event successfully logged")

    def __init__(self, monitor_name, log, actions):
        self.monitor_publishers = {}
        self.config_publishers = {}
        self.config_subscribers = {}
        self.ws_lock = Lock()
        self.name = monitor_name
        self.actions = actions
        self.logfn = log
        self.topics_info = {}

        super().__init__(self.name)

        self.monitor_publishers['error'] = self.create_publisher(
            MonitorError, self.name + '/monitor_error', 10)

        self.monitor_publishers['verdict'] = self.create_publisher(
            String, self.name + '/monitor_verdict', 10)

        self.publish_topics = False
        self.topics_info['battery_percentage'] = {'package': 'std_msgs.msg', 'type': 'Float32'}

        self.config_subscribers['battery_percentage'] = self.create_subscription(
            Float32, 'battery_percentage', self.callback_battery_percentage, 10)

        self.get_logger().info('Monitor ' + self.name + ' started and ready')
        self.get_logger().info('Logging at ' + self.logfn)

    def logging(self, json_dict):
        try:
            with open(self.logfn, 'a+') as log_file:
                log_file.write(json.dumps(json_dict) + '\n')
            self.get_logger().info('Event logged')
        except:
            self.get_logger().info('Unable to log the event')

def main(args=None):
    rclpy.init(args=args)
    log = './log_battery.txt'
    actions = {}
    actions['battery_percentage'] = ('log', 0)
    monitor = ROSMonitorBattery('monitor_battery', log, actions)
    rclpy.spin(monitor)
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
