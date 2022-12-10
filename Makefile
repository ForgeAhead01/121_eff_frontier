CCFLAGS=--std=gnu++98 -pedantic -Wall -Werror -ggdb3
efficient_frontier: main.o parse.o 
	g++ -o  efficient_frontier $(CCFLAGS) main.o parse.o 


%.o: %.cpp parse.h
	g++ -c $(CCFLAGS) $<

clean:
	rm -f *.o  *~ efficient_frontier