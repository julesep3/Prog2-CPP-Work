#include <iostream>
#include "stack.h"
using namespace std;

void push(char c) {
	stk[++top] = c;
}

void pop(char &i) {
	i = stk[top--];
}
int empty() {
	return top == -1;
}