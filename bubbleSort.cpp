/*
Julian Shen
Programming II
Due: 1 / 29 / 2020
Sorting Program
Bubble Sort, Shell Sort, Quick Sort, and a Main Program
*/

#include <iostream>
using namespace std;

int bCost = 0;

int Bubble(int ar[], int n) {
    int swaps, i;
    swaps = 1;
    while (swaps) {
        swaps = 0;
        for (i = 0; i < n - 1; i++) {
            if (ar[i] > ar[i + 1]) {
                swap(ar[i], ar[i+1]);
                swaps = 1;
                bCost = bCost + 6;
            }
            bCost = bCost + 1;
        }
    }
    return bCost;
}

#if __INCLUDE_LEVEL__ < 1
int main() {
    int i;
    int n = 20;
    int ar[n];
    for(i = 0; i < n; i++) {
        ar[i] = rand()%100;
        cout << ar[i] << ' ';
    }
    cout << endl;
    int bubbleCost = Bubble(ar, n);
    for(i = 0; i < n; i++) {
        cout << ar[i] << ' ';
    }
    cout << endl;
    cout << "Bubblesort costs " << bubbleCost << endl;

}

#endif