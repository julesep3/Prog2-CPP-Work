#pragma once

class stack {
private:
	class node {		
	public:
		int data;
		node* link;
		node(int); // data
	};
	node* ptop;
public:
	stack();
	~stack();
	void push(int);
	void pop();
	int top() const;
	bool empty() const;
	bool full() const;
};