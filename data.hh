#pragma once


#include <vector>
#include <map>
#include <string>

#include "endpoint.hh"

class Data
{
  public:
    Data(std::string file);

    std::vector<Endpoint> endpoints;
};
