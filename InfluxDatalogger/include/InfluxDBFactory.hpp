#ifndef FACTORY_H
#define FACTORY_H

#include "IJointPosition.hpp"
#include "ICartesianPosition.hpp"
#include "KinovaInfluxDBFactory.hpp"
#include "SchunkInfluxDBFactory.hpp"

class InfluxDBFactory
{
  public:
    virtual ICartesianPosition *CreateCartesianPosition() const = 0;
    virtual IJointPosition     *CreateJointPosition() const = 0;
};

#endif /* FACTORY_H */
