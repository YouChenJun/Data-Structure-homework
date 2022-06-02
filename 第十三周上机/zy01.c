#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct BSTNode//数据节点定义
{
	int data;
	struct BSTNode *lchild,*rchild;
};
struct BSTNode *CreateBST(int a[],int n)
{
	int i;
	struct BSTNode *p,*pre=NULL;//
	struct BSTNode *root=(struct BSTNode *)malloc(sizeof(struct BSTNode));
	root->data=a[0];
	root->lchild=NULL;
	root->rchild=NULL;
	for(i=1;i<=n-1;i++)
	{
		p=root;
		while(p)
		{
			pre=p;
			if(a[i]<p->data)
				p=p->lchild;
			else if(a[i]>p->data)
				p=p->rchild;
			else
				break;
		}
		if(!p)//如果p为空
		{
			p=(struct BSTNode *)malloc(sizeof(struct BSTNode));
			p->data=a[i];
			p->lchild=NULL;
			p->rchild=NULL;
			if(a[i]<pre->data)
				pre->lchild=p;
			else 
				pre->rchild=p;
		}
	}
	return root;			  
}
void InsertBST(struct BSTNode **bst,int k)
{
	if(bst==NULL)
	{
		*bst=(struct BSTNode *)malloc(sizeof(struct BSTNode));
		(*bst)->data=k;
		(*bst)->lchild=NULL;
		(*bst)->rchild=NULL;
	}
	else
	{
		struct BSTNode *p=*bst,*pre=NULL;
		while(p)
		{
			pre=p;
			if(k<p->data)
				p=p->lchild;
			else if(k>p->data)
				p=p->rchild;
			else
				break;
		}
		if(!p)
		{
			struct BSTNode *p=(struct BSTNode *)malloc(sizeof(struct BSTNode));
			p->data=k;
			p->lchild=NULL;
			p->rchild=NULL;
			if(k<pre->data)
				pre->lchild=p;
			else 
				pre->rchild=p;
		}
	}
}
void InOrder(struct BSTNode *root)//中序遍历
{
	if(root!=NULL)
	{
		InOrder(root->lchild);
		printf(" %d ",root->data);
		InOrder(root->rchild);
	}
}
void FiOrder(struct BSTNode *root)//先序遍历
{
	if(root!=NULL)
	{
		printf(" %d ",root->data);
		FiOrder(root->lchild);
		FiOrder(root->rchild);
	}
}
void FreeBST(struct BSTNode *root)//释放二叉树空间
{
	if(root!=NULL)
	{
		FreeBST(root->lchild);
		FreeBST(root->rchild);
		free(root);
	}
}
struct BSTNode *SearchBST(struct BSTNode *bst,int key)//在二叉排序树
{
	struct BSTNode *p=bst;
	while(p)
	{
		if(key==p->data)
			return p;
		else if(key<p->data)
			p=p->lchild;
		else
			p=p->rchild;
	}
	return NULL;
}
void DeleteBST(struct BSTNode **bst,int key)//在二叉排序树中删除指定结点
{
	struct BSTNode *p=*bst,*pre=*bst,*s=NULL,*spre=NULL;
	while(p)
	{
		if(key==p->data)
			break;
		else if(key<p->data)
		{
			pre=p;
			p=p->lchild;
		}
		else
		{
			pre=p;
			p=p->rchild;
		}
	}
	if(p)//如果找到key结点
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			if(p==*bst)
				*bst=NULL;
		    else if(p==pre->lchild)
				pre->lchild=NULL;
		    else if(p==pre->rchild)
			    pre->rchild=NULL;
	    }
		else if(p->lchild!=NULL&&p->rchild==NULL)
		{
			if(p==*bst)
				*bst=p->lchild;
			else if(p==pre->lchild)
				pre->lchild=p->lchild; 
			else if(p==pre->rchild)
				pre->rchild=p->lchild; 
		}
		else if((p->lchild==NULL)&&(p->rchild!=NULL))
		{
			if(p==*bst)
				*bst=p->rchild;
		    else if(p==pre->lchild)
				pre->lchild=p->rchild;
		    else if(p==pre->rchild)
				pre->rchild=p->rchild;
		}
		else
		{
			s=p->lchild;
			if(s->rchild==NULL)
			{
				if(p==*bst)
					*bst=s;
		        else if(p==pre->lchild)		
					pre->lchild=s;
		        else if(p==pre->rchild)
					pre->rchild=s;
				s->rchild=p->rchild;
			}
			else
			{
				while(s->rchild)
				{
					spre=s;
					s=s->rchild;
				}
				spre->rchild=s->lchild;
				if(p==*bst)
					*bst=s;
		        else if(p==pre->lchild)		
					pre->lchild=s;
		        else if(p==pre->rchild)
					pre->rchild=s;
				s->lchild=p->lchild;
				s->rchild=p->rchild;
			}
		}
		free(p);
	}
}
//
int jdgs=0,zbjcs=0;//结点个数,总比较次数
void qasl(struct BSTNode *t,int jdcs)//jdcs结点所在层数
{
	if(t)
	{
		jdgs++;
		zbjcs=zbjcs+jdcs;
		qasl(t->lchild,jdcs+1);
		qasl(t->rchild,jdcs+1);
	}
}
//
int main()
{
	int a[12]={5,2,7,6,9,12,1,3,4,8,10,11};
	struct BSTNode *bst=NULL,*p=NULL;
	bst=CreateBST(a,12);
	InOrder(bst);
	printf("\n");

	InsertBST(&bst,16);
	InOrder(bst);
	printf("\n");

	p=SearchBST(bst,16);
	if(p)
		printf("\n找到了：%d\n",p->data);
	else
		printf("\n没找到！\n");
	DeleteBST(&bst,5);
	InOrder(bst);
	
	qasl(bst,1);
	printf("ASL:%d/%d\n",zbjcs,jdgs);

	FreeBST(bst);

}
