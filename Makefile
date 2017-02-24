CXX = g++
CXXFLAGS = -std=c++14 -pedantic

SRC = main.cc
BIN = hash

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm $(BIN)
