/*
Julian Shen
Programming II
Due: 1 / 29 / 2020
Sorting Program
Bubble Sort, Shell Sort, Quick Sort, and a Main Program
*/

#include <iostream>
using namespace std;

int partition(int ar[], int l, int r)
{
	while (l < r)
	{
		while ((l < r) && (ar[l] <= ar[r]))
			r--;
		swap(ar[l], ar[r]);
		//cout << "L : " << ar[l] << endl;
		//cout << "R : " << ar[r] << endl;
		while ((l < r) && (ar[l] <= ar[r]))
			l++;
		swap(ar[l], ar[r]);
		//cout << "L : " << ar[l] << endl;
		//cout << "R : " << ar[r] << endl;
	}
	return l;
}

int stak[50];
int top = -1;

void pop(int &i)
{
	i = stak[top--];
	//cout << "POP: " << i << endl;
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

void Quick(int ar[], int x, int y)
{
	int l = ar[x];
	int r = ar[y];
	int n = y;
	push(l);
	push(r);

	while (!empty())
	{
		cout << "START START START START START START START START START START START START START START START START START START START START START START START START " << endl;
		cout << "Top is " << top << endl;
		cout << "YYYY is " << y << endl;
		/*
		for (int i = 0; i < 20; i++)
		{
			cout << ar[i] << ' ';
		}
		cout << endl; */
		pop(r);
		pop(l);
		//cout << "Top is " << top << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << stak[i] << ' ';
		}
		cout << endl;
// ======================================================================
		int pos = partition(ar, x, y);
		cout << "Position is " << pos << endl;
		//cout << "If 1 is " << (y - pos > 1) << endl;
		if (y - pos > 1)
		{
			int w = ar[pos + 1];
			push(w);
			push(r);
		}

		//cout << "If 2 is " << (pos - x > 1) << endl;
		if (pos - x > 1)
		{
			int w = ar[pos - 1];
			push(l);
			push(w);
		}
		
		y = pos - 1;


		cout << "X : " << x << " || Y : " << y << endl;
		if(y == x) {
			y = n;
			r = ar[y];
			cout << "YY is " << y << endl;
			x = pos + 1;
		}

		if ( x > y ) {
			y = n;
			x = pos + 1;
		}
		
		cout << "TOP is " << top << ".   Y is " << y << ".   X is " << x << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << ar[i] << ' ';
		}
		cout << endl;
	}
}

#if __INCLUDE_LEVEL__ < 1
int main()
{
	int i;
	int n = 20;
	int ar[n];
	for (i = 0; i < n; i++)
	{
		ar[i] = rand() % 100;
		cout << ar[i] << ' ';
	}
	cout << endl;
	Quick(ar, 0, n - 1);
	cout << "Final Stak : " << endl;
	for (i = 0; i < n; i++)
	{
		cout << ar[i] << ' ';
	}
	cout << endl;
}

#endif