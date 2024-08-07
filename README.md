# 5-DOF Robotic Arm with Gripper using ROS

This project presents the development of a 5-Degree-of-Freedom (5-DOF) robotic arm with a gripper, utilizing the Robot Operating System (ROS). The system is constructed with an Arduino connected to a laptop running Ubuntu, where ROS is installed. The integration of the MoveIt plugin in ROS facilitates the arm's operation, and pick-and-place functionalities are implemented through Python code.

## Prerequisites

1. **Ubuntu 20.04**: This project is tested on Ubuntu 20.04.
2. **ROS Noetic**: Follow the [official installation guide](http://wiki.ros.org/noetic/Installation/Ubuntu).
3. **Arduino IDE**: To upload code to the Arduino.
4. **MoveIt**: Follow the [official installation guide](https://moveit.ros.org/install/).

## Hardware Components

1. SG90 Servo Motors
2. MG996R Servo Motors
3. Arduino
4. 3.7V Lithium-ion Battery
5. 18650 Battery Slot
6. Jumper Wires
7. 3D-Printed Robotic Arm

## Software Components

1. URDF (Unified Robot Description Format)
2. RViz (ROS Visualization)
3. MoveIt (Motion Planning Framework)

## System Architecture

The system architecture includes several key components and nodes working together within the ROS framework:

- **ROS Nodes**: Joint State Publisher, Inverse Kinematics Solver, Trajectory Planner, Gripper Controller, and Sensor Interfaces.
- **ROS Topics**: Joint State Topics, Desired Pose Topics, and Gripper Control Topics.
- **ROS Services and Actions**: Inverse Kinematics Service and Trajectory Execution Action.

## Launching the Project

### Without MoveIt Package

1. **Clone the Repository**
    ```bash
    git clone https://github.com/Rohitvgupta15/5-DOF-ROBOTIC-ARM-WITH-GRIPPER.git
    cd robotic_arm
    ```

2. **Build the Workspace**
    ```bash
    catkin_make
    source devel/setup.bash
    ```

3. **Launch the Nodes**
    ```bash
    roslaunch arm_5dof_description display.launch
    ```

### With MoveIt Package

1. **Setup MoveIt Configuration**
    ```bash
    roslaunch moveit_setup_assistant setup_assistant.launch
    ```

2. **Generate MoveIt Configuration**
    - Follow the GUI steps to create a MoveIt configuration for your robotic arm.
    - Save the configuration in your workspace.

3. **Launch MoveIt**
    ```bash
    roslaunch moveit_pkg demo.launch
    ```

### Integrating with Hardware

1. **Upload Arduino Code**
    - Connect your Arduino to the computer.
    - Upload the provided Arduino code from the `arduino` directory.

2. **Launch the ROS Nodes with Hardware Integration**
    ```bash
      rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0 _baud:=115200  
```

