#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 99999
typedef struct snode { //�����������ṹ
	char c;
	int qz;
	char bm[30];
	int lchild, rchild, bz; //bzΪ1ʱ��ʾ��Ȩ�����У�bzΪ0��ʾ����Ȩֵ�����У�������±�
} snode;
typedef struct sz { //��������洢�Ĺ�������
	snode *arr;//ָ���������ָ��
	int num_yz;//��������Ҷ�ӽ�����
} hfms;
typedef struct cnode {
	//��������洢�Ľ��
	char c;
	int qz;
	struct cnode *next;
} hconde;
void tjzf(char *a, hfms *s) { //���ַ���a��ӵ����������������
	int i = 0;
	hconde *hd = (hconde *)malloc(sizeof(hconde)), *p; //����ͷ���
	hd->next = NULL;
	while (a[i] != '\0') { //ͳ��a���ַ�����������洢�ַ�������Ȩֵ

		p = hd->next;
		while (p != NULL) {
			//���������д��ڴ洢a[i]�Ľ�㣬��ô���Ȩֵ++
			if (p->c == a[i]) {
				p->qz++;
				break;
			}
			p = p->next;
		}
		if (p == NULL) {
			//��pΪ�գ����赱ǰ����û�д洢�ַ�a[i]�Ľ�㣬��ô���ٿռ�
			hconde *t = (hconde*)malloc(sizeof(hconde));
			t->c = a[i];
			t->qz = 1;
			t->next = hd->next; //ͷ�巨����t��������
			hd->next = t;
		}
		i++;
	}
	i = 0;
	p = hd->next;
	while (p != NULL) {
		i++;
		p = p->next; //����������
	}
	s->num_yz = i; //��������Ҷ�ӽ�㳤��=������
	s->arr = (snode*)malloc(sizeof(snode) * (s->num_yz * 2 - 1));
	//���ٿռ䣬�ռ��С/�ڵ���=2*n0-1
	p = hd->next;
	i = 0;
	while (p != NULL) {
		//�������и��������ݴ���������
		s->arr[i].c = p->c;
		s->arr[i].qz = p->qz;
		strcpy(s->arr[i].bm, "");
		s->arr[i].lchild = -1; //�洢�ַ�����Ҷ�ӽ�㣬������
		s->arr[i].rchild = -1;
		s->arr[i].bz = 1; //Ȩֵ��������
		p = p->next;
		i++;
	}
	for (; i < s->num_yz * 2 - 1; i++) {
		//��ʣ�µĽ���ʼ��
		s->arr[i].c = '\0';
		s->arr[i].qz = 0;
		strcpy(s->arr[i].bm, "");
		s->arr[i].lchild = -1;
		s->arr[i].rchild = -1;
		s->arr[i].bz = 0; //Ȩ��������
	}
	p = hd->next;
	while (p != NULL) {
		hd->next = p->next;
		free(p);
		p = hd->next;
	}
	free(hd);

}
void js(hfms s) {//������������
	int i, minlxb, min2xb, minxb, minz, k;
	for (k = s.num_yz; k < s.num_yz * 2 - 1; k++) {
		//��Ϊ�洢���ַ��Ľڵ�������ݣ�ȨֵԽ���������е�λ��Խ����
		minxb = -1;
		minz = max;
		for (i = 0; i < s.num_yz * 2 - 1; i++) {
			if (s.arr[i].bz == 1 && s.arr[i].qz < minz) {
				minz = s.arr[i].qz; //��Ȩ������С��Ȩֵ����minz
				minxb = i; //��Ȩֵ������Сֵ������С��
			}
		}
		minlxb = minxb;
		s.arr[minlxb].bz = 0; //����СȨֵ����Ԫ���Ƴ�Ȩ����
		minxb = -1;
		minz = max;
		for (i = 0; i < s.num_yz * 2 - 1; i++) {
			if (s.arr[i].bz == 1 && s.arr[i].qz < minz) {
				minz = s.arr[i].qz; //����ǰȨֵ������С��Ȩֵ����
				minxb = i; //��ǰȨֵ������СȨֵ
			}
		}
		min2xb = minxb;
		s.arr[min2xb].bz = 0; //�ѵ�ǰ�ڶ�СȨֵ������Ԫ���Ƴ�

		s.arr[k].qz = s.arr[minlxb].qz + s.arr[min2xb].qz; //
		s.arr[k].bz = 1; //�ý����ӽ�Ȩ����
		s.arr[k].lchild = minlxb;
		s.arr[k].rchild = min2xb;

	}
}
void bm(hfms s, int xb, char cc[30], int t) { //����������б���
	if (t == 0) { //������ڵ�Ϊ���׽�������
		strcat(s.arr[xb].bm, cc);
		strcat(s.arr[xb].bm, "0");
	} else if (t == 1) { //���ýڵ�Ϊ���׽����Һ���
		//�ȰѸ��׽���bm��ֵ���ýڵ��bm��Ȼ��ýڵ��bm+1
		strcat(s.arr[xb].bm, cc);
		strcat(s.arr[xb].bm, "1");
	}
	if (s.arr[xb].lchild != -1) { //������Ӵ��ڣ��������0
		bm(s, s.arr[xb].lchild, s.arr[xb].bm, 0);
	}
	if (s.arr[xb].rchild != -1) {
		//����Һ��Ӵ���....
		bm(s, s.arr[xb].rchild, s.arr[xb].bm, 1);
	}
}
void main() {
	int i;
	char a[200] = "abbccccdddddddddd";
	hfms s;
	tjzf(a, &s);
	js(s);
	bm(s, s.num_yz * 2 - 1 - 1, "", - 1);
	for (i = 0; i <= s.num_yz - 1; i++) {
		printf("%c:%d:%s\n", s.arr[i].c, s.arr[i].qz, s.arr[i].bm);
	}
	free(s.arr);
}
