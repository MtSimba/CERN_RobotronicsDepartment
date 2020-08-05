#include "../include/SchunkCartesianPosition.hpp"

void SchunkCartesianPosition::WriterCartesianPosition(int j1, int j2, int j3, int j4, int j5, int j6,
                                                 int j7, int j8, int j9, int j10, int j11, int j12,
                                                 int j13, int j14, int j15, int j16) 
{
  std::string a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
  std::string query = "CartesianPositions,robottype=Schunk joint1="+ (a = std::to_string(j1)) +",joint2="
  + (b = std::to_string(j2)) +",joint3="+ (c = std::to_string(j3)) +",joint4="
  + (d = std::to_string(j4)) +",joint5="+ (e = std::to_string(j5)) +",joint6="
  + (f = std::to_string(j6)) +",joint7="+ (g = std::to_string(j7)) +",joint8="
  + (h = std::to_string(j8)) +",joint9="+ (i = std::to_string(j9)) +",joint10="
  + (j = std::to_string(j10)) +",joint11="+ (k = std::to_string(j11)) +",joint12="
  + (l = std::to_string(j12)) +",joint13="+ (m = std::to_string(j13)) +",joint14="
  + (n = std::to_string(j14)) +",joint15="+ (o = std::to_string(j15)) +",joint16="
  + (p = std::to_string(j16));
  try
    {
      // That's all that is needed to do cleanup of used resources (RAII style).
      curlpp::Cleanup cleaner;
      curlpp::Easy request;

      request.setOpt(new curlpp::options::Url("http://localhost:8086/write?db=Schunk&precision=ns"));
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

void SchunkCartesianPosition::ReaderCartesianPosition()
{
  std::string query = "q=SELECT * FROM CartesianPositions";
  try
    {
      // That's all that is needed to do cleanup of used resources (RAII style).
      curlpp::Cleanup cleaner;
      curlpp::Easy request;

      request.setOpt(new curlpp::options::Url("http://localhost:8086/query?db=Schunk&pretty=true"));
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
