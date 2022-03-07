#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}listnode;
listnode *INITLIST()
{
	listnode *hd=(listnode *)malloc(sizeof(listnode));
	hd->next=NULL;
	return hd;
}
void CREALIST(listnode *hd)
{
	int dt;
	scanf("%d",&dt);
	while(dt!=-1)
	{
		listnode *p=(listnode *)malloc(sizeof(listnode));
		p->data=dt;
		p->next=hd->next;
		hd->next=p;
		scanf("%d",&dt);
	}
}
void PRINTLIST(listnode *hd)
{
	listnode *p=hd->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int Getelem(listnode *hd,int i,int *e)
{
	int j=1;
	listnode *p=hd->next;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p->next!=NULL&&j==i)
	{
		listnode *q=p->next;
		p->next=q->next;
		*e=q->data;
		free(q);
		return 1;
	}
	return 0;
}
void FREELIST(listnode *hd)
{
	while(hd->next!=NULL)
	{
		listnode *p=hd->next;
		hd->next=p->next;
		free(p);
	}
	free(hd);
}
void QB(listnode *la,listnode *lb)
{
	listnode *pb=lb->next,*pa=la->next;
	while(pb!=NULL)
	{
		lb->next=pb->next;
		pa=la->next;
		while(pa!=NULL)
		{
			if(pb->data==pa->data)
				break;
			pa=pa->next;
		}
		if(pa==NULL)
		{
			pb->next=la->next;
			la->next=pb;
		}
		else
			free(pb);
		pb=lb->next;
	}
}
void insertelem(listnode *hd,int i,int e)
{
	int j=1;
	listnode *q=(listnode *)malloc(sizeof(listnode)),*p=hd;
	q->data=e;
	while(j<i&&p->next!=NULL)
	{
		p=p->next;
		j++;
	}
	q->next=p->next;
	p->next=q;
}
void listhb(listnode *la,listnode *lb,listnode *lc)//O(m+n)
{
	listnode *pa=la->next,*pb=lb->next,*pc=lc;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			la->next=pa->next;//从la删除pa节点
			pc->next=pa;
			pa->next=NULL;//pa插入lc
			pc=pa;//pc后移，指向lc最后一个数据节点
			pa=la->next;//取la下一节点
		}
		else
		{
			lb->next=pb->next;//从lb删除pb节点
			pc->next=pb;
			pb->next=NULL;//pb插入lc
			pc=pb;//pc后移，指向lc最后一数据节点
			pb=lb->next;//取lb下一节点
		}
	}
	if(la->next!=NULL)//若la还有数据节点，将后部分节点插入
	{
		pa=la->next;
		lb->next=NULL;
		pc->next=pb;
	}
}
void main()
{
	int i;
	listnode *head=NULL,*head1=NULL,*head2=NULL;
	head=INITLIST();
	head1=INITLIST();
	head2=INITLIST();
	for(i=1;i<10;i++)
		insertelem(head,i,i*i);
	PRINTLIST(head);
	for(i=1;i<10;i++)
		insertelem(head1,i,i*i*i);
	PRINTLIST(head1);
	listhb(head,head1,head2);
	PRINTLIST(head2);
	FREELIST(head);
	FREELIST(head1);
	FREELIST(head2);
}
