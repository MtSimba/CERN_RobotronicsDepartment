#ifndef JOINT_H
#define JOINT_H

class IJointPosition
{
  public:
    virtual void WriterJointPosition() const = 0;
    virtual void ReaderJointPosition() const = 0;
    virtual ~IJointPosition(){ };
};

#endif /* JOINT_H */
