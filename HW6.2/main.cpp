/*
Julian Shen
Programming II
Due: 03 / 09 / 2020
CRead input packet, put packets in order, print total message
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Node {
	string data;
	Node* next;
	Node* prev;
	string order;
};

struct Stack {
	Node* stack[100];
	int top = -1;
	void push(Node* t) 
	{
		stack[++top] = t;
	};
	Node* pop() 
	{
		return stack[top--];
	};
	int empty()
	{
		return top == -1;
	}
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
				else if (!isdigit(s[i])) 
				{
					cout << "NOT DIGIT";
					cout << " || i = " << i << endl;
					break;
				}
			}
		}
		cout << tempstring << endl;

		p->data = s;
		p->next = NULL;
		p->prev = NULL;
		

		delete p;
	}
	inData.close();
}