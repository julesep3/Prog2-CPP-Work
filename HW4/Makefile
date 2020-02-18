a.out: infixToPostfix.o istack.o
	g++ -g infixToPostfix.o istack.o

istack.o: istack.cpp istack.h
	g++ -c -g istack.cpp

infixToPostfix.o: infixToPostfix.cpp istack.h
	g++ -c -g infixToPostfix.cpp