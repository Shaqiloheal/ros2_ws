# ros2_ws

## Author
**W. Spalding**

## Overview
This repository contains the ROS 2 workspace (`ros2_ws`) for projects developed alongside the [ROSMonitoring3.0](https://github.com/autonomy-and-verification-uol/ROSMonitoring) repository.  
It includes custom action interfaces, monitoring nodes, and simulation tools designed to extend the runtime verification capabilities provided by ROSMonitoring3.0.

## Purpose
The workspace serves as:
- A **testing environment** for custom monitoring of ROS 2 Actions, Topics, and Services.
- An **extension** for experimenting with runtime verification, battery simulation, and feedback/result monitoring.
- A **learning platform** for ROS 2 Actions, Feedback, and Runtime Event Logging.

## Important Notes
- This workspace assumes that the [ROSMonitoring3.0](https://github.com/autonomy-and-verification-uol/ROSMonitoring) repository is also cloned and built alongside it.
- Developed using **ROS 2 Jazzy**.
- Primary programming language: **Python 3.12**.

## Build Instructions
```bash
cd ~/ros2_ws
colcon build
source install/setup.bash
```

## Running Example
Example launch files are available under the `src/` directory for simulating action servers, clients, and monitors.

---
