CXX = g++
CXXFLAGS = -std=c++14 -pedantic -fpermissive

SRC = main.cc \
			data.cc \
			endpoint.cc
BIN = hash

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm $(BIN)
