#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str {
	char word[20];
	int num;
	struct str* next;
};
struct str* init() {
	struct str* hd = (struct str*)malloc(sizeof(struct str));
	hd->next = NULL;
	return hd;
}
void SF(struct str* hd) {
	struct str* p = hd->next;
	while (p != NULL) {
		hd->next = p->next;
		free(p);
		p = hd->next;
	}
	free(hd);
}
void print(struct str* hd) {
	struct str* p = hd->next;
	int i = 0;
	while (p != NULL) {
		printf("%s : %d \n", p->word, p->num);
		p = p->next;
		i++;
		if (i >= 20)
			break;
	}
}
void savetofile(struct str* hd) {
	struct str* p = hd->next;
	FILE* fp = fopen("C:\\Users\\user\\Desktop\\数据结构\\第四周上机\\2.txt ", "w");
	while (p != NULL) {
		fprintf(fp, "%s : %d \n", p->word, p->num);
		p = p->next;
	}
	fclose(fp);
}
void px(struct str* hd) {
	struct str* p = hd->next->next, * r, * t;
	hd->next->next = NULL;
	while (p != NULL) {
		r = p;
		p = p->next;
		t = hd;
		while (t->next != NULL && t->next->num > r->num)
			t = t->next;
		r->next = t->next;
		t->next = r;
	}
}
void find(struct str* hd, char s[]) {
	struct str* p = hd->next;
	while (p != NULL) {
		if (strcmp(p->word, s) == 0)
			break;
		p = p->next;
	}
	if (p == NULL) {
		struct str* p = (struct str*)malloc(sizeof(struct str));
		strcpy(p->word, s);
		p->num = 1;
		p->next = hd->next;
		hd->next = p;
	} else
		p->num++;
}
void sclb(struct str* hd) {
	FILE* fp = fopen("C:\\Users\\user\\Desktop\\数据结构\\第四周上机\\3.txt", "r");
	int i = 0, bz = 0, k;
	char c, substr[20];
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c >= 'A' && c <= 'Z')
			c = c + 32;

		if (c >= 'a' && c <= 'z') {
			if (bz == 0) {
				k = 0;
				substr[k++] = c;
				bz = 1;
			} else
				substr[k++] = c;
		} else {
			if (bz == 1) {
				bz = 0;
				substr[k] = '\0';
				find(hd, substr);
			}
		}
	}
	if (bz == 1) {
		substr[k] = '\0';
		find(hd, substr);
	}
	fclose(fp);

}
void main() {
	struct str* head = init();
	sclb(head);
	px(head);
	print(head);
	savetofile(head);
	SF(head);
}





