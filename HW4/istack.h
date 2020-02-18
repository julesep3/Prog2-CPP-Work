#pragma once

template <class T>
class istack {
private:
	class node {		
	public:
		T data;
		node* link;
		node(T); // data
	};
	node* ptop;
public:
	istack();
	~istack();
	void push(T);
	void pop();
	int top() const;
	bool empty() const;
	bool full() const;
};