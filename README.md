# IronFish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple ROS based diff-drive mobile robot that you can simply build it by yourself!  
(**ROS kinetic** is recommended)  
Inspiration from:  
https://github.com/willie5588912/rsc_car_course  
https://github.com/willie5588912/iubot1  
Especially thanks to @willie5588912 developing ros_control  

SW  
* amcl localization  
* gmapping SLAM  
* move_base navigation stack  
* fine-tuned teb_local_planner  
* robot_pose_ekf sensor fusion of odometry  

HW  
* Processor: Your laptop (or Nvidia TX2)
* Sensor: Kinect, RealSense, Hokuyo_LiDAR, Razor_IMU, Faulhaber_encoder
* Actuator: Two DC motor with two wheels, and one guide wheel.  
  
  
## Overview 
There are 8 pkgs in IronFish:   

| Pkg's name | Description            | 
| -----------| ----------------       |
| ironfish_hardware | **ironfish's** hardware **info**. No code inside. Check it out at ironfish_hardware/README.md |
| ironfish_ros_control |  **launching** the control of robot in **real** world. Check it out at ironfish_ros_control/README.md |  
| ironfish_uart |  **helping** ironfish_ros_control to communicate with the robot in **real** world. Check it out at ironfish_uart/README.md  |
| ironfish_description | **ironfish's** robot **model**(including plugins). Check it out at ironfish_description/README.md |
| ironfish_gazebo |  **launching** ironfish gazebo **simulation**(including control and sense). Check it out at ironfish_gazebo/README.md |
| iceira_gazebo | **iceira's** gazebo world. Check it out at iceira_gazebo/README.md |
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
roslaunch ironfish_gazebo ironfish_gazebo.launch
```
#### Sensor nodes (only be needed in reality)
Launch hokuyo laser scanner  
```
roslaunch ironfish_sensors urg.launch
roslaunch ironfish_sensors urg_dual.launch
```
Launch intel realsense rgbd-camera  
```
roslaunch ironfish_sensors rs_camera.launch
```
Launch microsoft kinectv1 rgbd-camera  
```
roslaunch ironfish_sensors openni.launch
```
Launch SparkFun 9DOF Razor IMU M0  
```
roslaunch ironfish_sensors razor-pub.launch
roslaunch ironfish_sensors razor-pub-and-display.launch
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
Launch rtabmap for vslam  
```
roslaunch ironfish_navigation rtabmap_demo.launch
```
Launch map saver for saving the map as test66.yaml and test66.pgm in ./ironfish_navigation/map/ after slam  
```
roslaunch ironfish_navigation map_saver.launch number:=66
```
Launch map server for publishing the known map  
```
roslaunch ironfish_navigation map_sever.launch
```
#### Localization
Launch amcl for localization  
```
roslaunch ironfish_navigation amcl.launch
```
#### Navigation
Launch navigation  
```
roslaunch ironfish_navigation move_base.launch
```
#### High level application
Launch steering, navigation and gmapping integration in sim(or real) world  
```
roslaunch ironfish_navigation ironfish_nav_gmapping.launch
(roslaunch ironfish_navigation ironfish_nav_gmapping.launch env:=1)
```
Launch steering, navigation and amcl integration in sim(or real) world  
```
roslaunch ironfish_navigation ironfish_nav_amcl.launch
(roslaunch ironfish_navigation ironfish_nav_amcl.launch env:=1)
```
#### Tools
Launch rviz gui
```
rviz
rosrun rviz rviz -d <config_file_name>
```
Launch control panel  
```
rosrun rqt_robot_steering rqt_robot_steering
```
Tuning config online  
```
rosrun rqt_reconfigure rqt_reconfigure
```
Cropping map after using map saver saves it  
```
cd ./ironfish_navigation/script
python crop_map.py <YOUR_MAP.yaml>
```
Analyzing nodes and topics relationship  
```
rosrun rqt_graph rqt_graph
```
<img src="https://github.com/shannon112/IronFish/blob/master/rqt_graph(debug off).png" width="800">
<img src="https://github.com/shannon112/IronFish/blob/master/rqt_graph.png" width="800">

Analyzing tf relationship
```
rosrun rqt_tf_tree rqt_tf_tree
```
<img src="https://github.com/shannon112/IronFish/blob/master/rqt_tf_tree.png" width="800">
