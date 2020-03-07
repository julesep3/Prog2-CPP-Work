/*
Julian Shen
Programming II
Due: 03 / 09 / 2020
HW6 - UDP Packet Recombination
Read input packet, put packets in order, print total message
*/

#include <iostream>
#include <string>
#include <fstream>
#include "sllist.h"
using namespace std;

int main()
{
	sllist cstack;
	fstream inData;
	inData.open("input.txt");
	string s, tempPosition;
	int positionSet = 0;
	while (getline(inData, s))
	{
		for (int i = 0; i < s.length(); i++) {
			cout << s[i] << "|";
		}
		cout << endl;
		tempPosition = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				//if (isdigit(s[i-1])) break;
				if (isdigit(s[i]))
				{
					tempPosition += s[i];
				}
				if (!isdigit(s[i])) 
				{
					cout << "NOT DIGIT";
					cout << " || i = " << i << endl;
					break;
				}
			}
		}
		cout << tempPosition << endl;
	}
	inData.close();
}