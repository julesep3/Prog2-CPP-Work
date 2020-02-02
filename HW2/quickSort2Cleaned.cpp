/*
Julian Shen
Programming II
Due: 1 / 29 / 2020
Sorting Program
Bubble Sort, Shell Sort, Quick Sort, and a Main Program
*/

#include <iostream>
using namespace std;

int stak[50];
int top = -1;
int qCost = 0;

int partition(int ar[], int l, int r)
{
	while (l < r)
	{
		while ((l < r) && (ar[l] <= ar[r])) {
           	r--; 
            qCost += 1;
        }
		swap(ar[l], ar[r]);
        qCost += 6;
		while ((l < r) && (ar[l] <= ar[r])) {
            l++;
            qCost += 1;
        }
		swap(ar[l], ar[r]);
        qCost += 6;
	}
	return l;
}

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
    int x = 0;
    n--;
    int y = n;

	int l = ar[x];
	int r = ar[y];
	push(l);
	push(r);

	while (!empty())
	{
		pop(r);
		pop(l);
		int pos = partition(ar, x, y);
		if (y - pos > 1)
		{
			int w = ar[pos + 1];
			push(w);
			push(r);
		}
		if (pos - x > 1)
		{
			int w = ar[pos - 1];
			push(l);
			push(w);
		}
		y = pos - 1;
		if(y == x) {
			y = n;
			r = ar[y];
			x = pos + 1;
		}
		if ( x > y ) {
			y = n;
			x = pos + 1;
		}
	}
    return qCost;
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
	int quickCost = Quick(ar, n);
	cout << "Final Stak : " << endl;
	for (i = 0; i < n; i++)
	{
		cout << ar[i] << ' ';
	}
	cout << endl;
    cout << "Quicksort costs: " << quickCost << endl;
}

#endif