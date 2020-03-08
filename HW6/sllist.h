#pragma once
#include "node.h"

class sllist {
private:
	node* head;
	node* tail;
	int count;
public:
	sllist();
	~sllist();
	void append(string, int);
	int size() const;
	string get(int) const;
	int getRank(int);
	void insert(int, string, int); // pos, data
	void remove(int); // pos
	int index_of(string) const; // 1st occurence of data
};