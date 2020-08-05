#ifndef FACTORY_H
#define FACTORY_H

#include "IJointPosition.hpp"
#include "ICartesianPosition.hpp"

class InfluxDBFactory
{
  public:
    virtual ICartesianPosition *CreateCartesianPosition() = 0;
    virtual IJointPosition     *CreateJointPosition() = 0;
};

#endif /* FACTORY_H */
