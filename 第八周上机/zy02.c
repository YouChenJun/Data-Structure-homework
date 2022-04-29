#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 99999
typedef struct snode { //哈夫曼树结点结构
	char c;
	int qz;
	char bm[30];
	int lchild, rchild, bz; //bz为1时表示在权数列中，bz为0表示不在权值数列中，存的是下标
} snode;
typedef struct sz { //定义数组存储的哈夫曼树
	snode *arr;//指向结点数组的指针
	int num_yz;//哈夫曼树叶子结点个数
} hfms;
typedef struct cnode {
	//定义链表存储的结点
	char c;
	int qz;
	struct cnode *next;
} hconde;
void tjzf(char *a, hfms *s) { //将字符串a添加到哈夫曼树结点数组
	int i = 0;
	hconde *hd = (hconde *)malloc(sizeof(hconde)), *p; //创建头结点
	hd->next = NULL;
	while (a[i] != '\0') { //统计a中字符，创建链表存储字符，计算权值

		p = hd->next;
		while (p != NULL) {
			//若当链表中存在存储a[i]的结点，那么这个权值++
			if (p->c == a[i]) {
				p->qz++;
				break;
			}
			p = p->next;
		}
		if (p == NULL) {
			//若p为空，爸妈当前链表没有存储字符a[i]的结点，那么开辟空间
			hconde *t = (hconde*)malloc(sizeof(hconde));
			t->c = a[i];
			t->qz = 1;
			t->next = hd->next; //头插法，将t插入链表
			hd->next = t;
		}
		i++;
	}
	i = 0;
	p = hd->next;
	while (p != NULL) {
		i++;
		p = p->next; //计算链表长度
	}
	s->num_yz = i; //哈夫曼树叶子结点长度=链表长度
	s->arr = (snode*)malloc(sizeof(snode) * (s->num_yz * 2 - 1));
	//开辟空间，空间大小/节点数=2*n0-1
	p = hd->next;
	i = 0;
	while (p != NULL) {
		//将链表中个结点的数据存入数组中
		s->arr[i].c = p->c;
		s->arr[i].qz = p->qz;
		strcpy(s->arr[i].bm, "");
		s->arr[i].lchild = -1; //存储字符都是叶子结点，无左右
		s->arr[i].rchild = -1;
		s->arr[i].bz = 1; //权值在数列中
		p = p->next;
		i++;
	}
	for (; i < s->num_yz * 2 - 1; i++) {
		//对剩下的结点初始化
		s->arr[i].c = '\0';
		s->arr[i].qz = 0;
		strcpy(s->arr[i].bm, "");
		s->arr[i].lchild = -1;
		s->arr[i].rchild = -1;
		s->arr[i].bz = 0; //权不在数列
	}
	p = hd->next;
	while (p != NULL) {
		hd->next = p->next;
		free(p);
		p = hd->next;
	}
	free(hd);

}
void js(hfms s) {//创建哈夫曼树
	int i, minlxb, min2xb, minxb, minz, k;
	for (k = s.num_yz; k < s.num_yz * 2 - 1; k++) {
		//对为存储的字符的节点存入数据，权值越大，在数组中的位置越靠后
		minxb = -1;
		minz = max;
		for (i = 0; i < s.num_yz * 2 - 1; i++) {
			if (s.arr[i].bz == 1 && s.arr[i].qz < minz) {
				minz = s.arr[i].qz; //将权树列最小的权值赋给minz
				minxb = i; //将权值列中最小值所属的小标
			}
		}
		minlxb = minxb;
		s.arr[minlxb].bz = 0; //将最小权值所属元素移出权数列
		minxb = -1;
		minz = max;
		for (i = 0; i < s.num_yz * 2 - 1; i++) {
			if (s.arr[i].bz == 1 && s.arr[i].qz < minz) {
				minz = s.arr[i].qz; //将当前权值树列最小的权值赋给
				minxb = i; //当前权值列中最小权值
			}
		}
		min2xb = minxb;
		s.arr[min2xb].bz = 0; //把当前第二小权值所属的元素移除

		s.arr[k].qz = s.arr[minlxb].qz + s.arr[min2xb].qz; //
		s.arr[k].bz = 1; //该结点添加进权数列
		s.arr[k].lchild = minlxb;
		s.arr[k].rchild = min2xb;

	}
}
void bm(hfms s, int xb, char cc[30], int t) { //先序遍历进行编码
	if (t == 0) { //如果噶节点为父亲结点的左孩子
		strcat(s.arr[xb].bm, cc);
		strcat(s.arr[xb].bm, "0");
	} else if (t == 1) { //若该节点为父亲结点的右孩子
		//先把父亲结点的bm赋值给该节点的bm，然后该节点的bm+1
		strcat(s.arr[xb].bm, cc);
		strcat(s.arr[xb].bm, "1");
	}
	if (s.arr[xb].lchild != -1) { //如果左孩子存在，传入编码0
		bm(s, s.arr[xb].lchild, s.arr[xb].bm, 0);
	}
	if (s.arr[xb].rchild != -1) {
		//如果右孩子存在....
		bm(s, s.arr[xb].rchild, s.arr[xb].bm, 1);
	}
}
void main() {
	int i;
	char a[200] = "abbccccdddddddddd";
	hfms s;
	tjzf(a, &s);
	js(s);
	bm(s, s.num_yz * 2 - 1 - 1, "", - 1);
	for (i = 0; i <= s.num_yz - 1; i++) {
		printf("%c:%d:%s\n", s.arr[i].c, s.arr[i].qz, s.arr[i].bm);
	}
	free(s.arr);
}
