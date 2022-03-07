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
void PX(listnode *hd)//��С��������
{
	listnode *fs=hd->next->next,*r=NULL,*p;//fsָ��ڶ������ݽڵ�
	hd->next->next=NULL;//hdֻ��һ���ڵ�ӵ�һ���ڵ��ض�
	//fs��Ϊ����ͷ�ڵ�ĵ�����
	while(fs!=NULL)
	{
		r=fs;//rָ�򲻴�ͷ�ڵ��б�ĵ�һ�����ݽڵ㣬�൱��ժ����һ�����ݽڵ�
		fs=fs->next;//fs����ͷ�ڵ������ͷָ�����
		p=hd;
		while(p->next!=NULL)//�Ҳ���λ��
		{
			if(p->next->data>r->data)
				break;//pָ���һ������r->data�ڵ��ǰһλ��
			p=p->next;
		}
		r->next=p->next;
		p->next=r;//��r�������ҵ���λ�� 
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
void main()
{
	int i;
	listnode *head=NULL;
	srand((unsigned)time(NULL));
	head=INITLIST();
	for(i=1;i<10;i++)
		insertelem(head,i,rand()%100);
	PRINTLIST(head);
    FZ(head);
	PRINTLIST(head);
	PX(head);
	PRINTLIST(head);
	FZ(head);
	PRINTLIST(head);
	PX1(head);
	PRINTLIST(head);
	FREELIST(head);
}
