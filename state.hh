#pragma once



#include "buffer.hh"
#include <set>


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

    void initial_solution();

    std::set<int> placed;
  void export_file(std::string);

};
