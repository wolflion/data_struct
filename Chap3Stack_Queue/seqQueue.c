#include "seqQueue.h"

seqQueue Create()
{
	seqQueue sq = (seqQueue)malloc(sizeof(struct seqQueue));
	sq->front = sq->rear-1;
	memset(sq->data,0,MAXSIZE*sizeof(int));
	return sq;
}

int getLength(seqQueue sq)
{
	return sq->rear - sq->front;   // ���г��� �Ƕ�ͷ��β֮��
}

int IsEmpty(seqQueue sq)
{
	if(sq->front == sq->rear)  // ����Ϊ�յ�������  ==��=����?
	{
		return 1;
	}
	return 0;
}

// �����ı�־

// ����ǰ���Ƕ�ͷ������Ƕ�β
void insert(seqQueue sq, int val)
{
	// �����Ƿ���
	if (sq->rear == MAXSIZE - 1)
	{
		printf("�����������޷��ٲ���Ԫ�أ�\n");
		return;
	}
	// �����Ƿ��
	if (sq->front == sq->rear)
	{
		sq->front = sq->rear = 0;
		sq->data[sq->rear] = val;
		sq->rear++;
	}
	else
	{
		sq->data[sq->rear] = val; // ��������
		sq->rear++;
	}
}

int del(seqQueue sq)
{
	// �ն���
	if(sq->front == sq->rear)
	{
		printf("����Ϊ�գ���Ԫ�ؿɵ���\n");
		return 10000;
	}
	int temp = sq->data[sq->front];
	sq->front++;  // ɾ����ͷԪ�غ�front����ƶ�
	return temp;
}

int getHead(seqQueue sq)
{
	if(sq->front == sq->rear)
	{
		printf("����Ϊ�գ���Ԫ�ؿɵ���\n");
		return 10000;
	}
	// ��ȡԪ��
	return sq->data(sq->front);
}

void clear(seqQueue sq)
{
	sq->front = sq->rear  = -1;
	printf("��������գ�\n");
}

void Destory(seqQueue sq)
{
	free(sq);
	printf("���������٣�\n");
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
	printf("���г��ȣ�%d\n",getLength(sq));
	printf("��ͷԪ�� ����Ԫ��\n");

	while(sq->front != sq->rear)
	{
		ret = getHead(sq);
		printf(" %d    ",ret);
		ret = del(sq);   // ������
		printf("%d\n",ret);
	}
	printf("���г���:%d\n",getLength(sq));
	clear(sq);
	Destory(sq);
}