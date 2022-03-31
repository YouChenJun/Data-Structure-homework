#include<stdio.h>
#include<malloc.h>
typedef struct bitnode {
	int data;
	struct bitnode *lchild, *rchild;
} bitnode, *bitree; //����������������

bitree create() {
	int d;
	bitnode *T;
	scanf("%d", &d);
	if (d == 0) T = NULL;
	else {
		T = (bitnode *)malloc(sizeof(bitnode));
		T->data = d;
		T->lchild = create();
		T->rchild = create();
	}
	return T;
}

int a[20] = {1, 3, 5, 0, 0, 7, 4, 6, 0, 0, 3, 5, 0, 0, 3, 0, 0}, a_i = 0;
void creat_sz(bitree *T) {
	if (a[a_i] == 0) {
		(*T) = NULL;
		a_i++;

	} else {
		(*T) = (bitnode *)malloc(sizeof(bitnode));
		(*T)->data = a[a_i];
		a_i++;
		creat_sz(&(*T)->lchild);
		creat_sz(&(*T)->rchild);
	}
}

typedef struct {
	bitree data[60];//���ָ������
	int top;
} stack;
//����ջ
//Ϊ��������������ǵݹ���׼��
void push(stack *st, bitree tp) { //��ջ
	if (st->top == 60 - 1)
		printf("overflow");
	else {
		st->top++;
		st->data[st->top] = tp;
	}
}

bitree pop(stack *st) { //��ջ
	bitree p;
	if (st->top == -1) {
		printf("underflow");
		return 0;
	} else {
		p = st->data[st->top];
		st->top--;
		return p;
	}
}

void blxfd(bitree t) { //�������-�ǵݹ�
	stack s;
	s.top = -1;
	while ((t != NULL) || (s.top != -1)) { //t���ջ���ջ����
		if (t != NULL) {
			printf("%d ", t->data);
			push(&s, t);
			t = t->lchild;
		} else {
			t = pop(&s);
			t = t->rchild;
		}
	}
}

void blzfd(bitree t) { //�������-�ǵݹ�
	stack s;
	s.top = -1;
	while ((t != NULL) || (s.top != -1)) {
		if (t != NULL) {
			push(&s, t);
			t = t->lchild;
		} else {
			t = pop(&s);
			printf("%d ", t->data);
			t = t->rchild;
		}
	}
}


void ft(bitree t) {
	if (t != NULL) {
		ft(t->lchild);
		ft(t->rchild);
		free(t);
	}
}

void main() {
	bitnode *t = NULL;
	//t = create();
	creat_sz(&t);
	printf("�ǵݹ��������Ϊ��");
	blxfd(t);
	printf("\n�ǵݹ��������Ϊ��");
	blzfd(t);
	ft(t);
}
