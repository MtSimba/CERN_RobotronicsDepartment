#ifndef SCHUNK_FACTORY_H
#define SCHUNK_FACTORY_H

#include "InfluxDBFactory.hpp"

class SchunkInfluxDBFactory : public InfluxDBFactory
{
  public:
    ICartesianPosition *CreateCartesianPosition() const override{
      return new SchunkCartesianPosition;
    }
    IJointPosition *CreateJointPosition() const override {
      return new SchunkJointPosition;
    }
};

#endif /* SCHUNK_FACTORY_H */
