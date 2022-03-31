#include<stdio.h>
#include<malloc.h>
typedef struct bitnode {
	int data;
	struct bitnode *lchild, *rchild;
} bitnode, *bitree; //定义二叉树结点类型

bitree create() {
	int d;
	bitnode *T;
	scanf("%d", &d);
	if (d == 0) T = NULL;
	else {
		T = (bitnode *)malloc(sizeof(bitnode));
		T->data = d;
		T->lchild = create();
		T->rchild = create();
	}
	return T;
}

int a[20] = {1, 3, 5, 0, 0, 7, 4, 6, 0, 0, 3, 5, 0, 0, 3, 0, 0}, a_i = 0;
void creat_sz(bitree *T) {
	if (a[a_i] == 0) {
		(*T) = NULL;
		a_i++;

	} else {
		(*T) = (bitnode *)malloc(sizeof(bitnode));
		(*T)->data = a[a_i];
		a_i++;
		creat_sz(&(*T)->lchild);
		creat_sz(&(*T)->rchild);
	}
}

typedef struct {
	bitree data[60];//结点指针类型
	int bz[60];
	int top;
} stack;
//定义栈
//为二叉树先序中序非递归做准备
void push(stack *st, bitree tp,int bz) { //进栈
	if (st->top == 60 - 1)
		printf("overflow");
	else {
		st->top++;
		st->data[st->top] = tp;
		st->bz[st->top]=bz;//这里加了一个标志存着
	}
}

bitree pop(stack *st,bitree *tp,int *bz) { //出栈
	bitree p;
	if (st->top == -1) {
		printf("underflow");
		return 0;
	} else {
		*tp = st->data[st->top];
		*bz=st->bz[st->top]--;//出标志
		st->top--;
	}
}

void blhfd(bitree t)//后序，非递归
{
	stack s;
	int tag;
	s.top=-1;
	while((t!=NULL)||(s.top!=-1)){
		if(t!=NULL){
			tag=0;
			push(&s,t,tag);
			t=t->lchild;//第一次进
		}
		else
		{
			pop(&s,&t,&tag);
			if(tag==0){
				tag=1;//找右子数字，标记为1，右子树处理完成
				push(&s,t,tag);
				t=t->rchild;
			}
			else
			{
				printf("%d ",t->data);
				t=NULL;
			}
		}
	}
}

void ft(bitree t) {
	if (t != NULL) {
		ft(t->lchild);
		ft(t->rchild);
		free(t);
	}
}

void main() {
	bitnode *t = NULL;
	//t = create();
	creat_sz(&t);
	printf("\n非递归后序遍历为：");
	blhfd(t);
	ft(t);
}
