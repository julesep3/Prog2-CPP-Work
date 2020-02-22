/*
Julian Shen
Programming II
Due: 02 / 21 / 2020
Infix to Postfix
Take input, convert into postfix
*/

#include <iostream>
//#include <istream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
struct stack
{
	T stk[50];
	int top = -1;
	void push(T i)
	{
		stk[++top] = i;
	}
	void pop(T &i)
	{
		i = stk[top--];
	}
	int empty()
	{
		return top == -1;
	}
	T getTop()
	{
		return stk[top];
	}
	void display()
	{
		if (top >= 0)
		{
			for (int i = top; i >= 0; i--)
			{
				cout << stk[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "Stack is empty" << endl;
			;
		}
	}
};
int priority(char c)
{
	int rank = 0;
	if (c == '^')
	{
		rank = 3;
	}
	else if ((c == '*') || (c == '/'))
	{
		rank = 2;
	}
	else if ((c == '+') || (c == '-'))
	{
		rank = 1;
	}
	else if (c == '(')
	{
		rank = 0;
	}
	return rank;
}

int main()
{
	string aline, s;
	int i = 0;
	fstream inData;
	//stack<int> iStack;
	//stack<char> cStack;
	//stack<char> output;

	int sLength;

	inData.open("input.txt");
	while (getline(inData, aline, '\n'))
	{

		for(i = 0; i < aline.length(); i++) {
			cout << " " << aline[i] << "|";
		}
		cout << endl;
		
	}
	//cout << endl << aline[13];
	inData.close();

	
	//output.display();
	//iStack.display();
	//cStack.display();








/*
		sLength = aline.length();
		for(int i = 0; i < sLength; i++) {
			if(aline[i] == ' ') {
				i++;
			}
			cout << aline[i] << " ";
		}
		cout << endl;
		*/

	/*
	while (getline(aline, bline, '\n'))
		{
			cout << aline.length() << " || ";
			if (aline.length() == 2)
			{
				if (aline[0] == '(')
				{
					cout << aline[1] << endl;
				}
				else if (aline[1] == ')')
				{
					cout << aline[0] << endl;
		
			}
			else if (aline.length() == 4)
			{
				cout << aline << endl;
			}
			else if (aline.length() == 1)
			{
				cout << aline << endl;
			}
		}
	*/
}
