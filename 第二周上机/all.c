#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
} listnode;
listnode *INITLIST() {
	listnode *hd = (listnode *)malloc(sizeof(listnode));
	hd->next = NULL;
	return hd;
}
void CREALIST(listnode *hd) { //前插法创建
	int dt;
	scanf("%d", &dt);
	while (dt != -1) {
		listnode *p = (listnode *)malloc(sizeof(listnode));
		p->data = dt;
		p->next = hd->next;//插入
		hd->next = p;//插入
		scanf("%d", &dt);
	}
}
void CREALISTWC(listnode *hd) { //尾插
	int dt;
	listnode *r = hd;
	scanf("%d", &dt);
	while (dt != -1) {
		listnode *p = (listnode*)malloc(sizeof(listnode));
		p->data = dt;
		p->next = NULL;

		r->next = p; //插入
		r = p;
		scanf("%d", &dt);
	}
}

void PRINTLIST(listnode *hd) {
	listnode *p = hd->next;
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
void FPRINTLIST(listnode *hd) {

	while (hd->next != NULL) {
		listnode*p = hd->next;
		hd->next = p->next;
		free(p);
	}
	free(hd);
	
}
int Getelem(listnode *hd, int i, int *e) {
	int j = 1;
	listnode *p = hd->next;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (p->next != NULL && j == i) {
		listnode *q = p->next;
		p->next = q->next;
		*e = q->data;
		free(q);
		return 1;
	}
	return 0;
}
int Getelemd(listnode *hd, int i, int*e) {
	int j = 1;
	listnode *p = hd;
	while (p->next != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (p->next != NULL && j == 1) {
		listnode *q = p->next;
		p->next = q->next; //把p后节点q从列表中删除
		*e = q->data; //保存值
		free(q);
		return 1;
	}
	return 0;
}
void FREELIST(listnode *hd) {
	while (hd->next != NULL) {
		listnode *p = hd->next;
		hd->next = p->next;
		free(p);
	}
	free(hd);
}
int Lenght(listnode *hd) {//输出多少个元素
	int i = 0;
	listnode *p = hd->next;
	while (p != NULL) {
		i++;
		p = p->next;

	}
	return i;
}
int locatelem(listnode *hd, int e) {//查找元素
	listnode *p = hd->next;
	int i = 1;
	while (p != NULL) {
		if (p->data == e)
			break;
		else p = p->next;
		i++;
	}
	if (p != NULL) {
		return i;
	} else
		return 0;

}
void insertelem(listnode *hd, int i, int e) {//第i个位置插入e
	int j = 1;
	listnode *q=(listnode *)malloc(sizeof(listnode)),*p=hd;
	q->data=e;
	while(i<i&&p->next!=NULL){
		p=p->next;
		j++;
	}
	q->next=p->next;
	p->next=q;
}

void main() {
	int e;
	listnode *head = NULL;
	head = INITLIST();
	CREALISTWC(head);
	PRINTLIST(head);
	Getelem(head, 4, &e);
	PRINTLIST(head);
	FREELIST(head);
}
