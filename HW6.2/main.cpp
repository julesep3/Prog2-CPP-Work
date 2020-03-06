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
using namespace std;

struct Node {
	string data;
	Node* next;
	int order;
};

int main()
{
	Node* p, tail, head;
	fstream inData;
	inData.open("input.txt");
	string s;
	string tempstring;
	while (getline(inData, s))
	{
		p = new Node;
		tempstring = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				if (isdigit(s[i]))
				{
					tempstring += s[i];
				}
				if (!isdigit(s[i])) 
				{
					cout << "NOT DIGIT" << endl;
					break;
				}
			}
		}
		cout << tempstring << endl;

		p->data = s;
		p->next = NULL;
		tail = head;
		

		delete p;
	}
	inData.close();
}