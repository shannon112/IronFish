# Ironfish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple ROS mobile robot that you can simply build it by yourself! (ROS kinetic is recommended)  
* Processor: Your laptop
* Sensor: Kinect, RealSense, Hokuyo lazer
* Actuator: Two DC motor with two wheels, and one guide wheel.
  
### Introduction 
There are 4 pkgs including 3 launch files  
* ironfish_hardware:  
This folder is for the robot hardware info. No code inside. Check it out at ironfish_hardware/README.md
* ironfish_ros_control:  

* ironfish_uart:  

* ironfish_description:   
This package is for ironfish gazebo/rviz ros launch files. Check it out at ironfish_description/README.md
  
### Quickly start
Launch control node (with control panel)
```
roslaunch ironfish_ros_control ironfish_ros_control.launch
(roslaunch ironfish_ros_control ironfish_ros_control.launch rqt_steering:=1)
```
Launch control panel
```
rosrun rqt_robot_steering rqt_robot_steering
```
Launch rviz
```
roslaunch ironfish_description ironfish_rviz.launch
```
Launch gazebo
```
roslaunch ironfish_description ironfish_gazebo.launch
```
