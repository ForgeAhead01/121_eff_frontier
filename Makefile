CCFLAGS=--std=gnu++11 -pedantic -Wall -Werror -ggdb3
efficient_frontier: main.o parse.o asset.o
	g++ -I/usr/include/eigen3 -o  efficient_frontier $(CCFLAGS) main.o asset.o parse.o 


%.o: %.cpp asset.h parse.h 
	g++ -c $(CCFLAGS) $<

clean:
	rm -f *.o  *~ efficient_frontier