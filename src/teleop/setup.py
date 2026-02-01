from setuptools import setup
import os
from glob import glob

package_name = 'teleop'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='r2d3',
    maintainer_email='r2d3@todo.todo',
    description='Teleoperation and data collection',
    license='MIT',
    tests_require=[],
    entry_points={
        'console_scripts': [
        ],
    },
)
