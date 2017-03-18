pHead* create()
{
	pHead* ph = (pHead*)malloc(sizeof(pHead));
	ph->length = 0;
	ph->next = NULL;
	return ph;
}

int size (pHead* ph)
{
	if(ph == NULL)
	{
		printf("参数传入有误！");
		return 0;
	}
	return ph->length;
}

int Insert(pHead* ph,int pos,int val)
{
	if(ph == NULL || pos < 0 || pos > ph->length)
	{
		printf("参数传入有误！");
		return 0;
	}
	List* pval = (List*)malloc(sizeof(List));
	pval->data = val;
	List* pCur = ph->next;
	if(pos == 0)
	{
		ph->next = pval;   // 指针断开连接过程
		pval->next = pCur;
	}
	else
	{
		for (int i = 1; i < pos; ++i)
		{
			pCur = pCur->next;
		}

		pval->next = pCur->next; //指针断开再连接的过程
		pCur->next = pval;
	}
	ph->length++; // 增加一个元素，长度要加1
	return 1;
}

List* find(pHead* ph, int val)
{
	if(ph == NULL)
	{
		printf("参数传入有误！");
		return 0;
	}
	// 遍历链表来查找元素
	List* pTmp = ph->next;
	do
	{
		if(pTmp->data == val)
		{
			return pTmp;
		}
		pTmp=pTmp->next;
	}while(pTmp->next != NULL);

	printf("没有值为%d的元素！\n", val);
	return NULL;
}

List* Delete(pHead* ph, int val)
{
	if(ph == NULL)
	{
		printf("参数传入有误！");
		return 0;
	}

	List* pval = find(ph,val);
	if(pval == NULL)
	{
		printf("没有值为%d的元素\n", val);
		return NULL;
	}

	// 遍历链表找到要删除的结点，并找出其前驱及后继结点
	List* pRe = ph->next;
	List* pCur = NULL;
	if(pRe->data == val)
	{
		ph->next = pRe->next;
		ph->length--;
		return pRe;
	}
	else
	{
		for(int i =0 ;i<ph->length;i++)
		{
			pCur = pRe->next;
			if(pCur->data == val)
			{
				pRe->next = pCur->next;
				ph->length--;
				return pCur;
			}
			pRe = pRe->next;
		}
	}
}

void Destory(pHead* ph)
{
	List* pCur = ph->next;
	List* pTmp;
	if(ph == NULL)
		printf("参数传入有误！\n");

	while(pCur->next != NULL)
	{
		pTmp = pCur->next;
		free(pCur);
		pCur=pTmp;
	}

	ph->length = 0;
	ph->next = NULL;
}

void print(pHead* ph)
{
	if(ph == NULL)
	{
		printf("参数传入有误！\n");
	}
	List* pTmp = ph->next;
	while(pTmp != NULL)
	{
		printf("%d ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}