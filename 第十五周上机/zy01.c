#include<stdio.h>
void swap(int *a, int *b) { //交换
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a[10] = {49, 38, 65, 97, 76, 13, 27, 49, 35, 86};
	int i, j, key;
	//有多少记录，就需要多少次冒泡，当比较过程，所有记录都按照升序排列时，排序结束
	for (i = 0; i < 10; i++) {
		key = 0; //到10-i结束，key初识为0
		for (j = 0; j + 1 < 10 - i; j++) {
			if (a[i] > a[j + 1]) {
				key = 1;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (key == 0) {
			break;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}
