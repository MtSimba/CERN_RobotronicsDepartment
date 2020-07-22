/* Benchmark testing for loguru */
/* Author : Victor Mtsimbe Norrild */

#include "loguru.hpp"
#include "loguru.cpp"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>
#include <vector>
#include <numeric>

using namespace std;

void *infothread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start = std::chrono::high_resolution_clock::now();
      LOG_F(INFO,"Info test");
      auto end = std::chrono::high_resolution_clock::now();

      chrono::duration<float> time_span = end - start;
      v.push_back(static_cast<float>(time_span.count()));
    }

  LOG_F(INFO,"execution time for INFO: %f ms", average = accumulate( v.begin(), v.end(), 0.0/ v.size()));

}

void *warningthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start = std::chrono::high_resolution_clock::now();
      LOG_F(WARNING,"Warning test");
      auto end = std::chrono::high_resolution_clock::now();

      chrono::duration<float> time_span = end - start;
      v.push_back(static_cast<float>(time_span.count()));
    }

  LOG_F(INFO,"execution time for WARNING: %f ms", average = accumulate( v.begin(), v.end(), 0.0/ v.size()));

}

void *errorthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start = std::chrono::high_resolution_clock::now();
      LOG_F(ERROR,"Error test");
      auto end = std::chrono::high_resolution_clock::now();

      chrono::duration<float> time_span = end - start;
      v.push_back(static_cast<float>(time_span.count()));
    }

  LOG_F(INFO,"execution time for ERROR: %f ms", average = accumulate( v.begin(), v.end(), 0.0/ v.size()));

}

void *fatalthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start = std::chrono::high_resolution_clock::now();
      LOG_F(FATAL,"Fatal test");
      auto end = std::chrono::high_resolution_clock::now();

      chrono::duration<float> time_span = end - start;
      v.push_back(static_cast<float>(time_span.count()));
    }

  LOG_F(INFO,"execution time for Fatal: %f ms", average = accumulate( v.begin(), v.end(), 0.0/ v.size()));

}



int main(int argc,char* argv[])
{
  loguru::init(argc,argv);
  loguru::add_file("Logs.txt", loguru::Append, loguru::Verbosity_INFO);

  pthread_t t1,t2,t3,t4;

  int a = pthread_create(&t1,NULL,infothread,NULL);
  int b = pthread_create(&t2,NULL,warningthread,NULL);
  int c = pthread_create(&t3,NULL,errorthread,NULL);
  //int d = pthread_create(&t4,NULL,fatalthread,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  //pthread_join(t4,NULL);
  return 0;

}
