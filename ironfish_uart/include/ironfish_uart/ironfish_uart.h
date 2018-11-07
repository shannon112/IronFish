#ifndef RSC_CAR_UART_H
#define RSC_CAR_UART_H

#include <sstream>
#include <string>
#include <SerialStream.h>

using namespace LibSerial ;    

class SerialHandle
{
	public:
		SerialHandle();
		~SerialHandle();
		void set_port(const char* const);
		void set_baudRate(int);
		void set_dataBits(int);
		void set_stopBit(int);
		void set_parity(bool);
		void set_hardwareFlowControl(bool);
		void writeData(std::string p_data);
		std::string readData();

		
	private:
  	SerialStream serial_port_;
		int baud_rate_;
		int data_bits_;
		int stop_bit_;
		bool flow_control_;
};

#endif
