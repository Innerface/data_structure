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

	void initQueue(queue_c *q,const int cap);//����
	void destoryQueue(queue_c *q);//���ٶ�
	void clearQueue(queue_c *q);//��ն�
	bool emptyQueue(const queue_c *q);//�п�
	bool fullQueue(const queue_c *q);//����
	bool push(queue_c *q, const int ele);//���
	bool pop(queue_c *q,int *out);//����
	void print(const queue_c *q);//������ӡ

	void test();

#ifdef _cplusplus
}
#endif
#endif