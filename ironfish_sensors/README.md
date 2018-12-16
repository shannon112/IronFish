# ironfish_gazebo
This is a ros package for launching the driver of ironfish sensors in real world.  

### Dependencies
Install urg_node: http://wiki.ros.org/urg_node
```
sudo apt install ros-kinetic-urg-node
```

# Getting more info if you are interested in this package
### Dependencies reference
At package.xml
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>urg_node</build_depend>

  <run_depend>urg_node</run_depend>
```
At CMakeLists.txt
```
  find_package(catkin REQUIRED urg_node)
  catkin_package(CATKIN_DEPENDS urg_node)
```

### Builts
There is nothing be built.
