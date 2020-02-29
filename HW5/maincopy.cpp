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
	stack<int> estack;
	fstream inData;
	inData.open("input.txt");
	string s;
	int inputNum = 1;
	while (getline(inData, s))
	{
		if (s.length() > 1)
		{
			cout << inputNum << ":   " << s << endl
				 << "     ";
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
		// end of converting infix to postfix
		int result;
		int t = output.top;
		output.top = 0;
		for (int r = 0; r <= t; r++)
		{
			char token = output.onTop();
			if (isdigit(token))
			{
				int p = token - '0';
				estack.push(p);
				//cout << "E Stack : " << estack.onTop() << endl;
			}
			else
			{
				int opn2 = estack.onTop();
				estack.pop();
				int opn1 = estack.onTop();
				estack.pop();
				cout << endl << "OPN1 : " << opn1 << ". OPN2 : " << opn2 << ". TOKEN : " << token << endl;;
				result = evaluate(opn1, token, opn2);
				cout << result;
				estack.push(result);
				
			}
			output.top++;
		}
		output.popAll();
		if (s.length() > 1)
		{
			inputNum++;
		}
	}
	inData.close();
}