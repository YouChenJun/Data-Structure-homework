#include<stdio.h>
void inssort(int r[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (r[i] < r[i - 1]) {
			r[0] = r[i];
			j = i - 1;
			while (r[j] > r[0]) {
				r[j + 1] = r[j];
				j--;
			}
			r[j + 1] = r[0];
		}
	}
}
void main() {
	int a[11]={0,3,5,2,1,9,12,8,6,18,7},i;//第一个0为监视哨
	inssort(a,10);
	for(i=1;i<=10;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
}
