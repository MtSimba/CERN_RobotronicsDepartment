#include "ICartesianPosition.hpp"

class SchunkCartesianPosition : public ICartesianPosition
{
  public:
    void WriterCartesianPosition(int j1, int j2, int j3, int j4, int j5, int j6,
                                         int j7, int j8, int j9, int j10, int j11, int j12,
                                         int j13, int j14, int j15, int j16);
    void ReaderCartesianPosition();
};
