CXX = g++
CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all:clean hw5

hw5: src/main.cpp obj/hashtable.o obj/stats.o
	$(CXX) $(CXXFLAGS) src/main.cpp obj/hashtable.o obj/stats.o -o bin/hw5

obj/hashtable.o: src/hashtable.cpp src/hashtable.h src/hasher.h
	$(CXX) $(CXXFLAGS)  -c src/hashtable.cpp -o obj/hashtable.o

obj/stats.o: src/stats.cpp src/stats.h src/hashtable.h
	$(CXX) $(CXXFLAGS) -c src/stats.cpp -o obj/stats.o
clean:
	rm -f obj/*.o bin/hw5

