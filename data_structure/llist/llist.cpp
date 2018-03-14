#include "llist.h"


lx::llist::llist():head(nullptr){}


lx::llist:: ~llist() {
	clear();
}


int lx::llist::size() {
	int length = 0;
	_node *p = head;
	if (p == nullptr) {
		return 0;
	}
	while (p) {
		p = p->next;
		length++;
	}
	return length;
}


bool lx::llist::empty() {
	return head == nullptr ? true : false;
}


int lx::llist::at(int index) {
	if (empty()) {
		std::cerr << "get element in "<<index<<" failed,list is empty." << std::endl;
		return -1;
	}
	
	/*this way will traverse some element twice */
	//if (index >= size()) {
	//	std::cerr << "index out of bound." << std::endl;
	//	exit(-1);
	//}

	_node *p = head;
	_node *q = head->next;
	int i = 0;
	for (; i <= index && p; i++) {
		p = q;
		q = p->next;
	}
	if (i != index) {
		std::cerr << "get element in index "<<index<<" failed,index out of bound." << std::endl;
		return -1;
	}
	return p->data;
}

int lx::llist::r_at(int index) {
	if (empty()) {
		std::cerr << "get the bottom "<<index<<" element failed,list is empty." << std::endl;
		return -1;
	}
	//if (index >= size()) {
	//	std::cerr << "index out of bound." << std::endl;
	//	return -1;
	//}

	_node *match = head;
	_node *current = head;
	int i = 0;
	for (; i <= index && current; i++) {
		current = current->next;
	}
	if (i != index) {
		std::cerr << "get the bottom " << index << " element faled,index out of bound." << std::endl;
		return -1;
	}
	while (current->next) {
		match = match->next;
		current = current->next;
	}
	return match->data;
}


int lx::llist::front() {
	if (empty()) {
		std::cerr << "get the first element failed,list is empty." << std::endl;
		return -1;
	}
	return head->data;
}


int lx::llist::back() {
	if (empty()) {
		std::cerr << "get the last element failed,list is empty." << std::endl;
		return -1;
	}
	_node *first = head;
	_node *second = head->next;
	while (second) {
		first = second;
		second = second->next;
	}
	return first->data;
}


bool lx::llist::push_front(int item) {
	_node *tmp = nullptr;
	try {
		tmp = new _node;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "bad_alloc:" << e.what() << std::endl;
		return false;
	}
	tmp->data = item;
	tmp->next = head;
	head = tmp;
	return true;
}


void lx::llist::pop_front() {
	if (empty()){
		return;
	}
	_node *tmp = head;
	head = head->next;
	delete tmp;
	tmp = nullptr;
}


bool lx::llist::push_back(int item){
	_node *tmp = nullptr;
	try {
		tmp = new _node;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "bad_alloc:" << e.what() << std::endl;
		return false;
	}
	tmp->data = item;
	tmp->next = nullptr;


	if (empty()){
		head = tmp;
		tmp = nullptr;
		return true;
	}

	_node *first = head;
	_node *second = head->next;
	while (second){
		first = second;
		second = second->next;
	}
	first->next = tmp;
	tmp = nullptr;
}


void lx::llist::pop_back() {
	if (empty()) {
		std::cout << "nothing to pop ,list is empty." << std::endl;
		return;
	}

	/*
	error solution:

	_node *first = head;
	_node *second = head->next;
	while (second) {
		first = second;
		second = second->next;
	}
	delete first;
	first = nullptr; //just point local pointer to the NULL
	*/

	if (!head->next) {
		delete head;
		head = nullptr; 
		return;
	}
	_node *first = head;
	_node *second = head->next;
	while (second->next) {
		first = second;
		second = second->next;
	}
	delete second;
	first->next = nullptr;
}


bool lx::llist::insert(int index, int item){
	_node *tmp = nullptr;
	try {
		tmp = new _node;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "bad_alloc:" << e.what() << std::endl;
		return false;
	}
	tmp->data = item;
	tmp->next = nullptr;


	if (empty()){
		if (index != 0){
			std::cout << "index out of bound" << std::endl;
			return false;
		}
		head = tmp;
		tmp = nullptr;
		return true;
	}
	else{
		_node *first = head;
		_node *second = head->next;
		int i = 0;
		for (; i <= index&&second; i++){
			first = second;
			second = second->next;
		}
		if (i != index){
			std::cout << "index out of bound" << std::endl;
			return false;
		}
		first->next = tmp;
		tmp = nullptr;
		second = nullptr;
		return true;
	}
}


bool lx::llist::erase(int index){
	if (empty()){
		std::cout << "index out of bound,list is empty." << std::endl;
		return false;
	}
	




}

void reverse();//逆序链表
void remove(int item);//删除链表中的所有item
void lx::llist::clear(){

}