#include<stdio.h>
#include<stdlib.h>
void fun(int **t,int n)
{
	int *q=(int *)malloc(sizeof(int)*n),i;
	for(i=0;i<=n-1;i++){
		q[i]=i*i;
	}
	*t=q;
}
void main()
{
	int*p=NULL,i,n=10;
	fun(&p,n);
	for(i=0;i<=n-1;i++){
		printf("%d ",p[i]);
		
	}
	printf("\n");
	free(p);
}
