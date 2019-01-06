#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"
#include "rosgraph_msgs/Log.h"

ros::Time time_last_call_service;
std_srvs::Empty srv;
double reset_gap_ros_time=2.0;

void my_callback(const std_msgs::String& msg)
{
    ros::Time current_time = ros::Time::now();
    if ((current_time - time_last_call_service).toSec() < reset_gap_ros_time){
      time_last_call_service = time_last_call_service;
    }else if ((current_time-time_last_call_service).toSec() >= reset_gap_ros_time){
      ros::service::call("/move_base/clear_costmaps",srv);
      ROS_INFO("%s\n", msg.data.c_str());
      time_last_call_service = ros::Time::now();
    }
}


int main(int argc, char **argv)
{
    //Node initialization
    ros::init(argc, argv, "reset_costmap_node");
    ros::NodeHandle nh;
    time_last_call_service=ros::Time::now();//initialize

    ros::Subscriber my_sub = nh.subscribe("/move_base/TebLocalPlannerROS/not_feasible",1000,my_callback);
    ros::spin();
}
