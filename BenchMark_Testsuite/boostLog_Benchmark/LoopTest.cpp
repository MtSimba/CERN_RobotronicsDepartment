/* Benchmark testing for Boost */
/* Author : Victor Mtsimbe Norrild */


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <pthread.h>
#include <vector>
#include <numeric>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
using namespace std;

void *infothread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start1 = std::chrono::high_resolution_clock::now();
      BOOST_LOG_TRIVIAL(info) <<"Info test";
      auto end1 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span1 = end1 - start1;
      v.push_back(static_cast<float>(time_span1.count()));
    }
  average = accumulate( v.begin(), v.end(), 0.0/ v.size());
  BOOST_LOG_TRIVIAL(info) <<"execution time for info: " << average << " ms";


}

void *warningthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start2 = std::chrono::high_resolution_clock::now();
      BOOST_LOG_TRIVIAL(warning) <<"Warning test";
      auto end2 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span2 = end2 - start2;
      v.push_back(static_cast<float>(time_span2.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    BOOST_LOG_TRIVIAL(info) <<"execution time for Warning: " << average << " ms";

}

void *errorthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start3 = std::chrono::high_resolution_clock::now();
      BOOST_LOG_TRIVIAL(error) <<"error test";
      auto end3 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span3 = end3 - start3;
      v.push_back(static_cast<float>(time_span3.count()));
    }
    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    BOOST_LOG_TRIVIAL(info) <<"execution time for error: " << average << " ms";

}

void *fatalthread(void *arg)
{
  vector<float> v;
  float average;
  for (size_t i = 0; i < 100; i++)
    {
      auto start4 = std::chrono::high_resolution_clock::now();
      BOOST_LOG_TRIVIAL(fatal) <<"fatal test";
      auto end4 = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double> time_span4 = end4 - start4;
      v.push_back(static_cast<float>(time_span4.count()));
    }

    average = accumulate( v.begin(), v.end(), 0.0/ v.size());
    BOOST_LOG_TRIVIAL(info) <<"execution time for fatal: " << average << " ms";


}


int main(int argc,char* argv[])
{
  logging::add_file_log("Log.txt");

  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);

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
