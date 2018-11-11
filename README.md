# Ironfish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple ROS mobile robot that you can simply build it by yourself!  
* Processor: Your laptop
* Sensor: Kinect, RealSense, Hokuyo lazer
* Actuator: Two DC motor with two wheels, and one guide wheel.

<<<<<<< HEAD
### Introduction
There are 4 pkgs 3 launch files
ironfish_hardware:

### Quickly start
Launch gazebo
=======
## Guidance
There are 3 pkg 1 doc folder in Ironfish repo. 
* ironfish_description: This package is for <usage><meaning>
* ironfish_ros_control: This package is for <usage><meaning>
* ironfish_uart: This package is for <usage><meaning>
* ironfish_hardware: This folder is for <usage><meaning>

## Usage
In real world
```
roslaunch rsc_car_ros_control rsc_car_ros_control.launch
```
4 nodes would be launched
>>>>>>> 216cbf84dce7589cf9e9aec42aed2ac579a79f9b
```
roslaunch ironfish_description ironfish_gazebo.launch
```
Launch rviz
```
roslaunch ironfish_description ironfish_rviz.launch
```
Launch control node
```
roslaunch ironfish_ros_control ironfish_ros_control.launch
```
