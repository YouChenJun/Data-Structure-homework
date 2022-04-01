#include<stdio.h>
#include<stdlib.h>
#define max 40
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

int a[17] = {1, 4, 0, 0, 9, 3, 0, 0}, a_i = 0; //����ģ�����

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
int ceng = 1, s[10], qsmin = -100; //����һ�����־������һ�����鱣��
int temp1;
void ccbl(bitnode *t) { //��α���
	bitnode *dl[max], *p = NULL;
	int f = 0, r = 0;
	if (t != NULL) { //���
		dl[r] = t;
		s[1] = dl[r];
		r++;

	}
	while (f != r) {
		p = dl[f];
		f++;//����
		//printf("%d ", p->data);
		if (p->lchild != NULL || p->rchild != NULL) {
			if (p->lchild != NULL) {
				dl[r] = p->lchild;
				temp1 = dl[r];
				s[ceng] += temp1; //ÿ��һ�㣬����һ���Ȩֵ����������
				r++;
			}
			if (p->rchild != NULL) {
				dl[r] = p->rchild;
				temp1 = dl[r];
				s[ceng] += temp1;
				r++;
			}
			ceng++;//����++
		}
	}
	int index;
	for (int j = 1; j <ceng; j++) { //������Ȩֵ����һ��
		if (qsmin < s[j]) {
			index = j;
		}
	}
	printf("\nȨֵ������һ���ǣ�%d", index);
}
void blx(bitnode *t) { //�������
	if (t) {
		printf("%d ", t->data);
		blx(t->lchild);
		blx(t->rchild);
	}
}
void blz(bitnode *t) { //�������
	if (t) {
		blz(t->lchild);
		printf("%d ", t->data);
		blz(t->rchild);
	}
}
void blh(bitnode *t) { //�������
	if (t) {
		blh(t->lchild);
		blh(t->rchild);
		printf("%d ", t->data);
	}
}
void freetree(bitnode *t) { //�ͷ�
	if (t != NULL) {
		freetree(t->lchild);
		freetree(t->rchild);
		freetree(t);
	}
}
void main() {

	bitnode *t = NULL;
	t = creat();
	//create_sz(&t);
	ccbl(t);
	freetree(t);
}
