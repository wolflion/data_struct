#include <stdlib.h>
#include <memory.h>
#include <stdio.h>


#ifndef _SEQSTRING_H_
#define _SEQSTRING_H_

typedef struct string
{
	char *str;  // 指向串的指针
	int length; // 串的长度
}String;


#endif