#include "ironfish_ros_control/hardware_transmission_interface.h"
#include <sstream>
#include <stdlib.h>
#include <ros/ros.h>

#define PI 3.1415926
#define G_GEAR_RATIO_R 43
#define G_GEAR_RATIO_L 43
#define ENC_FULL 2048 // This is for RSC small car

HwTmIntf::HwTmIntf(
  std::vector<std::string> jnt_names,
  int update_freq)
  : update_freq_(update_freq)
{
  jnt_names_ = jnt_names;

  // Initialize Gear Ratios
  //for(size_t i = 0; i < 2; i++)
  tm_data_.trans_.emplace_back(G_GEAR_RATIO_R, 0.0);
  tm_data_.trans_.emplace_back(G_GEAR_RATIO_L, 0.0);

  // Initialize hardware data
  hw_data_init_();

  // Initialize transmission data
  tm_data_init_();

  // Register hardware data
  hw_register_();

  // Wrap transmission data
  tm_wrap_();

  // Register transmission data
  tm_register_();

  // Initialize serial port
  ironfish_port.set_port("/dev/ttyUSB0");
  ironfish_port.set_baudRate(9600);
  ironfish_port.set_dataBits(8);
  ironfish_port.set_stopBit(1);
  ironfish_port.set_parity(false);
  ironfish_port.set_hardwareFlowControl(false);
}


HwTmIntf::~HwTmIntf()
{}


void HwTmIntf::update()
{
  static std::stringstream ss_cmd_vel_;
  static std::stringstream ss_curr_vel_;
  static bool init = true;
  if(init)
  {
    ironfish_port.writeData("en\r");
    ironfish_port.writeData("en\r");
    ironfish_port.writeData("en\r");
    ironfish_port.writeData("en\r");
    ironfish_port.writeData("en\r");

    init = false;
  }

  tm_data_.act_to_jnt_state_.propagate();
  tm_data_.jnt_to_act_state_.propagate();

#if 1
  std::cout << "Write : " << std::endl;
  std::cout << "1v" << hw_data_.act_cmd_vel_[0] * (30 / PI)<< " rpm" << std::endl;
  std::cout << "2v" << hw_data_.act_cmd_vel_[1] * (30 / PI)<< " rpm" << std::endl;
  std::cout << "=======================================\n" << std::endl;
#endif

  // Write data to motors
  ss_cmd_vel_.str("");
  ss_cmd_vel_ << "1v" <<  (hw_data_.act_cmd_vel_[0] * (30 / PI)) << "\r"; // Right wheel (node 1)
  ironfish_port.writeData(ss_cmd_vel_.str());

  ss_cmd_vel_.str("");
  ss_cmd_vel_ << "2v" << -(hw_data_.act_cmd_vel_[1] * (30 / PI)) << "\r"; // Left wheel (node 2)
  ironfish_port.writeData(ss_cmd_vel_.str());

  // Read data from motors
  ss_curr_vel_.str("");
  ss_curr_vel_ << 1 << "pos\r"; // Right wheel (node 1)
  ironfish_port.writeData(ss_curr_vel_.str());
  hw_data_.act_curr_pos_[0] = ((float)atoi((ironfish_port.readData()).c_str()) / ENC_FULL) * (2 * PI);


  ss_curr_vel_.str("");
  ss_curr_vel_ << 2 << "pos\r"; // Left wheel (node 2)
  ironfish_port.writeData(ss_curr_vel_.str());
  hw_data_.act_curr_pos_[1] = -((float)atoi((ironfish_port.readData()).c_str()) / ENC_FULL) * (2 * PI);

#if 0
  std::cout << "Read rwheel position: " << hw_data_.act_curr_pos_[0] << " rad" << std::endl;
  std::cout << "Read lwheel position: " << hw_data_.act_curr_pos_[1] << " rad" << std::endl;
  std::cout << "=======================================\n" << std::endl;
#endif

}


ros::Time HwTmIntf::get_time() const
{
  return ros::Time::now();
}


ros::Duration HwTmIntf::get_period() const
{
  return ros::Duration(1.0 / update_freq_);
}
