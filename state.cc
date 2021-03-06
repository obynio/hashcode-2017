#include "state.hh"
#include "data.hh"

#include <iostream>
#include <fstream>
#include <set>

State::State()
{
  buffers.resize(Data::nb_cache);
  int freesize = Data::capacity_cache;
  for (auto& it : buffers)
  {
    it.free_size = freesize;
  }
}


void State::initial_solution()
{
  for (auto& endpoint : Data::endpoints)
  {
    for (auto& buff : endpoint.cost_per_buffer)
    {
      int diff = endpoint.cost - buff.second;
      if (diff < 0)
        break;
      for (auto& vid : endpoint.request_per_video)
      {
        buffers[buff.first].gain_per_video[vid.first] += diff * vid.second;
      }
    }
  }

  for (auto& buff : buffers)
  {
    for (auto& it : buff.gain_per_video)
    {
      buff.inv_gain[it.second] = it.first;
    }
    for (auto& it : buff.inv_gain)
    {
      if (buff.free_size < Data::video_size[it.second])
        continue;
      if (placed.find(it.second) != placed.end())
        continue;
      placed.insert(it.second);
      buff.videos.push_back(it.second);
      buff.free_size -= Data::video_size[it.second];
    }
  }
}

void State::export_file(std::string file)
{
  std::ofstream myfile;
  myfile.open (file + ".sub");
  myfile << Data::nb_cache << "\n";
  for (unsigned int i = 0; i < buffers.size(); i++)
  {
    myfile << i;
    for (int v = 0; v < ((int)buffers[i].videos.size()) - 1; v++)
    {
      myfile <<  " " << buffers[i].videos[v];
    }
    myfile << "\n";
  }
  myfile.close();  
}
