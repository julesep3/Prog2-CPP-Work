#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct stack {
	int stk[50];
	int top = -1;
	void push(int i) {
		stk[++top] = i;
	}
	void pop(int &i) {
		i = stk[top--];
	}
	int empty() {
		return top == -1;
	}
};

int main() {
	stack<int> intstack;
	stack<char> charstack;
	string s;
	ifstream inData;

	inData.open("input.txt");

	while (getline(inData, s)) {
		cout << s << endl;
	}

	inData.close();
}