#include<stdio.h>
#include<stdlib.h>
typedef struct bithrnode {
	int data;
	int ltag, rtag;
	struct bithrnode *lchild, *rchild;
} bithrnode, *bithree;
int a[20] = {1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0}, a_i = 0;
void creattree(bithree *t) { //创建二叉树
	if (a[a_i] == 0) {
		(*t) = NULL;
		a_i++;
	} else {
		(*t) = (bithrnode *)malloc(sizeof(bithrnode));
		(*t)->data = a[a_i];
		a_i++;
		(*t)->ltag = 0;
		(*t)->rtag = 0;
		creattree(&(*t)->lchild);
		creattree(&(*t)->rchild);
	}
}
bithree pre = NULL; //全局变量，指向最近前一节点
void InThreading(bithree p) {//中序对二叉树进行线索化
	//如果当前结点存在
	if (p) {
		InThreading(p->lchild);//递归当前结点的左子树，进行线索化
		//如果当前结点没有左孩子，左标志位设为1，左指针域指向上一结点 pre
		if (!p->lchild) {
			p->ltag = 1;
			p->lchild = pre;
		}
		//如果 pre 没有右孩子，右标志位设为 1，右指针域指向当前结点。
		if (pre && !pre->rchild) {
			pre->rtag = 1;
			pre->rchild = p;
		}
		pre = p; //pre指向当前结点
		InThreading(p->rchild);//递归右子树进行线索化
	}
}
void blzxs(bithree t) { //线索二叉树中序遍历
	bithree p = t->lchild;
	while (p != t) {
		//一直找左孩子，最后一个为中序序列中排第一的
		while (p->ltag == 0) {
			p = p->lchild;
		}
		printf("%d ", p->data);  //操作结点数据
		//当结点右标志位为1时，直接找到其后继结点
		while (p->rtag == 1 && p->rchild != NULL) {
			p = p->rchild;
			printf("%d ", p->data);
		}
		//否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
		p = p->rchild;
	}
}

void blzxs_nx(bithree t) { //逆序
	bithree p = t->rchild; //指向右边

	while (p != t) {
		printf("%d ", p->data);
		if (p->ltag == 1) {
			p = p->lchild;
		} else {
			p = p->lchild;
			while (p->rtag == 0) {
				p = p->rchild;
			}
		}
	}
}

void inOrderReverse(bithree T) {//逆
	bithree p = T;
	while (p->rchild != NULL) {//一直找到最右边的
		p = p->rchild;
	}
	while (p) {
		printf("%d ", p->data);
		if(p->ltag==1){
			p=p->lchild;
		}
		else
		{
			p=p->lchild;
			while(p->rtag==0){
				p=p->rchild;
			}
		}
	}
}

void bl(bithree t) { //中序遍历，递归
	if (t) {
		bl(t->lchild);
		printf("%d ", t->data);
		bl(t->rchild);
	}
}
void main() {
	bithree t = NULL, s = NULL;
	creattree(&t);
	bl(t);//递归遍历
	printf("\n");
//	s = (bithree)malloc(sizeof(bithrnode)); //创建附加的头节点
//	s->ltag = 0;
//	s->rtag = 1;
//	s->rchild = s; //右孩子是自己
//	if (t == NULL) {
//		s->lchild = s;
//	} else
	InThreading(t);//线索化
	//blzxs_nx(t);
	inOrderReverse(t);
	printf("\n");
	blzxs(t);
}


