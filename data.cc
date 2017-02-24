#include "data.hh"

Data::Data(std::string str)
{
  std::ifstream file;

  file.open(str, std::ios::in);

  if (!file.good())
  {
    throw std::invalid_argument("error reading file");
  }


}
