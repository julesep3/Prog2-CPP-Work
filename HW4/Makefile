a.out: istack.o main.o priority.o
	g++ -g istack.o priority.o main.o

istack.o: istack.cpp istack.h
	g++ -c -g istack.cpp

priority.o: priority.cpp priority.h
	g++ -c -g priority.cpp

main.o: main.cpp istack.h priority.h
	g++ -c -g main.cpp