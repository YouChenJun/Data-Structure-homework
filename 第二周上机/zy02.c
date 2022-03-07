#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}listnode;
listnode *INITLIST()
{
	listnode *hd=(listnode *)malloc(sizeof(listnode));//ÉêÇë¿Õ¼ä
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
		lb->next=pb->next;//Õª³ýpb
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
void main()
{
	int i;
	listnode *hdl=NULL,*hd2=NULL;
	hdl=INITLIST();
	hd2=INITLIST();
	for(i=1;i<=25;i++)
		insertelem(hdl,i,i);
	PRINTLIST(hdl);
	for(i=1;i<=8;i++)
		insertelem(hd2,i,i*i);
	PRINTLIST(hd2);
	QB(hdl,hd2);
	PRINTLIST(hdl);
	FREELIST(hdl);
	FREELIST(hd2);
}
