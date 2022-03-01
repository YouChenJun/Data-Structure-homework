/*
设将n个整数存放到一维数组R中。试设计一个在时间和空间两方面尽可能高效的算，将R中保存的序列循环左移动p个位置，即将R中的数据由(x0,x1,x2,...xn-1)变换为(xp,xp+1,...xn-1,x0,...xp)。要求：
1. 给出算法的基本设计思想
2. 说明算法的时间复杂度和空间复杂度。
*/

#include<stdio.h>
void fun(int R[], int n, int p);
void reverse(int R[], int left, int right);

void fun(int R[], int n, int p) {//这里是调用的代码===处将长度为n的数组r中的数据循环左移p个位置
	reverse(R, 0, 9);//原地逆序xn,xn-1,...x0
	reverse(R, 0, n - p - 1);//前面的逆序xp,xp+1,..,xn-1,xp-1,...x0
	reverse(R, n - p, n - 1);//后面p个数据逆序xp,xp+1,...xn-1,x0,...xp-1
}
void reverse(int R[], int left, int right) {
	int t;
	while (left < right) {
		t = R[left];
		R[left] = R[right];
		R[right] = t;
		right--;
		left++;
	}
}
int main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10}, i;
	fun(a, 10, 4);
	for (i = 0; i <= 9; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
