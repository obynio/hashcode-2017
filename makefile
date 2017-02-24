CXX = g++
CXXFLAGS = -std=c++14 -O0 -g3

SRC = main.cc \
			data.cc \
			endpoint.cc \
			state.cc
BIN = hash

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm $(BIN)

data: all
	zip misc/sources.zip *.cc *.hh makefile
	./hash misc/me_at_the_zoo.in
	./hash misc/trending_today.in
	./hash misc/videos_worth_spreading.in
	./hash misc/kittens.in
