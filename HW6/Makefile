a.out: istack.o main.o
	g++ -g istack.o main.o

istack.o: istack.cpp istack.h
	g++ -c -g istack.cpp

main.o: main.cpp istack.h
	g++ -c -g main.cpp