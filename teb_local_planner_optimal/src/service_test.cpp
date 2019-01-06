#include "ros/ros.h"
#include "std_srvs/Empty.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_test");
  ros::NodeHandle n;

  /*method1
  ros::ServiceClient clear_map_client;
  clear_map_client=n.serviceClient<std_srvs::Empty>("move_base/clear_costmaps");
  std_srvs::Empty srv;
  if (clear_map_client.call(srv))
  {
    ROS_INFO("Success!");
  }
  else
  {
    ROS_ERROR("Failed to call service");
  }*/

  /*method2*/
  std_srvs::Empty srv;
  ros::service::call("/move_base/clear_costmaps",srv);

}
