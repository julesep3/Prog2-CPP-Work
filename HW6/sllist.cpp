#include "sllist.h"
#include <iostream>
#include <cassert>
using namespace std;

sllist::sllist()
 : head(nullptr), tail(nullptr), count(0)
 {}

sllist::~sllist() {
	// free all nodes
}

int sllist::size() const {
	return count;
}

void sllist::append(string data, int rank) {
	node* p = new node(data, rank);
	if (count == 0) {
		//empty list
		head = tail = p;
	} else {
		tail->link = p;
		tail = p;
	}
	++count;
}

string sllist::get(int pos) const {
	assert(0 <= pos && pos < count);
	node* n = head;
	for (int i = 0; i < pos; i++) {
		n = n->link;
	}
	return n->data;
}

int sllist::getRank(int pos) {
	assert(0 <= pos && pos < count);
	node* e = head;
	for (int j = 0; j < pos; j++) {
		e = e->link;
	}
	return e->rank;
}

void sllist::insert(int pos, string data, int rank) {
	assert(0 <= pos && pos <= count);
	if (pos == count || count == 0) {
		append(data, rank);
	} else if (pos == 0) {
		// push of stack
		node* p = new node(data, rank);
		p->link = head;
		head = p;
		++count;
	} else { // insert between two nodes
		node* p = new node(data, rank);
		node* left = head;
		for (int i = 0; i < pos-1; i++) {
			left = left->link;
		}
		//node* right = left->link;
		// left ==> p ==> right
		p->link = left->link;
		left->link = p;
		++count;
	}
}

void sllist::remove(int pos) {
	assert(0 <= pos && pos < count);
	if (count == 1) {
		delete head;
		head = tail = nullptr;
	} else if (pos == 0) {
		// pop of stack
		node* discard = head;
		head = head->link;
		delete discard;
	} else if (0 < pos && pos < count - 1) {
		// between two nodes
		node* left = head;
		for (int i = 0; i < pos - 1; i++) {
			left = left->link;
		}
		node* discard = left->link;
		// node* right = left->link->link;
		left->link = left->link->link;
		delete discard;
	} else {
		// tail node
		node* left = head;
		for (int i = 0; i < count - 2; i++) {
			left = left->link;
		}
		delete tail;
		left->link = nullptr;
		tail = left;
	}

	--count;
}

int sllist::index_of(string data) const {
	assert(count > 0);
	node* n = head;
	int pos = 0;

	while (n != nullptr) {
		if (n->data == data) break;
		++pos;
		n = n->link;
	}
	if (n == nullptr) return -1; // not found
	return pos;
}