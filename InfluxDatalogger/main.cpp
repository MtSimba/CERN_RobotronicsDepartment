#include "src/Client.cpp"
#include "include/InfluxDBFactory.hpp"
#include "include/KinovaInfluxDBFactory.hpp"

int main()
{
  KinovaInfluxDBFactory *f1 = new KinovaInfluxDBFactory();
  ClientCode(*f1);
  delete f1;

  return 0;
}
