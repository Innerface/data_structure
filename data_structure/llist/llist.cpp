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
		std::cerr << "list is empty." << std::endl;
		exit(-1);
	}
	if (index >= size()) {
		std::cerr << "index out of bound." << std::endl;
		exit(-1);
	}

	_node *p = head;
	_node *q = head->next;
	for (int i = 0; i < index; i++) {
		p = q;
		q = p->next;
	}
	return p->data;
}

int lx::llist::r_at(int index) {
	if (empty()) {
		std::cerr << "list is empty." << std::endl;
		exit(-1);
	}
	if (index >= size()) {
		std::cerr << "index out of bound." << std::endl;
		exit(-1);
	}

	_node *match = head;
	_node *current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	while (current->next) {
		match = match->next;
		current = current->next;
	}
	return match->data;
}


int lx::llist::front() {
	if (empty()) {
		std::cerr << "list is empty." << std::endl;
		exit(-1);
	}
	return head->data;
}


int lx::llist::back() {
	if (empty()) {
		std::cerr << "list is empty." << std::endl;
		exit(-1);
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

void lx::llist::pop_back() {
	if (empty()) {
		std::cerr << "list is empty." << std::endl;
		exit(-1);
	}
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


bool insert(int index, int item);//插入元素到第index
bool erase(int index);//删除第index哥元素
void reverse();//逆序链表
void remove(int item);//删除链表中的所有item
void lx::llist::clear(){

}