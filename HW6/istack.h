#pragma once
#include <string>

class istack {
private:
	class node {		
	public:
		string data;
		node* link;
		node(string); // data
	};
	node* ptop;
public:
	istack();
	~istack();
	void push(string);
	void pop();
	string top() const;
	bool empty() const;
};