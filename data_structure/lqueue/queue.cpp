#include "queue.h"
#include <iostream>

queue::queue() :capacity(10), length(0), head(0), tail(0){}

queue::queue(int cap) :capacity(cap), length(0), head(0), tail(0){
	q = new int[capacity];
}

queue::~queue(){
	delete[]q;
	q = NULL;
}

void queue::clear(){
	length = 0;
	head = 0;
	tail = 0;
}

bool queue::empty() const{
	return length == 0 ? true : false;
}

bool queue::full() const{
	return length == capacity ? true : false;
}

int queue::getLength() const{
	return length;
}

bool queue::push(const int &in){
	if (full()){
		return false;
	}
	else{
		q[tail] = in;
		tail = (++tail) % capacity; 
		length++;
		return true;
	}
}

bool queue::pop(int &out){
	if (empty()){
		return false;
	}
	else{
		out = q[head];
		head = (++head) % capacity;
		length--;
		return true;
	}

}

void queue::print(){
	int i = head;
	for (int i = 0; i < length;i++){
		std::cout << q[(i+head)%capacity];
	}
}


void test(){
	queue q(3);
	for (int i = 0; i < 3; i++){
		q.push(i);
	}
	q.print();
	int out = 0;
	if (q.pop(out)){
		std::cout << out << std::endl;
	}
}