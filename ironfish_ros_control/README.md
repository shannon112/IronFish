# ironfish_ros_control
This package is for
A main launch file is in it.

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

### Builts
A library calls ironfish.
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

A executable file calls ironfish_ros_control.(Would be used by launch file)
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

### After catkin_make
```
[ 91%] Linking CXX shared library /home/shannon/Documents/ros-kinetic/devel/lib/libironfish_uart.so
[ 91%] Built target ironfish_uart
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
