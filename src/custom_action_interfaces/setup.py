from setuptools import setup, find_packages

package_name = 'custom_action_interfaces'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(where='src'),  # <<< FIND PACKAGES AUTOMATICALLY
    package_dir={'': 'src'},               # <<< POINT TO src/ FOLDER
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='shaqiloheal',
    maintainer_email='w.spalding.toc@gmail.com',
    description='Custom action interface for Fibonacci',
    license='Apache-2.0',
    tests_require=['pytest'],
)
