# ironfish_ros_control
This package is for \<usage\>\<meaning\>  
This package is built as a library package but also a executable package.(one launch file and one executable file)  
* /config is param which could be import(rosparam) by ironfish_ros_control.launch and ironfish_gazebo.launch

### Dependencies
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>controller_manager</build_depend>
  <build_depend>hardware_interface</build_depend>
  <build_depend>ironfish_uart</build_depend>

  <run_depend>roscpp</run_depend>
  <run_depend>controller_manager</run_depend>
  <run_depend>hardware_interface</run_depend>
  <run_depend>ironfish_uart</run_depend>
```
```
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp controller_manager hardware_interface 
)
```
You need to install ros_control which including:   
combined_robot_hw | combined_robot_hw_tests | controller_interface | controller_manager | controller_manager_msgs | controller_manager_tests | hardware_interface | joint_limits_interface | realtime_tools | transmission_interface
```
sudo apt-get install ros-kinetic-ros-control ros-kinetic-ros-controllers
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
