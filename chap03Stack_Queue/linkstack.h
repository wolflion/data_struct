#ifndef _LINKSTACK_H
#define _LINKSTACK_H

typedef struct Node* pNode;
typedef struct Stack* LinkStack;

struct Node   // ���ݽ��
{
	int data;
	pNode next;  // ָ��
};

struct Stack   // ��¼ջ�Ĵ�С��ջ��Ԫ��ָ��
{
	pNode top; // ջ��Ԫ��ָ��
	int size; // ջ��С
};

LinkStack Create();   // ����LinkStack����ջ
int IsEmpty(LinkStack lstack);
int getSize(LinkStack lstack);
int Push(LinkStack lstack, int val);   // ��ջ��ֻҪ�ж���ջ�ɲ��ɹ�����
pNode getTop(LinkStack lstack);
pNode Pop(LinkStack lstack);     // ����ջ��Ԫ�أ�Ԫ������ΪNode���ͣ�
void Destory(LinkStack lstack);
void testLinkStack();

#endif