#include <stdio.h>
#include <malloc.h>

#include "stack_c.h"


void initStack(stack_c *s,int cap) {
	s->elements = (int *)malloc(cap * sizeof(int));
	s->capacity = cap;
	s->length = 0;
	s->top = -1;
}

void destoryStack(stack_c *s) {
	free(s->elements);
	s->capacity = 0;
}

void clearStack(stack_c *s) {
	s->length = 0;
	s->top = -1;
}

bool emptyStack(stack_c *s) {
	return s->length == 0 ? true : false;
}

bool fullStack(stack_c *s) {
	return s->length == s->capacity ? true : false;
}

bool pushStack(stack_c *s, int ele) {
	if (fullStack(s)) {
		return false;
	}
	else {
		s->elements[++s->top] = ele;
		s->length++;
		return true;
	}
}

bool popStack(stack_c *s) {
	if (emptyStack(s)) {
		return false;
	}
	else {
		s->top--;
		s->length--;
		return true;
	}
}

bool getTop(stack_c *s, int *out) {
	if (emptyStack(s)) {
		return false;
	}
	else {
		*out = s->elements[s->top];
		return true;
	}
}


void test() {
	stack_c s;
	initStack(&s, 10);
	if (emptyStack(&s)) {
		printf("empty\n");
	}
	for (int i = 0; i < 11; i++) {
		if (pushStack(&s, i)) {
			int tmp;
			getTop(&s, &tmp);
			printf("length:%d ,top index:%d ,top:%d \n", s.length, s.top, tmp);
		}
	}

	printf("\n\n");
	for (int i = 0; i < 11; i++) {
		if (popStack(&s)) {
			int tmp;
			getTop(&s, &tmp);
			printf("length:%d ,top index:%d ,top:%d \n", s.length, s.top, tmp);
		}
	}
}

//test
int main() {
	test();
	return 0;
}