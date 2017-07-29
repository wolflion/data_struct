#include "linkQueue.h"

/*
���ʱ��Ҫִ������3�����
s->next = NULL;
rear->next = s;
rear = s;
*/

LQueue create()
{
	LQueue lq = (LQueue)malloc(sizeof(struct Queue)); // Ϊͷ������ռ�
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

// ��ӣ�����һ��Ԫ��
void insert(LQueue lq,int val)
{
	// ���ȵô���һ���ڵ�
	pNode pn = (pNode)malloc(sizeof(struct Node));
	pn->data = val;
	pn->next = NULL;

	// �������Ϊ�գ���pn�����뵽ͷ���֮��
	if (IsEmpty(lq))
	{
		lq->next = pn;  //
		lq->front = pn;
		lq->rear = pn;
	}
	else
	{
		lq->rear->next = pn; // �´����Ľڵ㸳ֵ����β��next
		lq->rear = pn;       // �´����Ľڵ㸳ֵ����β
	}
	lq->length++;
}

int getHead(LQueue lq)
{
	if(IsEmpty(lq))
	{
		printf("����Ϊ�գ���Ԫ�ؿ�ȡ��\n");
		return 10000;
	}
	return lq->front->data;
	//return lq->front->next->data; // ��������ɶ����
}

//  ����
pNode del(LQueue lq)
{
	if(IsEmpty(lq))
	{
		printf("����Ϊ�գ�ɾ������\n");
		return NULL;
	}
	pNode pTmp = lq->front;
	lq->front = pTmp->next;
	lq->length--;
	return pTmp;
}

//����
void DelLinkList(LQueue lq,int *elem)
{
	if(IsEmpty(lq))
	{
		printf("����Ϊ�գ�ɾ������\n");
		return NULL;
	}
	else
	{
		*elem = lq->front->next->data;
		//����һ���ڵ�s
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
	printf("�����Ѿ���գ�\n");
}

void testLinkQueue()
{
	int i,ret;
	LQueue lq = create();
	srand((unsigned)time(0));
	for(i=0;i<10;i++)
		insert(lq,rand()%100);
	printf("���г��ȣ�%d\n",getLength(lq));
	printf("��ͷԪ�أ�%d\n",getHead(lq));
	printf("��ͷԪ��  ����Ԫ��\n");
	while(getLength(lq) >0) // �����У�ѭ�������Ƕ��в�Ϊ��
	{
		ret = getHead(lq); // ��ȡ��ͷԪ��
		printf("%d      ",ret);
		ret = del(lq)->data;
		printf("%d\n",ret);
	}
	clear(lq);
}