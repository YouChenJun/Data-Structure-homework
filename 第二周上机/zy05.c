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
void CREALISTWCSZ(listnode *hd,int a[],int n)
{
	int i;
	listnode *r=hd;
	for(i=0;i<=n-1;i++)
	{
		listnode *p=(listnode *)malloc(sizeof(listnode));
		p->data=a[i];
		p->next=NULL;
		r->next=p;
		r=p;
	}
	/*int dt;
	scanf("%d",&dt);
	while(dt!=-1)
	{
		listnode *p=(listnode *)malloc(sizeof(listnode));
		p->data=dt;
		p->next=hd->next;
		hd->next=p;
		scanf("%d",&dt);
	}*/
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
void listhb(listnode *la,listnode *lb,listnode *lc)
{
	listnode *pa=la->next,*pb=lb->next,*pc=lc;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			la->next=pa->next;
			pc->next=pa;
			pa->next=NULL;
			pc=pa;
			pa=la->next;
		}
		else
		{
			lb->next=pb->next;
			pc->next=pb;
			pb->next=NULL;
			pc=pb;
			pb=lb->next;
		}
	}
	if(la->next!=NULL)
	{
		pa=la->next;
		lb->next=NULL;
		pc->next=pb;
	}
}
void PX(listnode *hd)
{
	listnode *fs=hd->next->next,*r=NULL,*p;
	hd->next->next=NULL;
	while(fs!=NULL)
	{
		r=fs;
		fs=fs->next;
		p=hd;
		while(p->next!=NULL)
		{
			if(p->next->data>r->data)
				break;
			p=p->next;
		}
		r->next=p->next;
		p->next=r;
	}
}
void PX1(listnode *l)
{
	listnode *p=l->next,*q=NULL;
	int t;
	while(p)
	{
		q=p->next;
		while(q)
		{
			if(p->data>q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
			q=q->next;
		}
		p=p->next;
	}
}
void FZ(listnode *hd)
{
	listnode *p=hd->next->next,*r=NULL;
	hd->next->next=NULL;
	while(p!=NULL)
	{
		r=p;
		p=p->next;
		r->next=hd->next;
		hd->next=r;
	}
}
void qjj(listnode *la,listnode *lb)
{
	listnode *pb=lb,*pa=NULL,*pr=NULL;//pb指向操作节点的前一节点
	while(pb->next!=NULL){
		pa=la->next;
		while(pa!=NULL){
			if(pb->next->data==pa->data)
			break;
			pa=pa->next;
		}
		if(pa==NULL){
			pr=pb->next;
			pb->next=pr->next;
			free(pr);
		}
		else//
		{
			pb=pb->next;
		}
		
	}
}
void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},b[5]={2,4,16,8,19};
	listnode *hda=NULL,*hdb=NULL;
	hda=INITLIST();
	hdb=INITLIST();
	CREALISTWCSZ(hda,a,10);
	CREALISTWCSZ(hdb,b,5);
	PRINTLIST(hda);
	PRINTLIST(hdb);
    qjj(hda,hdb);
	PRINTLIST(hdb);
	FREELIST(hda);
	FREELIST(hdb);
}
