#include <iostream>
#include <cassert>
using namespace std;
#include "istack.h"

istack::node::node(char d)
 : data(d), link(nullptr) {
}

istack::istack() : ptop(nullptr) {
}

istack::~istack() {
	while (!empty()) {
		pop();
	}
}

void istack::push(char data) {
	node* new_node = new node(data);

	if(ptop == nullptr) {
		ptop = new_node;
	} else {
		new_node->link = ptop;
		ptop = new_node;
	}
}

void istack::pop() {
	assert(!empty());
	// one node data only
	if (ptop->link == nullptr) {
		// one node only
		delete ptop;
		ptop = nullptr;
	} else {
		node* discard = ptop;
		ptop = ptop->link; // bypass top of the stack
		delete discard;
	}
}

bool istack::empty() const {
	return ptop == nullptr;
}

char istack::top() const {
	assert(!empty());
	return ptop->data;
}
