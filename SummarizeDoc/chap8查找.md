

## 内容
+ 衡量查找算法效率的标准是 **平均查找长度（ Average Search Length）** =比较次数C*查找到某记录的概率P(默认1/n)。
+ 查找的基本方法分为两大类
    + 比较式查找法
        + 基于线性表的查找法
        + 基于树的查找法
    + 计算式查找法 
        + 哈希查找法  

###  基于静态表的查找
+ 顺序查找
    + 思想：从表中第一个记录开始，逐个比较，直到找到为止。
    + 适用：线性表的顺序存储结构、链式存储结构。
    + 查找长度：
        + 只考虑成功：(n+1)/2=1/n*(n-i+1)的求和
        + 成功和失败：3/4*(n+1)
    + 代码：[查找.c](https://github.com/wolflion/data_struct/blob/master/chap08Find/chazhao.c)   [改进版查找.c](https://github.com/wolflion/data_struct/blob/master/chap08Find/chazhao1.c)
+ 折半查找
    + 思想：用k与中间位置的关键字比较，然后再左或右区间比较，循环比较，直到找到。
    + 前提：必须确保查找表有序。
    + 适用：线性表的顺序存储结构
    + 查找长度：
        + 查找成功时：log2(n+1)-1
    + 代码：[折半查找.c](https://github.com/wolflion/data_struct/blob/master/chap08Find/zheban.c)
+ 分块查找（索引顺序查找）
    + 前提：每一块中的结点存放不一定有序，但块与块之间是有序的。
    + 思想：首先查找索引表，以确定待查的结点在哪一块，然后到块内进行顺序查找。**分块的方法，一般是块的长度均分，最后一块可以不满。**
    + 适用：
    + 查找长度：log2(n/s+1)+s/2
    + 代码：[别人的实现](http://www.cnblogs.com/hanjun/archive/2013/02/05/2892826.html)

###  基于动态树的查找
+ 二叉排序树BST（Binary Sort Tree）
+ 平衡二叉树AVL（Balanced Binary Tree）
+ B-树
+ B+树


###  哈希表的查找


##  履历
+ 20170908 静态表的查找整理（三个算法）