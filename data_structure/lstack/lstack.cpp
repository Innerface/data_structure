#include "lstack.h"



lx::stack_cpp::stack_cpp(int cap): capacity(cap),length(0),top(0){
	elements = new int[cap];
}

lx::stack_cpp::~stack_cpp() {
	delete[]elements;
}

void lx::stack_cpp::clear() {
	length = 0;
	top = -1;
}

bool lx::stack_cpp::empty() {
	return length == 0 ? true : false;
}

bool lx::stack_cpp::full() {
	return length == capacity ? true : false;
}

bool lx::stack_cpp::push(const int &ele) {
	if (full()) {
		return false;
	}
	elements[top++] = ele;
	length++;
	return true;
}

bool lx::stack_cpp::pop() {
	if (empty()) {
		return false;
	}
	top--;
	length--;
	return true;
}

int lx::stack_cpp::getTop() {
	if (!empty()) {
		return elements[top-1];
	}
	return -1;	//if empty
}

int lx::stack_cpp::size() {
	return length;
}


void lx::stack_cpp::print(){
	std::cout << "informantion of this stack now :" << std::endl;
	std::cout << "empty? " << empty() << std::endl;
	std::cout << "full? " << full() << std::endl;
	std::cout << "capacity: " << capacity << std::endl;
	std::cout << "length: " << length << std::endl;
	std::cout << "index top: " << top << std::endl;
	std::cout << "element in top: " << getTop() << std::endl;
	std::cout << "elements: ";
	for (int i = 0; i < top; i++){
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl << std::endl;
}





void test_lstack() {
	std::cout << "-------------------------test lstack version c++-----------------------\n" << std::endl;
	std::cout << "create stack,capacity: 16" << std::endl;
	lx::stack_cpp s(16);
	s.print();

	std::cout << "push 16 elements to the stack,";
	for (int i = 0; i < 16; i++) {
		s.push(i);
	}
	s.print();

	std::cout << "pop 8 elements:";
	for (int i = 0; i < 8; i++){
		s.pop();
	}
	s.print();

	std::cout << "clear the stack,";
	s.clear();
	s.print();
}

