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
		printf("������������");
		return 0;
	}
	return ph->length;
}

int Insert(pHead* ph,int pos,int val)
{
	if(ph == NULL || pos < 0 || pos > ph->length)
	{
		printf("������������");
		return 0;
	}
	List* pval = (List*)malloc(sizeof(List));
	pval->data = val;
	List* pCur = ph->next;
	if(pos == 0)
	{
		ph->next = pval;   // ָ��Ͽ����ӹ���
		pval->next = pCur;
	}
	else
	{
		for (int i = 1; i < pos; ++i)
		{
			pCur = pCur->next;
		}

		pval->next = pCur->next; //ָ��Ͽ������ӵĹ���
		pCur->next = pval;
	}
	ph->length++; // ����һ��Ԫ�أ�����Ҫ��1
	return 1;
}

List* find(pHead* ph, int val)
{
	if(ph == NULL)
	{
		printf("������������");
		return 0;
	}
	// ��������������Ԫ��
	List* pTmp = ph->next;
	do
	{
		if(pTmp->data == val)
		{
			return pTmp;
		}
		pTmp=pTmp->next;
	}while(pTmp->next != NULL);

	printf("û��ֵΪ%d��Ԫ�أ�\n", val);
	return NULL;
}

List* Delete(pHead* ph, int val)
{
	if(ph == NULL)
	{
		printf("������������");
		return 0;
	}

	List* pval = find(ph,val);
	if(pval == NULL)
	{
		printf("û��ֵΪ%d��Ԫ��\n", val);
		return NULL;
	}

	// ���������ҵ�Ҫɾ���Ľ�㣬���ҳ���ǰ������̽��
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
		printf("������������\n");

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
		printf("������������\n");
	}
	List* pTmp = ph->next;
	while(pTmp != NULL)
	{
		printf("%d ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}