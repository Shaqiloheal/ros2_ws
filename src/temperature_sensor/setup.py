from setuptools import find_packages, setup

package_name = 'temperature_sensor'

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
    description='Simulated Temperature Sensor Publisher',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'temperature_publisher = temperature_sensor.temperature_publisher:main',
            'temperature_subscriber = temperature_sensor.temperature_subscriber:main',
        ],
    },
)
