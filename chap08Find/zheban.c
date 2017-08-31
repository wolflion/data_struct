#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 10
int source[] = { 6, 12, 28, 32, 53, 65, 69, 83, 90, 92 };

// �۰����  ��n��������s�����key��ֵ�ǲ��Ǵ���
int zheban(int s[], int n, int key)  
{
	/*
	s����̬���ұ��������ʾ
	n����̬���ұ�������Ԫ�ص�����
	key�����ҵĹؼ���
	*/
	int low,high,mid;
	low = 0;
	high = n - 1;
	while (low<=high)  //���ҷ�Χ������1��Ԫ��
	{
		mid = (low + high) / 2;  //�����м�λ�����
		if (s[mid] == key)
		{
			return mid;
		}
		else if (s[mid]>key)   // �м�Ԫ�ش��ڹؼ���
		{
			high = mid - 1;
		}
		else  
		{
			low = mid + 1;
		}
	}
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

	pos = zheban(source, ARRAYLEN, key);
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