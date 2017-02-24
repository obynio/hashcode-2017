#include "state.hh"
#include "data.hh"


State::State()
{
  buffers.resize(Data::nb_cache);
  for (auto it : buffers)
  {
    it.total_size = Data::capacity_cache;
    it.free_size = Data::capacity_cache;
  }
}


void State::initial_solution()
{
  for (auto endpoint : Data::endpoints)
  {
    for (auto buff : endpoint.cost_per_buffer)
    {
      int diff = endpoint.cost - buff.second;
      if (diff < 0)
        break;
      for (auto vid : endpoint.request_per_video)
      {
        buffers[buff.first].gain_per_video[vid.first] += diff * vid.second;
      }
    }
  }

  for (auto buff : buffers)
  {
    for (auto it : buff.gain_per_video)
    {
      buff.inv_gain[it.second] = it.first;
    }
    for (auto it : buff.inv_gain)
    {
      if (buff.free_size < Data::video_size[it.second])
        break;
      buff.videos.push_back(it.second);
      buff.free_size -= Data::video_size[it.second];
    }
  }
}
