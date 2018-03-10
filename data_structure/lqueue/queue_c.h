#pragma once
#ifndef _QUEUE_C_H_
#define _QUEUE_C_H_

#include <stdbool.h>

#ifdef _cplusplus
extern "C" {
#endif
	typedef struct queue {
		int *elements;
		int length;
		int capacity;
		int head;
		int tail;
	} queue_c;

	void initQueue(queue_c *q,const int cap);//建队
	void destoryQueue(queue_c *q);//销毁队
	void clearQueue(queue_c *q);//清空队
	bool emptyQueue(const queue_c *q);//判空
	bool fullQueue(const queue_c *q);//判满
	bool push(queue_c *q, const int ele);//入队
	bool pop(queue_c *q,int *out);//出队
	void print(const queue_c *q);//遍历打印

	void test();

#ifdef _cplusplus
}
#endif
#endif