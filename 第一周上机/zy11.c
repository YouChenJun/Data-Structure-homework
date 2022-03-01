#include <stdio.h>
int fun(int hang, int lie) {
	if (hang == lie) return 1; //三个递归出口，也就是当行列相等或者行列为1时
	if (hang == 1) return 1;
	if (lie == 1) return 1;
	else   return fun(hang - 1, lie) + fun(hang - 1, lie - 1);
}

int main() {
	int i, j;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%4d", fun(i, j));
		}
		printf("\n");
	}
}
