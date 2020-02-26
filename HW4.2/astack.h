#pragma once

class astack {
private:
	char stk[50];
	int top;
public:
	void push(char);
	void pop();
	int empty();
	char onTop();
};