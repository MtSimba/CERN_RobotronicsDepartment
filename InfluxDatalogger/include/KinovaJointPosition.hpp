#ifndef KINOVA_JOINT_H
#define KINOVA_JOINT_H

#include "IJointPosition.hpp"

class KinovaJointPosition : public IJointPosition
{
  public:
    void WriterJointPosition() const override {}
    void ReaderJointPosition() const override {}
};

#endif /* KINOVA_JOINT_H */
