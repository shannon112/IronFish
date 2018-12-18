# IronFish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple ROS mobile robot that you can simply build it by yourself!   
(**ROS kinetic** is recommended)  
* Processor: Your laptop
* Sensor: Kinect, RealSense, Hokuyo LiDAR
* Actuator: Two DC motor with two wheels, and one guide wheel.
  
## Overview 
There are 7 pkgs in IronFish:   

| Pkg's name | Description            | 
| -----------| ----------------       |
| ironfish_hardware | **ironfish's** hardware **info**. No code inside. Check it out at ironfish_hardware/README.md |
| ironfish_ros_control |  **launching** the control of robot in **real** world. Check it out at ironfish_ros_control/README.md |  
| ironfish_uart |  **helping** ironfish_ros_control to communicate with the robot in **real** world. Check it out at ironfish_uart/README.md  |
| ironfish_description | **ironfish's** robot **model**(including plugins). Check it out at ironfish_description/README.md |
| ironfish_gazebo |  **launching** ironfish gazebo **simulation**(including control and sense). Check it out at ironfish_gazebo/README.md |
| ironfish_sensors |  **launching** the driver of ironfish sensors in **real** world. Check it out at ironfish_sensors/README.md |
| ironfish_navigation | **launching** ironfish high level application in **real/sim** world -- navigation and slam. Check it out at ironfish_navigation/README.md |
  
## Dependences
Please check and read at all packages in IronFish/<pkg_name>/README.md  

## Quickly start
#### Control nodes
Launch real world control node (with gui control panel)
```
roslaunch ironfish_ros_control ironfish_ros_control.launch
(roslaunch ironfish_ros_control ironfish_ros_control.launch rqt_steering:=1 rviz:=1)
```
Launch simulation(gazebo) world control node 
```
roslaunch ironfish_description ironfish_gazebo.launch
```
#### Sensor nodes (only be needed in reality)
Launch hokuyo LiDAR  
```
roslaunch ironfish_sensors urg.launch
```
Launch intel realsense rgbd-camera  
```
roslaunch ironfish_sensors realsense.launch
```
Launch microsoft kinectv1 rgbd-camera  
```
roslaunch ironfish_sensors openni.launch
```
#### Mapping aka. SLAM
Launch gmapping for slam  
```
roslaunch ironfish_navigation slam_gmapping.launch
```
Launch cartographer for slam  
```
roslaunch ironfish_navigation cartographer_ros.launch
```
#### Navigation
Launch navigation  
```
roslaunch ironfish_navigation move_base.launch
```
#### High level application
Launch steering & navigation and slam integration in real world  
```
roslaunch ironfish_navigation ironfish_nav_real.launch
```
Launch steering & navigation and slam integration in simulation world  
```
roslaunch ironfish_navigation ironfish_nav_sim.launch
```
#### Tool nodes
Launch control panel
```
rosrun rqt_robot_steering rqt_robot_steering
```
Analyzing
```
rosrun rqt_graph rqt_graph
```
<img src="https://github.com/shannon112/IronFish/blob/master/rqt_graph(debug off).png" width="800">
<img src="https://github.com/shannon112/IronFish/blob/master/rqt_graph.png" width="800">

```
rosrun rqt_tf_tree rqt_tf_tree
```
<img src="https://github.com/shannon112/IronFish/blob/master/rqt_tf_tree.png" width="800">
