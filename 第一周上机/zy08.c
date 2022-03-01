#include <stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100//���Ա�ĳ�ʼ����
#define LISTINCREMENT 10//���Ա�ĳ�������
typedef struct {
	int *elem;
	int length;//��ǰԪ�ظ���
	int listsize; //��ǰ����Ĵ洢������С
} Sqlist; //��������
int Initlist_Sq(Sqlist *l) {
	l->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int)); //�ڴ��п��ٿռ�
	if (!l->elem)
		return 0;
	l->length = 0;
	l->listsize = LIST_INIT_SIZE; //��ʼ������
	return 1;
}
int Listinsert_Sq(Sqlist *l, int k, int e) { /*1<=k<=length+1*/
	int *p, *q;
	if (k < 1 || k > l->length + 1) //�������λ�ò��Ϸ�
		return 0;
	if (l->length >= l->listsize) {//��ǰ���ȵ���100����ô�������������ռ�
		int i, *newelem = (int*)malloc((l->listsize + LISTINCREMENT) * sizeof(int));
		if (!newelem)
			return  0;
		for (i = 0; i < l->length; i++) {
			newelem[i] = l->elem[i];
		}
		free(l->elem);
		l->elem = newelem;
	}
	q = &(l->elem[k - 1]);
	for (p = &(l->elem[l->length - 1]); p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	l->length++;
	return 1;
}
//���뵽n+1λ�ã���Ҫ�ƶ�0��
//���뵽��1��λ�ã���Ҫ����n��
//�����ƶ�n/2
//���뵽iλ�ã���Ҫ�ƶ�n-(k-1)
void DestroyList(Sqlist *l) {
	free(l->elem);//�ͷſռ�
}
void PrintList(Sqlist *l) {
	int i = 0;
	while (i < l->length) {
		printf("%d ", l->elem[i++]);
	}
	printf("\n");
}
void ClearList(Sqlist *l) {
	l->length = 0; //���õ�ǰԪ�ظ���Ϊ0
}
int ListEmpty(Sqlist*l) {
	if (l->length == 0)
		return 1;
	else
		return 0;

}
int ListLength(Sqlist *l) {
	return l->length;//Ԫ�ظ���
}
void GetElem(Sqlist *l, int i, int *e) { /*1<=i<=1-length*/
	*e = l->elem[i - 1];
}//�����ȡ��O(1)

int LocatElem(Sqlist *l, int e) {
	int i;
	for (i = 0; i < l->length; i++)
		if (l->elem[i] == e)
			return i + 1;
	return 0;
}
//��ñȽ�һ�Σ���Ƚ�n��,ƽ���Ƚ�(1+n)/2

void ListDelete(Sqlist * l, int k, int *e) {
	int i;
	*e = l->elem[k - 1];
	for (i = k; i < l->length; i++) {
		l->elem[i - 1] = l->elem[i];
	}
	l->length--;
}
//ɾ�����ǵ�һ�����֣�ǰ��n-1
//ɾ����n����ǰ��0
//�����ƶ�(n-1)/2

void MerList(Sqlist *La, Sqlist *Lb, Sqlist *Lc) {
	int i = 1, j = 1, k = 0, ai, bj;
	int La_len = ListLength(La), Lb_len = ListLength(Lb);
	while (i <= La_len && j <= Lb_len) {
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bj);
		if (ai <= bj) {
			Listinsert_Sq(Lc, ++k, ai);
			i++;
		} else {
			Listinsert_Sq(Lc, ++k, bj);
			j++;
		}
	}
	while (i <= La_len) {
		GetElem(La, i++, &ai);
		Listinsert_Sq(Lc, ++k, ai);
	}
	while (j <= Lb_len) {
		GetElem(Lb, j++, &bj);
		Listinsert_Sq(Lc, ++k, bj);
	}
}
void MerList1(Sqlist*La, Sqlist *Lb, Sqlist*Lc) {
	int i = 0, j = 0, k = 0;
	while (i < La->length && j < Lb->length) {
		if (La->elem[i] <= Lb->elem[j]) {
			Lc->elem[k++] = La->elem[i++];
		} else {
			Lc->elem[k++] = Lb->elem[j++];
		}
	}
	while (i < La->length) {
		Lc->elem[k++] = La->elem[i++];
	}
	while (j <= Lb->length) {
		Lc->elem[k++] = Lb->elem[j++];
	}
	Lc->length=La->length+Lb->length;
}
int main() {
	Sqlist la, lb, lc;
	int i;
	Initlist_Sq(&la);
	Initlist_Sq(&lb);
	Initlist_Sq(&lc);
	for (i = 1; i <= 10; i++)
		Listinsert_Sq(&la, i, i);
	PrintList(&la);
	printf("\n");
	for (i = 1; i <= 8; i++)
		Listinsert_Sq(&lb, i, 2 * i);
	PrintList(&lb);
	printf("\n");
	MerList1(&la, &lb, &lc); //la,lb�ϲ���lc
	PrintList(&lc);
	printf("\n");
	DestroyList(&la);
	DestroyList(&lb);
	DestroyList(&lc);
}
