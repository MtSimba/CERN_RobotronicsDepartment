#include "../include/InfluxDBFactory.hpp"
#include "../include/KinovaJointPosition.hpp"

void ClientCode(const InfluxDBFactory &factory)
{
  const IJointPosition *Joint = factory.CreateJointPosition();
  Joint->WriterJointPosition();
}
