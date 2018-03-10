#pragma once


class stack_cpp {
public:
	stack_cpp(int cap);
	~stack_cpp();

	void clear();
	bool empty();
	bool full();
	bool push(const int &ele);
	bool pop();
	int getTop();
	int size();



private:
	int *elements;
	int capacity;
	int length;
	int top;
};


void test();