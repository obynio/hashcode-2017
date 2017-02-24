#include "data.hh"

#include <string>

int Data::nb_video;
int Data::nb_endpoint;
int Data::nb_request;
int Data::nb_cache;
int Data::capacity_cache;

Data::Data(std::string str)
{
  std::ifstream file;

  file.open(str, std::ios::in);

  if (!file.good())
  {
    throw std::invalid_argument("error reading file");
  }

  file >> nb_video;
  file >> nb_endpoint;
  file >> nb_request;
  file >> nb_cache;
  file >> capacity_cache;

  file.close();
}
