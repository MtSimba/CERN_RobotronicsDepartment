#include "src/Client.cpp"

int main()
{
  KinovaInfluxDBFactory *f1 = new KinovaInfluxDBFactory();

  ClientCode(*f1);

  delete f1;

  return 0;
}
