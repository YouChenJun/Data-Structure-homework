#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct {
	int *base;
	int *top;
	int stacksize;
} sqstack;
int initstack(sqstack *s) {
	s->base = (int*)malloc(stack_init_size * sizeof(int));
	if (!s->base) {
		return 0;
	}
	s->top = s->base;
	s->stacksize = stack_init_size;
	return 1;
}
void destroystack(sqstack *s) {
	free(s->base);
}
int stackempty(sqstack *s) {
	if (s->base == s->top) {
		return 1;
	} else
		return 0;
}
int pop(sqstack *s, int*e) {
	if (s->top != s->base) {
		*e = *(s->top - 1);
		s->top--;
		return 1;
	} else
		return 0;
}
int push(sqstack *s, int e) {
	if (s->top - s->base >= s->stacksize) {
		s->base = (int *)realloc(s->base, (s->stacksize + stackincrement) * sizeof(int));
		if (!s->base) {
			return 0;
		}
		s->stacksize += stackincrement;
	}
	*(s->top) = e;
	s->top++;
	return 1;
}
int conversion(sqstack *sq, int n, int jz, char s[]) {
	int e, i = 0;

	while (n) {
		push(sq, n % jz);
		n = n / jz;
	}
	while (!stackempty(sq)) {
		pop(sq, &e);
		if (e <= 9) {
			s[i] = e + '0';
		} 
		else 
//		{
//			if  (e / 16 < 10)
//			         s[0] = e / 16 +  '0' ;
//			     else
//			         s[0] = e / 16 - 10 +  'A' ;
//			     if  (e % 16 < 10)
//			         s[1] = e % 16 +  '0' ;
//			     else
//			         s[1] = e % 16 - 10 +  'A' ;
//			    s[2] = '\0';
//			    return s;
//		}
			s[i]=e-10+'A';
			
		i++;
	}
	s[i] = '\0';
}
int main() {
	int n;
	char c[20];
	sqstack sq;
	initstack(&sq);
	scanf("%d", &n);
	printf("您输入的10进制数:%d\n", n);
	conversion(&sq, n, 8, c);
	printf("八进制:%s\n", c);
	conversion(&sq, n, 2, c);
	printf("二进制:%s\n", c);
	conversion(&sq, n, 16, c);
	printf("十六进制:%s", c);
	destroystack(&sq);
}
