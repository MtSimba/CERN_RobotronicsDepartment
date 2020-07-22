/* Benchmark testing for spdlog */
/* Author : Victor Mtsimbe Norrild */

#include <plog/Log.h> // Step1: include the headers
#include "plog/Initializers/RollingFileInitializer.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>

void *infothread(void *arg)
{
  auto start1 = std::chrono::high_resolution_clock::now();
  PLOG_INFO << "INFO test";
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span1 = end1 - start1;
  PLOG_INFO << "execution time for INFO: " << time_span1.count()  << "ms";
}

void *warningthread(void *arg)
{
  auto start2 = std::chrono::high_resolution_clock::now();
  PLOG_WARNING << "WARNING test";
  auto end2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span2 = end2 - start2;
  PLOG_INFO << "execution time for WARNING: " << time_span2.count() << "ms";
}

void *errorthread(void *arg)
{
  auto start3 = std::chrono::high_resolution_clock::now();
  PLOG_ERROR << "ERROR test";
  auto end3 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span3 = end3 - start3;
  PLOG_INFO << "execution time for ERROR: " << time_span3.count() << "ms";
}

void *fatalthread(void *arg)
{
  auto start4 = std::chrono::high_resolution_clock::now();
  PLOG_FATAL << "FATAL test";
  auto end4 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span4 = end4 - start4;
  PLOG_INFO << "execution time for FATAL: " << time_span4.count() << "ms";
}



int main()
{
  plog::init(plog::debug,"Logs.txt");

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
