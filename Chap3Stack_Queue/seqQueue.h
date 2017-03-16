#ifndef _SQQUEUE_H 
#define  _SQQUEUE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 50
typedef struct Queue* seqQueue;

struct Queue
{
	int front;// 队头
	int rear;// 队尾
	int data[MAXSIZE];//数据
};

seqQueue Create();
int getLength(seqQueue sq);
int IsEmpty(seqQueue sq);
void insert(seqQueue sq, int val); // 入队
int del(seqQueue sq); // 出队
int getHead(seqQueue sq);  // 获取队头元素
void clear(seqQueue sq);
void destory(seqQueue sq);

void testSeqQueue();
#endif 