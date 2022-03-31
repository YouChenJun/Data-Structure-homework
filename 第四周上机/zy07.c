#include <stdio.h>
int main() {
	int a[20001];//储存每一位所得到的数
	int ds, ws, n, i, j = 0; //ds每次的得数   ws每次得数的位数
	scanf("%d", &n);
	a[0] = 1; //从1开始乘
	ws = 1; //位数从第一位开始
	for (i = 2; i <= n; i++) {
		int num = 0;
		for (j = 0; j < ws; j++) {
			ds = a[j] * i + num; //将一个数的每一位数都分别乘以i，
			a[j] = ds % 10; //将一个数的每一位数利用数组进行储存
			num = ds / 10;
		}
		while (num) { //判断退出循环后，num的值是否为0
			a[ws] = num % 10; //继续储存
			num = num / 10;
			ws++;
		}
	}
	for (i = ws - 1; i >= 0; i--) //倒序输出每一位
		printf("%d", a[i]);
	printf("\n");
	return 0;
}
