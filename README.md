# -Datatructur
记录我学习数据结构过程，采用C语言编写

下面介绍下C语言中多文件编译

`gcc main.c 1.cpp -o out  `

列举所有要编译的文件 #其中.h文件不需要编译进去，最终会产生一个out的二进制文件

`./out`                                      

 执行第一步编译产生的二进制文件out



多文件编译具体内容可参考我的[博客](https://www.niuboom.cn/index.php/2022/01/14/g%e4%bd%bf%e7%94%a8%e6%8c%87%e5%8d%97/) ，文中我主要讨论cpp使用g++的多文件编译，c文件同理，将g++换成gcc即可。
