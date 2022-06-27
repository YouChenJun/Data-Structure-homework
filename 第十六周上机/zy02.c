#include "stdio.h"
#include "stdlib.h"
#include <time.h>
void Merge(int a[], int t[], int L, int R, int RightEnd) { //合并两个有序序列，
	int LeftEnd = R - 1; //4
	int p = L, i;
	int num = RightEnd - L + 1; //10
	while (L <= LeftEnd && R <= RightEnd) //0<=4,5<=9,将两序列合并到t中
		if (a[L] <= a[R])
			t[p++] = a[L++];
		else
			t[p++] = a[R++];
	while (L <= LeftEnd) //若右提前结束,将左依次复制过去
		t[p++] = a[L++];
	while (R <= RightEnd) //若左提前结束，将右依次复制过去
		t[p++] = a[R++];
	for (i = 0; i < num; i++, RightEnd--) //将t中数依次复制到a中
		a[RightEnd] = t[RightEnd];
}

void MSort(int a[], int t[], int L, int R) {
	int center;
	if (L < R) {
		center = (L + R) / 2;
		MSort(a, t, L, center);
		MSort(a, t, center + 1, R);
		Merge(a, t, L, center + 1, R);
	}
}

void Merge_sort(int a[], int n) {
	int *t = (int *)malloc(n * sizeof(int)); //申请辅助空间
	if (t) {
		MSort(a, t, 0, n - 1); //借助辅助空间t将0至n-1元素合并排序到a中
		free(t);
	} else
		printf("no space!\n");
}

void main() {
	int i, a[] = {1, 3, 63, 5, 78, 9, 12, 52, 8, 22};
	Merge_sort(a, 10) ;
	for (i = 0; i <= 9; i++)
		printf(" %d ", a[i]);

	printf("\n");

}
