/*
Julian Shen
Programming II
Due: 02 / 28 / 2020
HW5 - Infix to Postfix with evaluation
 - Convert file input from infix to postfix expression, 
    then evaluate and print solution
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
	stack<char> output;
	fstream inData;
	inData.open("input.txt");
	string s;
	int inputNum = 1;
	while (getline(inData, s))
	{
		if (s.length() > 1) {
			cout << inputNum << ":   "<< s << endl << "     ";
		}

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				if (isdigit(s[i]))
				{
					output.push(s[i]);
				}
				else if (s[i] == '(')
				{
					cstack.push(s[i]);
				}
				else if (s[i] == ')')
				{
					while (cstack.onTop() != '(')
					{
						output.push(cstack.onTop());
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
						output.push(cstack.onTop());
						cstack.pop();
					}
					cstack.push(s[i]);
				}
			}
		}
		while (!cstack.empty())
		{
			output.push(cstack.onTop());
			cstack.pop();
		}
		output.display();
		output.popAll();
		if (s.length() > 1) {
			inputNum++;
		}
	}
	inData.close();
}