#ifndef _LINKLIST_H
#define _LINKLIST_H

struct  Node;
typedef  struct Node List;
typedef struct Header pHead;

pHead* createList();
int isEmpty(pHead* l);
int insert(pHead* l,int pos, int val);
List* Delete(pHead* l,int ele);
List* find(pHead* l, int ele);
int size(pHead* l);
void destory(pHead* l);
void print(pHead* l);

struct Node     // 结点
{
	int data;
	struct  Node* next;
};

struct  Header
{
	int length;
	struct Node* next;
};

#endif