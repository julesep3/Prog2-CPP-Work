
#include <iostream>
#include <cassert>
using namespace std;
#include "stack.h"

stack::node::node(int d)
 : data(d), link(nullptr) {
}

stack::stack() : ptop(nullptr) {
}

stack::~stack() {
	while (!empty()) {
		pop();
	}
}

void stack::push(int data) {
	node* new_node = new node(data);

	if(ptop == nullptr) {
		ptop = new_node;
	} else {
		new_node->link = ptop;
		ptop = new_node;
	}
}

void stack::pop() {
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

bool stack::empty() const {
	return ptop == nullptr;
}

bool stack::full() const {
	return false;
}

int stack::top() const {
	assert(!empty());
	return ptop->data;
}