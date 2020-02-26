/*
Julian Shen
Programming II
Due: 02 / 21 / 2020
Infix to Postfix
Convert file input from infix to postfix expression
*/

#include <iostream>
#include <string>
#include <fstream>
#include "stack.cpp"
#include "evaluate.h"
using namespace std;

int main()
{
	stack<char> cstack;
	fstream inData;
	inData.open("input.txt");
	string s;
	int num = 1;
	while (getline(inData, s))
	{
		if (s.length() > 1) {
			cout << num << ":   "<< s << endl << "     ";
		}

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				if (isdigit(s[i]))
				{
					cout << s[i];
				}
				else if (s[i] == '(')
				{
					cstack.push(s[i]);
				}
				else if (s[i] == ')')
				{
					while (cstack.onTop() != '(')
					{
						cout << cstack.onTop();
						cstack.pop();
					}
					cstack.pop();
				}
				else if (cstack.empty())
				{
					cstack.push(s[i]);
				}
				else
				{
					while (!cstack.empty() && (priority(s[i]) <= priority(cstack.onTop())))
					{
						cout << cstack.onTop();
						cstack.pop();
					}
					cstack.push(s[i]);
				}
			}
		}
		while (!cstack.empty())
		{
			cout << cstack.onTop();;
			cstack.pop();
		}
		if (s.length() > 1) {
			num++;
		}
		cout << endl;
	}
	inData.close();
}