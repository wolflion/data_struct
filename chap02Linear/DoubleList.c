//
//  Lionel.c
//  
//
//  Created by apple on 2017/3/13.
//
//

#include "Lionel.h"
#include <stdio.h>
#include <stdlib.h>

// 创建双链表
pHead DlistCreate()
{
    pHead ph = (pHead)malloc(sizeof(struct Head));
    if(ph == NULL)
        printf("allocation error\n");
    
    // 初始化头结点中的数据
    ph->length = 0;
    ph->next = NULL;
    return ph;  // 将头结点返回
}

// 获取链表的长度
int getDlistLength(pHead ph)
{
    if(ph == NULL) // ph->next == NULL 区别
        printf("error\n");
    return ph->length;
}

// 判断双链表是否为空
int isEmpty(pHead ph)
{
    if(ph == NULL)
        printf("error\n");
    if(ph->length == 0)  // 长度为0,则为空
        return 1;
    else
        return 0;
}

// 在链表的pos位置插入元素val
int DlistInsert(pHead ph, int pos, int val)
{
    pNode = pval = NULL;
    if(ph==NULL || pos <0 || pos>ph->length)
        printf("error\n");
    
    pval = (pNode)malloc(sizeof(struct Node));
    pval->data = val;  // 将值val保存到此结点中
    
    // 判断在哪个位置插入元素，先判断链表是否为空
    if(isEmpty(ph))
    {
        ph->next = pval;  // 将结点插入到头结点后
        pval->next = NULL;
        pval->pre = NULL;   // 第一个结点不回指头结点
    }
    else
    {
        pNode pCur = ph->next;
        if(pos == 0)
        {
            ph->next = pval;
            pval->pre = NULL;
            pval->next = pCur;
            pCur->pre = pval;
        }
        else
        {
            for (int i=1; i<pos; i++)
            {
                pCur=pCur->next;
            }
            
            pval->next = pCur->next;
            pCur->next->pre = pval;
            pval->pre = pCur;
            pCur->next = pval;
        }
    }
    ph->length++;
    return 1;
}


