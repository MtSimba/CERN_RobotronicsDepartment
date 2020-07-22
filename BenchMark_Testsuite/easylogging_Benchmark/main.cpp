/* Benchmark testing for loguru */
/* Author : Victor Mtsimbe Norrild */

#include "easylogging++.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>

INITIALIZE_EASYLOGGINGPP

void *infothread(void *arg)
{
  auto start1 = std::chrono::high_resolution_clock::now();
  LOG(INFO) <<"Info test\n";
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span1 = end1 - start1;
  LOG(INFO) <<"execution time for INFO: "<< time_span1.count() << " ms\n";
}

void *warningthread(void *arg)
{
  auto start2 = std::chrono::high_resolution_clock::now();
  LOG(WARNING) <<"Warning test\n";
  auto end2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span2 = end2 - start2;
  LOG(INFO) <<"execution time for WARNING: " << time_span2.count() << " ms\n";
}

void *errorthread(void *arg)
{
  auto start3 = std::chrono::high_resolution_clock::now();
  LOG(ERROR) <<"ERROR test\n";
  auto end3 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span3 = end3 - start3;
  LOG(INFO) <<"execution time for ERROR: "<< time_span3.count() << " ms\n";
}

void *fatalthread(void *arg)
{
  auto start4 = std::chrono::high_resolution_clock::now();
  LOG(FATAL) <<"Info test\n";
  auto end4 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span4 = end4 - start4;
  LOG(INFO) <<"execution time for FATAL: "<< time_span4.count() << " ms\n";
}



int main(int argc, char* argv[])
{
  pthread_t t1,t2,t3,t4;

  int a = pthread_create(&t1,NULL,infothread,NULL);
  int b = pthread_create(&t2,NULL,warningthread,NULL);
  int c = pthread_create(&t3,NULL,errorthread,NULL);
  //int d = pthread_create(&t4,NULL,fatalthread,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
//  pthread_join(t4,NULL);
  return 0;
}
