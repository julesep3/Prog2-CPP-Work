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
		/*
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i] << "|";
		}
		cout << endl;*/

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
		cout << pos << " | " << tempData << endl;
		// insert into list
		if (list.size() == 0)
		{
			list.append(tempData, pos);
			cout << list.getRank(0) << "|" << list.get(0) << "|" << list.size() << endl;
		}
		else if (list.size() == 1)
		{
			//cout << list.getRank(0) << " HEY " << pos << " HEY " << list.size() << endl;
			if (list.getRank(0) < pos)
			{
				list.append(tempData, pos);
			}
			else
			{
				list.insert(0, tempData, pos);
			}
			cout << list.getRank(1) << "||" << list.get(1) << "||" << list.size() << endl;
		}
		else if (list.size() >= 2)
		{
			for (int m = 0; m < list.size(); m++)
			{
				cout << m << "===============================" << list.size() << endl;
				cout << "Compare " << list.getRank(m) << " to " << pos << endl;
				if (list.getRank(m) > pos)
				{
					cout << "HIT CASE 1" << endl;
					//list.insert(0, tempData, pos);					
				}
				else if ((list.getRank(m) < pos) && (list.getRank(m + 1) < pos))
				{
					cout << "HIT CASE 2" << endl;
				}
				else if ((list.getRank(m) < pos) && (list.getRank(m + 1) > pos))
				{
					cout << "HIT CASE 3" << endl;
					//list.insert(m + 1, tempData, pos);
				}
				else {
					cout << "HIT CASE 4" << endl;
				}
			}
		}
	}
	inData.close();
}