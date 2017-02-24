#pragma once


#include <map>
#include <list>



class Endpoint
{
  public:
    
    Endpoint(int id, int cost, int nb_cache);


    std::map<int, int> request_per_video;
    std::map<int, int> cost_per_buffer;
    int cost;
    int id;
    int nb_cache;
};
