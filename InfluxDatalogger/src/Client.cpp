#include "../include/InfluxDBFactory.hpp"



class Client
{
public:
  InfluxDataLogger(InfluxDBFactory Factory)
  {
    _JointP = Factory.CreateJointPosition();
    _CartesianP = Factory.CreateCartesianPosition();
  };
private:
  IJointPosition _JointP;
  ICartesianPosition _CartesianP;

};

/*
void ClientCode(const InfluxDBFactory &factory)
{
  IJointPosition * joint = factory.CreateJointPosition();
  ICartesianPosition * Carte = factory.CreateCartesianPosition();

  joint->WriterJointPosition(1,2,3,4,5,6);

  delete joint;
  delete Carte;
}
*/
