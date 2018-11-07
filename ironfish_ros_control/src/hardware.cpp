#include "ironfish_ros_control/hardware_transmission_interface.h"

void HwTmIntf::hw_data_init_()
{
  hw_data_.jnt_curr_pos_.clear();
  hw_data_.jnt_curr_vel_.clear();
  hw_data_.jnt_curr_eff_.clear();

  hw_data_.jnt_cmd_pos_.clear();
  hw_data_.jnt_cmd_vel_.clear();
  hw_data_.jnt_cmd_eff_.clear();

  hw_data_.act_curr_pos_.clear();
  hw_data_.act_curr_vel_.clear();
  hw_data_.act_curr_eff_.clear();

  hw_data_.act_cmd_pos_.clear();
  hw_data_.act_cmd_vel_.clear();
  hw_data_.act_cmd_eff_.clear();


  hw_data_.jnt_curr_pos_.resize(2);
  hw_data_.jnt_curr_vel_.resize(2);
  hw_data_.jnt_curr_eff_.resize(2);

  hw_data_.jnt_cmd_pos_.resize(2);
  hw_data_.jnt_cmd_vel_.resize(2);
  hw_data_.jnt_cmd_eff_.resize(2);

  hw_data_.act_curr_pos_.resize(2);
  hw_data_.act_curr_vel_.resize(2);
  hw_data_.act_curr_eff_.resize(2);

  hw_data_.act_cmd_pos_.resize(2);
  hw_data_.act_cmd_vel_.resize(2);
  hw_data_.act_cmd_eff_.resize(2);
}

void HwTmIntf::hw_register_()
{
  for(size_t i = 0; i < 2; i++)
  {
    hw_data_.jnt_state_interface_.registerHandle(
      hardware_interface::JointStateHandle(
        jnt_names_[i], 
        &hw_data_.jnt_curr_pos_[i],
        &hw_data_.jnt_curr_vel_[i],
        &hw_data_.jnt_curr_eff_[i]));

    hw_data_.jnt_vel_interface_.registerHandle(
      hardware_interface::JointHandle(
        hw_data_.jnt_state_interface_.getHandle(jnt_names_[i]), 
        &hw_data_.jnt_cmd_vel_[i]));

#if 0
    hw_data_.jnt_pos_interface_.registerHandle(
      hardware_interface::JointHandle(
        hw_data_.jnt_state_interface_.getHandle(jnt_names_[i]), 
        &hw_data_.jnt_cmd_pos_[i]));
#endif

  }
  
  registerInterface(&hw_data_.jnt_state_interface_);
  registerInterface(&hw_data_.jnt_vel_interface_);
  //registerInterface(&hw_data_.jnt_pos_interface_);
}

