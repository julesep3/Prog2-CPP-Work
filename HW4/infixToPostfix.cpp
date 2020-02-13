#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string aline;
	ifstream inData;

	inData.open("infix.data");

	while (getline(inData, aline)) {
		cout << aline << endl;
	}

	inData.close();
}