#include<stdio.h>
#include<stdlib.h>
typedef struct bithrnode {
	int data;
	int ltag, rtag;
	struct bithrnode *lchild, *rchild;
} bithrnode, *bithree;
int a[20] = {1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0}, a_i = 0;
void creattree(bithree *t) { //����������
	if (a[a_i] == 0) {
		(*t) = NULL;
		a_i++;
	} else {
		(*t) = (bithrnode *)malloc(sizeof(bithrnode));
		(*t)->data = a[a_i];
		a_i++;
		(*t)->ltag = 0;
		(*t)->rtag = 0;
		creattree(&(*t)->lchild);
		creattree(&(*t)->rchild);
	}
}
bithree pre = NULL; //ȫ�ֱ�����ָ�����ǰһ�ڵ�
void InThreading(bithree p) {//����Զ���������������
	//�����ǰ������
	if (p) {
		InThreading(p->lchild);//�ݹ鵱ǰ����������������������
		//�����ǰ���û�����ӣ����־λ��Ϊ1����ָ����ָ����һ��� pre
		if (!p->lchild) {
			p->ltag = 1;
			p->lchild = pre;
		}
		//��� pre û���Һ��ӣ��ұ�־λ��Ϊ 1����ָ����ָ��ǰ��㡣
		if (pre && !pre->rchild) {
			pre->rtag = 1;
			pre->rchild = p;
		}
		pre = p; //preָ��ǰ���
		InThreading(p->rchild);//�ݹ�����������������
	}
}
void blzxs(bithree t) { //�����������������
	bithree p = t->lchild;
	while (p != t) {
		//һֱ�����ӣ����һ��Ϊ�����������ŵ�һ��
		while (p->ltag == 0) {
			p = p->lchild;
		}
		printf("%d ", p->data);  //�����������
		//������ұ�־λΪ1ʱ��ֱ���ҵ����̽��
		while (p->rtag == 1 && p->rchild != NULL) {
			p = p->rchild;
			printf("%d ", p->data);
		}
		//���򣬰�����������Ĺ��ɣ������������������µĽ�㣬Ҳ���Ǽ���ѭ������
		p = p->rchild;
	}
}

void blzxs_nx(bithree t) { //����
	bithree p = t->rchild; //ָ���ұ�

	while (p != t) {
		printf("%d ", p->data);
		if (p->ltag == 1) {
			p = p->lchild;
		} else {
			p = p->lchild;
			while (p->rtag == 0) {
				p = p->rchild;
			}
		}
	}
}

void inOrderReverse(bithree T) {//��
	bithree p = T;
	while (p->rchild != NULL) {//һֱ�ҵ����ұߵ�
		p = p->rchild;
	}
	while (p) {
		printf("%d ", p->data);
		if(p->ltag==1){
			p=p->lchild;
		}
		else
		{
			p=p->lchild;
			while(p->rtag==0){
				p=p->rchild;
			}
		}
	}
}

void bl(bithree t) { //����������ݹ�
	if (t) {
		bl(t->lchild);
		printf("%d ", t->data);
		bl(t->rchild);
	}
}
void main() {
	bithree t = NULL, s = NULL;
	creattree(&t);
	bl(t);//�ݹ����
	printf("\n");
//	s = (bithree)malloc(sizeof(bithrnode)); //�������ӵ�ͷ�ڵ�
//	s->ltag = 0;
//	s->rtag = 1;
//	s->rchild = s; //�Һ������Լ�
//	if (t == NULL) {
//		s->lchild = s;
//	} else
	InThreading(t);//������
	//blzxs_nx(t);
	inOrderReverse(t);
	printf("\n");
	blzxs(t);
}


