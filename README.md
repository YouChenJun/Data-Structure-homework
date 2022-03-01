# Data-Structure-homework
数据结构上级作业// 写的超级菜//
# 数据结构上机源码

:o:**这里是每次对应的题目||最近更新时间2022年03月01日 17:51:29**




:o:**本人学识短浅，写的代码多多少少有些错误。许多代码比较杂乱。如果感觉有建议或者想交流。QQ：848053352**



:o: :o: [学习笔记地址](https://xiaohuang.vip/)





## 数据结构-网安第01周作业

## zy01

> 调试如下程序，理解顺序(数组)存储，物理顺序和逻辑顺序相同并且连续。

![image-20220301175433187](https://gitee.com/youchenjun/webblog/raw/master/image-20220301175433187.png)



## zy02

> 调试如下程序，理解链式存储线性表，物理顺序和逻辑顺序可能不同，并且各物理单元不连续。



![image-20220301175524215](https://gitee.com/youchenjun/webblog/raw/master/image-20220301175524215.png)



### zy03



> 递归算法如下，在纸上写出调用fun(1234)时的运行结果。然后自己添加主函数验证，理解递归调用的执行过程(展开和回归)、递归出口和递归体。

![image-20220301175607493](https://gitee.com/youchenjun/webblog/raw/master/image-20220301175607493.png)



### zy04

>  递归算法如下，在纸上写出调用fun(1234)时的运行结果。然后自己添加主函数验证，理解递归调用的执行过程(展开和回归)、递归出口和递归体。

![image-20220301175629922](https://gitee.com/youchenjun/webblog/raw/master/image-20220301175629922.png)



### zy05



>  递归算法如下，在纸上写出调用fun(4)时的运行结果。然后自己添加主函数验证，理解递归调用的执行过程(展开和回归)、递归出口和递归体。



![image-20220301175706980](https://gitee.com/youchenjun/webblog/raw/master/image-20220301175706980.png)



### zy06



>  调试并理解线性表顺序存储的实现，如线性表结构定义、初始化、插入元素、删除元素、遍历显示、清空等。



### zy07

>  用顺序存储实现教材算法2.1求两集合并集。提示：以前调试过的代码中添加Qbingji函数和Qbingji1函数分别使用自定义函数和不使用自定义函数求并集，并修改主函数调用验证。主函数调用Qbingji个Qbingji1执行结果是一样的。



### zy08

> 用顺序存储实现教材算法2.2将两非递减线性表合并后仍非递减；写两个函数，一个使用线性表操作自定义函数，一个不使用自定义函数。



### zy09

> 参考求并集思想，用顺序存储实现求两集合的交集，一个不使用自定义函数。需要的数据定义、线性存储初始化显示释放空间等函数可以直接复制过来。



### zy10

>初始化n个整数到一维数组R中。设计一个时间和空间两方面尽可能高效的算法void fun(int R[],int n,int p)，将R中整数序列循环左移p（p大于0小于n）个位置，即将R中的数据序列（X0,X1,…,Xn-1）变换为（Xp,Xp+1, …,Xn-1,X0,X1,…,Xp-1），
>（1）算法设计思想：先将这n个元素的数据序列（X0,X1,…, Xp-1,Xp,…,Xn-1）原地逆置，得到的数据序列为（Xn-1,…, Xp,Xp-1,…,X1, X0），然后再将前n-p个元素（Xn-1,…, Xp）和后p个元素（Xp-1,…X1, X0）分别原地逆置，得到最终结果（Xp,Xp+1, …,Xn-1,X0,X1,…Xp-1）。
>算法可以先定义一函数void reverse(int R[],int left,int right)，实现数组R[left…right]的逆置，然后fun()函数调用reverse()三次。
>（2）算法描述：
>void reverse(int R[],int left,int right)
>//将数组R[left…right]的逆置
>{
>......
>}
>void fun(int R[],int n,int p)//循环左移
>{
>......
>}
>void main()
>{
>int a[]={...}
>fun(a,...);
>显示a数组
>}
>完善主函数，两自定义函数，运行验证。
>（2010年全国统考考研原题）



### zy11

> 编程显示如下杨辉三角，要求各值使用递归函数int fun(int hang,int lie)计算。 for(i=1;i<=9;i++){     for(j=1;j<=i;j++)         printf("%4d",fun(i,j));     printf("\n"); }



![image-20220301175900393](https://gitee.com/youchenjun/webblog/raw/master/image-20220301175900393.png)

### zy12

> 编程显示斐波那数列前20项，要求各值使用递归函数int fun(int n)计算。

