#pragma once


#include <vector>
#include <map>
#include <string>

#include "endpoint.hh"

class Data
{
  public:
    Data(std::string file);

    static std::vector<Endpoint> endpoints;
    static std::map<int, int> video_size;
};
