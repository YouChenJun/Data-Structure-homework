#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	char c;//字符
	int qz;//权值
	char bm[30];//编码
	struct node *lchild, *rchild, *next, *nt;
	//哈夫曼树左右孩子指针，nt为叶子链表下一节点指针，next哈夫曼树创建过程中合并链表下一节点
} hnode;
hnode *tjzf(char *a) { //字符统计
	hnode *hd = (hnode *)malloc(sizeof(hnode));
	int i = 0;
	
	hd->next = NULL;
	hd->lchild = NULL;
	hd->rchild = NULL;
	hd->nt = NULL;
	
	while (a[i] != '\0') {
		hnode *p = hd->next;
		while (p != NULL) {
			if (p->c == a[i]) {//如果在叶子链表中找到字符
				p->qz++;//权值加
				break;
			}
			p = p->next;
		}
		if (p == NULL) { //如果没有找到，叶子链表加1新节点
			hnode *t = (hnode *)malloc(sizeof(hnode));
			t->c = a[i];
			t->qz = 1;
			t->lchild = NULL;
			t->rchild = NULL;
			t->bm[0] = '\0';

			t->next = hd->next;
			hd->next = t;

			t->nt = hd->nt;
			hd->nt = t;
		}
		i++;
	}
	return hd;
}
void select(hnode *hd) {//选择 
	while (hd->next->next != NULL) {
		hnode *m = hd, *p = m->next, *min1, *min2;

		while (p->next != NULL) { //p和m一直指向比较结点的前一结点
			if (p->next->qz < m->next->qz) {
				m = p;
			}
			p = p->next;
		}

		//循环之后，m指向最小结点的前一节点
		min1 = m->next; //min指向第一最小结点
		m->next = min1->next; //将最小结点摘除

		m = hd, p = m->next;
		while (p->next != NULL) { //找第二最小权值结点
			if (p->next->qz < m->next->qz) {
				m = p;
			}
			p = p->next;
		}//循环之后，m指向最小结点的前一结点
		min2 = m->next; //min2指向第二小结点
		m->next = min2->next; //将第二小结点摘除

		m = (hnode *)malloc(sizeof(hnode));
		m->qz = min1->qz + min2->qz; //两最小权值合成一个新的结点
		m->lchild = min1;
		m->rchild = min2;
		m->next = hd->next;
		m->bm[0] = '\0';
		hd->next = m;
	}
}
void blx(hnode *hd,char cc[30],int t)//编码
{
	if(hd!=NULL){
		if(t==0){
			strcat(hd->bm,cc);
			strcat(hd->bm,"0");//左子树添加0
		}
		else if(t==1){
			strcat(hd->bm,cc);
			strcat(hd->bm,"1");//右子树添加1
		}
		blx(hd->lchild,hd->bm,0);//递归调用处理左子树
		blx(hd->rchild,hd->bm,1);//递归处理右子树
	}
}
void freetree(hnode *t)//释放
{
	if(t!=NULL){
		freetree(t->lchild);
		freetree(t->lchild);
		free(t);
		
	}
}
void main() {
	char a[200] = "adsafeadwaasddsdfgdfsefsdafsefef";
	hnode *head, *p, *hd = (hnode*)malloc(sizeof(hnode));
	head = tjzf(a);
	hd->nt = head->nt;

	select(head);
	blx(head->next, head->bm, -1);
	p = hd->nt;
	while (p != NULL) {
		printf("%c:%d:%s\n", p->c, p->qz, p->bm); //显示各叶子结点的字符，权值，编码
		p = p->nt;
	}
	freetree(head->next);
}
