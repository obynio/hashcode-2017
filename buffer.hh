#pragma once


#include <vector>
#include <map>

class Buffer
{
  public:
    std::vector<int> videos;
    std::map<int, int> gain_per_video;
    std::map<int, int> inv_gain;

    int free_size;
    static int total_size;
};
