#ifndef CARTESIAN_H
#define CARTESIAN_H

class ICartesianPosition
{
  public:
    virtual void WriterCartesianPosition() const = 0;
    virtual void ReaderCartesianPosition() const = 0;
    virtual ~ICartesianPosition(){ };
};

#endif /* CARTESIAN_H */
