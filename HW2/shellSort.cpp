/*
Julian Shen
Programming II
Due: 1 / 29 / 2020
Sorting Program
Bubble Sort, Shell Sort, Quick Sort, and a Main Program
*/

#include <iostream>
using namespace std;

int sCost = 0;

int Shell(int ar[], int n) {
    int gap = n / 2;
    int swaps, i;
    while(gap > 0) {
        swaps = 1;
        while(swaps) {
            swaps = 0;
            for(i = 0; i < n - gap; i++) {
                if(ar[i] > ar[i + gap]) {
                    swap(ar[i], ar[i + gap]);
                    swaps = 1;
                    sCost += 6;
                }
                sCost++;
            }
            
        }
        gap = gap / 2;
    }
    return sCost;
}

#if __INCLUDE_LEVEL__ < 1
int main() {
    int i;
    int ar[20];
    int n = 20;
    for(i = 0; i < n; i++) {
        ar[i] = rand()%100;
        cout << ar[i] << ' ';
    }
    cout << endl;
    int shellCost = Shell(ar, n);
    for(i = 0; i < n; i++) {
        cout << ar[i] << ' ';
    }
    cout << endl;
    cout << "Shellsort costs " << shellCost << endl;

}

#endif