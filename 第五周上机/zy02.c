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

int a[17]={1,5,6,0,0,7,0,0,8,0,0},a_i=0;//数组模拟遍历

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
int qgs(bitnode *t)//求个数-return 返回
{
	int x,l,r;
	if(t!=NULL){
		l=qgs(t->lchild);
		r=qgs(t->rchild);
		x=l+r+1;
	}	
	else{
		x=0;
	}
	return x;
}
int qh(bitnode *t)//求结点和-return 返回
{
	int x,l,r;
	if(t!=NULL){
		l=qh(t->lchild);
		r=qh(t->rchild);
		x=l+r+t->data;
	}	
	else{
		x=0;
	}
	return x;
}

int num=0;
void qgs1(bitnode *t)//求结点个数-全局变量
{
	if(t!=NULL){
		num++;
		qgs1(t->lchild);
		qgs1(t->rchild);
	}
}

int he=0;
void qh1(bitnode *t)//求结点和-全局变量
{
	if(t!=NULL){
		he=he+t->data;
		qh1(t->lchild);
		qh1(t->rchild);
	}
}
int max,min;
void qmax_min(bitnode *t)//求结点和-全局变量
{
	if(t!=NULL){
		if(t->data>max){
			max=t->data;
		}
		else if(t->data<min){
			min=t->data;
		}
		qmax_min(t->lchild);
		qmax_min(t->rchild);
	}
}


void qgs2(bitnode *t,int *p)//求节点个数-局部静态变量
{
	if(t!=NULL){
		(*p)++;
		qgs2(t->lchild,p);
		qgs2(t->rchild,p);
	}
}
void qh2(bitnode *t,int *p)//求节点和-局部静态变量
{
	if(t!=NULL){
		(*p)=(*p)+t->data;
		qh2(t->lchild,p);
		qh2(t->rchild,p);
	}
}


void main()
{
	int gs=0;
	
	int s=0;
	
	bitnode *t=NULL;
	//t=creat();
	create_sz(&t);
	printf("先序遍历:");
	blx(t);
	//printf("\n中序遍历:");
	//blz(t);
	//printf("\n后序遍历:");
	//blh(t);
	
	printf("\n%d\n",qgs(t));
	qgs1(t);
	printf("%d\n",num);
	qgs2(t,&gs);
	printf("%d\n",gs);
	//以下为求和
	printf("求和：\n");
	printf("%d\n",qh(t));
	qh1(t);
	printf("%d\n",he);
	qh2(t,&s);
	printf("%d\n",s);
	//以下为求最大小值
	if(t!=NULL){
		max=t->data;
		min=t->data;
		qmax_min(t);
		printf("max:%d,min:%d",max,min);
	}
	else{
		printf("树为空，为最大最小值");
	}
	
	freetree(t);
}
