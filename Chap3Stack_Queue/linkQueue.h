#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

typedef struct Node *pNode;
typedef struct Queue *LQueue;  // �൱�ڶ���ͷ���pHead

struct Node
{
	int data;           // ������
	pNode next;         // ָ����
};

struct Queue    // ͷ���
{
	pNode front;  // ָ��ͷ��㣬�൱��������ͷ������nextָ��
	pNode rear;   // ָ��β���
	int length;   // ���г���
};

LQueue create();
int getLength(LQueue lq);
int IsEmpty(LQueue lq);
void insert(LQueue lq,int val);
int getHead(LQueue lq);
pNode del(LQueue lq);  // ����
void clear(LQueue lq);
void testLinkQueue();

#endif