#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prior,*next;
	
}listnode;
listnode *INITLIST()
{
	listnode *hd=(listnode*)malloc(sizeof(listnode));
	hd->next=hd;
	hd->prior=hd;
	return hd;
}
void CREALIST(listnode *hd,int N)
{
	int i;
	listnode *r=hd;
	for(i=1;i<=N;i++){
		listnode *p=(listnode *)malloc(sizeof(listnode));
		p->data=2*i;
		
		p->next=r->next;
		p->prior=r;
		hd->prior=p;
		r->next=p;
		
		r=p;//r后移，做准备
	}
}
void PRINTLIST(listnode *hd)
{
	listnode *p=hd->next;
	while(p!=hd){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	p=hd->prior;
	while(p!=hd){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void FREELIST(listnode *hd)
{
	while(hd->next!=hd){
		listnode *p=hd->next;
		hd->next=p->next;//摘除p
		free(p);
	}
	free(hd);//时返回给头节点
}
void funst(listnode *L)
{
	listnode *p=L->next,*q=NULL,*r=NULL;
	while(p->next){
		q=p;
		while(q->next){
			if(q->next->data==p->data){
				r=q->next;
				q->next=r->next;
				free(r);
			}
			else
			{
				
			}
		}
	}
}
//listnode* Locate(listnode *hd,int e)//hd内找e
//{
//	listnode *p=hd->next;
//	while(p!=hd){
//		if(p->data==e){
//			return p;
//		}
//		p=p->next;
//	}
//	return NULL;
//}
//void DELETEP(listnode *hd,listnode *p)
//{
//	p->next->prior=p->next;
//	p->prior->next=p->next;
//	free(p);
//}
//void DELETEPH(listnode *hd,listnode *p)
//{
//	listnode *r=p->next;
//	p->next=r->next;
//	r->next->prior=r->prior;
//	
//}
//void INSH(listnode *p,int e)//p后插入节点e
//{
//	listnode *r=(listnode*)malloc(sizeof(listnode));
//	r->data=e;
//	r->next=r->next;
//	r->next->prior=r;
//	p->next=r;
//	p->prior=p;
//}
//void INSQ (listnode *p, int e)//p前插e
//{
//	listnode *r=(listnode *)malloc(sizeof(listnode));
//	r->data=e;
//	r->next=p;
//	r->prior=p->prior;
//	r->prior->next=r;
//	p->prior=r;
//}
void main()
{
	int a[10]={1,2,1,4,2,2,1,8,2,2};
	listnode *hd=NULL;
	hd=	INITLIST();
	
}
