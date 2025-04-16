# Author: Warren Spalding
# Description:
# This is the setup configuration script for the ROS 2 package `custom_action_interfaces`.
# It defines a custom action interface used in action-based communication between nodes.
# The script uses `setuptools` to manage the package installation and integration with ROS 2.

from setuptools import setup, find_packages

package_name = 'custom_action_interfaces'

setup(
    name=package_name,
    version='0.0.0',

    # Automatically discover all Python packages under the 'src' directory
    packages=find_packages(where='src'),

    # Maps package directories to the 'src' root
    package_dir={'': 'src'},

    # Registers package metadata and resources with ROS 2 ament system
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],

    # Required dependencies for the package
    install_requires=['setuptools'],

    # Whether the package can be safely archived as a zip file
    zip_safe=True,

    # Maintainer metadata
    maintainer='shaqiloheal',
    maintainer_email='w.spalding.toc@gmail.com',

    # Short description of the package purpose
    description='Custom action interface for Actions',

    # License declaration
    license='Apache-2.0',

    # Unit test dependencies
    tests_require=['pytest'],
)
