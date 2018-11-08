# Ironfish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple ROS mobile robot that you can simply build it by yourself!  
* Processor: Your laptop
* Sensor: Kinect, RealSense, Hokuyo lazer
* Actuator: Two DC motor with two wheels, and one guide wheel.
 

## Guidance
There are 3 pkg 1 doc folder in Ironfish repo. 
* ironfish_description: This package is for <usage><meaning>
* ironfish_ros_control: This package is for <usage><meaning>
* ironfish_uart: This package is for <usage><meaning>
* ironfish_hardware: This folder is for <usage><meaning>

## Usage
In real world
```
roslaunch rsc_car_ros_control rsc_car_ros_control.launch
```
4 nodes would be launched
```
  <!--Spawn Controller-->
  <node name="diff_controller_spawner" pkg="controller_manager" type="spawner"
    args="penguin_joint_state_controller
          penguin_diff_drive_controller"/>

  <!--Main control node-->
  <node name="penguin_ros_control" pkg="penguin_ros_control" type="penguin_ros_control"
    output="log" respawn="true" respawn_delay="3"/>

  <!--Publish robot state-->
  <node name="robot_state_publisher" pkg="robot_state_publisher" type="robot_state_publisher"
    respawn="false" output="screen">
  </node>

  <!--Gui steering console (Optional)-->
  <group if="$(arg rqt_steering)">
    <node name="rqt_robot_steering" pkg="rqt_robot_steering" type="rqt_robot_steering">
      <param name="default_topic" value="penguin_diff_drive_controller/cmd_vel"/>
      <!--param name="default_vx_max" value="0.3"/-->
      <!--param name="default_vx_min" value="-0.25"/-->
    </node>
  </group>
```
