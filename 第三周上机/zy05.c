#include "stdio.h"
#include "stdlib.h"
#define maxsize 100
typedef struct 
{
	int *base;
	int front;
	int rear;
} sqque;

void initque(sqque *lq) 
{
	lq->base=(int *)malloc(maxsize*sizeof(int));
	lq->front=0;
	lq->rear=0;
}

int enque(sqque *lq,int e) 
{
	if((lq->rear+1)%maxsize!=lq->front) 
	{
		lq->base[lq->rear]=e;
		lq->rear=(lq->rear+1 )%maxsize;
		return 1;
	}
	return 0;
}
int deque(sqque *lq,int *e) 
{
	if(lq->front !=lq->rear) 
	{
		*e=lq->base[lq->front];
		lq->front=(lq->front+1 )%maxsize;
		return 1;
	}
	return 0;
}

int empque(sqque *lq) 
{
	if(lq->front==lq->rear) return 1;
	else return 0;
}

int lenque(sqque *lq) 
{
	return((lq->rear-lq->front+maxsize)%maxsize);
}

void desque(sqque *lq) 
{
	free(lq->base);
}
void main() 
{
	int k,e;
	sqque sq;
	initque(&sq);
	scanf("%d",&k);
	while(k!=-1) {
		e=enque(&sq,k);//Èë¶Ó²Ù×÷
		if(e==0)
			break;
		scanf("%d",&k);
	}

    printf("\n cd: %d \n", lenque(&sq));
	while(!empque(&sq))
	{
		e=deque(&sq,&k);
		if(e==0) 
			break;
		printf("%d ",k);
	}
	desque(&sq);
}



