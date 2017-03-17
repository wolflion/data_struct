#include "linkQueue.h"

LQueue create()
{
	LQueue lq = (LQueue)malloc(sizeof(struct Queue)); // 为头结点分配空间
	lq->front = NULL;
	lq->rear = NULL;
	lq->length = 0;
}

int getLength(LQueue lq)
{
	return lq->length;
}

int IsEmpty(LQueue lq)
{
	if(lq->length == 0)
		return 1;
	return 0;
}

// 入队，插入一个元素
void insert(LQueue lq,int val)
{
	pNode pn = (pNode)malloc(sizeof(struct Node));
	pn->data = val;
	pn->next = NULL;

	// 如果队列为空，则将pn结点插入到头结点之后
	if (IsEmpty(lq))
	{
		lq->next = pn;  //
		lq->front = pn;
		lq->rear = pn;
	}
	else
	{
		lq->rear->next = pn;
		lq->rear = pn;
	}
	lq->length++;
}

int getHead(LQueue lq)
{
	if(IsEmpty(lq))
	{
		printf("队列为空，无元素可取！\n");
		return 10000;
	}
	return lq->front->data;
}

pNode del(LQueue lq)
{
	if(IsEmpty(lq))
	{
		printf("队列为空，删除错误！\n");
		return NULL;
	}
	pNode pTmp = lq->front;
	lq->front = pTmp->next;
	lq->length--;
	return pTmp;
}

void clear(LQueue lq)
{
	lq->front = NULL;
	lq->rear = NULL;
	lq->length = 0;
	printf("队列已经清空！\n");
}

void testLinkQueue()
{
	int i,ret;
	LQueue lq = create();
	srand((unsigned)time(0));
	for(i=0;i<10;i++)
		insert(lq,rand()%100);
	printf("队列长度：%d\n",getLength(lq));
	printf("队头元素：%d\n",getHead(lq));
	printf("队头元素  出队元素\n");
	while(getLength(lq) >0) // 出队列，循环条件是队列不为空
	{
		ret = getHead(lq); // 获取队头元素
		printf("%d      ",ret);
		ret = del(lq)->data;
		printf("%d\n",ret);
	}
	clear(lq);
}