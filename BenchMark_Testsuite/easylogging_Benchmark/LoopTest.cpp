/* Benchmark testing for loguru */
/* Author : Victor Mtsimbe Norrild */

#include "easylogging++.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>
#include <vector>
#include <numeric>

INITIALIZE_EASYLOGGINGPP

using namespace std;

void *infothread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start1 = std::chrono::high_resolution_clock::now();
        LOG(INFO) <<"Info test\n";
      auto end1 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span1 = end1 - start1;
      v.push_back(static_cast<float>(time_span1.count()));
    }
  average = accumulate( v.begin(), v.end(), 0.0/ v.size());
  LOG(INFO) <<"execution time for INFO: " << average << " ms";

}

void *warningthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start2 = std::chrono::high_resolution_clock::now();
      LOG(WARNING) <<"Warning test\n";
      auto end2 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span2 = end2 - start2;
      v.push_back(static_cast<float>(time_span2.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    LOG(INFO) <<"execution time for WARNING: " << average << " ms\n";

}

void *errorthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start3 = std::chrono::high_resolution_clock::now();
      LOG(ERROR) <<"ERROR test\n";
      auto end3 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span3 = end3 - start3;
      v.push_back(static_cast<float>(time_span3.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    LOG(INFO) <<"execution time for ERROR: " << average << " ms\n";

}

void *fatalthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start4 = std::chrono::high_resolution_clock::now();
      LOG(FATAL) <<"FATAL test\n";
      auto end4 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<float> time_span4 = end4 - start4;
      v.push_back(static_cast<float>(time_span4.count()));
    }

    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    LOG(INFO) <<"execution time for FATAL: " << average << " ms\n";

}



int main(int argc,char* argv[])
{

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
