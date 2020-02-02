#include <iostream>
#include "bubbleSort.cpp"
#include "shellSort.cpp"
#include "quickSort.cpp"
using namespace std;

int main()
{
	//  Generate 20 random numbers.
	//  Print the random numbers.
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


	// Bubble Sort Procedure =====================================
	int arBubble[n];
	cout << "Bubble Sort" << endl;
	//   Move the original random numbers into another array.
	for (i = 0; i < n; i++)
	{
		arBubble[i] = ar[i];
		cout << arBubble[i] << ' ';
	}
	cout << endl;
	//   Bubble Sort the other array.
	int bubbleCost = Bubble(arBubble, n);
	// Print the sorted numbers AND the cost of sorting the numbers.
	for (i = 0; i < n; i++)
	{
		cout << arBubble[i] << ' ';
	}
	cout << endl;
	cout << "Bubblesort costs " << bubbleCost << endl
		 << endl;

	// Shell Sort Procedure =========================================
	int arShell[n];
	cout << "Shell Sort" << endl;
	//  Move the original random numbers into another array.
	for (i = 0; i < n; i++)
	{
		arShell[i] = ar[i];
		cout << arShell[i] << ' ';
	}
	cout << endl;
	//  Shell Sort the other array.
	int shellCost = Shell(arShell, n);
	//  Print the sorted numbers AND the cost of sorting the numbers. 
	for (i = 0; i < n; i++)
	{
		cout << arShell[i] << ' ';
	}
	cout << endl;
	cout << "Shellsort costs " << shellCost << endl
		 << endl;

	// Quick Sort Procedure ========================================
	int arQuick[n];
	cout << "Quick Sort" << endl;
	//  Move the original random numbers into another array.
	for (i = 0; i < n; i++)
	{
		arQuick[i] = ar[i];
		cout << arQuick[i] << ' ';
	}
	cout << endl;
	//  Quick Sort the other array.
	int cost = Quick(arQuick, n);
	//  Print the sorted numbers AND the cost of sorting the numbers. 
	for (i = 0; i < n; i++)
	{
		cout << arQuick[i] << ' ';
	}
	cout << endl;
	cout << "Quicksort costs " << cost << endl;
}