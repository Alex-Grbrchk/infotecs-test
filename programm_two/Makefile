all: p_two

p_two: main.o 
	g++ main.o -o p_two -lpthread

main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm -rf *.o p_two
	
install:
	install ./p_two /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/p_two
