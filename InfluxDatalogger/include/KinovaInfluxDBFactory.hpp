#ifndef KINOVA_FACTORY_H
#define KINOVA_FACTORY_H

#include "InfluxDBFactory.hpp"
#include "KinovaJointPosition.hpp"
#include "KinovaCartesianPosition.hpp"
#include "ICartesianPosition.hpp"
#include "IJointPosition.hpp"

class KinovaInfluxDBFactory : public InfluxDBFactory
{
  public:
    ICartesianPosition *CreateCartesianPosition() const override {
      return new KinovaCartesianPosition();
    }
    IJointPosition *CreateJointPosition() const override {
      return new KinovaJointPosition();
    }
};

#endif /* KINOVA_FACTORY_H */
