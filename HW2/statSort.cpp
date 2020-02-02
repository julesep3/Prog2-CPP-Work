/*
Julian Shen
Programming II
Due: 1 / 29 / 2020
Sorting Program
Bubble Sort, Shell Sort, Quick Sort, and a Main Program
*/

#include <iostream>
using namespace std;

void Bubble(int ar[], int n) {
    int swaps, i;
    swaps = 1;
    while (swaps) {
        swaps = 0;
        for (i = 0; i < n - 1; i++) {
            if (ar[i] > ar[i + 1]) {
                swap(ar[i], ar[i+1]);
                swaps = 1;
            }
        }
    }
}

#if __INCLUDE_LEVEL__ < 1
int main() {
    int i;
    int ar[153] = {84, 74, 52, 62, 54, 62, 52, 76, 54, 60, 72, 62, 62, 80, 80, 66, 64, 98, 44, 88, 70, 64, 74, 74, 54, 68, 56, 82, 74, 62, 64, 94, 56, 64, 60, 56, 68, 72, 82, 56, 80, 68, 88, 70, 54, 84, 72, 74, 64, 68, 62, 60, 82, 54, 60, 52, 104, 78, 88, 74, 72, 66, 50, 42, 74, 74, 76, 66, 68, 82, 66, 84, 62, 80, 62, 70, 80, 80, 74, 64, 52, 62, 68, 56, 72, 70, 66, 72, 68, 54, 80, 66, 68, 70, 68, 66, 58, 74, 60, 102, 76, 66, 88, 58, 80, 88, 70, 72, 92, 58, 66, 66, 66, 62, 62, 66, 58, 64, 58, 72, 58, 64, 82, 80, 72, 62, 76, 76, 78, 84, 72, 74, 58, 70, 66, 80, 80, 54, 78, 76, 68, 52, 72, 66, 68, 82, 74, 62, 72, 62, 94, 86, 92};
    int n = 153;
    for(i = 0; i < n; i++) {
        cout << ar[i] << ' ';
        if((i%10 == 0) && (i/10 != 0)) {
            cout << "\n";
        }
    }
    cout << endl;
    Bubble(ar, n);
    for(i = 0; i < n; i++) {
        cout << ar[i] << ' ';
        if((i%10 == 0) && (i/10 != 0)) {
            cout << "\n";
        }
    }
    cout << endl;
}

#endif