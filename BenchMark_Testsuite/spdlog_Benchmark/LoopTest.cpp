/* Benchmark testing for spdlog */
/* Author : Victor Mtsimbe Norrild */

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
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
  auto mylogger = spdlog::basic_logger_mt("mylogger1", "Logs.txt");
  for (size_t i = 0; i < 100; i++)
    {
      auto start1 = std::chrono::high_resolution_clock::now();
      mylogger->info("Info test\n");
      auto end1 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span1 = end1 - start1;;
      v.push_back(static_cast<float>(time_span1.count()));
    }
  average = accumulate( v.begin(), v.end(), 0.0/ v.size());
  mylogger->info("execution time for info: {0:f} ms\n ", average);

}

void *warningthread(void *arg)
{
  vector<float> v;
  float average;
  auto mylogger = spdlog::basic_logger_mt("mylogger2", "Logs.txt");
  for (size_t i = 0; i < 100; i++)
    {
      auto start3 = std::chrono::high_resolution_clock::now();
      mylogger->warn("warning test\n");
      auto end3 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span3 = end3 - start3;
      v.push_back(static_cast<float>(time_span3.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    mylogger->info("execution time for warning: {0:f} ms\n ", average);

}

void *errorthread(void *arg)
{
  vector<float> v;
  float average;
  auto mylogger = spdlog::basic_logger_mt("mylogger3", "Logs.txt");
  for (size_t i = 0; i < 100; i++)
    {
      auto start2 = std::chrono::high_resolution_clock::now();
      mylogger->error("error test\n");
      auto end2 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span2 = end2 - start2;
      v.push_back(static_cast<float>(time_span2.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    mylogger->info("execution time for error: {0:f} ms\n ", average);
}

void *criticalthread(void *arg)
{
  vector<float> v;
  float average;
  auto mylogger = spdlog::basic_logger_mt("mylogger4", "Logs.txt");
  for (size_t i = 0; i < 100; i++)
    {
      auto start4 = std::chrono::high_resolution_clock::now();
      mylogger->critical("critical test");
      auto end4 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span4 = end4 - start4;
      v.push_back(static_cast<float>(time_span4.count()));
    }

    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    mylogger->info("execution time for critical: {0:f} ms\n ", average);

}



int main(int argc,char* argv[])
{

  pthread_t t1,t2,t3,t4;

  int a = pthread_create(&t1,NULL,infothread,NULL);
  int b = pthread_create(&t2,NULL,warningthread,NULL);
  int c = pthread_create(&t3,NULL,errorthread,NULL);
  int d = pthread_create(&t4,NULL,criticalthread,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  pthread_join(t4,NULL);
  return 0;

}
