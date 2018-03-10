#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stddef.h>
class queue{
public:
	queue();//Ĭ�Ϲ���
	explicit queue(int cap); //��������Ϊcap�Ķ���
	virtual ~queue();//����
	void clear();//���
	bool empty() const;//�п�
	bool full() const;//����
	int getLength() const;//��ȡ����
	bool push(const int &in);//���
	bool pop(int &out);//����
	void print();//������ӡ

private :
	int *q;
	int length;
	int capacity;
	int head;
	int tail;
};

void test();

#endif