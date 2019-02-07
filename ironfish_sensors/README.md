# ironfish_gazebo
This is a ros package for launching the driver of ironfish sensors in real world.  

### Dependencies
(if you want to use hokuyo lidar) Install urg_node: http://wiki.ros.org/urg_node
```
sudo apt install ros-kinetic-urg-node
```
(if you want to use microsoft kinectv1) Install openni: http://wiki.ros.org/openni_launch
```
Please go through https://www.evernote.com/l/ATvjQg_dJ0JOSIujndgTWSIuqhwF1vAzPVQ
```
(if you want to use intel realsense) Install realsense2_camera: https://github.com/intel-ros/realsense
```
Please read https://www.evernote.com/shard/s315/sh/2b688e7a-322b-4d87-9180-97405ff2e37a/805ffb34a97606c1b0838a7750205e19
```
(if you want to use SparkFun Razor IMU M0) Install razor_imu_9dof: http://wiki.ros.org/razor_imu_9dof
```
Please read https://www.evernote.com/l/ATsbvRpS7nZLiKoklp756MNPt2dNEVbX-9I
```

# Getting more info if you are interested in this package
### Dependencies reference
At package.xml
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>urg_node</build_depend>
  <build_depend>openni_launch</build_depend>
  <build_depend>realsense2_camera</build_depend>
  <build_depend>razor_imu_9dof</build_depend>

  <run_depend>urg_node</run_depend>
  <run_depend>openni_launch</run_depend>
  <run_depend>realsense2_camera</run_depend>
  <run_depend>razor_imu_9dof</run_depend>
```
At CMakeLists.txt
```
  find_package(catkin REQUIRED urg_node openni_launch realsense2_camera razor_imu_9dof)
  catkin_package(CATKIN_DEPENDS urg_node openni_launch realsense2_camera razor_imu_9dof)
```

### Builts
There is nothing be built.
