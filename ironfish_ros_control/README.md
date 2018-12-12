# ironfish_ros_control
This is a ros package for launching the control of robot in real world.  
It is built as a library package but also a executable package.(one launch file and one executable file)  

### Dependencies
* Install ros_control which including:   
combined_robot_hw | combined_robot_hw_tests | controller_interface | **controller_manager** | controller_manager_msgs | controller_manager_tests | **hardware_interface** | joint_limits_interface | realtime_tools | **transmission_interface**
```
sudo apt-get install ros-kinetic-ros-control
```
* Install ros_controllers which including:   
ackermann_steering_controller | **diff_drive_controller** | effort_controllers | force_torque_sensor_controller | forward_command_controller | gripper_action_controller | imu_sensor_controller | **joint_state_controller** | joint_trajectory_controller | position_controllers | rqt_joint_trajectory_controller | velocity_controllers
```
sudo apt-get install ros-kinetic-ros-controllers
```
* Install rqt_robot_plugins which including:   
rqt_moveit | rqt_nav_view | rqt_pose_view | rqt_robot_dashboard | rqt_robot_monitor | **rqt_robot_steering** | rqt_runtime_monitor | rqt_rviz | **rqt_tf_tree**
```
sudo apt install ros-kinetic-rqt-robot-plugins
```

### Dependencies Reference
At package.xml
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>controller_manager</build_depend>
  <build_depend>hardware_interface</build_depend>
  <build_depend>ironfish_uart</build_depend>
  <build_depend>joint_state_controller</build_depend>
  <build_depend>diff_drive_controller</build_depend>
  <build_depend>transmission_interface</build_depend>

  <run_depend>roscpp</run_depend>
  <run_depend>controller_manager</run_depend>
  <run_depend>hardware_interface</run_depend>
  <run_depend>ironfish_uart</run_depend>
  <run_depend>transmission_interface</run_depend>
  <run_depend>diff_drive_controller</run_depend>
  <run_depend>joint_state_controller</run_depend>

```
At CMakeLists.txt
```
find_package(catkin REQUIRED COMPONENTS
  roscpp
  controller_manager
  hardware_interface
  transmission_interface
  diff_drive_controller
  joint_state_controller
  ironfish_uart
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp
                 controller_manager
                 hardware_interface
                 transmission_interface
                 diff_drive_controller
                 joint_state_controller
                 ironfish_uart 
)

```

### Builts
A library "ironfish".
```
add_library(ironfish
  src/hardware.cpp
  src/transmission.cpp
  src/hardware_transmission_interface.cpp
)
target_link_libraries(ironfish
  ${catkin_LIBRARIES}
  ${Boost_LIBRARIES}
)
```

A executable file "ironfish_ros_control".(Would be used by launch file)
```
add_executable(ironfish_ros_control
  src/ironfish_ros_control.cpp
)
target_link_libraries(ironfish_ros_control
  ironfish
  ${catkin_LIBRARIES}
  ${Boost_LIBRARIES}
)

```

### Catkin message
catkin_make messages
```
Scanning dependencies of target ironfish
[ 92%] Building CXX object IronFish/ironfish_ros_control/CMakeFiles/ironfish.dir/src/hardware.cpp.o
[ 94%] Building CXX object IronFish/ironfish_ros_control/CMakeFiles/ironfish.dir/src/transmission.cpp.o
[ 95%] Building CXX object IronFish/ironfish_ros_control/CMakeFiles/ironfish.dir/src/hardware_transmission_interface.cpp.o
[ 97%] Linking CXX shared library /home/shannon/Documents/ros-kinetic/devel/lib/libironfish.so
[ 97%] Built target ironfish
Scanning dependencies of target ironfish_ros_control
[ 98%] Building CXX object IronFish/ironfish_ros_control/CMakeFiles/ironfish_ros_control.dir/src/ironfish_ros_control.cpp.o
[100%] Linking CXX executable /home/shannon/Documents/ros-kinetic/devel/lib/ironfish_ros_control/ironfish_ros_control
[100%] Built target ironfish_ros_control
```
location of products (ironfish_ros_control)
```
~/Documents/ros-kinetic/build/IronFish/ironfish_ros_control/CMakeFiles/ironfish_ros_control.dir/src/ironfish_ros_control.cpp.o*
~/Documents/ros-kinetic/devel/lib/ironfish_ros_control/ironfish_ros_control*
```
location of products (ironfish)
```
~/Documents/ros-kinetic/build/IronFish/ironfish_ros_control/CMakeFiles/ironfish.dir/src/
hardware.cpp.o  hardware_transmission_interface.cpp.o  transmission.cpp.o
~/Documents/ros-kinetic/devel/lib/libironfish.so*
```
