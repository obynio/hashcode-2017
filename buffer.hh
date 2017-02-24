#pragma once

#include "data.hh"
#include <vector>
#include <map>

class Buffer
{
  public:
    Buffer()
    {
      free_size = Data::capacity_cache;
    }
    std::vector<int> videos;
    std::map<int, int> gain_per_video;
    std::map<int, int> inv_gain;

    int free_size;
};
