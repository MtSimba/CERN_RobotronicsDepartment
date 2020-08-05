#ifndef SCHUNK_FACTORY_H
#define SCHUNK_FACTORY_H

#include "InfluxDBFactory.hpp"

class SchunkInfluxDBFactory : public InfluxDBFactory
{
  public:
    ICartesianPosition *CreateCartesianPosition() {
      return new SchunkCartesianPosition;
    }
    IJointPosition *CreateJointPosition() {
      return new SchunkJointPosition;
    }
};

#endif /* SCHUNK_FACTORY_H */
