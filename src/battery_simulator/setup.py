# Author: Warren Spalding
# Description: ROS 2 package setup file for the battery_simulator package.
# This setup file configures installation parameters and entry points for launching
# various ROS 2 nodes, including battery simulation, charging server, filtering,
# and a solar charging sensor.

from setuptools import find_packages, setup

# Define the package name used for installation
package_name = 'battery_simulator'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),  # Automatically find and include source directories, excluding test files
    data_files=[
        # Registers the package with ROS 2's ament indexing system
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        # Includes the package.xml in the install path
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],  # Specifies Python dependencies required for this package
    zip_safe=True,  # Indicates the package can be safely used in a zipped form
    maintainer='shaqiloheal',
    maintainer_email='w.spalding.toc@gmail.com',
    description='A simple battery percentage simulator for ROS 2.',
    license='Apache-2.0',  # Open source license type
    tests_require=['pytest'],  # Test dependencies

    # Console scripts to define ROS 2 node executables
    entry_points={
        'console_scripts': [
            # Launches the simulated battery node, responsible for monitoring usage and charge state
            'battery_node = battery_simulator.battery_node:main',

            # Provides an Action server that allows external nodes to send charge requests
            'battery_charge_server = battery_simulator.battery_charge_server:main',

            # Filters velocity commands based on battery state to prevent movement under low power
            'battery_cmd_vel_filter = battery_simulator.battery_cmd_vel_filter:main',

            # Simulates solar charging and publishes charge state depending on time of day
            'solar_sensor_node = battery_simulator.solar_sensor_node:main',
        ],
    },
)
