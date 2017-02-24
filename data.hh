#pragma once


#include <vector>
#include <map>
#include <string>
#include <fstream>

#include "endpoint.hh"

class Data
{
  public:
    Data(std::string str);

    static std::vector<Endpoint> endpoints;
    static std::map<int, int> video_size;

    static int nb_video;
    static int nb_endpoint;
    static int nb_request;
    static int nb_cache;
    static int capacity_cache;

};
