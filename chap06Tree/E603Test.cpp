// 20170829

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

// 输入节点为 ABD-E-H-CF-GI-，"-"代表空格。