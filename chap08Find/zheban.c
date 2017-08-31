#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 10
int source[] = { 6, 12, 28, 32, 53, 65, 69, 83, 90, 92 };

// 折半查找  在n长的数组s里查找key的值是不是存在
int zheban(int s[], int n, int key)  
{
	/*
	s：静态查找表，用数组表示
	n：静态查找表中数据元素的数量
	key：查找的关键字
	*/
	int low,high,mid;
	low = 0;
	high = n - 1;
	while (low<=high)  //查找范围含至少1个元素
	{
		mid = (low + high) / 2;  //计算中间位置序号
		if (s[mid] == key)
		{
			return mid;
		}
		else if (s[mid]>key)   // 中间元素大于关键字
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
	printf("输入关键字：");
	scanf_s("%d", &key);

	pos = zheban(source, ARRAYLEN, key);
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