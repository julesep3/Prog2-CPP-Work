/*
Julian Shen
Programming II
Due: 02 / 21 / 2020
Infix to Postfix
Take input, convert into postfix
*/

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

template <typename T>
struct stack {
	T stk [50];
	int top = -1;
	void push(T i) {
		stk[++top] = i;
	}
	void pop(T &i) {
		i = stk[top--];
	}
	int empty() {
		return top == -1;
	}
	int getTop() {
		return top;
	}
	void display() {
		if (top >= 0) {
			for (int i = 0; i <= top; i++) {
				cout << stk[i] << " ";
			}
			cout << endl;
		} else {
			cout << "Stack is empty";
		}
	}
};
int priority(char c) {
	int rank = 0;
	if(c == '^') {
		rank = 3;
	} else if((c == '*') || (c == '/')) {
		rank = 2;
	} else if ((c == '+') || (c == '-')) {
		rank = 1;
	} else if (c == '(') {
		rank = 0;
	}
	return rank;
}

int main() {
	string aline;
	ifstream inData;
	stack<int> iStack;
	stack<char> cStack;
	stack<char> output;

	inData.open("input.txt");
	while (getline(inData, aline, ' ')) {
		if (isdigit(aline[0])) {
			output.push(aline[0]);
		} else if (aline.length() == 2) {
			if (aline[0] == '(') {
				cStack.push(aline[0]);
				iStack.push(aline[1]);
			} else if (aline[1] == ')') {
				iStack.push(aline[0]);
				int q = cStack.getTop();
				
			}
		}
		


		
		/*
		cout << aline.length() << " || ";
		if (aline.length() == 2) {
			if (aline[0] == '(') {
				cout << aline[1] << endl;
			} else if (aline[1] == ')') {
				cout << aline[0] << endl;
			}
		}
		else if(aline.length() == 4) {
			cout << aline << endl;
		}
		else if(aline.length() == 1) {
			cout << aline << endl;
		} */
	}
	inData.close();
	output.display();
	iStack.display();
}