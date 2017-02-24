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

dataset: all
	./hash dataset/me_at_the_zoo.in
	./hash dataset/trending_today.in
	./hash dataset/videos_worth_spreading.in
	./hash dataset/kittens.in
