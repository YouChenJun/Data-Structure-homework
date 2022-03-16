#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct {
	int *base;
	int *top;
	int stacksize;
}sqstack;
int initstack(sqstack *s)
{
	s->base=(int *)malloc(stack_init_size*sizeof(int));
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
void clearstack(sqstack *s)//Çå¿ÕÕ»
{
	s->top=s->base;
}
int stackempty(sqstack *s)
{
	if(s->base==s->top){
		return 1;
	}
	else
		return 0;
	
}
int stacklength(sqstack *s)
{
	return(s->top-s->base);
}
int gettop(sqstack *s,int *e)
{
	if(s->top!=s->base){
		*e=*(s->top-1);
		return 1;
	}
	else
		return 0;
}
int pop(sqstack *s,int *e)//³ö
{
	if(s->top!=s->base){
		*e=*(s->top-1);
		s->top--;
		return 1;
	}
	else 
		return 0;
}
int push(sqstack *s,int e)//·Å
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
void stacktraverse(sqstack *s)
{
	int *p;
	p=s->top-1;
	printf("scz:");
	while(p>=s->base){
		printf(" %d ",*p);
		p--;
	}
	printf("\n");
}
void main()
{
	sqstack sq;
	int i,e;
	initstack(&sq);
	
	scanf("%d",&i);
	while(i!=-1){
		push(&sq,i);
		scanf("%d",&i);
	}
	stacktraverse(&sq);
	
	while(!stackempty(&sq)){
		pop(&sq,&e);
		printf(" *%d* ",e);
	}
	destroystack(&sq);
}
