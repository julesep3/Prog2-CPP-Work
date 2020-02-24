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
#include "istack.h"
#include "priority.h"
using namespace std;

int main()
{
	istack cstack;
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
					while (cstack.top() != '(')
					{
						cout << cstack.top();
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
					while (!cstack.empty() && (priority(s[i]) <= priority(cstack.top())))
					{
						cout << cstack.top();
						cstack.pop();
					}
					cstack.push(s[i]);
				}
			}
		}
		while (!cstack.empty())
		{
			cout << cstack.top();;
			cstack.pop();
		}
		if (s.length() > 1) {
			num++;
		}
		cout << endl;
	}
	inData.close();
}