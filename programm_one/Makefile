all: p_one

p_one: main.o Buffer.o ThreadOne.o ThreadTwo.o
	g++ main.o Buffer.o ThreadOne.o ThreadTwo.o -o p_one -lpthread

main.o: main.cpp
	g++ -c main.cpp 

ThreadTwo.o:
	g++ -c ThreadTwo.cpp
	
ThreadOne.o:
	g++ -c ThreadOne.cpp

Buffer.o:
	g++ -c Buffer.cpp

clean:
	rm -rf *.o p_one
	
install:
	install ./p_one /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/p_one
