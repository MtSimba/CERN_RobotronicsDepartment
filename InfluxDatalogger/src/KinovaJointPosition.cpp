/*
#include "include/KinovaJointPosition.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>

void KinovaJointPosition::WriterJointPosition(int j1, int j2, int j3, int j4, int j5, int j6)
{
  std::string a,b,c,d,e,f;
  std::string query = "JointPositions,robottype=Kinova joint1="+ (a = std::to_string(j1)) +",joint2="
  + (b = std::to_string(j2)) +",joint3="+ (c = std::to_string(j3)) +",joint4="
  + (d = std::to_string(j4)) +",joint5="+ (e = std::to_string(j5)) +",joint6="
  + (f = std::to_string(j6));
  try
    {
      // That's all that is needed to do cleanup of used resources (RAII style).
      curlpp::Cleanup cleaner;
      curlpp::Easy request;

      request.setOpt(new curlpp::options::Url("http://localhost:8086/write?db=Kinova&precision=ns"));
      request.setOpt(new curlpp::options::Verbose(true));

      request.setOpt(new curlpp::options::PostFields(query));
      request.setOpt(new curlpp::options::PostFieldSize(query.length()));

      // Send request and get a result.
      // By default the result goes to standard output.
      request.perform();
    }
  catch(curlpp::RuntimeError & e)
    {
      std::cout << e.what() << std::endl;
    }

  catch(curlpp::LogicError & e)
    {
      std::cout << e.what() << std::endl;
    }
}

void KinovaJointPosition::ReaderJointPosition()
{
  std::string query = "q=SELECT * FROM JointPositions";
  try
    {
      // That's all that is needed to do cleanup of used resources (RAII style).
      curlpp::Cleanup cleaner;
      curlpp::Easy request;

      request.setOpt(new curlpp::options::Url("http://localhost:8086/query?db=Kinova&pretty=true"));
      request.setOpt(new curlpp::options::Verbose(true));

      request.setOpt(new curlpp::options::PostFields(query));
      request.setOpt(new curlpp::options::PostFieldSize(query.length()));

      // Send request and get a result.
      // By default the result goes to standard output.
      request.perform();
    }

  catch(curlpp::RuntimeError & e)
    {
      std::cout << e.what() << std::endl;
    }

  catch(curlpp::LogicError & e)
    {
      std::cout << e.what() << std::endl;
    }
}
*/
