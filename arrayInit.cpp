#include <iostream>
using namespace std;

void arrayInit() {
	int i;
    int ar[20];
    int n = 20;
    for(i = 0; i < n; i++) {
        ar[i] = rand()%100;
        cout << ar[i] << ' ';
    }
    cout << endl;
}

#if __INCLUDE_LEVEL__ < 1
int main() {
	arrayInit();
}
#endif