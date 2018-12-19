# ironfish_gazebo
This is a ros package for launching ironfish gazebo simulation(including control and sense). 

### Dependencies
Install gazebo-ros-control:
http://wiki.ros.org/gazebo_ros_control
```
sudo apt install ros-kinetic-gazebo-ros-control
```

# Getting more info if you are interested in this package
### Dependencies reference
At package.xml
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>gazebo-ros-control</build_depend>
  <run_depend>gazebo-ros-control</run_depend>
```
At CMakeLists.txt
```
  find_package(catkin REQUIRED gazebo_ros_control)
  catkin_package(CATKIN_DEPENDS gazebo_ros_control)
```

### Builts
There is nothing be built.

### Trouble shooting
If you got the msg below:
[WARN]Controller spawner couldn’t find the expected controller_manager ros interface
you definitely have not installed gazebo-ros-control yet.
```
sudo apt install ros-kinetic-gazebo-ros-control
```
