/*
 * 20160420
 * 直接插入排序
 * created by lionel
 */

# if 0
#include <stdio.h>
#include <stdlib.h>
#define LEN 6

void insertSort(int a[LEN],int n)
{
	// for()里不能定义临时变量
	int i,j,f;
	// 循环从第2个元素开始
	for (i = 1; i < LEN; i++)
	{
		if(a[i] < a[i-1])
		{
			int tmp = n;
			for(j=i-1;j>0&&a[j]>tmp; j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = tmp;
		}
	}

	// 输出
	for (f=0; f<LEN; f++)
	{
		printf("%d\n",a[f]);
	}
}

int main()
{
	int arr[LEN] = {1,2,4,10,15};
	insertSort(arr,30);

	system("pause");
	return 0;
}
# endif


/*
 * 20160510
 */
#include <iostream>
using namespace std;
int main()
{
	int a[] = {98,76,109,34,67,190,80,12,14,89,1};
	int len = sizeof(a)/sizeof(a[0]);
	int j;
	// 只是stdio.h里面无法在for()里定义int j,在iostream里还是可以的
	// 循环从第2个元素开始
	for (int i=1;i<len;i++)
	{
		// 第1个元素 大于 第2个元素
		if(a[i] < a[i-1])
		{
			int temp = a[i];
			for(j=i-1;j>=0;&&a[j]>temp;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]= temp;
		}
	}

	for(int f=0;f<len;f++)
	{
		cout << a[f] << " ";
	}

	system("pause");
	return 0;
}
