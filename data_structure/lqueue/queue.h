#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stddef.h>
class queue{
public:
	queue();//默认构造
	explicit queue(int cap); //构造容量为cap的队列
	virtual ~queue();//析构
	void clear();//清空
	bool empty() const;//判空
	bool full() const;//判满
	int getLength() const;//获取长度
	bool push(const int &in);//入队
	bool pop(int &out);//出队
	void print();//遍历打印

private :
	int *q;
	int length;
	int capacity;
	int head;
	int tail;
};

void test();

#endif