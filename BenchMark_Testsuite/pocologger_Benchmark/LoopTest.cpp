/* Benchmark testing for Poco */
/* Author : Victor Mtsimbe Norrild */

#include "Poco/Logger.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/AutoPtr.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>
#include <vector>
#include <numeric>

using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::AutoPtr;
using namespace std;

void *infothread(void *arg)
{
  vector<float> v;
  float average;
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Log.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger1 = Logger::get("TestLogger"); // inherits root channel

  for (size_t i = 0; i < 100; i++)
    {
      auto start1 = std::chrono::high_resolution_clock::now();
      logger1.information("Info test");
      auto end1 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span1 = end1 - start1;
      v.push_back(static_cast<float>(time_span1.count()));
    }
  average = accumulate( v.begin(), v.end(), 0.0/ v.size());
  logger1.information("execution time for INFO: {%hf} ms ",average);

}

void *warningthread(void *arg)
{
  vector<float> v;
  float average;
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Log.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger2 = Logger::get("TestLogger"); // inherits root channel

  for (size_t i = 0; i < 100; i++)
    {
      auto start2 = std::chrono::high_resolution_clock::now();
      logger2.warning("Warning test");
      auto end2 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span2 = end2 - start2;
      v.push_back(static_cast<float>(time_span2.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    logger2.information("execution time for Warning: {%hf} ms ",average);

}

void *errorthread(void *arg)
{
  vector<float> v;
  float average;
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Log.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger3 = Logger::get("TestLogger"); // inherits root channel

  for (size_t i = 0; i < 100; i++)
    {
      auto start3 = std::chrono::high_resolution_clock::now();
      logger3.error("Error test");
      auto end3 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span3 = end3 - start3;
      v.push_back(static_cast<float>(time_span3.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    logger3.information("execution time for Error: {%hf} ms ",average);

}

void *fatalthread(void *arg)
{
  vector<float> v;
  float average;
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Log.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger4 = Logger::get("TestLogger"); // inherits root channel

  for (size_t i = 0; i < 100; i++)
    {
      auto start4 = std::chrono::high_resolution_clock::now();
      logger4.fatal("Fatal test");
      auto end4 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span4 = end4 - start4;
      v.push_back(static_cast<float>(time_span4.count()));
    }

    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    logger4.information("execution time for Fatal: {%hf} ms ",average);

}


int main(int argc,char* argv[])
{

  pthread_t t1,t2,t3,t4;

  int a = pthread_create(&t1,NULL,infothread,NULL);
  int b = pthread_create(&t2,NULL,warningthread,NULL);
  int c = pthread_create(&t3,NULL,errorthread,NULL);
  int d = pthread_create(&t4,NULL,fatalthread,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  pthread_join(t4,NULL);
  return 0;

}
