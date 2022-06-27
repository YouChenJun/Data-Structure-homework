#include<stdlib.h>
#include<stdio.h>
int c = 0;
void swap(int a[], int i, int j) {
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	c++;
}
void heapadjust(int a[], int m, int n) {
	int i;
	for (i = 2 * m; i <= n; i *= 2) {
		if (i + 1 > n) {
			if (a[i] > a[m]) {
				swap(a, i, m);
				m = i;
			} else
				break;
		} else if (i + 1 <= n) {
			if (a[i + 1] > a[i]) {
				if (a[i + 1] > a[m]) {
					swap(a, i + 1, m);
					i++;
					m = i;
				} else
					break;
			} else {
				if (a[i] > a[m]) {
					swap(a, i, m);
					m = i;
				} else
					break;
			}
		}
	}
}

void crtheap(int a[], int n) {
	int i;
	for (i = n / 2; i >= 1; i--) {
		heapadjust(a, i, n);
	}
}
void heapsort(int a[], int n) {
	int i;
	crtheap(a, n); //第一次调整为最大根堆
	for (i = n; i >= 2; i--) {
		swap(a, 1, i); //替换到最上面
		heapadjust(a, 1, i - 1); //剩下的a[i]到a[i-1]重新跳转
	}
}
void main() {
	int i;
	int a[11] = {-1, 8, 5, 2, 6, 0, 3, 9, 1, 7, 4};
	heapsort(a, 10);
	printf("交换数字%d次\n", c);
	for (i = 1; i <= 10; i++) {
		
		printf("%d ", a[i]);
	}
}
