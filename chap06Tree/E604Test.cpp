// 20170829
// 虽然前面接了E603Test.cpp中的部分代码，但本例中的PreOrder(bt);并没有执行。

#define  MAXSIZE  20
typedef char datatype;
typedef struct node  // 二叉树结点结构
{
	datatype data;
	struct node *lchild, *rchild;
}BTNode;

// 按先序遍历顺序建立一棵给定的二叉树函数
void createBT(BTNode **bt)
{
	char ch;
	if ((ch = getchar()) == ' ')
		*bt = NULL;  // 所建立的二叉树为一棵空二叉树
	else
	{
		*bt = new BTNode;
		(*bt)->data = ch;
		createBT(&(*bt)->lchild);
		createBT(&(*bt)->rchild);
	}
}

// 非递归的二叉树先序遍历算法
void PreOrder(BTNode *bt)
{
	BTNode *St[MAXSIZE], *p;
	int top = -1; //初始化栈
	if (bt != NULL)
	{
		St[++top] = bt;
		while (top > -1)  //栈不空循环
		{
			p = St[top--]; // 出栈并访问该结点
			cout << p->data;
			if (p->rchild != NULL)
			{
				St[++top] = p->rchild;  //右孩子先入栈，后出栈
			}
			if (p->lchild != NULL)
			{
				St[++top] = p->lchild;  //左孩子后入栈，先出栈
			}
		}
		cout << endl;
	}
}

// 输入节点为 ABD-E-H-CF-GI-，"-"代表空格。
int main()
{
	BTNode *bt = NULL;
	cout << "按照先序遍历顺序建立一棵二叉树，以空格作为空二叉树的标志：" << endl;
	createBT(&bt);    //按照先序遍历顺序建立一棵给定的二叉树
	cout << "二叉树的先序遍历（非递归）：";
	PreOrder(bt);
	system("pause");
	return 0;
}