#include <iostream>
#include <sstream>
#include <ros/ros.h>
#include <iomanip>
#include "ironfish_uart/ironfish_uart.h"


using namespace LibSerial ;    

//open the serial port
SerialHandle::SerialHandle()
{
}

SerialHandle::~SerialHandle()
{
    serial_port_.Close();
}

void SerialHandle::set_port(const char* const port_name)
{
  serial_port_.Open(port_name);
  if (!serial_port_.good()) 
    ROS_ERROR("Could not open serial port %s", port_name);
}

//set baud rate
void SerialHandle::set_baudRate(int baud_rate)
{
	if(baud_rate == 9600)
	{
		serial_port_.SetBaudRate(SerialStreamBuf::BAUD_9600);
		if (!serial_port_.good()) 
      ROS_ERROR("Error: Could not set the baud rate %d", baud_rate);
	}
	else
		ROS_ERROR("Please set baud rate 9600 in cpp.");
}

//set the num of data bits
void SerialHandle::set_dataBits(int data_bits)
{
	if(data_bits == 8)
	{
		serial_port_.SetCharSize(SerialStreamBuf::CHAR_SIZE_8) ;
		if (!serial_port_.good()) 
      ROS_ERROR("Could not set data bits %d", data_bits);
	}
	else
		ROS_ERROR("Please set data bits 8");
}

//set stop bit
void SerialHandle::set_stopBit(int stop_bit)
{
	serial_port_.SetNumOfStopBits(stop_bit) ;
  if(stop_bit == 1)
  {
    if(!serial_port_.good()) 
      ROS_ERROR("Could not set stop bit %d", stop_bit);
  }
  else
    ROS_ERROR("Please set stop bit 1");

}

//set parity
void SerialHandle::set_parity(bool parity)
{
	//disable parity
	if(!parity)
	{
		serial_port_.SetParity( SerialStreamBuf::PARITY_NONE);
		if (!serial_port_.good()) 
      ROS_ERROR("Could not disable the parity.");
  }
	else
		ROS_ERROR("Please disable the parity.");
}

//set hardware flow control
void SerialHandle::set_hardwareFlowControl(bool control)
{
	//disable hardware flow control
	if(!control)
	{
		serial_port_.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
		if (!serial_port_.good()) 
      ROS_ERROR("Could not disable hardware flow control.");
	}
	else
		ROS_ERROR("Please disable hardware flow contorl.");
}

void SerialHandle::writeData(std::string p_data)
{
	serial_port_ << p_data << std::endl ;
}

std::string SerialHandle::readData()
{
  char next_byte;
	std::stringstream ss_enc;
	ss_enc.str("");
  while(ros::ok()) 
  {
    serial_port_.get(next_byte);
    if(next_byte == '\r')
      break;
    else
        ss_enc << next_byte;
  } 

	return ss_enc.str();
}
