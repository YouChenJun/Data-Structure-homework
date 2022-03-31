#include<stdio.h>
#include<stdlib.h>
typedef struct bitnode
{
	int data;
	struct bitnode *lchild,*rchild;
}bitnode;
bitnode *creat()
{
	int d;
	bitnode *T;
	scanf("%d",&d);
	if(d==0){
		T=NULL;
	}else{
		T=(bitnode *)malloc(sizeof(bitnode));
		T->data=d;
		T->lchild=creat();
		T->rchild=creat();
		
	}
	return T;
}
void blx(bitnode *t)//ÏÈÐò±éÀú
{
	if(t){
		printf("%d ",t->data);
		blx(t->lchild);
		blx(t->rchild);
	}
}
void main()
{
	bitnode *t=NULL;
	t=creat();
	blx(t);
}
