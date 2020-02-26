#include <iostream>
#include "evaluate.h"
#include <cmath>

using namespace std;

int priority(char e)
{
	int q = 0;
	if (e == '^')
	{
		q = 3;
	}
	else if (e == '*' || e == '/')
	{
		q = 2;
	}
	else if (e == '+' || e == '-')
	{
		q = 1;
	}
	else if (e == '(')
	{
		q = 0;
	}
	return q;
}

int evaluate(int opn1, char token, int opn2)
{
	int result = 0;
	switch (token)
	{
		case '+' : result = opn1 + opn2;
		case '-' : result = opn1 - opn2;
		case '*' : result = opn1 * opn2;
		case '/' : result = opn1 / opn2;
		case '^' : result = pow(opn1, opn2);
	}
	return result;
}