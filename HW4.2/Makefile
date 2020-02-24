a.out: astack.o priority.o main.o
	g++ -g astack.o priority.o main.o

astack.o: astack.cpp astack.h
	g++ -c -g astack.cpp

priority.o: priority.cpp priority.h
	g++ -c -g priority.cpp

main.o: main.cpp astack.h priority.h
	g++ -c -g main.cpp