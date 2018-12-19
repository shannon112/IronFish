# ironfish_gazebo
This is a ros package for launching the driver of ironfish sensors in real world.  

### Dependencies
Install urg_node: http://wiki.ros.org/urg_node
```
sudo apt install ros-kinetic-urg-node
```
Install openni:http://wiki.ros.org/openni_launch
```
Please go through https://www.evernote.com/l/ATvjQg_dJ0JOSIujndgTWSIuqhwF1vAzPVQ
```
Install intelrealsense realsense2_camera: https://github.com/intel-ros/realsense
```
Please read https://www.evernote.com/shard/s315/sh/2b688e7a-322b-4d87-9180-97405ff2e37a/805ffb34a97606c1b0838a7750205e19
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
