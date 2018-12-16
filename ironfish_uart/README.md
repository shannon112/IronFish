# ironfish_uart
This is a ros package for helping ironfish_ros_control to communicate with the robot in real world.  
It is built as a library package. There is no launch files or ros nodes in it.  

### Dependencies
* Install serial (C++ library)
```
Go reading
https://github.com/shannon112/libserial-0.6.0rc2/blob/master/README.md
```
* Install boost (C++ library)
```
Already built-in or
sudo apt-get install libboost-all-dev
```
# Getting more info if you are interested in this package
### Dependencies reference
At package.xml
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>serial</build_depend>
  <build_depend>boost</build_depend>

  <run_depend>roscpp</run_depend>
  <run_depend>serial</run_depend>
  <run_depend>boost</run_depend>
```
At CMakeLists.txt
```
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ironfish_uart
  CATKIN_DEPENDS roscpp
)
```

### Builts
A library "ironfish_uart".
```
add_library(ironfish_uart
  src/ironfish_uart.cpp)
target_link_libraries(ironfish_uart
  serial
  ${catkin_LIBRARIES})
```

### Catkin message
catkin_make messages
```
Scanning dependencies of target ironfish_uart
[ 89%] Building CXX object IronFish/ironfish_uart/CMakeFiles/ironfish.dir/src/ironfish_uart.cpp.o
[ 91%] Linking CXX shared library /home/shannon/Documents/ros-kinetic/devel/lib/libironfish_uart.so
[ 91%] Built target ironfish_uart
Scanning dependencies of target ironfish
```
location of products
```
~/Documents/ros-kinetic/build/IronFish/ironfish_uart/CMakeFiles/ironfish_uart.dir/src/ironfish_uart.cpp.o*
~/Documents/ros-kinetic/devel/lib/libironfish_uart.so*
```
