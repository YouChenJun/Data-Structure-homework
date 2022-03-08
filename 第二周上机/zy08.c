#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int cs,cf;//次数，次方
	struct node *next;
}listnode;
listnode *INITLIST()
{
	listnode *hd=(listnode *)malloc(sizeof(listnode));
	hd->next=NULL;
	return hd;
}
void CREALISTWCSZ(listnode *hd,listnode fc[],int n)
{
	int i;
	listnode *r=hd;
	for(i=0;i<=n-1;i++)
	{
		listnode *p=(listnode *)malloc(sizeof(listnode));
		p->cs=fc[i].cs;
		p->cf=fc[i].cf;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	
}
void PRINTLIST(listnode *hd)
{
	listnode *p=hd->next;
	while(p!=NULL)
	{
	if(p==hd->next)
		printf("%dX(%d)",p->cs,p->cf);
		else if(p->cf==0)
			printf("%+d",p->cs);
		else
			printf("%+dX(%d)",p->cs,p->cf);
		p=p->next;
	}
	printf("\n");
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

void XJ(listnode *la, listnode *lb)
{
	listnode *pa=la,*pb=lb,*r=NULL;
	while(pa->next!=NULL&&pb->next!=NULL)
	{
		if(pb->next->cf>pa->next->cf)
		{
			r=pb->next;
			pb->next=r->next;
			r->next=pa->next;
			pa->next=r;
			pa=pa->next;
		}
		else if(pb->next->cf<pa->next->cf)
		{
			pa=pa->next;
		}
		else
		{
			pa->next->cs=pa->next->cs+pb->next->cs;
			if(pa->next->cs==0)
			{
				r=pa->next;
				pa->next=r->next;
				free(r);
			}
		
			else
			pa=pa->next;
			r=pb->next;
			pb->next=r->next;
			free(r);
		}
	}
}
void main()
{
	listnode *head1=NULL,*head2=NULL;
	listnode fc1[5]={{5,7},{7,5},{4,3},{3,2},{9,0}};
	listnode fc2[6]={{8,9},{4,7},{3,6},{-3,2},{6,1},{6,0}};
	head1=INITLIST();
	head2=INITLIST();
	CREALISTWCSZ(head1,fc1,5);
	CREALISTWCSZ(head2,fc2,6);
	PRINTLIST(head1);
	PRINTLIST(head2);
	XJ(head1,head2);
	PRINTLIST(head1);
	FREELIST(head1);
	FREELIST(head2);
}
