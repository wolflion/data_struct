// 20170829

#define  MAXSIZE  20
typedef char datatype;
typedef struct node  // ���������ṹ
{
	datatype data;
	struct node *lchild, *rchild;
}BTNode;

// ���������˳����һ�ø����Ķ���������
void createBT(BTNode **bt)
{
	char ch;
	if ((ch = getchar()) == ' ')
		*bt = NULL;  // �������Ķ�����Ϊһ�ÿն�����
	else
	{
		*bt = new BTNode;
		(*bt)->data = ch;
		createBT(&(*bt)->lchild);
		createBT(&(*bt)->rchild);
	}
}

// ����ڵ�Ϊ ABD-E-H-CF-GI-��"-"����ո�