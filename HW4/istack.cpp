#include <iostream>
#include <cassert>
using namespace std;
#include "istack.h"

template <class T>
istack<T>::node::node(T d)
 : data(d), link(nullptr) {
}
template <class T>
istack<T>::istack() : ptop(nullptr) {
}
template <class T>
istack<T>::~istack() {
	while (!empty()) {
		pop();
	}
}
template <class T>
void istack<T>::push(T data) {
	node* new_node = new node(data);

	if(ptop == nullptr) {
		ptop = new_node;
	} else {
		new_node->link = ptop;
		ptop = new_node;
	}
}
template <class T>
void istack<T>::pop() {
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
template <class T>
bool istack<T>::empty() const {
	return ptop == nullptr;
}
template <class T>
bool istack<T>::full() const {
	return false;
}
template <class T>
int istack<T>::top() const {
	assert(!empty());
	return ptop->data;
}