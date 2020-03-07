#pragma once
#include <iostream>
using namespace std;

class node {
private:
	string data;
	int rank;
	node* link;
public:
	node(string, int);

	friend class sllist;
};