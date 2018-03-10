#include <iostream>
#include "stack_cpp.h"


stack_cpp::stack_cpp(int cap): capacity(cap),length(0),top(0){
	elements = new int[cap];
}

stack_cpp::~stack_cpp() {
	delete[]elements;
}

void stack_cpp::clear() {
	length = 0;
	top = -1;
}

bool stack_cpp::empty() {
	return length == 0 ? true : false;
}

bool stack_cpp::full() {
	return length == capacity ? true : false;
}

bool stack_cpp::push(const int &ele) {
	if (full()) {
		return false;
	}
	elements[++top] = ele;
	length++;
	return true;
}

bool stack_cpp::pop() {
	if (empty()) {
		return false;
	}
	top--;
	length--;
	return true;
}

int stack_cpp::getTop() {
	if (!empty()) {
		return elements[top];
	}
	//if empty
	return -1;
}

int stack_cpp::size() {
	return length;
}




void test() {
	stack_cpp s(5);
	std::cout << "stack is empty:" << s.empty() << std::endl;
	for (int i = 0; i < 6; i++) {
		if (s.push(i))
			std::cout << "empty?" << s.empty() << ",  length:" << s.size() << ",  top:" << s.getTop() << std::endl;
	}

	std::cout << "stack is full:" << s.full() << std::endl;

	for (int i = 0; i < 6; i++) {
		if (s.pop()) {
			std::cout<<"empty?"<<s.empty() << ",  length:" << s.size() << ",  top:" << s.getTop() << std::endl;
		}
	}
}


int main() {
	test();
	return 0;
}