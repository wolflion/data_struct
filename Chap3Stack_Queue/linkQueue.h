#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

typedef struct Node *pNode;
typedef struct Queue *LQueue;  // 相当于定义头结点pHead

struct Node
{
	int data;           // 数据域
	pNode next;         // 指针域
};

struct Queue    // 头结点
{
	pNode front;  // 指向头结点，相当于链表中头结点里的next指针
	pNode rear;   // 指向尾结点
	int length;   // 队列长度
};

LQueue create();
int getLength(LQueue lq);
int IsEmpty(LQueue lq);
void insert(LQueue lq,int val);
int getHead(LQueue lq);
pNode del(LQueue lq);  // 出队
void clear(LQueue lq);
void testLinkQueue();

#endif