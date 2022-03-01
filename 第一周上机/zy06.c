//插入元素、删除元素、遍历显示、清空
#include <stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100//线性表的初始长度
#define LISTINCREMENT 10//线性表的长度增量
typedef struct {
	int *elem;
	int length;//当前元素个数
	int listsize; //当前分配的存储容量大小
} Sqlist; //定义类型
int Initlist_Sq(Sqlist *l) {
	l->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int)); //内存中开辟空间
	if (!l->elem)
		return 0;
	l->length = 0;
	l->listsize = LIST_INIT_SIZE; //初始化长度
	return 1;
}
int Listinsert_Sq(Sqlist *l, int k, int e) { /*1<=k<=length+1*/
	int *p, *q;
	if (k < 1 || k > l->length + 1) //如果插入位置不合法
		return 0;
	if (l->length >= l->listsize) {//当前长度到达100，那么重新申请增量空间
		int i, *newelem = (int*)malloc((l->listsize + LISTINCREMENT) * sizeof(int));
		if (!newelem)
			return  0;
		for (i = 0; i < l->length; i++) {
			newelem[i] = l->elem[i];
		}
		free(l->elem);
		l->elem = newelem;
	}
	q = &(l->elem[k - 1]);
	for (p = &(l->elem[l->length - 1]); p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	l->length++;
	return 1;
}
//插入到n+1位置，需要移动0个
//插入到第1个位置，需要后移n个
//评价移动n/2
//插入到i位置，需要移动n-(k-1)
void DestroyList(Sqlist *l) {
	free(l->elem);//释放空间
}
void PrintList(Sqlist *l) {
	int i = 0;
	while (i < l->length) {
		printf("%d ", l->elem[i++]);
	}
	printf("\n");
}
void ClearList(Sqlist *l) {
	l->length = 0; //设置当前元素个数为0
}
int ListEmpty(Sqlist*l) {
	if (l->length == 0)
		return 1;
	else
		return 0;

}
int ListLength(Sqlist *l) {
	return l->length;//元素个数
}
void GetElem(Sqlist *l, int i, int *e) { /*1<=i<=1-length*/
	*e = l->elem[i - 1];
}//随机存取，O(1)

int LocatElem(Sqlist *l, int e) {
	int  i;
	for (i = 0; i <= 0; i++) {
		for (i = 0; i < l->length; i++) {
			if (l->elem[i] == e) {
				return i + 1;
			}
			return 0;
		}
	}
}
//最好比较一次，最坏比较n次,平均比较(1+n)/2

void ListDelete(Sqlist * l, int k, int *e) {
	int i;
	*e = l->elem[k - 1];
	for (i = k; i < l->length; i++) {
		l->elem[i - 1] = l->elem[i];
	}
	l->length--;
}
//删除的是第一个数字，前移n-1
//删除第n个，前移0
//评价移动(n-1)/2


int main() {
	Sqlist list;//list有elem ,个数,容量三个成员变量
	int m;
	Initlist_Sq(&list);
	for (m = 1; m <= 20; m++)
		Listinsert_Sq(&list, m, m * m);

	PrintList(&list);
	ListDelete(&list, 19, &m);
	printf("%d\n", m);
	PrintList(&list);
	DestroyList(&list);
}



