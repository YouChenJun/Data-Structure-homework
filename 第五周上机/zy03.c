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

int a[17] = {1, 8, 9, 0, 0, 6, 7, 0, 0, 8, 0, 0}, a_i = 0; //����ģ�����

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
//int qgs(bitnode *t)//�����-return ����
//{
//	int x,l,r;
//	if(t!=NULL){
//		l=qgs(t->lchild);
//		r=qgs(t->rchild);
//		x=l+r+1;
//	}
//	else{
//		x=0;
//	}
//	return x;
//}
//int qh(bitnode *t)//�����-return ����
//{
//	int x,l,r;
//	if(t!=NULL){
//		l=qh(t->lchild);
//		r=qh(t->rchild);
//		x=l+r+t->data;
//	}
//	else{
//		x=0;
//	}
//	return x;
//}
//
//int num=0;
//void qgs1(bitnode *t)//�������-ȫ�ֱ���
//{
//	if(t!=NULL){
//		num++;
//		qgs1(t->lchild);
//		qgs1(t->rchild);
//	}
//}
//
//int he=0;
//void qh1(bitnode *t)//�����-ȫ�ֱ���
//{
//	if(t!=NULL){
//		he=he+t->data;
//		qh1(t->lchild);
//		qh1(t->rchild);
//	}
//}
//int max,min;
//void qmax_min(bitnode *t)//�����-ȫ�ֱ���
//{
//	if(t!=NULL){
//		if(t->data>max){
//			max=t->data;
//		}
//		else if(t->data<min){
//			min=t->data;
//		}
//		qmax_min(t->lchild);
//		qmax_min(t->rchild);
//	}
//}
//
//
//void qgs2(bitnode *t,int *p)//��ڵ����-�ֲ���̬����
//{
//	if(t!=NULL){
//		(*p)++;
//		qgs2(t->lchild,p);
//		qgs2(t->rchild,p);
//	}
//}
//void qh2(bitnode *t,int *p)//��ڵ��-�ֲ���̬����
//{
//	if(t!=NULL){
//		(*p)=(*p)+t->data;
//		qh2(t->lchild,p);
//		qh2(t->rchild,p);
//	}
//}
int qgd(bitnode *t) { //��߶�
	int x, l, r;
	if (t != NULL) {
		l = qgd(t->lchild);
		r = qgd(t->rchild);//�����Ҵ��ǰ��
		if (l > r) {
			x = l + 1;
		} else {
			x = r + 1;
		}
	} else {
		x = 0;
	}
	return x;

}
void copy(bitnode **T, bitnode **S) { //���ƶ�����
	if ((*T) != NULL) {
		(*S) = (bitnode *)malloc(sizeof(bitnode));
		(*S)->data = (*T)->data;
		copy(&(*T)->lchild, &(*S)->lchild); //�ݹ��㷨
		copy(&(*T)->rchild, &(*S)->rchild);
	} else {
		(*S) = NULL;
	}
}
int qcc(bitnode *t, int n, int cc) { //��n�ڶ������Ĳ��
	if (t != NULL) {
		if (t->data) {
			return cc;
		} else {
			int c1, c2;
			c1 = qcc(t->lchild, n, cc + 1);
			c2 = qcc(t->rchild, n, cc + 1);
			if (c1 != 0) {
				return c1;//�������ҵ���
			} else if (c2 != 0) {
				return c2;
			} else
				return 0;
		}
	} else
		return 0;
}

void main() {
//	int gs = 0;
//
//	int s = 0;

	bitnode *t = NULL;
	bitnode *f = NULL; //Ϊ���ƶ�������������
	//t=creat();
	create_sz(&t);
	printf("�������:");
	blx(t);
	//printf("\n�������:");
	//blz(t);
	//printf("\n�������:");
	//blh(t);
//
//	printf("\n%d\n", qgs(t));
//	qgs1(t);
//	printf("%d\n", num);
//	qgs2(t, &gs);
//	printf("%d\n", gs);
//	//����Ϊ���
//	printf("��ͣ�\n");
//	printf("%d\n", qh(t));
//	qh1(t);
//	printf("%d\n", he);
//	qh2(t, &s);
//	printf("%d\n", s);
//	//����Ϊ�����Сֵ
//	if (t != NULL) {
//		max = t->data;
//		min = t->data;
//		qmax_min(t);
//		printf("max:%d,min:%d", max, min);
//	} else {
//		printf("��Ϊ�գ�Ϊ�����Сֵ");
//	}
	printf("\n");
	blx(f);
	printf("\n�߶ȣ�%d\n", qgd(t));
	printf("���Σ�%d\n", qcc(t, 9, 1));

	freetree(t);
}
