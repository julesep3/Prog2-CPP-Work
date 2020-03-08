/*
Julian Shen
Programming II
Due: 03 / 09 / 2020
Read input packet, put packets in order, print total message
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Node
{
	string data;
	Node *next;
	Node *prev;
	int rank;
};

Node *stk[20];
int top = -1;
void push(Node *t) { stk[++top] = t; }
Node *pop() { return stk[top--]; }
int empty() { return top == -1; }
string getData(int pos) { return stk[pos]->data; }
int getRank(int pos) { return stk[pos]->rank; }

void forward_traverse(Node *head)
{
	Node *p = head;
	while (p)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

Node *partition(Node *head, Node *tail)
{
	Node *l = head;
	Node *r = tail;
	while (l != r)
	{
		while (l != r && l->rank <= r->rank)
			r = r->prev;
		swap(l->rank, r->rank);
		swap(l->data, r->data);
		while (l != r && l->rank <= r->rank)
			l = l->next;
		swap(l->rank, r->rank);
		swap(l->data, r->data);
	}
	return l;
}

void quicksort(Node *head, Node *tail)
{
	Node *l;
	Node *r;
	push(tail);
	push(head);
	while (!empty())
	{
		l = pop();
		r = pop();
		Node *t = partition(l, r);
		if (l != t)
		{
			push(t->prev);
			push(l);
		}
		if (r != t)
		{
			push(r), push(t->next);
		}
	}
}

int main()
{
	Node *tail = NULL, *head = NULL, *p;
	fstream inData;
	inData.open("input.txt");
	string s, tempPosition, tempData;
	int pos = 0;
	int count = 1;
	while (getline(inData, s))
	{
		tempPosition = "";					 // reset tempPosition before reading each line
		tempData = "";						 // reset tempData before reading each line
		for (int i = 0; i < s.length(); i++) // collect rank and data from string
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
		// Create Node, assign values, sort
		p = new Node;
		p->rank = pos;
		p->data = tempData;
		p->prev = p->next = NULL;
		if (!head)
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			p->prev = tail;
			tail = p;
		}
		quicksort(head, tail);
		// print out available ordered data
		Node *j = head;
		while (j->rank == count)
		{
			cout << j->data;
			j = j->next;
			head = j;
			count++;
		}
		//cout << endl << count << endl;
	}

	inData.close();
}