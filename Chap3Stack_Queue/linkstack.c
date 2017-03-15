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
	pNode node = (pNode)malloc(sizeof(struct Node));  // 为元素val分配结点
	if (node != NULL)
	{
		node->data = val;
		node->next = getTop(lstack); // 新元素结点指向下一个结点，链式实现
		lstack->top = node; // top指向新结点
		lstack->size++;
	}
	return 1;
}

// 获取栈顶元素
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
	pNode node = lstack->top; // node指向栈顶元素
	lstack->top = lstack->top->next; // top指向下一个元素
	lstack->size--;
	return node;
}

void Destory(LinkStack lstack)
{
	if(IsEmpty(lstack))
	{
		free(lstack);
		printf("栈已为空，不必再行销毁！\n");
		return;
	}

	do 
	{
		pNode pTmp;
		pTmp = Pop(lstack);
		free(pTmp);
	} while (lstack->size > 0);
	printf("栈销毁成功！\n");
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
		printf("栈为空！\n");
	}
	else
	{
		printf("栈不为空！\n");
	}

	for (i=0;i<10;i++)
	{
		Push(lstack,rand()%100);
	}

	ret = IsEmpty(lstack);
	if (ret)
	{
		printf("栈为空！\n");
	}
	else
	{
		printf("栈不为空！\n");
	}

	printf("栈的长度：%d\n",getSize(lstack));

	printf("栈顶元素：%d\n",*((int *)getTop(lstack)));

	while(lstack->size > 0)
	{
		printf("%d ", *((int *)Pop(lstack)));
	}
	printf("\n");

	Destory(lstack);
}

