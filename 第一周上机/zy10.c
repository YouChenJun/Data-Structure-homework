/*
�轫n��������ŵ�һά����R�С������һ����ʱ��Ϳռ������澡���ܸ�Ч���㣬��R�б��������ѭ�����ƶ�p��λ�ã�����R�е�������(x0,x1,x2,...xn-1)�任Ϊ(xp,xp+1,...xn-1,x0,...xp)��Ҫ��
1. �����㷨�Ļ������˼��
2. ˵���㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�
*/

#include<stdio.h>
void fun(int R[], int n, int p);
void reverse(int R[], int left, int right);

void fun(int R[], int n, int p) {//�����ǵ��õĴ���===��������Ϊn������r�е�����ѭ������p��λ��
	reverse(R, 0, 9);//ԭ������xn,xn-1,...x0
	reverse(R, 0, n - p - 1);//ǰ�������xp,xp+1,..,xn-1,xp-1,...x0
	reverse(R, n - p, n - 1);//����p����������xp,xp+1,...xn-1,x0,...xp-1
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
