#include "../include/InfluxDBFactory.hpp"
#include "../include/KinovaJointPosition.hpp"

void ClientCode(const InfluxDBFactory &factory)
{
  const IJointPosition *Joint = factory.CreateJointPosition();

  Joint->WriterJointPosition(1,2,3,4,5,6);

  delete Joint;
}
