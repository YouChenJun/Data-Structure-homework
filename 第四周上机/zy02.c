#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char *ch;
	int length;
} hstring;
void strassign(hstring *s, char a[]) {//由字符串创建定长顺序存储串
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	s->length = i;
	s->ch = (char*)malloc(s->length * sizeof(char));
	for (i = 0; i < s->length; i++) {
		s->ch[i] = a[i];
	}
}
void strprint(hstring s) {
	int i;
	for (i = 0; i < s.length-1; i++) {
		printf("%c ", s.ch[i]);
	}
	printf("\n");
}
void freehsring(hstring s) {
	if (s.ch != NULL) {
		free(s.ch);
	}
}
int substr(hstring *sub, hstring s, int pos, int len) {
//由s串从pos开始截取len长度子串到sub子串中，pos从1开始
	int i;
	if (pos < 1 || pos > s.length || len < 0 || len > s.length - pos + 1) {//判断合理
		return 0;
	}
	sub->length = len;
	sub->ch = (char*)malloc(sub->length * sizeof(char));
	for (i = 0; i < len; i++) {
		sub->ch[i] = s.ch[pos + i - 1];
	}
	return 1;

}
int strcom(hstring s1, hstring s2) {//字串比较
	int i = 0;
	while (s1.ch[i] == s2.ch[i] && i <= s1.length - 1 && 1 <= s2.length - 1) {
		i++;
	}
	if (i <= s1.length - 1 && i <= s2.length - 1) {//都没结束
		return s1.ch[i] - s2.ch[i];//遇到了不等的字符
	} else if (i > s1.length - 1 && i > s2.length - 1) {//同时结束
		return 0;
	} else if (i > s1.length - 1) {
		return -1;
	} else
		return 1;
}
int index(hstring s, hstring t, int pos) {//串的朴素匹配，不调用子串截取函数，pos位置从1开始
	int i = pos, j = 1;
	while (i <= s.length && j < t.length) {
		if (s.ch[i - 1] == t.ch[j - 1]) {
			++i;
			++j;
		} else {
			i = i - j + 2;//i指向开始的下一个字符
			j = 1;
		}
	}
	if (j > t.length) {
		return i - t.length;
	} else
		return 0;
}
int concat(hstring *t, hstring s1, hstring s2) {
	int i;
	t->ch = (char *)malloc((s1.length + s2.length) * sizeof(char));
	if (!t->ch) {
		return 0;
	}
	for (i = 0; i <= s1.length - 1; i++) {
		t->ch[i] = s1.ch[i];
	}
	for (i = 0; i < s2.length - 1; i++) {
		t->ch[s1.length+i]=s2.ch[i];
	}
	t->length=s1.length+s2.length;
	return 1;
}
void main()
{
	int t;
	hstring s,sub, T;
	strassign(&s,"1234512367890");
	strassign(&sub,"123");
	t=index(s,sub,2);
	printf("%d \n",t);
	concat(&T,s,sub);
	strprint(T);
	freehsring(s);
	freehsring(sub);
	freehsring(T);
}
