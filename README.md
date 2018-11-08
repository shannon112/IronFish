# Ironfish
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish.png" width="350">

Ironfish is a simple mobile robot that you can simply build it by yourself!  
* Sensor: Kinect, RealSense, Hokuyo lazer
* Processor: Your laptop
* Actuator: Two DC motor with two wheels, and one guide wheel.
 

### Introduction
There are 4 pkg 1 launch file (4 nodes would be launched)


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


dependence:
_uart: serial 
https://github.com/shannon112/libserial-0.6.0rc2.git
_uart: boost
built-in or
sudo apt-get install libboost-all-dev



