#include "data.hh"
#include "state.hh"

int main()
{
  Data data("me_at_the_zoo.in"); 

  State state;
  state.export_file();
  return 0;
}
