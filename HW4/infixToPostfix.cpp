#include <iostream>
#include <fstream>
#include <string>
#include "istack.h"
#include <cassert>
#include <cctype>
#include <locale>
using namespace std;
/*
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
};*/

int main()
{
	//stack<int> intstack;
	//stack<char> charstack;

	istack<int> intstack;
	//assert(intstack.empty());
	//assert(!intstack.full());
	//istack<char> charstack;
	string s;
	string output = "";
	ifstream inData;

	inData.open("input.txt");

	while (getline(inData, s, ' '))
	{
		cout << "This is S : " << s.length() << endl;
		cout << "s[0] is " << s[0] << endl;
		if (isdigit(s[0]))
		{
			output = output + s[0];
		}
		else if (s[0] == '(')
		{
			if (isdigit(s[1]))
			{
				output = output + s[1];
			}
		}
		if (s[1] == '\n')
		{
			cout << "END OF LINE" << endl;
			cout << "Output is : " << output << endl;
			output = "";
		}
		cout << "Output is : " << output << endl;
		cout << "==========================" << endl;
	}

	inData.close();
}
/*
if (s[1] == '\n') {
	cout << "This is S : " << s.length() << endl;
	output = "";
}
*/