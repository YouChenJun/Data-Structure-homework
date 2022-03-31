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
	int bz[60];
	int top;
} stack;
//����ջ
//Ϊ��������������ǵݹ���׼��
void push(stack *st, bitree tp,int bz) { //��ջ
	if (st->top == 60 - 1)
		printf("overflow");
	else {
		st->top++;
		st->data[st->top] = tp;
		st->bz[st->top]=bz;//�������һ����־����
	}
}

bitree pop(stack *st,bitree *tp,int *bz) { //��ջ
	bitree p;
	if (st->top == -1) {
		printf("underflow");
		return 0;
	} else {
		*tp = st->data[st->top];
		*bz=st->bz[st->top]--;//����־
		st->top--;
	}
}

void blhfd(bitree t)//���򣬷ǵݹ�
{
	stack s;
	int tag;
	s.top=-1;
	while((t!=NULL)||(s.top!=-1)){
		if(t!=NULL){
			tag=0;
			push(&s,t,tag);
			t=t->lchild;//��һ�ν�
		}
		else
		{
			pop(&s,&t,&tag);
			if(tag==0){
				tag=1;//���������֣����Ϊ1���������������
				push(&s,t,tag);
				t=t->rchild;
			}
			else
			{
				printf("%d ",t->data);
				t=NULL;
			}
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
	printf("\n�ǵݹ�������Ϊ��");
	blhfd(t);
	ft(t);
}
