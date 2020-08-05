#ifndef JOINT_H
#define JOINT_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <memory>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

class IJointPosition
{
  public:
    virtual void WriterJointPosition(int j1, int j2, int j3, int j4, int j5, int j6) const = 0;
    virtual void ReaderJointPosition() const = 0;
};

#endif /* JOINT_H */
