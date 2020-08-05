#ifndef KINOVA_FACTORY_H
#define KINOVA_FACTORY_H

#include "InfluxDBFactory.hpp"

class KinovaInfluxDBFactory : public InfluxDBFactory
{
  public:
    ICartesianPosition *CreateCartesianPosition() {
      return new KinovaCartesianPosition;
    }
    IJointPosition *CreateJointPosition() {
      return new KinovaJointPosition;
    }
};

#endif /* KINOVA_FACTORY_H */
