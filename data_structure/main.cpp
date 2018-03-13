//#include "lqueue\lqueue.h"
//#include "lqueue\lqueue_c.h"
//#include "lstack\lstack.h"
//#include "lstack\lstack_c.h"
//#include "lvector\lvector.h"


#include<iostream>
#include <thread>
#include <vector>

typedef unsigned long long LONG;

void foo(LONG begin, LONG end, LONG &res) {
	res = 0;
	for (LONG i = begin; i < end; i++) {
		res += i;
	}
}

int main(){
	//test_lqueue();
	//test_lqueue_c();
	//test_lstack();
	//test_lstack_c();
	//test_lvector();
	LONG res[100];
	LONG r = 0;
	std::vector<std::thread> threads;


	for (int i = 0; i < 100; i++) {
		threads.push_back(std::thread(foo, 0xffffffffffff * i, 0xffffffffffff * (i + 1), std::ref(res[i])));
	}

	for (int i = 0; i < 100; i++) {
		threads[i].join();
	}

	for (int i = 0; i < 100; i++) {
		r += res[i];
	}

	std::cout << r;

	return 0;
}