a.out: stack.o main.o priority.o
	g++ -g stack.o priority.o main.o

stack.o: stack.cpp stack.h
	g++ -c -g stack.cpp

priority.o: priority.cpp priority.h
	g++ -c -g priority.cpp

main.o: main.cpp stack.h priority.h
	g++ -c -g main.cpp