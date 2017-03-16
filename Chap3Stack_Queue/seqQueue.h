#ifndef _SQQUEUE_H 
#define  _SQQUEUE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 50
typedef struct Queue* seqQueue;

struct Queue
{
	int front;// ��ͷ
	int rear;// ��β
	int data[MAXSIZE];//����
};

seqQueue Create();
int getLength(seqQueue sq);
int IsEmpty(seqQueue sq);
void insert(seqQueue sq, int val); // ���
int del(seqQueue sq); // ����
int getHead(seqQueue sq);  // ��ȡ��ͷԪ��
void clear(seqQueue sq);
void destory(seqQueue sq);

void testSeqQueue();
#endif 