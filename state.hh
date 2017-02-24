#pragma once



#include "buffer.hh"


class State
{
  public:
    State();
    State(State& other)
    {
      buffers = other.buffers;
    }


    std::vector<Buffer> buffers;

    void check_one_buffer();
    void add_one_video();

};
