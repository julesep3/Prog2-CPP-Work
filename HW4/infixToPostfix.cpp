#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string s;
	ifstream inData;

	inData.open("input.txt");

	while (getline(inData, s)) {
		cout << s << endl;
	}

	inData.close();
}