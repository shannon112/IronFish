#include "ros/ros.h"
#include "std_msgs/String.h"
#include "rosgraph_msgs/Log.h"


void my_callback(const rosgraph_msgs::Log& msg)
{
    //ROS_WARN("TebLocalPlannerROS: trajectory is not feasible. Resetting local costmap...");
    ROS_INFO("I heard:　%s\n", msg.msg.c_str());
}


int main(int argc, char **argv)
{
    //Node initialization
    ros::init(argc, argv, "reset_costmap_node");
    ros::NodeHandle nh;

    //Subscriber topic
    ros::Subscriber my_sub = nh.subscribe("rosout_agg",1000,my_callback);

    //Receive Callback
    ros::spin();
}
