#include <iostream>
using namespace std;

void arrayCopy(int arOrig[], int arCopy[], int n) {
	for(int i = 0; i < n; i++) {
			arCopy[i] = arOrig[i];
			cout << arCopy[i] << ' ';
		}
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
	
	int arExample[20];
	arrayCopy(ar, arExample, n);

}
#endif