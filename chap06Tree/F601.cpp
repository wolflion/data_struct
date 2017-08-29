// 20170829
#include <iostream>
#include <malloc.h>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
typedef struct BitNode
{
	char data;
	struct BitNode* lchild, *rchild;
}BitNode;

// 前序遍历
void PreOrder(BitNode *T)
{
	//先根
	if (T == NULL)
		return;
	printf("%c", T->data);  // 输出根结点的值

	// 遍历左子树
	if (T->lchild != NULL)
		PreOrder(T->lchild);
	// 遍历右子树
	if (T->rchild != NULL)
		PreOrder(T->rchild);
}

// 中序遍历
void InOrder(BitNode *T)
{
	if (T == NULL)
		return;

	// 先左子树
	if (T->lchild != NULL)
		PreOrder(T->lchild);
	// 再根
	printf("%c", T->data);  
	// 最后右子树
	if (T->rchild != NULL)
		PreOrder(T->rchild);
}

// 后序遍历
void lastOrder(BitNode *T)
{
	if (T == NULL)
		return;

	// 先左子树
	if (T->lchild != NULL)
		PreOrder(T->lchild);

	// 再右子树
	if (T->rchild != NULL)
		PreOrder(T->rchild);
	// 最后根
	printf("%c", T->data);  
}

int main()
{
	BitNode nodeA, nodeB, nodeD, nodeF, nodeI, nodeL; //创建6个结点
	// 将结点都初始化为空，保证叶子结点相应指针指向空
	memset(&nodeA, 0, sizeof(BitNode));
	memset(&nodeB, 0, sizeof(BitNode));
	memset(&nodeD, 0, sizeof(BitNode));
	memset(&nodeF, 0, sizeof(BitNode));
	memset(&nodeI, 0, sizeof(BitNode));
	memset(&nodeL, 0, sizeof(BitNode));
	//给结点赋值
	nodeA.data = 'A';
	nodeB.data = 'B';
	nodeD.data = 'D';
	nodeF.data = 'F'; 
	nodeI.data = 'I';
	nodeL.data = 'L';

	// 存储结点之间的逻辑关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeD;
	nodeB.rchild = &nodeF;
	nodeF.lchild = &nodeL;
	nodeD.lchild = &nodeI;

	printf("二叉树构建成功!\n");

	printf("先序遍历：");
	PreOrder(&nodeA);
	printf("\n中序遍历：");
	InOrder(&nodeA);
	printf("\n后序遍历：");
	lastOrder(&nodeA);

	printf("\n");
	system("pause");
	return 0;
}
