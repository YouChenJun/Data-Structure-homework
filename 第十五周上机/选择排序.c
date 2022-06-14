#include<stdio.h>
void xzsort(int r[],int n)
{
	int i,j,minxb,t;
	for(i=1;i<=n-1;i++){
		minxb;
		for(j=i+1;j<=n;j++){
			if(r[j]<r[minxb]){
				minxb=j;
			}
			
		}
		if(minxb!=1){
			t=r[minxb];
			r[minxb]=r[i];
			r[i]=t;
		}
	}
}
void main()
{
	int a[11]={0,2,4,6,23,56,25,76,98,45,65};
	xzsort(a,10);
	int i;
	for(i=1;i<=10;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
}
