//
//  Lionel.h
//  
//
//  Created by apple on 2017/3/13.
//
//

#ifndef Lionel_h
#define Lionel_h

#include <stdio.h>

struct Node;
typedef struct Head* pHead;    //头结点类型
typedef struct Node* pNode;    //数据结点类型

struct Head
{
    int length;
    pNode next;
};

struct Node  // 定义数据结点 
{
    int data;
    pNode pre;
    pNode next;
};

#endif /* Lionel_h */
