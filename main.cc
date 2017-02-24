#include "data.hh"
#include "state.hh"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "hash [input]" << std::endl;
    return 0;
  }

  Data data(argv[1]); 

  State state;
  state.initial_solution();
  state.export_file(argv[1]);

  std::cout << "Done " << argv[1] << std::endl;

  return 0;
}
