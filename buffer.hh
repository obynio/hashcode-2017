#pragma once


#include <vector>

class Buffer
{
  public:
    std::vector<int> videos;

    int free_size;
    static int total_size;
};
