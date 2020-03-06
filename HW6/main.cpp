/*
Julian Shen
Programming II
Due: 03 / 09 / 2020
UDP Packet Recombination
Read input packet, put packets in order, print total message
*/

#include <iostream>
#include <string>
#include <fstream>
#include "istack.h"
using namespace std;

int main()
{
	istack cstack;
	fstream inData;
	inData.open("input.txt");
	string s;
	while (getline(inData, s))
	{
		for (int i = 0; i < s.length(); i++) {
			cout << s[i] << "|";
		}
		cout << endl;
	}
	inData.close();
}