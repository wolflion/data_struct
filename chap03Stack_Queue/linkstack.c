#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

LinkStack Create()
{
	LinkStack lstack = (LinkStack)malloc(sizeof(struct Stack));
	if(lstack != NULL)
	{
		lstack->top = NULL;
		lstack->size = 0;
	}
	return lstack;
}

int IsEmpty(LinkStack lstack)
{
	if (lstack->top == NULL || lstack->size == 0)
	{
		return 1;
	}
	return 0;
}

int getSize(LinkStack lstack)
{
	return lstack->size;
}

int Push(LinkStack lstack, int val)
{
	pNode node = (pNode)malloc(sizeof(struct Node));  // ΪԪ��val������
	if (node != NULL)
	{
		node->data = val;
		node->next = getTop(lstack); // ��Ԫ�ؽ��ָ����һ����㣬��ʽʵ��
		lstack->top = node; // topָ���½��
		lstack->size++;
	}
	return 1;
}

// ��ȡջ��Ԫ��
pNode getTop(LinkStack lstack)
{
	if(lstack->size != 0)
		return lstack->top;
	return NULL;
}

pNode Pop(LinkStack lstack)
{
	if(IsEmpty(lstack))
	{
		return NULL;
	}
	pNode node = lstack->top; // nodeָ��ջ��Ԫ��
	lstack->top = lstack->top->next; // topָ����һ��Ԫ��
	lstack->size--;
	return node;
}

void Destory(LinkStack lstack)
{
	if(IsEmpty(lstack))
	{
		free(lstack);
		printf("ջ��Ϊ�գ������������٣�\n");
		return;
	}

	do 
	{
		pNode pTmp;
		pTmp = Pop(lstack);
		free(pTmp);
	} while (lstack->size > 0);
	printf("ջ���ٳɹ���\n");
}

void testLinkStack()
{
	LinkStack lstack = NULL;
	int i,ret;
	srand((unsigned)time(0));
	lstack = Create();

	ret = IsEmpty(lstack);
	if (ret)
	{
		printf("ջΪ�գ�\n");
	}
	else
	{
		printf("ջ��Ϊ�գ�\n");
	}

	for (i=0;i<10;i++)
	{
		Push(lstack,rand()%100);
	}

	ret = IsEmpty(lstack);
	if (ret)
	{
		printf("ջΪ�գ�\n");
	}
	else
	{
		printf("ջ��Ϊ�գ�\n");
	}

	printf("ջ�ĳ��ȣ�%d\n",getSize(lstack));

	printf("ջ��Ԫ�أ�%d\n",*((int *)getTop(lstack)));

	while(lstack->size > 0)
	{
		printf("%d ", *((int *)Pop(lstack)));
	}
	printf("\n");

	Destory(lstack);
}

