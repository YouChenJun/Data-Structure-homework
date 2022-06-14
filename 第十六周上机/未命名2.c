#include "stdio.h"
#include "stdlib.h"
#include <time.h>
void Merge(int a[], int t[], int L, int R, int RightEnd) { //�ϲ������������У�
	int LeftEnd = R - 1; //4
	int p = L, i;
	int num = RightEnd - L + 1; //10
	while (L <= LeftEnd && R <= RightEnd) //0<=4,5<=9,�������кϲ���t��
		if (a[L] <= a[R])
			t[p++] = a[L++];
		else
			t[p++] = a[R++];
	while (L <= LeftEnd) //������ǰ����,�������θ��ƹ�ȥ
		t[p++] = a[L++];
	while (R <= RightEnd) //������ǰ�������������θ��ƹ�ȥ
		t[p++] = a[R++];
	for (i = 0; i < num; i++, RightEnd--) //��t�������θ��Ƶ�a��
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
	int *t = (int *)malloc(n * sizeof(int)); //���븨���ռ�
	if (t) {
		MSort(a, t, 0, n - 1); //���������ռ�t��0��n-1Ԫ�غϲ�����a��
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
