#include<stdio.h>
int search(int p[],int n,int k)
{
	int low=1,high=n,mid;
	while(low<high){
		mid=(low+high)/2;
		if(p[mid]==k){
			return mid;
		}
		else if(k<p[mid]){
			high=mid-1;
		}
		else
			low=mid+1;
	}
	
}
int BinarySearch1(int a[], int value, int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==value)
            return mid;
        if(a[mid]>value)
            high = mid-1;
        if(a[mid]<value)
            low = mid+1;
    }
    return -1;
}

void main()
{
	int a[12]={15,13,19,21,37,56,64,75,80,88,92};
	int key,t;
	scanf("%d",&key);
	t=search(a,11,key);
	printf("\n%d",t);
}
