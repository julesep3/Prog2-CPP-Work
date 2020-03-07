a.out: node.o sllist.o main.o
	g++ -g node.o sllist.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

sllist.o: sllist.cpp sllist.h node.h
	g++ -c -g sllist.cpp

main.o: main.cpp sllist.h
	g++ -c -g main.cpp