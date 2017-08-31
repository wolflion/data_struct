#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 8
int source[] = { 63, 61, 88, 37, 92, 32, 28, 54 };

// 顺序查找  在n长的数组s里查找key的值是不是存在
int chazhao(int s[], int n, int key)  
{
	/*
	s：静态查找表，用数组表示
	n：静态查找表中数据元素的数量
	key：查找的关键字
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
	printf("输入关键字：");
	scanf("%d", &key);  //cpp文件时需要改成scanf_s()
	pos = chazhao(source, ARRAYLEN, key);
	printf("原数据表：");
	for (i = 0; i < ARRAYLEN;i++)
	{
		printf("%d  ", source[i]);
	}
	printf("\n");
	if (pos > 0)
	{
		printf("查找成功，该关键字位于数组的第%d个位置。\n", pos);
	}
	else
	{
		printf("查找失败！\n");
	}
	//getch();
	system("pause");
	return 0;
}