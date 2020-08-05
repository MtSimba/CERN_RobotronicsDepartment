//g++ -std=c++17 main.cpp -Iinclude -o main

#include "InfluxDBFactory.hpp"
#include "KinovaInfluxDBFactory.hpp"

void ClientCode(const InfluxDBFactory &factory)
{
  const IJointPosition *Joint = factory.CreateJointPosition();
  Joint->WriterJointPosition();
  delete Joint;
}


int main()
{
  KinovaInfluxDBFactory *f1 = new KinovaInfluxDBFactory();

  ClientCode(*f1);

  delete f1;

  return 0;
}
