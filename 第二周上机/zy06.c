#include"stdio.h"
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}listnode;
listnode* INITLIST()
{		
	listnode *hd=(listnode *)malloc (sizeof (listnode));
	hd->next=hd;
	return hd;
}
void CREALIST (listnode *hd, int N)
{
	int i;
	listnode *r=hd;
	for(i=1;i<=N;i++)
	{
		listnode *p=(listnode *)malloc(sizeof(listnode));
		p->data=i;
		p->next=r->next;
		r->next=p;
		r=p;//这里一直创建空间，并且r一直后移到最后一个，为插入做准备
		}
	}
void PRINTLIST(listnode *hd)
{
	listnode *p=hd->next;
	while(p!=hd)
	{
		printf("%d ", p->data);
		p=p->next;
	}
}
void CQPRINT(listnode *hd, int M)
{
	int i=1;//计数器，1，2，3，m到达m出圈
	listnode *p=hd,*r=NULL;//p是第一个
	while(hd->next!=hd) //当循环链表不空
	{
		p=p->next;
		if(p->next==hd) p=p->next;//p数到hd空节点，则再下一一个节点
		i++;
		if(i==M)//数到m删除p后面的节点
		{
			r=p->next;
			p->next=r->next;
			printf("%d ", r->data);
			free(r);
			i=1;
			if(p->next==hd) p=p->next;//当删除p后结束后
		}
	}
}
void FREELIST(listnode *hd)
{
	while(hd->next!=hd)
	{
		listnode *p=hd->next;
		hd->next=p->next;
		free(p);//摘除p
	}
	free(hd);
}
void main()
{
	listnode *head=INITLIST();
	CREALIST(head, 20);
	PRINTLIST(head);
	printf("\n");
	CQPRINT(head, 7);
	FREELIST(head);
}
