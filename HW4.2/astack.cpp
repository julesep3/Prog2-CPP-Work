#include <iostream>
#include "astack.h"
using namespace std;

char stk[50];
int top = -1;

void push(char c) {
	stk[++top] = c;
}
void pop() {
	top--;
}
int empty() {
	return top == -1;
}
char onTop() {
	return stk[top];
}