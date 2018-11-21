# ironfish_description
This package is for ironfish gazebo/rviz ros launch files.
* rviz/gazebo launch files at /launch
* rviz config file at rviz/ironfish_rviz.rviz
* gazebo world at world/ironfish_room.world
* gazebo robot model at robot/
* solidwork 3d model at meshes/

### Dependencies
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>gazebo-ros-control</build_depend>
  <run_depend>gazebo-ros-control</run_depend>
```
```
  find_package(catkin REQUIRED gazebo-ros-control)
```
Install gazebo-ros-control:
http://wiki.ros.org/gazebo_ros_control
```
sudo apt install ros-kinetic-gazebo-ros-control
```

### Builts
There is nothing be built.

### Catkin message
No

### trouble shooting
if you got the msg below:
[WARN]Controller spawner couldn’t find the expected controller_manager ros interface
you definitely have not installed gazebo-ros-control yet.
```
sudo apt install ros-kinetic-gazebo-ros-control
```
