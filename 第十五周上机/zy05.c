#include<stdio.h>
int parti(int r[],int low,int high)
{
	int pkey;
	r[0]=r[low];
	pkey=r[low];
	while (low<high)
	{
		while (low<high&&r[high]>=pkey)
		{
			--high;
		}
		r[low]=r[high];
		while (low<high&&r[low<=pkey])
		{
			++low;
		}
		r[high]=r[low];
	}
	r[low]=r[0];
	return low;
}
void kssort(int r[],int low,int high)
{
	int piv;
	if (low<high)
	{
		piv=parti(r,low,high);
		kssort(r,low,piv-1);
		kssort(r,piv+1,high);
	}
	
}
void main()
{
	int a[11]={0,3,5,2,1,9,12,8,6,18,17},i;
	kssort(a,1,10);
	for (i=1; i <=10; i++)
	{
		/* code */
		printf(" %d",a[i]);
	}
	printf("\n");
	
}