#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 8
int source[] = { 63, 61, 88, 37, 92, 32, 28, 54 };

// ˳�����  ��n��������s�����key��ֵ�ǲ��Ǵ���
int chazhao(int s[], int n, int key)  
{
	/*
	s����̬���ұ��������ʾ
	n����̬���ұ�������Ԫ�ص�����
	key�����ҵĹؼ���
	*/
	int i;
	for (i = 0; i < n&&s[i]!=key;i++)
	{
		;
	}
	if (i < n)
		return i;
	else
		return -1;
}

int main()
{
	/*
	input :61
	output: find success
	*/
	int key, i, pos;
	printf("����ؼ��֣�");
	scanf("%d", &key);  //cpp�ļ�ʱ��Ҫ�ĳ�scanf_s()
	pos = chazhao(source, ARRAYLEN, key);
	printf("ԭ���ݱ�");
	for (i = 0; i < ARRAYLEN;i++)
	{
		printf("%d  ", source[i]);
	}
	printf("\n");
	if (pos > 0)
	{
		printf("���ҳɹ����ùؼ���λ������ĵ�%d��λ�á�\n", pos);
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}
	//getch();
	system("pause");
	return 0;
}