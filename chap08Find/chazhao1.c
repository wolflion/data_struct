#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 8
int source[ARRAYLEN+1] = { 63, 61, 88, 37, 92, 32, 28, 54 };

// ˳�����  ��n��������s�����key��ֵ�ǲ��Ǵ���
int chazhao(int s[], int n, int key)  
{
	/*
	s����̬���ұ��������ʾ
	n����̬���ұ�������Ԫ�ص�����
	key�����ҵĹؼ���
	*/
	int i;
	for (i = 0; s[i]!=key;i++)  //�ڱ��ĩ������һ����Ԫ����key,�����Ͳ���Ҫÿ�ν���i<n�ıȽ��ˡ�
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
	input :54
	output: find success
	*/
	int key, i, pos;
	printf("����ؼ��֣�");
	scanf_s("%d", &key);
	
	// add line ����keyֵ�����һ��Ԫ��
	source[ARRAYLEN] = key;

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