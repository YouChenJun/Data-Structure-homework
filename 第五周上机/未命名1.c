#include<stdio.h>
#include<stdlib.h>
#define max 40
typedef long long ll;
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
ll max=-10000;
int flag=0,i;
void ccbl(bitnode *t)//层次遍历
{
	bitnode *dl[max],*p=NULL;
	int f=0,r=0;
	if(t!=NULL){
		dl[r]=t;
		r++;
	}
	while(f!=r){
		p=dl[f];
		f++;//出
		
		printf("%d ",p->data);
		if(p->lchild!=NULL){
			dl[r]=p->lchild;//进左
			r++;
		}
		if(p->rchild!=NULL){
			dl[r]=p->rchild;//进右
			r++;
		}
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
	ccbl(t);
	freetree(t);
	
}
