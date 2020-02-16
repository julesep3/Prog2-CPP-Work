a.out: infixToPostfix.o stack.o
	g++ -g infixToPostfix.o stack.o

nstack.o: stack.cpp stack.h
	g++ -c -g stack.cpp

infixToPostfix.o: infixToPostfix.cpp stack.h
	g++ -c -g infixToPostfix.cpp