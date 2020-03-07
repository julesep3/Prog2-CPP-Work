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
	void append(int);
	int size() const;
	int get(int) const;
	void insert(int, int); // pos, data
	void remove(int); // pos
	int index_of(int) const; // 1st occurence of data
};