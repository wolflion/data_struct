#include "seqQueue.h"

seqQueue Create() //typedef struct Queue* seqQueue;
{
	seqQueue sq = (seqQueue)malloc(sizeof(struct seqQueue));
	sq->front = sq->rear-1; // 队头队尾指向-1
	memset(sq->data,0,MAXSIZE*sizeof(int));
	return sq;
}

int getLength(seqQueue sq)
{
	return sq->rear - sq->front;   // 队列长度 是队头队尾之差
}

int IsEmpty(seqQueue sq)
{
	if(sq->front == sq->rear)  // 队列为空的条件？  ==或=区别?
	{
		return 1;
	}
	return 0;
}

// 队满的标志

// 【入队：将一个新元素插入到队尾】数组前边是队头，后边是队尾
void insert(seqQueue sq, int val) //typedef struct Queue* seqQueue;
{
	// 队列是否满
	if (sq->rear == MAXSIZE - 1)
	{
		printf("队列已满，无法再插入元素！\n");
		return;
	}
	// 队列是否空
	if (sq->front == sq->rear)
	{
		sq->front = sq->rear = 0;
		sq->data[sq->rear] = val;
		sq->rear++;
	}
	else
	{
		sq->data[sq->rear] = val; // 保存数据
		sq->rear++;
	}
	
	/*
	if((sq->rear+1)%MAXSIZE == sq->front) 
		//exit();
		return;
	else
	{
		sq->rear = (sq->rear+1)%MAXSIZE; // 这是取得一个新空间?
		sq->data[sq->rear]=val;
	}
	*/
}

// 【出队：取出队头元素，并同时删除该元素，使后一个元素成为队头】
int del(seqQueue sq)
{
	// 空队列
	if(sq->front == sq->rear)
	{
		printf("队列为空，无元素可弹！\n");
		return 10000;
	}
	int temp = sq->data[sq->front];
	sq->front++;  // 删除队头元素后，front向后移动
	return temp;
}

// 判断队列是否为空
int QueueEmpty(seqQueue sq)
{
	if(sq->front == sq->rear)
		return 1;
	else
		return 0;
}

/*
int delQueue(seqQueue sq,int *elem)
{
	if(QueueEmpty(sq))
		return 0;
	else
	{
		sq->front = (sq->front+1)%MAXSIZE;
		*elem = sq->data[sq->front];
	}
}
*/

// 获取第1个元素
int getHead(seqQueue sq)
{
	if(sq->front == sq->rear)
	{
		printf("队列为空，无元素可弹！\n");
		return 10000;
	}
	// 获取元素
	return sq->data[sq->front];
	// return sq->data[(s->front+1)%MAXSIZE]; //这个为什么要加1啊，又不用移动元素？
}

void clear(seqQueue sq)
{
	sq->front = sq->rear  = -1;
	printf("队列已清空！\n");
}

void Destory(seqQueue sq)
{
	free(sq);
	printf("队列已销毁！\n");
}

void testSeqQueue()
{
	seqQueue sq = Create();
	int i,ret;
	srand((unsigned)time(0));
	for(i=0;i<10;++i)
	{
		insert(sq,rand()%100);
	}
	printf("队列长度：%d\n",getLength(sq));
	printf("队头元素 出队元素\n");

	while(sq->front != sq->rear)
	{
		ret = getHead(sq);
		printf(" %d    ",ret);
		ret = del(sq);   // 出队列
		printf("%d\n",ret);
	}
	printf("队列长度:%d\n",getLength(sq));
	clear(sq);
	Destory(sq);
}