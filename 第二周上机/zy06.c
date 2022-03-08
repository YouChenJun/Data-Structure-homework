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
		r=p;//����һֱ�����ռ䣬����rһֱ���Ƶ����һ����Ϊ������׼��
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
	int i=1;//��������1��2��3��m����m��Ȧ
	listnode *p=hd,*r=NULL;//p�ǵ�һ��
	while(hd->next!=hd) //��ѭ��������
	{
		p=p->next;
		if(p->next==hd) p=p->next;//p����hd�սڵ㣬������һһ���ڵ�
		i++;
		if(i==M)//����mɾ��p����Ľڵ�
		{
			r=p->next;
			p->next=r->next;
			printf("%d ", r->data);
			free(r);
			i=1;
			if(p->next==hd) p=p->next;//��ɾ��p�������
		}
	}
}
void FREELIST(listnode *hd)
{
	while(hd->next!=hd)
	{
		listnode *p=hd->next;
		hd->next=p->next;
		free(p);//ժ��p
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
