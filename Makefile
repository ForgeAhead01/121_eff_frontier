CPPFLAGS=--std=gnu++11 -pedantic -Wall -Werror -ggdb3

all: clean efficient_frontier

efficient_frontier: main.o
	g++ $(CPPFLAGS) -o efficient_frontier main.o

main.o: main.cpp parse.h asset.h portfolio.h optfinder.h
	g++ $(CPPFLAGS) -c main.cpp

clean:
	rm -f *.o  *~