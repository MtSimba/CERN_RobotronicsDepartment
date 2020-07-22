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

using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::AutoPtr;

void *infothread(void *arg)
{
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Logs.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger1 = Logger::get("TestLogger"); // inherits root channel

  auto start1 = std::chrono::high_resolution_clock::now();
  logger1.information("Info test");
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span1 = end1 - start1;
  logger1.information("execution time for INFO: {%f} ms ", time_span1.count());
}

void *warningthread(void *arg)
{
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Logs.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger2 = Logger::get("TestLogger"); // inherits root channel

  auto start2 = std::chrono::high_resolution_clock::now();
  logger2.warning("Warning test");
  auto end2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span2 = end2 - start2;
  logger2.information("execution time for WARNING: {%f} ms ",time_span2.count());
}

void *errorthread(void *arg)
{
  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Logs.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger3 = Logger::get("TestLogger"); // inherits root channel

  auto start3 = std::chrono::high_resolution_clock::now();
  logger3.error("Error test");
  auto end3 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span3 = end3 - start3;
  logger3.information("execution time for ERROR: {%f} ms ",time_span3.count());
}

void *fatalthread(void *arg)
{

  AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
  pChannel->setProperty("path", "Logs.txt");
  Logger::root().setChannel(pChannel);
  Logger& logger4 = Logger::get("TestLogger"); // inherits root channel

  auto start4 = std::chrono::high_resolution_clock::now();
  logger4.fatal("Fatal test");
  auto end4 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span4 = end4 - start4;
  logger4.information("execution time for FATAL: {%f} ms ",time_span4.count());
}



int main(int argc, char* argv[])
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
