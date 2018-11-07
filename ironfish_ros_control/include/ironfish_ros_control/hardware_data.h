#ifndef HARDWARE_DATA
#define HARDWARE_DATA

#include <vector>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/joint_command_interface.h>

struct HwData
{
  std::vector<double> jnt_curr_pos_;
  std::vector<double> jnt_curr_vel_;
  std::vector<double> jnt_curr_eff_;

  std::vector<double> jnt_cmd_pos_;
  std::vector<double> jnt_cmd_vel_;
  std::vector<double> jnt_cmd_eff_;

  std::vector<double> act_curr_pos_;
  std::vector<double> act_curr_vel_;
  std::vector<double> act_curr_eff_;

  std::vector<double> act_cmd_pos_;
  std::vector<double> act_cmd_vel_;
  std::vector<double> act_cmd_eff_;
 
  hardware_interface::JointStateInterface jnt_state_interface_;
  hardware_interface::VelocityJointInterface jnt_vel_interface_;
};

#endif
