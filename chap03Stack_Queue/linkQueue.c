#include "linkQueue.h"

/*
入队时需要执行以下3条语句
s->next = NULL;
rear->next = s;
rear = s;
*/

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
	
	/*
	if(lq->frront == lq->rear)
		return 1;
	else 
		return 0;
	*/
}

// 入队，插入一个元素
void insert(LQueue lq,int val)
{
	// 首先得创建一个节点
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
		lq->rear->next = pn; // 新创建的节点赋值给队尾的next
		lq->rear = pn;       // 新创建的节点赋值给队尾
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
	//return lq->front->next->data; // 这两行有啥区别？
}

//  出队
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

//出队
void DelLinkList(LQueue lq,int *elem)
{
	if(IsEmpty(lq))
	{
		printf("队列为空，删除错误！\n");
		return NULL;
	}
	else
	{
		*elem = lq->front->next->data;
		//创建一个节点s
		pNode s = (pNode)malloc(sizeof(struct Node)); 
		s = lq->front->next;
		lq->front->next = s->next;
		free(s);
	}
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