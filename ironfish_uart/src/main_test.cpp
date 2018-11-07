#include <iostream>
#include <boost/thread/thread.hpp>
#include "penguin_uart/penguin_uart.h"
#include "ros/ros.h"

typedef boost::shared_lock<boost::shared_mutex> readLock;  
typedef boost::unique_lock<boost::shared_mutex> writeLock;
boost::shared_mutex rwmutex; 

int temp[9];

void write_odom(SerialHandle *my_port, int *temp)
{
  //ros::Rate rate(10);
  while(ros::ok())
  {
    //std::cout << "origin: " << int(my_port->readData()) << std::endl;
#if 1
    if(int(my_port->readData()) == -22)
      for(int i = 0; i < 9; i++)
      {
        writeLock wtlock(rwmutex);  
        temp[i] = int(my_port->readData());
        //std::cout << "after: " << temp[i] << std::endl;
      }
#endif
    //rate.sleep();
  }
}

#if 0
void read_odom(SerialHandle *my_port, int *temp)
{

  //ros::Rate rate(10);
  //while(ros::ok())
  {
    readLock rdlock(rwmutex); 
    std::cout << "=====" << std::endl;
    for(int i = 0; i < 9; i++)
      std::cout << temp[i] << std::endl;
    //rate.sleep();
  }
}
#endif

void read_odom_once()
{
  readLock rdlock(rwmutex); 
  std::cout << "=====" << std::endl;
  for(int i = 0; i < 9; i++)
    std::cout << temp[i] << std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "uart_m700_node");
  ros::NodeHandlePtr nh = boost::make_shared<ros::NodeHandle>();


  SerialHandle my_port; 
  my_port.set_port("/dev/ttyUSB0");
  my_port.set_baudRate(115200);
  my_port.set_dataBits(8);
  my_port.set_stopBit(1);
  my_port.set_parity(false);
  my_port.set_hardwareFlowControl(false);

  //boost::thread thread_read(read_odom, &my_port, temp);
  boost::thread thread_write(write_odom, &my_port, temp);

  ros::Rate rate(10);

#if 0
  read_odom_once();
  sleep(1);

  read_odom_once();
  sleep(1);

  read_odom_once();
  sleep(1);

  read_odom_once();
  sleep(1);
#endif

#if 1
  while(ros::ok())
  {
    read_odom_once();
    rate.sleep();
  }
#endif

  //thread_read.join();
  thread_write.join();

#if 0
  int temp;
  while(1)
  {
    temp = int(my_port.readData());
    std::cout << temp << std::endl;
  } 
#endif
#if 0
  my_port.writeData(100, 300);
  sleep(5);

  my_port.writeData(-100, -300);
  sleep(5);

  my_port.writeData(300, 100);
  sleep(5);

  my_port.writeData(-300, -100);
  sleep(5);
#endif

#if 0
  std::cout << "100" << std::endl;
  my_port.writeData(-100, -100);
  sleep(5);

  std::cout << "200" << std::endl;
  my_port.writeData(-200, -200);
  sleep(5);

  std::cout << "250" << std::endl;
  my_port.writeData(-250, -250);
  sleep(5);

  std::cout << "300" << std::endl;
  my_port.writeData(-300, -300);
  sleep(5);

  std::cout << "400" << std::endl;
  my_port.writeData(-400, -400);
  sleep(5);

  std::cout << "500" << std::endl;
  my_port.writeData(-500, -500);
  sleep(5);

  std::cout << "0" << std::endl;
  my_port.writeData(0, 0);
  sleep(5);
#endif

#if 0
  my_port.writeData(100, -100);
  sleep(1);

  my_port.writeData(-100, 100);
  sleep(1);

  my_port.writeData(200, -200);
  sleep(1);

  my_port.writeData(-200, 200);
  sleep(1);

  my_port.writeData(300, -300);
  sleep(1);

  my_port.writeData(-300, 300);
  sleep(1);

  my_port.writeData(200, -200);
  sleep(1);

  my_port.writeData(-200, 200);
  sleep(1);

  my_port.writeData(100, -100);
  sleep(1);

  my_port.writeData(-100, 100);
  sleep(1);

  my_port.writeData(0, 0);
  sleep(1);
#endif

}
