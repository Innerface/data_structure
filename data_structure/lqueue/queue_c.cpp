#include <malloc.h>
#include <stdio.h>
#include "queue_c.h"


void initQueue(queue_c *q,const int cap) {
	q->elements = (int *)malloc(cap * sizeof(int));
	q->capacity = cap;
	q->head = 0;
	q->tail = 0;
	q->length = 0;
}
void destoryQueue(queue_c *q) {
	free(q->elements);
	q->capacity = 0;
}

void clearQueue(queue_c *q) {
	q->head = 0;
	q->tail = 0;
	q->length = 0;
}

bool emptyQueue(const queue_c *q) {
	return q->length == 0 ? true : false;
}

bool fullQueue(const queue_c *q) {
	return q->length >= q->capacity ? true : false;
}

bool push(queue_c *q, const int ele) {
	if (fullQueue(q)) {
		return false;
	}
	q->elements[q->tail] = ele;
	q->tail = (q->tail++) % q->capacity;
	q->length++;
	return true;
}

bool pop(queue_c *q, int *out) {
	if (emptyQueue(q)) {
		return false;
	}
	*out = q->elements[q->head];
	q->head = (q->head++) % q->capacity;
	q->length--;
	return true;
}

void print(const queue_c *q) {
	for (int i = q->head; i < q->length + q->head; i++) {
		printf("%d ", q->elements[i]);
	}
	printf("\n");
}

void test() {
	queue_c q;
	printf("create a queue\n");
	initQueue(&q,4);
	if (emptyQueue(&q)) {
		printf("queue now is empty\n");
	}
	else {
		printf("queue not empty\n   elements: ");
		print(&q);
	}

	push(&q, 11);
	if (emptyQueue(&q)) {
		printf("queue now is empty\n");
	}
	else {
		printf("queue not empty\n   elements: ");
		print(&q);
	}

	push(&q, 23);
	if (emptyQueue(&q)) {
		printf("queue now is empty\n");
	}
	else {
		printf("queue not empty\n   elements: ");
		print(&q);
	}

	push(&q, 24);
	if (emptyQueue(&q)) {
		printf("queue now is empty\n");
	}
	else {
		printf("queue not empty\n   elements: ");
		print(&q);
	}

	push(&q, 45);
	if (emptyQueue(&q)) {
		printf("queue now is empty\n");
	}
	else {
		printf("queue not empty\n   elements: ");
		print(&q);
	}

	if (fullQueue(&q)) {
		printf("queue now is full\n   capacity:%d,length:%d,elements:",q.capacity,q.length);
		print(&q);
	}

	clearQueue(&q);
	if (emptyQueue(&q)) {
		printf("queue now is empty\n");
	}
	
	destoryQueue(&q);
	if (push(&q, 12345)) {
		printf("push successfully:12345\n");
	}
	else {
		printf("push failed\n");
	}	
}