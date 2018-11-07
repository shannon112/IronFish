#ifndef HARDEARE_TRANSMISSION_INTERFACE
#define HARDEARE_TRANSMISSION_INTERFACE

//source code: src/transmission.cpp src/hardware.cpp src/hardware_transmission_interface.cpp
#include "ironfish_ros_control/hardware_data.h"
#include "ironfish_ros_control/transmission_data.h"
#include "ironfish_uart/ironfish_uart.h"
#include <hardware_interface/robot_hw.h>

class HwTmIntf: public hardware_interface::RobotHW
{
  public:  //src/hardware_transmission_interface.cpp
    HwTmIntf(std::vector<std::string>, int);
    ~HwTmIntf();
    void update();
    ros::Time get_time() const;
    ros::Duration get_period() const;

  private:
    void hw_data_init_(); //src/hardware.cpp
    void tm_data_init_(); //src/transmission.cpp
    void hw_register_(); //src/hardware.cpp
    void tm_register_(); //src/transmission.cpp
    void tm_wrap_();     //src/transmission.cpp
    void read_odom_once_(); 

    HwData hw_data_;
    TmData tm_data_;
    SerialHandle ironfish_port;

    std::vector<std::string> jnt_names_;
    int update_freq_;
};

#endif
