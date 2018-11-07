#ifndef TRANSMISSION_DATA
#define TRANSMISSION_DATA

#include <vector>
#include <transmission_interface/transmission_interface.h>
#include <transmission_interface/simple_transmission.h>

struct TmData
{
  transmission_interface::JointToActuatorStateInterface jnt_to_act_state_;
  transmission_interface::ActuatorToJointStateInterface act_to_jnt_state_;

  std::vector<transmission_interface::JointData> jnt_state_data_;
  std::vector<transmission_interface::JointData> jnt_cmd_data_;

  std::vector<transmission_interface::ActuatorData> act_state_data_;
  std::vector<transmission_interface::ActuatorData> act_cmd_data_;

  std::vector<transmission_interface::SimpleTransmission> trans_;
};
#endif

