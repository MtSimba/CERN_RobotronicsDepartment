#ifndef KINOVA_JOINT_H
#define KINOVA_JOINT_H

#include "IJointPosition.hpp"

class KinovaJointPosition : public IJointPosition
{
  public:
    void WriterJointPosition(int j1, int j2, int j3, int j4, int j5, int j6);
    void ReaderJointPosition();
};

#endif /* KINOVA_JOINT_H */
