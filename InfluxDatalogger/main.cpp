//#include "src/Client.cpp"
#include "include/InfluxDBFactory.hpp"


int main()
{
  InfluxDBFactory *Factory;
  IJointPosition *joint;

  Factory = new KinovaInfluxDBFactory;
  joint = Factory->CreateJointPosition();
  joint->WriterJointPosition(1,2,3,4,5,6);

  return 0;
}
