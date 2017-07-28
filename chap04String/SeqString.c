// 顺序串
#define _CRT_SECURE_NO_WARNINGS   // 这一系列代表啥？
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "SeqString.h"
//typedef struct string
//{
//	char *str;  // 指向串的指针
//	int length; // 串的长度
//}String;

// 赋值
void strAssign(String* s, char* p)
{
	int i = 0;
	int j = 0;
	while(p[i]!='\0')
	{
		i++; //先计算p串的长度，然后按照这个长度为s中的str开辟空间
	}
	s->str = (char *)malloc((i+1)*sizeof(char));
	// p的值赋值给s
	for (j=0;j<i-1;j++)
	{
		s->str[j]=p[j];//这里应该是p->str[j]吧？
	}
	s->str[j+1]='\0'; // 末尾赋值'\0'
	s->length = i;  // 串长度记录
}

// 求串的长度
int strLength(String *s)
{
	return s->length;
}

// 复制，将串t复制到串s中
void strCopy(String *s,String *t)
{
	int i=0;
	//为串s分配空间
	s->str = (char*)malloc((t->length)*sizeof(char));//这个地方+1或不+1，其实无所谓
	memset(s->str,'\0',t->length+1);
	for (i=0; i < (t->length); i++)
	{
		s->str[i]= t->str[i];
	}
}

// 判断两个串是不是相等
int strEqual(String *s, String *t)
{
	if(s->length == t->length)
	{
		while(*(s->str++)!=*(t->str++))
		{
			printf("两个串不相等!\n");
			return 0;
		}
		printf("两个串相等!\n");
		return 1;
	}
	printf("两个串不相等!\n");
	return 0;
}

// 连接两个串
void strConnect(String* s ,String* t)
{
	int i,j;
	int len = s->length + t->length;
	char *temp = (char*)malloc(sizeof(char)*len); //申请空间放新串
	memset(temp,'\0',s->length);
	// 将串s先存入缓存中
	for (i=0;i<s->length;i++)
	{
		temp[i] = s->str[i];
	}
	// 再将串t先存入缓存中
	for (j=0;j<t->length;j++,i++)
	{
		temp[i]=t->str[j];
	}
	temp[i]='\0';
	s->str = temp; //将串s指向temp
	//s->length = len;
	s->length = s->length + t->length;
}

// 比较两个串
int strCompare(String* s, String* t)
{
	if(s && t) // 两个串不为空
	{
		// 记录两个串的长度
		int slen=s->length;
		int tlen=t->length;
		while(*(s->str)!='\0' && *(t->str)!='\0')
		{
			if(*(s->str) < *(t->str))
				return -1;
			if(*(s->str) == *(t->str))
			{
				s->str++;
				t->str++;
			}
			if(*(s->str) > *(t->str))
				return 1;
			s->str++;
			t->str++;
		}
		// 循环结束，就是有一个串已经到尾部了，那么这种情况，必有一个是子串一个是主串
		// 比较两个串的长度大小
		if(slen < tlen)
			return -1;
		if(slen == tlen)
			return 0;
		if(slen >tlen)
			return -1;
	}
}

// 插入
void Insert(String *s,int pos,String *p)
{
	int i;
	int plen = 0;
	int j = 0;
	if(pos<0 || pos>s->length)
		return;
	//先求出p的长度
	while(p[plen] != '\0')
	{
		plen++; //循环结束后，得到p的长度
	}
	// 申请空间放新串,将串s和串p存入
	char* temp = (char*)malloc((plen+s->length)*sizeof(char));
	//代码中没用memset
	for(i=0;i<pos;i++)
	{
		temp[i]=s->str[i]; //将串s的pos位置前的存入
	}
	//将串p存入到pos位置后
	while(p[j] != '\0')
	{
		temp[i] = p[j];
		i++;
		j++;
	}
	//将剩下的串存入
	for (;pos<s->length;pos++)
	{
		temp[i] = s->str[pos];
		i++;
	}
	temp[i]='\0';
	s->str = temp;
	s->length = s->length+plen;
	printf("插入之后:%s\n",temp);
}

// 删除
void Delete(String*s,int pos,int len)
{
	char* temp = NULL;
	if(pos<0 || pos>s->length || len >s->length-pos)
		return;
	//char* temp = (char*)malloc((s->length-len)*sizeof(char));
	temp = (char*)malloc((s->length-len)*sizeof(char));
	for(i=0;i<pos;i++)
	{
		temp[i]=s->str[i]; //将串s的pos位置前的存入
	}
	int j = pos +len;
	// 将去掉子串后剩余的串复制到temp中
	for(;j<s->length;j++)
	{
		temp[i]=s->str[j];
		i++;
	}
	temp[i]='\0';
	s->str = temp;
	s->length = s->length - len;
	printf("删除之后:%s\n",temp);
}

// 输出串
void print(String *s)
{
	if(s)
		printf("%s\n",s->str);
}

int main()
{
	String s;
	String t;
	char arr[1024];
	printf("请输入要赋值给s的串：\n");
	scanf("%s",arr);
	strAssign(&s,arr);

	printf("s:");
	//printf(&s);

	printf("长度：%d\n",strLentgh(&s));

	// 再创建一个串 t
	printf("请输入要赋值给t的串：\n");
	scanf("%s",arr);
	strAssign(&t,arr);
	printf("t:");
	//printf(&t);
	printf("长度：%d\n",strLentgh(&t));
	
	printf("判断两个串是否相等：");
	strEqual(&s,&t);

	printf("比较两个串是否相等：");
	int ret = strCompare(&s,&t);
	if(ret < 0)
		printf("串t较大!\n");
	if(ret == 0)
		printf("两个串一样大!\n");
	if(ret > 0)
		printf("串s较大!\n");

	printf("将串s和串t连接起来：");
	strConnect(&s,&t);
	printf(&s);
	printf("s的长度：%d\n",strLength(&s));

	printf("将串t复制到s：");
	strCopy(&s,&t);
	printf("复制后串s的值：");
	printf(&s);

	// 在串s中插入一个串
	printf("请输入要插入的子串：\n");
	scanf("%s",arr);
	Insert(&s,3,arr);
	printf("插入串后s的长度：%d\n",strLength(&s));

	// 删除串s中的某一个子串
	Delete(&s,3,5);
	printf("删除子串后,s的长度：%d\n",strLength(&s));

	system("pause");
	return 0;
}