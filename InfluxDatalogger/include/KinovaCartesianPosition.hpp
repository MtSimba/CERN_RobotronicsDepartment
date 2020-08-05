#ifndef KINOVA_CARTESIAN_H
#define KINOVA_CARTESIAN_H

#include "ICartesianPosition.hpp"

class KinovaCartesianPosition : public ICartesianPosition
{
  public:
    void WriterCartesianPosition() const override {}
    void ReaderCartesianPosition() const override {}
};

#endif /* KINOVA_CARTESIAN_H */
