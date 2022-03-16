#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}sqstack;
int initstack(sqstack *s)
{
	s->base=(int*)malloc(stack_init_size* sizeof(int));
	if(!s->base){
		return 0;
	}
	s->top=s->base;
	s->stacksize=stack_init_size;
	return 1;
}
void destroystack(sqstack *s)
{
	free(s->base);
}
int stackempty(sqstack *s)
{
	if(s->base==s->top){
		return 1;
	}
	else 
		return 0;
}
int pop(sqstack *s,int*e)
{
	if(s->top!=s->base){
		*e=*(s->top-1);
		s->top--;
		return 1;
	}
	else
		return 0;
}
int push(sqstack *s,int e)
{
	if(s->top-s->base>=s->stacksize){
		s->base=(int *)realloc(s->base,(s->stacksize+stackincrement)*sizeof(int));
		if(!s->base){
			return 0;
		}
		s->stacksize+=stackincrement;
	}
	*(s->top)=e;
	s->top++;
	return 1;
}
void conversion(sqstack *sq)
{
	int n,e;
	scanf("%d",&n);
	while(n){
		push(sq,n%8);
		n=n/8;
	}
	while(!stackempty(sq)){
		pop(sq,&e);
		printf("%d",e);
	}
}
int main()
{
	sqstack sq;
	initstack(&sq);
	conversion(&sq);
	destroystack(&sq);
}
