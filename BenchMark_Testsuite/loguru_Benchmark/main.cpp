/* Benchmark testing for loguru */
/* Author : Victor Mtsimbe Norrild */

#include "loguru.hpp"
#include "loguru.cpp"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>

void *infothread(void *arg)
{
  auto start1 = std::chrono::high_resolution_clock::now();
  LOG_F(INFO,"Info test");
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span1 = end1 - start1;
  LOG_F(INFO,"execution time for INFO: %f ms", time_span1.count());
}

void *warningthread(void *arg)
{
  auto start2 = std::chrono::high_resolution_clock::now();
  LOG_F(WARNING,"Warning test");
  auto end2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span2 = end2 - start2;
  LOG_F(INFO,"execution time for WARNING: %f ms", time_span2.count());
}

void *errorthread(void *arg)
{
  auto start3 = std::chrono::high_resolution_clock::now();
  LOG_F(ERROR,"ERROR test");
  auto end3 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span3 = end3 - start3;
  LOG_F(INFO,"execution time for ERROR: %f ms", time_span3.count());
}

void *fatalthread(void *arg)
{
  auto start4 = std::chrono::high_resolution_clock::now();
  LOG_F(FATAL,"Info test");
  auto end4 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span4 = end4 - start4;
  LOG_F(INFO,"execution time for FATAL: %f ms", time_span4.count());
}



int main(int argc,char* argv[])
{
  loguru::init(argc,argv);
  loguru::add_file("Logs.txt", loguru::Append, loguru::Verbosity_INFO);

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
