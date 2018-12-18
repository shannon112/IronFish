### Gazebo model of iCeiRA lab
**credit to https://github.com/willie5588912/iceira_gazebo**
#### Without furniture
```
roslaunch iceira_gazebo iceira_all_raw.launch
```
![iCeiRA](images/iceira_raw.png)

#### With furniture
Clone gazebo models
```
cd /tmp
git clone https://github.com/willie5588912/gazebo_models.git
mv gazebo_models/* ~/.gazebo/models
```
```
roslaunch iceira_gazebo iceira_all_furniture.launch
```
![iCeiRA](images/iceira_furniture.png)
