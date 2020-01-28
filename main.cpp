#include <iostream>
#include "bubbleSort.cpp"
#include "shellSort.cpp"
#include "quickSort.cpp"
using namespace std;

int main()
{
	// Original Array Initialization
	int i;
	int n = 20;
	int ar[n];
	cout << "Original Array: " << endl;
	for (i = 0; i < n; i++)
	{
		ar[i] = rand() % 100;
		cout << ar[i] << ' ';
	}
	cout << endl
		 << endl;

	// Bubble Sort Procedure
	int arBubble[n];
	cout << "Bubble Sort" << endl;
	
	for (i = 0; i < n; i++)
	{
		arBubble[i] = ar[i];
		cout << arBubble[i] << ' ';
	}
	cout << endl;
	int bubbleCost = Bubble(arBubble, n);
	for (i = 0; i < n; i++)
	{
		cout << arBubble[i] << ' ';
	}
	cout << endl;
	cout << "Bubblesort costs " << bubbleCost << endl
		 << endl;

	// Shell Sort Procedure
	int arShell[n];
	cout << "Shell Sort" << endl;
	for (i = 0; i < n; i++)
	{
		arShell[i] = ar[i];
		cout << arShell[i] << ' ';
	}
	cout << endl;
	int shellCost = Shell(arShell, n);
	for (i = 0; i < n; i++)
	{
		cout << arShell[i] << ' ';
	}
	cout << endl;
	cout << "Shellsort costs " << shellCost << endl
		 << endl;

	// Quick Sort Procedure
	int arQuick[n];
	cout << "Quick Sort" << endl;
	for (i = 0; i < n; i++)
	{
		arQuick[i] = ar[i];
		cout << arQuick[i] << ' ';
	}
	cout << endl;
	int cost = Quick(arQuick, n);
	for (i = 0; i < n; i++)
	{
		cout << arQuick[i] << ' ';
	}
	cout << endl;
	cout << "Quicksort costs " << cost << endl;
}