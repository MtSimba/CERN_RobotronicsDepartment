#ifndef SCHUNK_CARTESIAN_H
#define SCHUNK_CARTESIAN_H


#include "ICartesianPosition.hpp"

class SchunkCartesianPosition : public ICartesianPosition
{
  public:
    void WriterCartesianPosition() const override {}
    void ReaderCartesianPosition() const override {}
};

#endif /* SCHUNK_CARTESIAN_H */
