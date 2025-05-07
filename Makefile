CXX = g++
CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all:clean hw5



clean:
	rm -f obj/*.o bin/hw5

