#pragma once


#include <map>
#include <list>



class Endpoint
{
  public:
    
    Endpoint();


    std::map<int, int> request_per_video;
    std::map<int, int> cost_per_buffer;
    int cost;
    int id;
};
