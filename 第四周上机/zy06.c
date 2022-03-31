#include<stdio.h>
#define maxsize 100
typedef struct { //��Ԫ��Ԫ�ؽṹ����
	int i, j;
	int e;
} triple;
typedef struct { //��Ԫ��洢����
	triple data[maxsize + 1];
	int mu, nu, tu;
} tsmat;
void cjsyz(tsmat *s) {
	int i;
	scanf("%d %d %d", &s->mu, &s->nu, &s->tu);
	for (i = 1; i <= s->tu; i++) {
		scanf("%d %d %d", &s->data[i].i, &s->data[i].j, &s->data[i].e);
	}
}
void cjsyzsz(tsmat *s, int a[], int h, int l) {
	int i, j, k = 1;
	s->mu = h;
	s->nu = l;
	for (i = 0; i <= h - 1; i++) {
		for (j = 0; j <= l - 1; j++) {
			if (a[i * l + j] != 0) {
				s->data[k].i = i + 1;
				s->data[k].j = j + 1;
				s->data[k].e = a[i * l + j];
				k++;
			}
		}
	}
	s->tu = k - 1;
}
void psyz(tsmat* s) {
	int i;
	printf("hs: %d ls: %d flgs : %d \n", s->mu, s->nu, s->tu);
	printf("syz : \n");
	for (i = 1; i <= s->tu; i++)
		printf("    %d    %d   %d\n", s->data[i].i, s->data[i].j, s->data[i].e);
}
void syzzz(tsmat *s, tsmat *k) {
	k->mu = s->nu;
	k->nu = s->mu;
	k->tu = s->tu;
	if (s->tu > 0) {
		int q = 1, m, p;
		for (m = 1; m  <= s->nu; m++)
			for (p = 1; p <= s->tu; p++)
				if (s->data[p].j == m) {
					k->data[q].i = s->data[p].j;
					k->data[q].j = s->data[p].i;
					k->data[q].e = s->data[p].e;
					q++;
				}
	}

}
void syzzzd(tsmat* s, tsmat* k) {
	int num[maxsize], i, copt[maxsize], col, q;
	k->mu = s->nu;
	k->nu = s->mu;
	k->tu = s->tu;
	if (s->tu > 0) {
		for (i = 1 ; i <= s->tu; i++)
			num[i] = 0;
		for (i = 1; i <= s->tu; i++)
			num[s->data[i].j]++;
		copt[1] = 1;
		for (i = 2; i <= s->nu; i++)
			copt[i] = copt[i - 1] + num[i - 1];
		for (i = 1; i <= s->tu; i++) {
			col = s->data[i].j;
			q = copt[col];
			k->data[q]. i = s->data[i]. j;
			k->data[q]. j = s->data[i]. i;
			k->data[q]. e = s->data[i]. e;
			copt[col]++;

		}

	}
}

int main() {
	int s[42] = { 0, 12, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 14, 0,
	              0, 0, 24, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 15, 0, 0, -7, 0, 0, 0
	            };
	tsmat a, k;
	cjsyzsz(&a, s, 6, 7);
	psyz(&a);
	syzzzd(&a, &k);
	psyz(&k);
}
