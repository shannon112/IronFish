# ironfish_install
Put those files to your /opt/ros/kinetic/ workspace then  
```
sudo ldconfig
source /opt/ros/kinetic/setup.bash
source <YOUR_PATH_TO>/devel/setup.bash
```
Then, you can use IronFish without src code!

## Usage
Launch control node (with gui control panel)
```
roslaunch ironfish_ros_control ironfish_ros_control.launch
(roslaunch ironfish_ros_control ironfish_ros_control.launch rqt_steering:=1)
```
Launch control panel
```
rosrun rqt_robot_steering rqt_robot_steering
```
Launch rviz
```
roslaunch ironfish_description ironfish_rviz.launch
```
Launch gazebo
```
roslaunch ironfish_description ironfish_gazebo.launch
```

## Record
After catkin_make -DCMAKE_INSTALL_PREFIX=/opt/ros/<distro> install
```
shannon2@shannon2:/opt/ros/kinetic$ find . -type f -mtime -7 -exec ls -l {} \;
-rw-r--r-- 1 root root 32672 Nov 12 23:07 ./lib/libironfish_uart.so
-rw-r--r-- 1 root root 860832 Nov 13 02:11 ./lib/libironfish.so
-rwxr-xr-x 1 root root 307928 Nov 13 02:11 ./lib/ironfish_ros_control/ironfish_ros_control
-rw-r--r-- 1 root root 199 Nov 13 02:15 ./lib/pkgconfig/ironfish_uart.pc
-rw-r--r-- 1 root root 166 Nov 13 02:15 ./lib/pkgconfig/ironfish_description.pc
-rw-r--r-- 1 root root 318 Nov 13 02:15 ./lib/pkgconfig/ironfish_ros_control.pc
-rwxr-xr-x 1 root root 506 Nov 12 23:05 ./env.sh
-rw-r--r-- 1 root root 260 Nov 12 23:05 ./setup.bash
-rw-r--r-- 1 root root 270 Nov 12 23:05 ./setup.zsh
-rw-r--r-- 1 root root 581 Nov 12 23:06 ./include/ironfish_uart/ironfish_uart.h
-rw-r--r-- 1 root root 56 Nov 13 02:15 ./.rosinstall
-rwxr-xr-x 1 root root 12410 Nov 13 02:15 ./_setup_util.py
-rw-r--r-- 1 root root 2704 Nov 13 02:15 ./setup.sh
-rw-r--r-- 1 root root 426 Nov 12 23:07 ./share/ironfish_uart/cmake/ironfish_uartConfig-version.cmake
-rw-r--r-- 1 root root 7902 Nov 13 02:15 ./share/ironfish_uart/cmake/ironfish_uartConfig.cmake
-rw-r--r-- 1 root root 2128 Nov 12 23:06 ./share/ironfish_uart/package.xml
-rw-r--r-- 1 root root 787 Nov 12 23:06 ./share/ironfish_description/robots/ironfish_materials.xacro
-rw-r--r-- 1 root root 5946 Nov 12 23:06 ./share/ironfish_description/robots/ironfish.urdf
-rw-r--r-- 1 root root 1790 Nov 12 23:06 ./share/ironfish_description/robots/ironfish.gazebo
-rw-r--r-- 1 root root 5476 Nov 12 23:06 ./share/ironfish_description/rviz/ironfish_rviz.rviz
-rw-r--r-- 1 root root 81884 Nov 12 23:06 ./share/ironfish_description/meshes/rwheel_link.STL
-rw-r--r-- 1 root root 684 Nov 12 23:06 ./share/ironfish_description/meshes/hokuyo_link.STL
-rw-r--r-- 1 root root 81884 Nov 12 23:06 ./share/ironfish_description/meshes/lwheel_link.STL
-rw-r--r-- 1 root root 894784 Nov 12 23:06 ./share/ironfish_description/meshes/base_link.STL
-rw-r--r-- 1 root root 524 Nov 12 23:06 ./share/ironfish_description/launch/ironfish_rviz.launch
-rw-r--r-- 1 root root 1630 Nov 12 23:06 ./share/ironfish_description/launch/ironfish_gazebo.launch
-rw-r--r-- 1 root root 426 Nov 12 23:07 ./share/ironfish_description/cmake/ironfish_descriptionConfig-version.cmake
-rw-r--r-- 1 root root 8191 Nov 13 02:15 ./share/ironfish_description/cmake/ironfish_descriptionConfig.cmake
-rw-r--r-- 1 root root 47371 Nov 12 23:06 ./share/ironfish_description/world/ironfish_room.world
-rw-r--r-- 1 root root 1934 Nov 12 23:06 ./share/ironfish_description/package.xml
-rw-r--r-- 1 root root 1439 Nov 12 23:06 ./share/ironfish_ros_control/launch/ironfish_ros_control.launch
-rw-r--r-- 1 root root 12288 Nov 12 23:06 ./share/ironfish_ros_control/launch/.ironfish_ros_control.launch.swp
-rw-r--r-- 1 root root 426 Nov 12 23:07 ./share/ironfish_ros_control/cmake/ironfish_ros_controlConfig-version.cmake
-rw-r--r-- 1 root root 8328 Nov 13 02:15 ./share/ironfish_ros_control/cmake/ironfish_ros_controlConfig.cmake
-rw-r--r-- 1 root root 1667 Nov 12 23:06 ./share/ironfish_ros_control/config/ironfish_ros_control_real.yaml
-rw-r--r-- 1 root root 1667 Nov 12 23:06 ./share/ironfish_ros_control/config/ironfish_ros_control_sim.yaml
-rw-r--r-- 1 root root 2592 Nov 13 01:59 ./share/ironfish_ros_control/package.xml
```
classify
```
/share/ironfish_ros_control/
/share/ironfish_description/
/share/ironfish_uart/

/include/ironfish_uart/

/lib/ironfish_ros_control/
/lib/libironfish.so
/lib/libironfish_uart.so
/lib/pkgconfig/ironfish_ros_control.pc
/lib/pkgconfig/ironfish_uart.pc
/lib/pkgconfig/ironfish_description.pc

/env.sh
/setup.bash
/setup.zsh
/setup.sh
/_setup_util.py
/.rosinstall
```
