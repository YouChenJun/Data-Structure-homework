#include <stdio.h>
int h[100000];
int main() {
	int a[20001];//����ÿһλ���õ�����
	int ds, ws, n, i, j = 0; //dsÿ�εĵ���   wsÿ�ε�����λ��
	int hl = 0, hjw; //�׳˺ͣ��׳˺�λ��
	scanf("%d", &n);
	a[0] = 1; //��1��ʼ��
	ws = 1; //λ���ӵ�һλ��ʼ
	for (i = 1; i <= n; i++) {
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
		hjw = 0; //�׳˺ͽ�λ
		hl = ws > hl ? ws : hl;
		for(j=0;j<=hl;j++){
			h[j] = h[j] + a[j] + hjw;
			hjw = h[j] / 10;
			h[j] = h[j] % 10;
		}
		if(hjw!=0){
			h[++hl]=num;
		}

	}
	for (i = hl -1; i >= 0; i--) //�������ÿһλ
		printf("%d", h[i]);
	printf("\n");
	return 0;
}
