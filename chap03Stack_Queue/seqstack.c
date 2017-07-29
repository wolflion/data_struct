#include "seqstack.h"

// ��ʼ��ջ
void InitStack(SeqStack* stack)  
{
	stack->top = -1;
}

// ����ջ�أ�

int IsEmpty(SeqStack* stack)
{
	if(stack->top == -1) // ջ�п�
		return 1;
	else
		return 0;
}

int SeqStack_Top(SeqStack *stack)
{
	if(!IsEmpty(stack))
	{
		return stack->data[stack->top];
	}
	return INFINITY;
}

int SeqStack_Pop(SeqStack* stack)
{
	if(!IsEmpty(stack))
	{
		return stack->data[stack->top--]; // ����һ��Ԫ�غ�topҪ��1
	}
	return INFINITY;
}

void SeqStack_Push(SeqStack* stack, int val)
{
	if(stack->top >= MAXSIZE - 1) // ջ��
		return ;
	stack->top++;  // ����һ��Ԫ�غ�topҪ��1
	stack->data[stack->top] = val;
}

void SeqStack_Destory(SeqStack* stack)
{
	if (!IsEmpty(stack))
	{
		free(stack);
	}
}

void testSeqStack()
{
	SeqStack stackobj;
	int i;
	srand((unsigned)time(0)); // ��ʱ��Ϊ���Ӳ��������
	//SeqStack stackobj;
	//*SeqStack *stackobj = NULL;
	//stackobj = (SeqStack*)malloc(sizeof(SeqStack));*/
	// pHead ph = (pHead)malloc(sizeof(struct Head));
	// SeqStack stackObj;   // create
	InitStack(&stackobj);

	for (i= 0;i<50;i++)
	{
		//SeqStack_Push(&stackobj,rand()%1000);
		SeqStack_Push(&stackobj,rand()%1000);
	}

	//printf("Stack Top is: %d\n",SeqStack_Top(&stackobj));
	printf("Stack Top is: %d\n",SeqStack_Top(&stackobj));

	printf("Stack Element: ");
	for(i=0;i < 50;i++)
	{
		if (i % 5 == 0)
		{
			printf("\n");
		}
		//printf("%d ",SeqStack_Pop(&stackobj));
		printf("%d ",SeqStack_Pop(&stackobj));
	}

	printf("\n");
}