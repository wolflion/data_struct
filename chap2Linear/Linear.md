##  缘起

##  内容
###  顺序表
+ 在高级语言中，顺序存储是用数组来实现的。
+ 在顺序表中，插入或删除元素，效率会特别低。
	+ 插入大量数据，很难保证空间是否充足。分配好的空间，再重新分配空间，非常麻烦。
+ 顺序表中的**头结点** `struct TSeqList{int capacity;int length;int* node;}`//node[capacity]，为指针数组 

###  链表
+ 头结点(length|next)->结点(value|next)->...->结点(value|NULL)

###  双链表
+ 头结点(length|next)->结点(NULL|value|next)->...->结点(pre|value|NULL)

###  循环链表
####  单循环链表
####  多重循环链表

