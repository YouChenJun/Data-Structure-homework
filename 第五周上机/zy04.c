#include<stdio.h>
#include<stdlib.h>
typedef struct bitnode {
	int data;
	struct bitnode *lchild, *rchild;
} bitnode;
bitnode *creat() {
	int d;
	bitnode *T;
	scanf("%d", &d);
	if (d == 0) {
		T = NULL;
	} else {
		T = (bitnode *)malloc(sizeof(bitnode));
		T->data = d;
		T->lchild = creat();
		T->rchild = creat();

	}
	return T;
}

int a[17] = {1, 2, 4, 0, 0, 3, 0, 0, 8, 0, 0}, a_i = 0; //����ģ�����
int n;
void create_sz(bitnode **T) {
	if (a[a_i] == 0) {
		(*T) = NULL;
		a_i++;
	} else {
		(*T) = (bitnode *)malloc(sizeof(bitnode));
		(*T)->data = a[a_i];
		a_i++;
		create_sz(&(*T)->lchild);
		create_sz(&(*T)->rchild);
	}
}
void blx(bitnode *t) { //�������
	if (t && n >= 1) {
		printf("%d ", t->data);
		n--;
		blx(t->lchild);
		blx(t->rchild);
	}
}
void blz(bitnode *t) { //�������
	if (t ) {
		blz(t->lchild);
		if ( n >= 1) {
			printf("%d ", t->data);
			n--;
		}
		blz(t->rchild);
	}
}
void blh(bitnode *t) { //�������
	if (t ) {
		blh(t->lchild);
		blh(t->rchild);
		if (n >= 1) {

			printf("%d ", t->data);
			n--;
		}
	}
}
void freetree(bitnode *t) { //�ͷ�
	if (t != NULL) {
		freetree(t->lchild);
		freetree(t->rchild);
		freetree(t);
	}
}
void swap(bitnode *t) { //���ҽ���
	if (t) {
		bitnode *u = t->lchild;
		t->lchild = t->rchild;
		t->rchild = u;
		swap(t->lchild);
		swap(t->rchild);
	}
}
void main() {

	bitnode *t = NULL;
	//t=creat();
	create_sz(&t);
	printf("�������:");
	n = 3;
	blx(t);
	printf("\n�������:");
	n = 3;
	blz(t);
	printf("\n�������:");
	n = 3;
	blh(t);
	printf("\n");
	printf("---������---\n");

	swap(t);
	printf("�������:");
	n = 3;
	blx(t);
	printf("\n�������:");
	n = 3;
	blz(t);
	printf("\n�������:");
	n = 3;
	blh(t);
	freetree(t);
}
