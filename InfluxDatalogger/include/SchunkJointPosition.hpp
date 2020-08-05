#include "IJointPosition.hpp"

class SchunkJointPosition : public IJointPosition
{
  public:
    void WriterJointPosition(int j1, int j2, int j3, int j4, int j5, int j6);
    void ReaderJointPosition();
};
