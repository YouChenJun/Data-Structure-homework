#include<stdio.h>
void swap(int *a, int *b) { //����
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a[10] = {49, 38, 65, 97, 76, 13, 27, 49, 35, 86};
	int i, j, key;
	//�ж��ټ�¼������Ҫ���ٴ�ð�ݣ����ȽϹ��̣����м�¼��������������ʱ���������
	for (i = 0; i < 10; i++) {
		key = 0; //��10-i������key��ʶΪ0
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
