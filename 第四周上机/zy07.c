#include <stdio.h>
int main() {
	int a[20001];//����ÿһλ���õ�����
	int ds, ws, n, i, j = 0; //dsÿ�εĵ���   wsÿ�ε�����λ��
	scanf("%d", &n);
	a[0] = 1; //��1��ʼ��
	ws = 1; //λ���ӵ�һλ��ʼ
	for (i = 2; i <= n; i++) {
		int num = 0;
		for (j = 0; j < ws; j++) {
			ds = a[j] * i + num; //��һ������ÿһλ�����ֱ����i��
			a[j] = ds % 10; //��һ������ÿһλ������������д���
			num = ds / 10;
		}
		while (num) { //�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0
			a[ws] = num % 10; //��������
			num = num / 10;
			ws++;
		}
	}
	for (i = ws - 1; i >= 0; i--) //�������ÿһλ
		printf("%d", a[i]);
	printf("\n");
	return 0;
}
