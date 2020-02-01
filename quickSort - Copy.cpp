/*
Julian Shen
Programming II
Due: 1 / 29 / 2020
Sorting Program
Bubble Sort, Shell Sort, Quick Sort, and a Main Program
*/

#include <iostream>
using namespace std;

int qCost = 0;

int partition(int ar[], int l, int r)
{
	while (l < r)
	{
		while ((l < r) && (ar[l] <= ar[r]))
		{
			r--;
			qCost += 1;
		}
		swap(ar[l], ar[r]);
		qCost += 6;
		while ((l < r) && (ar[l] <= ar[r]))
		{
			l++;
			qCost += 1;
		}
		swap(ar[l], ar[r]);
		qCost += 6;
	}
	return l;
}

int top = -1;
int stak[20];

void pop(int &i)
{
	i = stak[top--];
}

int empty()
{
	return top == -1;
}

void push(int i)
{
	top++;
	stak[top] = i;
}

int Quick(int ar[], int n)
{
	int l, r;
	push(0);
	push(n - 1);

	while (!empty())
	{
		pop(r);
		pop(l);
		int pos = partition(ar, l, r);
		if ((r - pos) > 1)
		{
			push(pos + 1);
			push(r);
		}
		if (pos - l > 1)
		{
			push(l);
			push(pos - 1);
		}
	}
	return qCost;
}

#if __INCLUDE_LEVEL__ < 1
int main()
{
	int i;
	int ar[20];
	int n = 20;
	for (i = 0; i < n; i++)
	{
		ar[i] = rand() % 100;
		cout << ar[i] << " ";
	}
	cout << endl;
	Quick(ar, n);
	for (i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
#endif
