#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int evaluate(int opn1, char token, int opn2)
{
	int result = 0;
	switch (token)
	{
	case '+':
		result = opn1 + opn2;
		return result;
		break;
	case '-':
		result = opn1 - opn2;
		return result;
		break;
	case '*':
		result = opn1 * opn2;
		return result;
		break;
	case '/':
		result = opn1 / opn2;
		return result;
		break;
	case '^':
		result = pow(opn1, opn2);
		return result;
		break;
	}
	cout << result;
	return result;
}

int main()
{
	int xx = 3;
	int yy = 5;
	char zz = '*';
	int z = evaluate(xx, zz, yy);
	cout << z;

	//cout << x - y << endl;
}