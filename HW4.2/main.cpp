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
#include "astack.h"
#include "priority.h"
using namespace std;

int main()
{
	astack output;
	astack cstack;
	fstream inData;
	inData.open("input.txt");
	string s;
	while (getline(inData, s))
	{
		cout << s << endl;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				if (isdigit(s[i]))
				{
					//output.push(s[i]);
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
						char x = cstack.onTop();
						//output.push(x);
						cout << x;
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
						char y = cstack.onTop();
						//output.push(y);
						cout << y;
						cstack.pop();
					}
					cstack.push(s[i]);
				}
			}
		}
		while (!cstack.empty())
		{
			char z = cstack.onTop();
			//output.push(z);
			cout << z;
			cstack.pop();
		}
	}
	//output.display();

	inData.close();
}