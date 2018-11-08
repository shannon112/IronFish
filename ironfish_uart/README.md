# ironfish_uart
This package is for
Built as a library package. There is no launch files or nodes in it.

### Dependencies
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>serial</build_depend>
  <build_depend>boost</build_depend>

  <run_depend>roscpp</run_depend>
  <run_depend>serial</run_depend>
  <run_depend>boost</run_depend>
```
```
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ironfish_uart
  CATKIN_DEPENDS roscpp
  DEPENDS serial Boost
)
```
Install serial (C++ library)
```
https://github.com/shannon112/libserial-0.6.0rc2.git
```
Install boost (C++ library)
Already built-in or
```
sudo apt-get install libboost-all-dev
```

