#include "state.hh"


State::State()
{
  for (auto it : Data::endpoints)
  {
    for (auto buff : it.cost_per_buffer)
    {
      buffers[buff.first]
    }
  }
}
