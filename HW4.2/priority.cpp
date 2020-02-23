#include <iostream>
#include "priority.h"

using namespace std;

int priority(char e)
{
	int q = 0;
	if (e == '^') {
		q = 3;
	} else if (e == '*' || e == '/') {
		q = 2;
	} else if (e == '+' || e == '-') {
		q = 1;
	} else if (e == '(') {
		q = 0;
	}
	return q;
}