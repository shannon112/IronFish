# ironfish_description
This package is for ironfish gazebo/rviz ros launch files.

### Structure
├── CMakeLists.txt
├── launch                      //It contains launch files
│   ├── ironfish_gazebo.launch   //It would open rviz, rqt, gazebo at once
│   └── ironfish_rviz.launch
├── meshes                      //It contains solidwork robot model component
│   ├── base_link.STL
│   ├── hokuyo_link.STL
│   ├── lwheel_link.STL
│   └── rwheel_link.STL
├── package.xml
├── README.md
├── robots
│   ├── ironfish.gazebo
│   ├── ironfish_materials.xacro
│   └── ironfish.urdf
├── rviz                      //It contains rviz config file
│   └── ironfish_rviz.rviz
└── world                     //It contains gazebo world
    └── ironfish_room.world

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
