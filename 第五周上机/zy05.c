#include<stdio.h>
#include<stdlib.h>
#define max 40
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

int a[17]={1,4,0,0,9,3,0,0},a_i=0;//数组模拟遍历

void create_sz(bitnode **T)
{
	if(a[a_i]==0){
		(*T)=NULL;
		a_i++;
	}
	else
	{
		(*T)=(bitnode *)malloc(sizeof(bitnode));
		(*T)->data=a[a_i];
		a_i++;
		create_sz(&(*T)->lchild);
		create_sz(&(*T)->rchild);		
	}

}
void ccbl(bitnode *t)//层次遍历
{
	bitnode *dl[max],*p=NULL;
	int f=0,r=0;
	if(t!=NULL){//入队
		dl[r]=t;
		r++;
	}
	while(f!=r){
		p=dl[f];
		f++;//出队
		printf("%d ",p->data);
		if(p->lchild!=NULL){
			dl[r]=p->lchild;
			r++;
		}
		if(p->rchild!=NULL){
			dl[r]=p->rchild;
			r++;
		}
	}
	
}
void blx(bitnode *t)//先序遍历
{
	if(t){
		printf("%d ",t->data);
		blx(t->lchild);
		blx(t->rchild);
	}
}
void blz(bitnode *t)//中序遍历
{
	if(t){
		blz(t->lchild);
		printf("%d ",t->data);
		blz(t->rchild);
	}
}
void blh(bitnode *t)//后序遍历
{
	if(t){
		blh(t->lchild);
		blh(t->rchild);
		printf("%d ",t->data);
	}
}
void freetree(bitnode *t)//释放
{
	if(t!=NULL){
		freetree(t->lchild);
		freetree(t->rchild);
		freetree(t);
	}
}
void main()
{
	
	bitnode *t=NULL;
	t=creat();
	//create_sz(&t);
	ccbl(t);
	freetree(t);
}
