# ironfish_navigation
<img src="https://github.com/shannon112/IronFish/blob/master/ironfish_navigation/slam.png" width="200"> <img src="https://github.com/shannon112/IronFish/blob/master/ironfish_navigation/navigation.png" width="200">   
This is a ros package for launching ironfish high level application in real/sim world -- navigation and slam. 

### Dependencies
- Install openslam_gmapping:
http://wiki.ros.org/openslam_gmapping
```
sudo apt install ros-kinetic-openslam-gmapping
sudo apt install ros-kinetic-slam-gmapping
```
- Install move_base which including:  
amcl | base_local_planner | carrot_planner | clear_costmap_recovery | costmap_2d | **dwa_local_planner** | 
fake_localization | global_planner | map_server | **move_base** | move_base_msgs | move_slow_and_clear | nav_core | navfn | 
rotate_recovery | voxel_grid  
http://wiki.ros.org/move_base
```
sudo apt install ros-kinetic-navigation
```
- Install teb_local_planner:
http://wiki.ros.org/teb_local_planner
```
sudo apt install ros-kinetic-teb-local-planner
```

# Getting more info if you are interested in this package
### Dependencies reference
At package.xml
```
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>openslam_gmapping</build_depend>
  <build_depend>move_base</build_depend>
  <build_depend>dwa_local_planner</build_depend>
  <run_depend>openslam_gmapping</run_depend>
  <run_depend>move_base</run_depend>
  <run_depend>dwa_local_planner</run_depend>
```
At CMakeLists.txt
```
  find_package(catkin REQUIRED openslam_gmapping move_base dwa_local_planner)
  catkin_package(
     CATKIN_DEPENDS openslam_gmapping move_base dwa_local_planner
  )
```

### Builts
There is nothing be built.
