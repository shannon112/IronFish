# Ironfish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple ROS mobile robot that you can simply build it by yourself!  
* Processor: Your laptop
* Sensor: Kinect, RealSense, Hokuyo lazer
* Actuator: Two DC motor with two wheels, and one guide wheel.

### Introduction
There are 4 pkgs 3 launch files
ironfish_hardware:

### Quickly start
Launch gazebo
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
