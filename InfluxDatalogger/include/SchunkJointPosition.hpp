#ifndef SCHUNK_JOINT_H
#define SCHUNK_JOINT_H


#include "IJointPosition.hpp"

class SchunkJointPosition : public IJointPosition
{
  public:
    void WriterJointPosition() const override {}
    void ReaderJointPosition() const override {}
};

#endif /* SCHUNK_JOINT_H */
