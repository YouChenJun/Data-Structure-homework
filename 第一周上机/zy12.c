#include <stdio.h>
int fun(int n) {
	if (n == 1 || n == 2) {// µİ¹é³ö¿Ú
		return 1;
	}
	return fun(n - 1) + fun(n - 2);//µİ¹éÌå
}
int main() {
	int i;
	for (i = 1; i <= 20; i++) {
		printf("%d ", fun(i));
	}
	return 0;
}
