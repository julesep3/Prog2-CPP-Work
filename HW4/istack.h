#pragma once

class istack {
private:
	class node {		
	public:
		char data;
		node* link;
		node(char); // data
	};
	node* ptop;
public:
	istack();
	~istack();
	void push(char);
	void pop();
	char top() const;
	bool empty() const;
};