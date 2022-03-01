#include<stdio.h>
void fun(int n) {
	if (n / 10 != 0)
		fun(n / 10);
	printf("%d", n % 10);
}
int main() {
	int i;
	scanf("%d", &i);
	fun(i);
}
