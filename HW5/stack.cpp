#include <iostream>
using namespace std;

template<typename T>
struct stack {
	T stk[50];
	int top = -1;
	void push(T i) {
		stk[++top] = i;
	}
	void pop() {
		top--;
	}
	int empty() {
		return top == -1;
	}
	T onTop() {
		return stk[top];
	}
	void display() {
		for(int j = 0; j <= top; j++) {
			cout << stk[j];
		}
		cout << endl;
	}
	void popAll() {
		top = -1;
	}
};