#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAXSIZE 1024
#define  INFINITY 65535
typedef struct
{
	int data[MAXSIZE];  // ���ջ�е�Ԫ��
	int top;   // ָʾջ��Ԫ��
}SeqStack;

void InitStack(SeqStack* stack);
int IsEmpty(SeqStack* stack);
int SeqStack_Top(SeqStack* stack);  // ����ջ��Ԫ��
int SeqStack_Pop(SeqStack* stack);  // ����ջ��Ԫ�أ���ɾ��ջ����Ԫ��
void SeqStack_Push(SeqStack* stack, int val);  // ��Ԫ��valѹ��ջ��
void SeqStack_Destory(SeqStack* stack);   
void testSeqStack();

#endif

