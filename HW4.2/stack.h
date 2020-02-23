#pragma once

class stack {
private:
	char stk[50];
	int top = -1;
public:
	void push(char);
	void pop(char &);
	int empty();
}