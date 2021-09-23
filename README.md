# SMACC2

SMACC2 is a state-machine framework for ROS2-based applications written in C++.


## Repository Status, Packages and Documentation

 ROS2 Distro | Build status | Documentation | Released packages
 :---------: | :----------: | :-----------: | :---------------:
**Galactic** <br /> **Rolling** | [master](https://github.com/robosoft-ai/SMACC2/tree/master) <br /> [![Binary Build](https://github.com/robosoft-ai/SMACC2/actions/workflows/ci-build-binary.yml/badge.svg)](https://github.com/robosoft-ai/SMACC2/actions/workflows/ci-build-binary.yml) <br /> [![Semi-Binary Build](https://github.com/robosoft-ai/SMACC2/actions/workflows/ci-build-semi-binary.yml/badge.svg)](https://github.com/robosoft-ai/SMACC2/actions/workflows/ci-build-semi-binary.yml) <br /> [![Source Build](https://github.com/robosoft-ai/SMACC2/actions/workflows/ci-build-source.yml/badge.svg)](https://github.com/robosoft-ai/SMACC2/actions/workflows/ci-build-source.yml) | [![Doxygen Doc Deployment](https://github.com/robosoft-ai/SMACC2/actions/workflows/doxygen-deploy.yml/badge.svg)](https://github.com/robosoft-ai/SMACC2/actions/workflows/doxygen-deploy.yml) <br /> [Generated Doc](https://robosoft-ai.github.io/SMACC2_Documentation/master/html/index.html) | [smacc2](https://index.ros.org/p/smacc2/) <br /> [smacc2_msgs](https://index.ros.org/p/smacc2_msgs/)


## Repository Structure

- `smacc2` - core library of SMACC2.
- `smacc_client_library` - client libraries for SMACC2, e.g., Navigation2 (`move_base_z_client`), MoveIt2 (`move_group_interface_client`).
- `smacc_event_generators` - ...
- `smacc_msgs` - ROS2 messages for SMACC2 framework.
- `smacc_sm_reference_library` - libraries with reference implementations of state-machines used for demonstaration and testing of functionalities.
- `↓smacc_state_reactor_library` - ...


## Getting started

1. [Install ROS2 Rolling](https://index.ros.org/doc/ros2/Installation/Rolling/Linux-Install-Debians/).

2. Make sure that `colcon`, its extensions and `vcs` are installed:
   ```
   sudo apt install python3-colcon-common-extensions python3-vcstool
   ```

3. Create a new ROS2 workspace:
   ```
   export COLCON_WS=~/workspace/ros_ws_rolling_smacc
   mkdir -p $COLCON_WS/src
   ```

4. Pull relevant packages, install dependencies, compile, and source the workspace by using:
   ```
   cd $COLCON_WS
   git clone https://github.com/robosoft-ai/SMACC2.git src/SMACC2
   vcs import src --skip-existing --input src/SMACC2/SMACC2-not-released.rolling.repos
   rosdep install --ignore-src --from-paths src -y -r
   colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release
   source install/setup.bash
   ```

## Examples

To demonstrate some functionalities of the SMACC2 you can use following examples:

### sm_atomic
TBD: add some description
```
ros2 launch sm_atomic sm_atomic.py
```

### sm_dance_bot
TBD: add some description
```
ros2 launch sm_dance_bot sm_dance_bot_launch.py
```




SMACC2 is an event-driven, asynchronous, behavioral state machine library for real-time ROS2 (Robotic Operating System) applications written in C++, designed to allow programmers to build robot control applications for multicomponent robots, in an intuitive and systematic manner.

SMACC was inspired by Harel's statecharts and the [SMACH ROS package](http://wiki.ros.org/smach). SMACC is built on top of the [Boost StateChart library](https://www.boost.org/doc/libs/1_53_0/libs/statechart/doc/index.html).


## Features
 *  ***Powered by ROS2:*** SMACC2 has been developed specifically to work with ROS2. It supports ROS2 topics, services and actions, right out of the box.
 *   ***Written in C++:*** Until now, ROS2 has lacked a library to develop task-level behavioral state machines in C++. Although libraries have been developed in scripting languages such as python, these are unsuitable for real-world industrial environments where real-time requirements are demanded.
 *   ***Orthogonals:*** Originally conceived by David Harel in 1987, orthogonality is absolutely crucial to developing state machines for complex robotic systems. This is because complex robots are always a collection of hardware devices which require communication protocols, start-up determinism, etc. With orthogonals, it is an intuitive and relatively straight forward exercise (at least conceptually;) to code a state machine for a robot comprising a mobile base, a robotic arm, a gripper, two lidar sensors, a gps transceiver and an imu, for instance.
 *  ***Static State Machine Checking:*** One of the features that SMACC2 inherits from Boost Statechart is that you get compile time validation checking. This benefits developers in that the amount of runtime testing necessary to ship quality software that is both stable and safe is dramatically reduced. Our philosophy is "Wherever possible, let the compiler do it".
 *  ***State Machine Reference Library:*** With a constantly growing library of out-of-the-box reference state machines, (found in the folder [sm_reference_library](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_sm_reference_library)) guaranteed to compile and run, you can jumpstart your development efforts by choosing a reference machine that is closest to your needs, and then customize and extend to meet the specific requirements of your robotic application. All the while knowing that the library supports advanced functionalities that are practically universal among actual working robots.
 *  ***SMACC2 Client Library:*** SMACC2 also features a constantly growing library of [clients](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_client_library) that support ROS2 Action Servers, Service Servers and other nodes right out-of-the box. The clients within the SMACC2 Client library have been built utilizing a component based architecture that allows for developer to build powerful clients of their own. Current clients of note include MoveBaseZ, a full featured Action Client built to integrate with Nav2, the ros_timer_client, the multi_role_sensor_client, and a keyboard_client used extensively for state machine drafting & debugging.
  *  ***Extensive Documentation:*** Although many ROS users are familiar with doxygen, our development team has spent a lot of time researching the more advanced features of doxygen such as uml style class diagrams and call graphs, and we've used them to document the SMACC2 library. Have a look to [our doxygen sites](https://robosoft-ai.github.io/SMACC2_Documentation/master/html/namespaces.html) and we think you'll be blown away at what Doxygen looks like when [it's done right](https://robosoft-ai.github.io/SMACC2_Documentation/master/html/classsmacc2_1_1ISmaccStateMachine.html) and it becomes a powerful tool to research a codebase.
  *  ***SMACC2 Runtime Analyzer:*** The SMACC2 library works out of the box with the SMACC2 RTA. This allows developers to visualize and runtime debug the state machines they are working on. The SMACC2 RTA is closed source, but is free for individual and academic use. It can be found [here](https://robosoft.ai/product-category/smacc2-runtime-analyzer/).


## SMACC2 applications
From it's inception, SMACC2 was written to support the programming of multi-component, complex robots. If your project involves small, solar-powered insect robots, that simply navigate towards a light source, then SMACC2 might not be the right choice for you. But if you are trying to program a robot with a mobile base, a robotic arm, a gripper, two lidar sensors, a gps transceiver and an imu, then you've come to the right place.


## Getting Started
The easiest way to get started is by selecting one of the state machines in our [reference library](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_sm_reference_library), and then hacking it to meet your needs.

Each state machine in the reference library comes with it's own README.md file, which contains the appropriate operating instructions, so that all you have to do is simply copy & paste some commands into your terminal.


  *  If you are looking for a minimal example, we recommend [sm_atomic](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_sm_reference_library/sm_atomic).

  *  If you are looking for a minimal example but with a looping superstate, try [sm_three_some](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_sm_reference_library/sm_three_some).

  *  If you want to get started with the ROS Navigation stack right away, try [sm_dance_bot](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_sm_reference_library/sm_dance_bot).

  *  If you want to get started with ROS Navigation and exploring the orthogonal read-write cycle, then try [sm_dance_bot_strikes_back](https://github.com/robosoft-ai/SMACC2/tree/master/smacc_sm_reference_library/sm_dance_bot_strikes_back).


Operating instructions can be found in each reference state machines readme file.
Happy Coding.

## Support
If you are interested in getting involved or need a little support, feel free to contact us by emailing brett@robosoft.ai
