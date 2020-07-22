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


void *infothread(void *arg)
{
  auto mylogger = spdlog::basic_logger_mt("mylogger1", "Logs.txt");
  auto start1 = std::chrono::high_resolution_clock::now();
  mylogger->info("Info test");
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span1 = end1 - start1;
  mylogger->info("execution time for info: {0:f} ms",time_span1.count());
}


void *warningthread(void *arg)
{
  auto mylogger = spdlog::basic_logger_mt("mylogger2", "Logs.txt");
  auto start3 = std::chrono::high_resolution_clock::now();
  mylogger->warn("warning test");
  auto end3 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span3 = end3 - start3;
  mylogger->info("execution time for warnings: {0:f} ms",time_span3.count());
}

void *errorthread(void *arg)
{
  auto mylogger = spdlog::basic_logger_mt("mylogger3", "Logs.txt");
  auto start2 = std::chrono::high_resolution_clock::now();
  mylogger->error("error test");
  auto end2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span2 = end2 - start2;
  mylogger->info("execution time for error: {0:f} ms",time_span2.count());
}

void *criticalthread(void *arg)
{
  auto mylogger = spdlog::basic_logger_mt("mylogger4", "Logs.txt");
  auto start4 = std::chrono::high_resolution_clock::now();
  mylogger->critical("critical test");
  auto end4 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> time_span4 = end4 - start4;
  mylogger->info("execution time for critical: {0:f} ms",time_span4.count());
}



int main()
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
