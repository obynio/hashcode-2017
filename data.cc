#include "data.hh"

#include <string>
#include <sstream>

int Data::nb_video;
int Data::nb_endpoint;
int Data::nb_request;
int Data::nb_cache;
int Data::capacity_cache;

std::vector<Endpoint> Data::endpoints;
std::map<int, int> Data::video_size;

Data::Data(std::string str)
{
  std::ifstream file;
  std::string line;

  file.open(str, std::ios::in);

  if (!file.good())
  {
    throw std::invalid_argument("error reading file");
  }

  // first line
  std::getline(file, line);
  std::stringstream s1(line);

  s1 >> nb_video;
  s1 >> nb_endpoint;
  s1 >> nb_request;
  s1 >> nb_cache;
  s1 >> capacity_cache;

  // debug
  //std::cout << nb_video << std::endl;
  //std::cout << capacity_cache << std::endl;

  // second line
  std::getline(file, line);
  std::stringstream s2(line);


  for (int i = 0; !s2.eof(); i++)
    s2 >> video_size[i];

  //std::cout << video_size[2];

  for (int i = 0; i < nb_endpoint; i++)
  {
    int id;
    int cost;

    file >> id;
    file >> cost;

    Endpoint end(id, cost);

    for (int j = 0; j < cost; j++)
    {
      int idd;
      file >> idd;
      file >> end.cost_per_buffer[idd];
    }

    //std::cout << id << ":" << cost << std::endl;
    //std::cout << end.cost_per_buffer[9] << std::endl;

    endpoints.push_back(end);
  }

  while (!file.eof())
  {
    int req, e, vid;

    file >> vid;
    file >> e;
    file >> req;

    endpoints.at(e).request_per_video[vid] = req;

    //std::cout << vid << ":" << e << ":" << endpoints.at(e).request_per_video[vid] << ":" << std::endl;
  }

  file.close();
}
