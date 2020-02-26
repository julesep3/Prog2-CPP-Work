a.out: stack.o main.o evaluate.o
	g++ -g stack.o evaluate.o main.o

istack.o: stack.cpp
	g++ -c -g stack.cpp

evaluate.o: evaluate.cpp evaluate.h
	g++ -c -g evaluate.cpp

main.o: main.cpp stack.cpp evaluate.h
	g++ -c -g main.cpp