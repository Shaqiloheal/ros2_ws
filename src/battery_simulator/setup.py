from setuptools import find_packages, setup

package_name = 'battery_simulator'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='shaqiloheal',
    maintainer_email='w.spalding.toc@gmail.com',
    description='A simple battery percentage simulator for ROS 2.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'battery_node = battery_simulator.battery_node:main',
            'battery_charge_server = battery_simulator.battery_charge_server:main',
        ],
    },
)
