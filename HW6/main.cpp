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
	sllist list;
	fstream inData;
	inData.open("input.txt");
	string s, tempPosition, tempData;
	int pos = 0;
	while (getline(inData, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i] << "|";
		}
		cout << endl;

		tempPosition = ""; // reset tempPosition before reading each line
		tempData = "";	 // reset tempData before reading each line
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ' && tempPosition == "")
			{
				continue;
			}
			else if (isdigit(s[i]))
			{
				tempPosition += s[i];
			}
			else if (!isdigit(s[i]) || s[i] == ' ')
			{
				if (i == s.length() - 1)
					break;
				if (s[i] == '+')
					continue;
				if (s[i] == '=')
				{
					tempData += '\n';
					continue;
				}
				tempData += s[i];
			}
		}
		pos = stoi(tempPosition);
		//list.insert(pos, tempData);
	}
	inData.close();
}