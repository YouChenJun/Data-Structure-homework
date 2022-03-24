#include "stdio.h"
#include "stdlib.h"
#define MAXLEN 100
typedef unsigned char SString[MAXLEN + 1];
void StrAssign(SString a, char b[]) {
	int i = 0;
	while (b[i] != '\0') {
		a[i + 1] = b[i];
		i++;
	}
	a[0] = i;
}
int SubStr(SString sub, SString a, int wz, int cd) {
	int i = 0;
	if (wz < 1 || wz > a[0] || cd < 0 || cd > a[0] - wz + 1)
		return 0;
	while (i < cd) {
		sub[i + 1] = a[wz + i];
		i++;
	}
	sub[0] = cd;
	return 1;
}
int Strcom(SString a, SString b) {
	int i = 1;
	while (a[i] == b[i] && i <= a[0] && i <= b[0])
		i++;
	if (i > a[0] && i > b[0])
		return 0;
	else if (i > a[0])
		return -1;
	else if (i > b[0])
		return 1;
	else
		return a[i] - b[i];

}
int StrLenth(SString a) {
	return a[0];
}
int Index(SString S, SString T, int pos) {
	if (pos > 0) {
		int n = StrLenth(S), m = StrLenth(T), i = pos;
		SString sub;
		while (i <= n - m + 1) {
			int t = SubStr(sub, S, i, m);
			if (t == 1) {
				if (Strcom(sub, T) != 0)
					i++;
				else
					return i;
			} else return 0;
		}
	}
	return 0;
}
int IndexF(SString S, SString T, int pos) {
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			++i;
			++j;
		} else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}
int Concat(SString T, SString S1, SString S2) {
	int i;
	if (S1[0] + S2[0] <= MAXLEN) {
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return 1;
	} else if (S1[0] < MAXLEN) {
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = S1[0] + 1; i <= MAXLEN; i++)
			T[i] = S2[i - S1[0]];
		T[0] = MAXLEN;
	} else {
		for (i = 1; i <= MAXLEN; i++)
			T[i] = S1[i];
		T[0] = MAXLEN;
	}
	return 0;
}
void PrintSS(SString a) {
	int i;
	for (i = 1; i <= a[0]; i++)
		printf("%c ", a[i]);
	printf(" \n");
}


int main() {
	int t;
	SString a, sub, T;
	StrAssign(a, "1234512367890");
	StrAssign(sub, "123");
	t = Index(a, sub, 4);
	printf("%d\n", t);
	Concat(T, a, sub);
	PrintSS(T);
}
