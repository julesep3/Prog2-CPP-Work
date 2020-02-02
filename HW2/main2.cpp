#include <iostream>
#include "arrayInit.cpp"
#include "arrayCopy.cpp"
#include "bubbleSort.cpp"
#include "shellSort.cpp"
using namespace std;

int main() {
	// Original Array Initialization
	int i;
    int n = 20;
    arrayInit();

	// Bubble Sort Procedure
	int arBubble[20];
	for(i = 0; i < n; i++) {
		arBubble[i] = ar[i];
		cout << arBubble[i] << ' ';
	}
	cout << endl;
	Bubble(arBubble, n);
    for(i = 0; i < n; i++) {
        cout << arBubble[i] << ' ';
    }
    cout << endl;

	// Shell Sort Procedure
	int arShell[20];
	for(i = 0; i < n; i++) {
		arShell[i] = ar[i];
		cout << arShell[i] << ' ';
	}
	cout << endl;
	Shell(arShell, n);
	for(i = 0; i < n; i++) {
        cout << arShell[i] << ' ';
    }
    cout << endl;
	




}