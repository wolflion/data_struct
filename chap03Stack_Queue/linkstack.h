#ifndef _LINKSTACK_H
#define _LINKSTACK_H

typedef struct Node* pNode;
typedef struct Stack* LinkStack;

struct Node   // 数据结点
{
	int data;
	pNode next;  // 指针
};

struct Stack   // 记录栈的大小和栈顶元素指针
{
	pNode top; // 栈顶元素指针
	int size; // 栈大小
};

LinkStack Create();   // 返回LinkStack，链栈
int IsEmpty(LinkStack lstack);
int getSize(LinkStack lstack);
int Push(LinkStack lstack, int val);   // 入栈，只要判断入栈成不成功就行
pNode getTop(LinkStack lstack);
pNode Pop(LinkStack lstack);     // 弹出栈顶元素，元素类型为Node类型？
void Destory(LinkStack lstack);
void testLinkStack();

#endif