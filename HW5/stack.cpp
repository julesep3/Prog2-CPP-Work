template<typename T>
struct stack {
	T stk[50];
	int top = -1;
	void push(T i) {
		stk[++top] = i;
	}
	void pop() {
		top--;
	}
	int empty() {
		return top == -1;
	}
	T onTop() {
		return stk[top];
	}
};