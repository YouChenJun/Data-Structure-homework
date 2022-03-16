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
	//当前位置在路径上的序号
	PostType seat;
	//当前坐标
	int di;
	//往下一坐标的方向
}SElemType;

//栈元素类型
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
		//当前位置可通则返回1.否则返回0
	if (maze[curpos.y][curpos.x]==0)//可通
		return 1;
	else
		return 0;
}

void FootPrint(int maze[M][N],PostType curpos)
{
	maze[curpos.y][curpos.x]=2;//曾走过，可通留下足迹2
}

void MarkPrint(int maze[M][N],PostType curpos)//曾走过，不通，留下足迹3
{
	maze[curpos.y][curpos.x]=3;
}//MarkPrint

PostType NextPos(PostType curpos,int i)//指示并返回下一位置的坐标
{
	PostType cpos=curpos;
	switch(i)//1.2.3.4分别表示右,下,左,上方向
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
	int curstep;//当前方向,1.2.3.4分别表示右,下,左,上方向
	PostType curpos={1,1},end={8,8};
	SElemType e;
	initstack(&sq);
	curstep=1; //探索第一步
	
	do
	{
		if(Pass(mg,curpos))//当前位置可以通过,即是未曾走到过的通道
		{
		
			FootPrint(mg,curpos);//留下足迹2
			e.ord=curstep;//当前可通位置序号
			e.seat=curpos;//当前可通位置坐标
			e.di=1;//下一位置方向
			push(&sq,e);//可通进栈，加入路径
			if(curpos.x==end.x && curpos.y==end.y)//到达出口
			{
				break;
			}
			else//未到达出口
			{
				curpos=NextPos(curpos,1);//下一位置是当前位置的右邻
				curstep++;//探索下一步
			}
		}
		else//当前位置不通 
		{
			if(!stackempty(&sq))
			{
				pop(&sq,&e);
				while(e.di==4 &&!stackempty(&sq))
				{
				
					MarkPrint(mg,e.seat) ;
					pop(&sq,&e); //留下不能通过的标记,并退一步
					curstep--;
				}
				if(e.di < 4)//如果4个方向没判定完
				{
					e.di++;//换下一个方向探索
					push(&sq,e);
					curpos=NextPos(e.seat,e.di);//设定当前位置是该新方向上的相邻
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
				printf("■");
			else
				printf("□");
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
				printf("■");
			else if(maze[i][j]==1) 
				printf("□");
			else if(maze[i][j]==2) 
				printf("★");
			else if(maze[i][j]==3) 
				printf("☆");
			
		}
		printf("\n");
	}

}
