CXX = g++
CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all:clean hw5

hw5: src/main/cpp obj/hashtable.o obj/stats.obj
	$(CXX) $(CXXFLAGS) src/main.cpp obj/hashtable.o obj/stats.o -o bin/hw5

obj/hashtable.o: src.hashtable.cpp src/hashtable.h src/hasher.hasher
	$(CXX) $(CXXFLAGS)  -c src/hashtable.cpp -o obj/stats.o
clean:
	rm -f obj/*.o bin/hw5

