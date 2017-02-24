#include "data.hh"
#include "state.hh"

int main(int argc, char* argv[])
{

  if (argc == 2)
    Data data(argv[1]); 
  else
    std::cout << "no input file" << std::endl;

  State state;
  state.initial_solution();
  state.export_file();
  return 0;
}
