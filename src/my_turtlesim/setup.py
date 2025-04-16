# Author: Warren Spalding
# Description:
# This setup script configures the ROS 2 package my_turtlesim, which may include launch files
# and Python-based ROS 2 nodes related to the turtlesim simulator. It uses setuptools to define
# the package metadata, data files, dependencies, and console script entry points.

import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'my_turtlesim'

setup(
    name=package_name,
    version='0.0.0',

    # Automatically find Python sub-packages, excluding test directories
    packages=find_packages(exclude=['test']),

    # Specify additional data files to be installed with the package
    data_files=[
        # Register the package in the ament index
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),

        # Install the package's package.xml metadata file
        ('share/' + package_name, ['package.xml']),

        # Install all launch files located in the launch/ directory
        (os.path.join('share', package_name, 'launch'),
         glob(os.path.join('launch', '*launch.[pxy][ymx]*')))
    ],

    # Declare Python dependencies
    install_requires=['setuptools'],

    # Ensure compatibility with zipped installations
    zip_safe=True,

    # Package maintainer information
    maintainer='shaqiloheal',
    maintainer_email='w.spalding.toc@gmail.com',

    # Short description of the package’s purpose (to be updated)
    description='TODO: Package description',

    # License under which the package is released
    license='Apache-2.0',

    # Test requirements
    tests_require=['pytest'],

    # Define ROS 2 executable entry points if needed (currently empty)
    entry_points={
        'console_scripts': [
            # Example: 'my_node = my_turtlesim.my_node:main'
        ],
    },
)
