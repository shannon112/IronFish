#include "ironfish_ros_control/hardware_transmission_interface.h"
#include <sstream> 

void HwTmIntf::tm_data_init_()
{
  tm_data_.jnt_state_data_.clear();
  tm_data_.jnt_cmd_data_.clear();

  tm_data_.act_state_data_.clear();
  tm_data_.act_cmd_data_.clear();


  tm_data_.jnt_state_data_.resize(2);
  tm_data_.jnt_cmd_data_.resize(2);

  tm_data_.act_state_data_.resize(2);
  tm_data_.act_cmd_data_.resize(2);
}


void HwTmIntf::tm_register_()
{
  for(size_t i = 0; i < 2; i++)
  {
    std::stringstream ss_temp("");
    ss_temp << "trans" << i;

    tm_data_.jnt_to_act_state_.registerHandle(
      transmission_interface::JointToActuatorStateHandle(
        ss_temp.str(),
        &tm_data_.trans_[i],
        tm_data_.act_cmd_data_[i],
        tm_data_.jnt_cmd_data_[i]));

    tm_data_.act_to_jnt_state_.registerHandle(
      transmission_interface::ActuatorToJointStateHandle(
        ss_temp.str(),
        &tm_data_.trans_[i],
        tm_data_.act_state_data_[i],
        tm_data_.jnt_state_data_[i]));
  }
}

void HwTmIntf::tm_wrap_()
{
  for(size_t i = 0; i < 2; i++) 
  {
    tm_data_.jnt_state_data_[i].position.push_back(&hw_data_.jnt_curr_pos_[i]);
    tm_data_.jnt_state_data_[i].velocity.push_back(&hw_data_.jnt_curr_vel_[i]);
    tm_data_.jnt_state_data_[i].effort.push_back(&hw_data_.jnt_curr_eff_[i]);

    tm_data_.jnt_cmd_data_[i].position.push_back(&hw_data_.jnt_cmd_pos_[i]);
    tm_data_.jnt_cmd_data_[i].velocity.push_back(&hw_data_.jnt_cmd_vel_[i]);
    tm_data_.jnt_cmd_data_[i].effort.push_back(&hw_data_.jnt_cmd_eff_[i]);


    tm_data_.act_state_data_[i].position.push_back(&hw_data_.act_curr_pos_[i]);
    tm_data_.act_state_data_[i].velocity.push_back(&hw_data_.act_curr_vel_[i]);
    tm_data_.act_state_data_[i].effort.push_back(&hw_data_.act_curr_eff_[i]);
    
    tm_data_.act_cmd_data_[i].position.push_back(&hw_data_.act_cmd_pos_[i]);
    tm_data_.act_cmd_data_[i].velocity.push_back(&hw_data_.act_cmd_vel_[i]);
    tm_data_.act_cmd_data_[i].effort.push_back(&hw_data_.act_cmd_eff_[i]);
  }
}
