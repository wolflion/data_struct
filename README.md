data_struct
===========

learn data_struct

##   实践过程中的想法
+ 2017-03-14
	+ 实践Chap3Stack_Sequence时，不想每个类都有个main，想一个章节一个mian，最后全书是一个main。
		+ 这种最好的实践方式是写makefile，正好我的mac下可以支持gcc，这个需要实践一下。
	+ **VS编译器中关于C的哪些坑**
		+ 同样在写Chap3Stack_Sequence例子`testSeqStack()`时，自己用的是vs2010编译器，提示*[error C2275](http://blog.csdn.net/mfcing/article/details/52815712)* ，原因是：**由于c的编译器要求将变量的申明放在一个函数块的头部**
		+ 比如不支持`for(int i=0;i<n;i++)`//中i在语句中定义