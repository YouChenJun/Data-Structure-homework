#include<stdio.h>
#include<stdlib.h>
typedef struct qnode {
	int data;
	struct qnode *next;
} qnode, *queptr;
typedef struct {
	queptr front;
	queptr rear;
} linkque;
void initque(linkque *lq) {
	queptr p = (queptr)malloc(sizeof(qnode));
	p->next = NULL;
	lq->front = p;
	lq->rear = p;
}//数据初始化
void enque(linkque *lq, int e) {
	queptr q = (queptr)malloc(sizeof(qnode));
	q->data = e;
	q->next = NULL;
	lq->rear->next = q;
	lq->rear = q;
}

int deque(linkque *lq, int *e) {
	queptr p;
	if (lq->front == lq->rear) {
		return 0;
	}
	p = lq->front->next;
	lq->front->next = p->next;
	*e = p->data;
	if (lq->rear == p) {
		lq->rear = lq->front;
	}
	free(p);
	return 1;
}
int quempty(linkque *lq) {
	if (lq->front == lq->rear) {
		return 1;
	} else
		return 0;
}
void destroyque(linkque *lq) {
	queptr p;
	while (lq->front->next != NULL) {
		p = lq->front->next;
		lq->front->next = p->next;
		free(p);
	}
}
int quelen(linkque *lq) {
	int i = 0;
	queptr p;
	p = lq->front->next;
	while(p!=NULL){
		i++;
		p=p->next;
	}
	return i;
}
int main() {
	int n;
	linkque lq;
	initque(&lq);
	scanf("%d", &n);
	while (n != -1) {
		enque(&lq, n);
		scanf("%d", &n);
	}
	printf("\nshuchu:");
	while (!quempty(&lq)) {
		deque(&lq, &n);
		printf("%d ", n);
	}
	destroyque(&lq);
	
}
