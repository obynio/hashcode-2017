#pragma once



#include "buffer.hh"


class State
{
  public:
    State()
    {}
    State(State& other)
    {
      buffers = other.buffers;
    }


    std::vector<Buffer> buffers;

    void add_one_video();

};
