#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 10
#define stack_init_size 100
#define stackincrement 10
typedef struct
{
	int x,y; 
}PostType;

typedef struct
{
	int ord;
	//��ǰλ����·���ϵ����
	PostType seat;
	//��ǰ����
	int di;
	//����һ����ķ���
}SElemType;

//ջԪ������
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}sqstack;

int initstack(sqstack *s)
{
	s->base= (SElemType*) malloc(stack_init_size*sizeof(SElemType));
	if(!s->base) 
		return 0;
	s->top=s->base;
	s->stacksize=stack_init_size;
	return 1;
}

void destroystack(sqstack*s)
{
	free(s->base);
}

int stackempty(sqstack *s)
{
	if(s->base==s->top)
		return 1;
	else 
		return 0;
}

int pop(sqstack *s,SElemType *e)
{
	if(s->top!=s->base)
	{
		*e=*(s->top-1);
		s->top--;
		return 1;
	}
	else
		return 0;
}

int push(sqstack *s,SElemType e)
{

	*(s->top)=e;
	s->top++;
	return 1;
}

void stacktraverse(sqstack *s)
{
	SElemType *p;
	p=s->base;
	printf("\nscz: \n");
	while(p<s->top)
	{
		printf("%2d-(%d,%d)\t",p->ord,p->seat.y,p->seat.x);
		p++;
	}
	printf("\n");
}

int Pass ( int maze[M][N],PostType curpos)
{
		//��ǰλ�ÿ�ͨ�򷵻�1.���򷵻�0
	if (maze[curpos.y][curpos.x]==0)//��ͨ
		return 1;
	else
		return 0;
}

void FootPrint(int maze[M][N],PostType curpos)
{
	maze[curpos.y][curpos.x]=2;//���߹�����ͨ�����㼣2
}

void MarkPrint(int maze[M][N],PostType curpos)//���߹�����ͨ�������㼣3
{
	maze[curpos.y][curpos.x]=3;
}//MarkPrint

PostType NextPos(PostType curpos,int i)//ָʾ��������һλ�õ�����
{
	PostType cpos=curpos;
	switch(i)//1.2.3.4�ֱ��ʾ��,��,��,�Ϸ���
	{
		case 1 : cpos.x+=1; break;
		case 2 : cpos.y+=1; break;
		case 3 : cpos.x-=1; break;
		case 4 : cpos.y-=1; break;
	}
	return cpos;
}//Nextpos

void MazePath(int mg[M][N])
{
	sqstack sq;
	int curstep;//��ǰ����,1.2.3.4�ֱ��ʾ��,��,��,�Ϸ���
	PostType curpos={1,1},end={8,8};
	SElemType e;
	initstack(&sq);
	curstep=1; //̽����һ��
	
	do
	{
		if(Pass(mg,curpos))//��ǰλ�ÿ���ͨ��,����δ���ߵ�����ͨ��
		{
		
			FootPrint(mg,curpos);//�����㼣2
			e.ord=curstep;//��ǰ��ͨλ�����
			e.seat=curpos;//��ǰ��ͨλ������
			e.di=1;//��һλ�÷���
			push(&sq,e);//��ͨ��ջ������·��
			if(curpos.x==end.x && curpos.y==end.y)//�������
			{
				break;
			}
			else//δ�������
			{
				curpos=NextPos(curpos,1);//��һλ���ǵ�ǰλ�õ�����
				curstep++;//̽����һ��
			}
		}
		else//��ǰλ�ò�ͨ 
		{
			if(!stackempty(&sq))
			{
				pop(&sq,&e);
				while(e.di==4 &&!stackempty(&sq))
				{
				
					MarkPrint(mg,e.seat) ;
					pop(&sq,&e); //���²���ͨ���ı��,����һ��
					curstep--;
				}
				if(e.di < 4)//���4������û�ж���
				{
					e.di++;//����һ������̽��
					push(&sq,e);
					curpos=NextPos(e.seat,e.di);//�趨��ǰλ���Ǹ��·����ϵ�����
				}
			}
		} 
	}while(!stackempty(&sq));
	if(!stackempty(&sq))
	{
		printf("success!");
		stacktraverse(&sq);
	}
	else
		printf("no success ! ");
	destroystack(&sq);
}

void main ()
{
	int i,j,maze[M][N]={
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,1,0,0,1},
		{1,0,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,1,1,0,1},
		{1,0,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,1,1},
		{1,0,1,0,1,0,0,0,0,1},
		{1,0,0,0,1,0,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1}};
	for(i=0; i<=9; i++)
	{
		for(j=0; j<=9; j++)
		{
			if(maze[i][j]==0)
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}
	MazePath(maze);
	printf("\n");
	for(i=0; i<=9; i++)
	{
		for(j=0; j<=9; j++)
			printf("%2d",maze[i][j]);
		printf("\n");
	}
	for(i=0; i<=9;i++)
	{
		for(j=0; j<=9; j++)
		{
			if(maze[i][j]==0)
				printf("��");
			else if(maze[i][j]==1) 
				printf("��");
			else if(maze[i][j]==2) 
				printf("��");
			else if(maze[i][j]==3) 
				printf("��");
			
		}
		printf("\n");
	}

}
