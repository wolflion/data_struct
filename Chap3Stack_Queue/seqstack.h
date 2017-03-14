#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAXSIZE 1024
#define  INFINITY 65535
typedef struct
{
	int data[MAXSIZE];  // 存放栈中的元素
	int top;   // 指示栈顶元素
}SeqStack;

void InitStack(SeqStack* stack);
int IsEmpty(SeqStack* stack);
int SeqStack_Top(SeqStack* stack);  // 返回栈顶元素
int SeqStack_Pop(SeqStack* stack);  // 弹出栈顶元素，即删除栈顶的元素
void SeqStack_Push(SeqStack* stack, int val);  // 将元素val压入栈中
void SeqStack_Destory(SeqStack* stack);   
void testSeqStack();

#endif

