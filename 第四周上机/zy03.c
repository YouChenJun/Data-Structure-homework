#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char data;
	struct node *next;
} listnode;
listnode *initlist() {
	listnode *hd = (listnode *)malloc(sizeof(listnode));
	hd->next = NULL;
	return hd;
}
void carelistwcsz(listnode *hd, char a[]) {
	int i = 0;
	listnode *r = hd;
	while (a[i] != '\0') {
		listnode *p = (listnode *)malloc(sizeof(listnode));
		p->data = a[i];
		p->next = NULL;

		r->next = p;
		r = p;
		i++;
	}
}

void printlist(listnode *hd) {
	listnode *p = hd->next;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next;
	}
	printf(" \n");
}
void freelist(listnode *hd) {
	while (hd->next != NULL) {
		listnode *p = hd->next;
		hd->next = p->next;
		free(p);
	}
	free(hd);
}

void fun(listnode *hd, listnode *hdb, listnode *hdc) {
	listnode *p = hd, *rb = hdb, *rc = hdc, *q = NULL;
	while (p->next != NULL) {
		if (p->next->data >= 'A' && p->next->data <= 'Z') {
			q = p->next;
			p->next = q->next;
			q->next = NULL;

			rb->next = q;
			rb = rb->next;
		} else if (p->next->data >= 'a' && p->next->data <= 'z') {
			q = p->next;
			p->next = q->next;

			rc->next = q;
			rc = rc->next;
		} else {
			p = p->next;
		}
	}
}
int main() {
	listnode* head = NULL, * headb = NULL, * headc = NULL;
	head = initlist();
	headb = initlist();
	headc = initlist();
	carelistwcsz(head, "abADdddDD234a88Ad");
	printlist(head);
	fun(head, headb, headc);
	printlist(head);
	freelist(head);
	printlist(headb);
	freelist(headb);
	printlist(headc);
	freelist(headc);
}
