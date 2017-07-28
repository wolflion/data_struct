// ˳��
#define _CRT_SECURE_NO_WARNINGS   // ��һϵ�д���ɶ��
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "SeqString.h"
//typedef struct string
//{
//	char *str;  // ָ�򴮵�ָ��
//	int length; // ���ĳ���
//}String;

// ��ֵ
void strAssign(String* s, char* p)
{
	int i = 0;
	int j = 0;
	while(p[i]!='\0')
	{
		i++; //�ȼ���p���ĳ��ȣ�Ȼ�����������Ϊs�е�str���ٿռ�
	}
	s->str = (char *)malloc((i+1)*sizeof(char));
	// p��ֵ��ֵ��s
	for (j=0;j<i-1;j++)
	{
		s->str[j]=p[j];//����Ӧ����p->str[j]�ɣ�
	}
	s->str[j+1]='\0'; // ĩβ��ֵ'\0'
	s->length = i;  // �����ȼ�¼
}

// �󴮵ĳ���
int strLength(String *s)
{
	return s->length;
}

// ���ƣ�����t���Ƶ���s��
void strCopy(String *s,String *t)
{
	int i=0;
	//Ϊ��s����ռ�
	s->str = (char*)malloc((t->length)*sizeof(char));//����ط�+1��+1����ʵ����ν
	memset(s->str,'\0',t->length+1);
	for (i=0; i < (t->length); i++)
	{
		s->str[i]= t->str[i];
	}
}

// �ж��������ǲ������
int strEqual(String *s, String *t)
{
	if(s->length == t->length)
	{
		while(*(s->str++)!=*(t->str++))
		{
			printf("�����������!\n");
			return 0;
		}
		printf("���������!\n");
		return 1;
	}
	printf("�����������!\n");
	return 0;
}

// ����������
void strConnect(String* s ,String* t)
{
	int i,j;
	int len = s->length + t->length;
	char *temp = (char*)malloc(sizeof(char)*len); //����ռ���´�
	memset(temp,'\0',s->length);
	// ����s�ȴ��뻺����
	for (i=0;i<s->length;i++)
	{
		temp[i] = s->str[i];
	}
	// �ٽ���t�ȴ��뻺����
	for (j=0;j<t->length;j++,i++)
	{
		temp[i]=t->str[j];
	}
	temp[i]='\0';
	s->str = temp; //����sָ��temp
	//s->length = len;
	s->length = s->length + t->length;
}

// �Ƚ�������
int strCompare(String* s, String* t)
{
	if(s && t) // ��������Ϊ��
	{
		// ��¼�������ĳ���
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
		// ѭ��������������һ�����Ѿ���β���ˣ���ô�������������һ�����Ӵ�һ��������
		// �Ƚ��������ĳ��ȴ�С
		if(slen < tlen)
			return -1;
		if(slen == tlen)
			return 0;
		if(slen >tlen)
			return -1;
	}
}

// ����
void Insert(String *s,int pos,String *p)
{
	int i;
	int plen = 0;
	int j = 0;
	if(pos<0 || pos>s->length)
		return;
	//�����p�ĳ���
	while(p[plen] != '\0')
	{
		plen++; //ѭ�������󣬵õ�p�ĳ���
	}
	// ����ռ���´�,����s�ʹ�p����
	char* temp = (char*)malloc((plen+s->length)*sizeof(char));
	//������û��memset
	for(i=0;i<pos;i++)
	{
		temp[i]=s->str[i]; //����s��posλ��ǰ�Ĵ���
	}
	//����p���뵽posλ�ú�
	while(p[j] != '\0')
	{
		temp[i] = p[j];
		i++;
		j++;
	}
	//��ʣ�µĴ�����
	for (;pos<s->length;pos++)
	{
		temp[i] = s->str[pos];
		i++;
	}
	temp[i]='\0';
	s->str = temp;
	s->length = s->length+plen;
	printf("����֮��:%s\n",temp);
}

// ɾ��
void Delete(String*s,int pos,int len)
{
	char* temp = NULL;
	if(pos<0 || pos>s->length || len >s->length-pos)
		return;
	//char* temp = (char*)malloc((s->length-len)*sizeof(char));
	temp = (char*)malloc((s->length-len)*sizeof(char));
	for(i=0;i<pos;i++)
	{
		temp[i]=s->str[i]; //����s��posλ��ǰ�Ĵ���
	}
	int j = pos +len;
	// ��ȥ���Ӵ���ʣ��Ĵ����Ƶ�temp��
	for(;j<s->length;j++)
	{
		temp[i]=s->str[j];
		i++;
	}
	temp[i]='\0';
	s->str = temp;
	s->length = s->length - len;
	printf("ɾ��֮��:%s\n",temp);
}

// �����
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
	printf("������Ҫ��ֵ��s�Ĵ���\n");
	scanf("%s",arr);
	strAssign(&s,arr);

	printf("s:");
	//printf(&s);

	printf("���ȣ�%d\n",strLentgh(&s));

	// �ٴ���һ���� t
	printf("������Ҫ��ֵ��t�Ĵ���\n");
	scanf("%s",arr);
	strAssign(&t,arr);
	printf("t:");
	//printf(&t);
	printf("���ȣ�%d\n",strLentgh(&t));
	
	printf("�ж��������Ƿ���ȣ�");
	strEqual(&s,&t);

	printf("�Ƚ��������Ƿ���ȣ�");
	int ret = strCompare(&s,&t);
	if(ret < 0)
		printf("��t�ϴ�!\n");
	if(ret == 0)
		printf("������һ����!\n");
	if(ret > 0)
		printf("��s�ϴ�!\n");

	printf("����s�ʹ�t����������");
	strConnect(&s,&t);
	printf(&s);
	printf("s�ĳ��ȣ�%d\n",strLength(&s));

	printf("����t���Ƶ�s��");
	strCopy(&s,&t);
	printf("���ƺ�s��ֵ��");
	printf(&s);

	// �ڴ�s�в���һ����
	printf("������Ҫ������Ӵ���\n");
	scanf("%s",arr);
	Insert(&s,3,arr);
	printf("���봮��s�ĳ��ȣ�%d\n",strLength(&s));

	// ɾ����s�е�ĳһ���Ӵ�
	Delete(&s,3,5);
	printf("ɾ���Ӵ���,s�ĳ��ȣ�%d\n",strLength(&s));

	system("pause");
	return 0;
}