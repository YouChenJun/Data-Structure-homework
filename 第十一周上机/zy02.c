# include <stdio.h>
# include <stdlib.h>
# define VEXNUM 6
# define INF 9999//�����
# include <time.h>
#define ARCNUM 10

struct Graph {
	int vexnum, arcnum, kind; //��������������ͼ���ͣ�1234-����ͼ������ͼ����������������
	char vexs[VEXNUM + 1]; //�����ַ�����
	int arcs[30]; //����ֹ���±꼰Ȩֵ����
} graph = {6, 10, 1, "ABCDEF", {0, 1, 6, 0, 2, 1, 0, 3, 5, 1, 2, 5, 1, 4, 3, 2, 4, 6, 2, 5, 4, 2, 3, 5, 3, 5, 2, 4, 5, 6}};

struct MGraph_Mat { //ͼ���ڽӾ���洢���ݶ���
	int vexnum, arcnum; //������������
	char vexs[VEXNUM];//��������
	int arcs[VEXNUM][VEXNUM];//�ڽӾ���
	int kind;//ͼ������
};

void create_Mat(struct MGraph_Mat *g) { //����ͼ���ڽӾ���
	int i, j;
	g->vexnum = graph.vexnum; //������
	g->arcnum = graph.arcnum; //����
	g->kind = graph.kind; //ͼ�����ͣ�1234-����ͼ������ͼ����������������

	for (i = 0; i <= g->vexnum - 1; i++) {
		g->vexs[i] = graph.vexs[i]; //�����ֵ�����ַ�
	}
	for (i = 1; i <= g->vexnum; i++) {
		for (j = 1; j <= g->vexnum; j++) {
			if (g->kind == 1 || g->kind == 2) { //���������ͼ�Ļ�����ͼ
				g->arcs[i - 1][j - 1] = 0; //�ڽӾ���ȫ����ʼֵΪ0
			} else {
				g->arcs[i - 1][j - 1] = INF; //�ڽӾ���ȫ����ʼֵΪ����
			}
		}
	}
	for (i = 0; i <= g->arcnum - 1; i++) { //����ߴ�����Ȩֵ��1
		if (g->kind == 1) { //���������ͼ��һ���ߴ����������Ԫ�أ���1
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = 1;
			g->arcs[graph.arcs[i * 3 + 1]][graph.arcs[i * 3]] = 1; //�ԳƵ�
		} else if (g->kind == 2) { //���������ͼ��һ���ߴ������һ��Ԫ�أ���1
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = 1;
		} else if (g->kind == 3) { //�������������һ���ߴ����������Ԫ�أ���Ȩֵ
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = graph.arcs[i * 3 + 2];
			g->arcs[graph.arcs[i * 3 + 1]][graph.arcs[i * 3]] = graph.arcs[i * 3 + 2];
		} else if (g->kind == 4) { //�������������һ���ߴ������һ��Ԫ�أ���Ȩֵ
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = graph.arcs[i * 3 + 2];
		}
	}
}

void print_Mat(struct MGraph_Mat g) { //��ʾ�ڽӾ���
	int i, j;
	printf("     ");
	for (i = 0; i <= (g.vexnum - 1); i++) {
		printf("%3c", graph.vexs[i]); //��ʾ��һ�У����ڵ��ַ�
	}
	printf("\n");

	for (i = 0; i <= g.vexnum - 1; i++) { //����
		printf("   %c   ", graph.vexs[i]); //����ʾ�ַ�
		for (j = 0; j <= g.vexnum - 1; j++) { //����
			if (g.kind == 1 || g.kind == 2) { //�����ͼ
				printf("%d  ", g.arcs[i][j]); //��ʾ1��0
			} else { //�������
				if (g.arcs[i][j] == INF) {
					printf(" ��");//��ʾ����
				} else {
					printf("%d  ", g.arcs[i][j]); //��Ȩֵ
				}
			}
		}
		printf("\n");
	}
}


//�ڽӱ�-�߽��
struct arcnode {
	int adjvex, weight; //�ڽӱ��±꣬Ȩֵ
	struct arcnode *nextarc;//��һ�߱�ָ��
};
struct vexnode { //������
	char vexdata;//�����ַ�����
	struct arcnode *firstarc; //��һ���߱�ָ��
};

struct MGraph_Adj { //ͼ���ڽӱ������ݶ���
	int vexnum, arcnum; //������������
	struct vexnode vexarr[VEXNUM];//����ڵ�����
	int kind;//ͼ����
};

void create_Adj(struct MGraph_Adj *g) { //����ȫ��ͨ��ͼ�ζ���graph������ͼ���ڽӱ�
	int i;
	struct arcnode *p = NULL;
	g->vexnum = graph.vexnum; //������
	g->arcnum = graph.arcnum; //����
	g->kind = graph.kind; //ͼ�����ͣ�1234-����ͼ������ͼ����������������
	for (i = 0; i <= g->vexnum - 1; i++) {
		g->vexarr[i].vexdata = graph.vexs[i]; //��һ���㸳ֵ-�����ַ�
		g->vexarr[i].firstarc = NULL; //��һ���߳�ʼֵ�ÿ�
	}
	for (i = 0; i <= g->arcnum - 1; i++) { //�����ߴ����߱���
		p = (struct arcnode *)(malloc(sizeof(struct arcnode))); //����߱�ռ�
		p->adjvex = graph.arcs[i * 3 + 1]; //�߽��-���±�
		p->weight = graph.arcs[i * 3 + 2]; //�߽��-Ȩֵ

		p->nextarc = g->vexarr[graph.arcs[i * 3]].firstarc;
		g->vexarr[graph.arcs[i * 3]].firstarc = p; //��p��������ָ������֮��-ǰ��

		if (g->kind == 1 || g->kind == 3) { //����������ͼ�������������ٴ���һ�����
			p = (struct arcnode *)(malloc(sizeof(struct arcnode)));
			p->adjvex = graph.arcs[i * 3]; //�߽��-���±�
			p->weight = graph.arcs[i * 3 + 2]; //�߽��-Ȩֵ

			p->nextarc = g->vexarr[graph.arcs[i * 3 + 1]].firstarc;
			g->vexarr[graph.arcs[i * 3 + 1]].firstarc = p; //��p��������ָ������֮��
		}
	}
}

void print_Adj(struct MGraph_Adj g) { //��ʾ�ڽӱ�
	int i;
	struct arcnode *p = NULL;
	printf("\n\n");
	for (i = 0; i <= g.vexnum - 1; i++) { //������ڵ�
		printf("   %d %c", i, g.vexarr[i].vexdata); //�±꣬�����ַ�
		p = g.vexarr[i].firstarc; //pָ���һ���߱���
		while (p) { //����߱���ʾ
			if (g.kind == 1 || g.kind == 2) {
				printf("->%d", p->adjvex);
			} else {
				printf("->%d|%d", p->adjvex, p->weight);
			}
			p = p->nextarc;
		}
		printf("\n");
	}
}
int prim_Mat(struct MGraph_Mat g, int v) {
	int lowcost[VEXNUM];
	int mst[VEXNUM];
	int i, j, min, minid, sum = 0;
	for (i = 0; i <= g.vexnum - 1; i++) {
		lowcost[i] = g.arcs[v][i];
		mst[i] = v;
	}
	for (i = 1; i <= g.vexnum - 1; i++) {
		min = INF;
		minid = v;
		for (j = 0; j <= g.vexnum - 1; j++) {
			if (lowcost[j] < min && lowcost[j] != 0) {
				min = lowcost[j];
				minid = j;
			}
		}
		printf(" \n%d->%d=%d", mst[minid], minid, min);
		sum += min;
		lowcost[minid] = 0;
		for (j = 1 + v; j <= g.vexnum - 1 + v; j++) {
			if (g.arcs[minid][j % g.vexnum] < lowcost[j % g.vexnum]) {
				lowcost[j % g.vexnum] = g.arcs[minid][j % g.vexnum];
				mst[j % g.vexnum] = minid;
			}

		}
	}
	return sum;
}
int prim_Adj(struct MGraph_Adj g, int v) {
	struct arcnode* p = NULL;
	int lowcost[VEXNUM];
	int mst[VEXNUM];
	int i, j, min, minid, sum = 0;
	for (i = 0; i <= g.vexnum - 1; i++) {
		lowcost[i] = INF;
		mst[i] = v;
	}
	p = g.vexarr[v].firstarc;
	while (p) {
		lowcost[p->adjvex] = p->weight;
		p = p->nextarc;
	}
	for (i = 1; i <= g.vexnum - 1; i++) {
		min = INF;
		minid = v;
		for (j = 0; j <= g.vexnum - 1; j++) {
			if (lowcost[j] < min && lowcost[j] != 0) {
				min = lowcost[j];
				minid = j;
			}
		}
		printf("\n%d>%d=%d", mst[minid], minid, min);
		sum += min;
		lowcost[minid] = 0;
		p = g.vexarr[minid].firstarc;
		while (p) {
			if ((p->weight < lowcost[p->adjvex]) && (p->adjvex != mst[p->adjvex]))

			{
				lowcost[p->adjvex] = p->weight;
				mst[p->adjvex] = minid;
			}
			p = p->nextarc;
		}
	}
	return sum;
}
struct Edge {
	int u;
	int v;
	int w;
};
void Bubblesort(struct Edge R[], int e) {
	struct Edge temp;
	int i, j, swap;
	for (i = 0; i <= e - 2; i++) {
		swap = 0;
		for (j = 0; j <= e - 2 - i; j++)
			if (R[j].w > R[j + 1].w) {
				temp = R[j];
				R[j] = R[j + 1];
				R[j + 1] = temp;
				swap = 1;
			}
		if (swap == 0) break;
	}
}
int krskl_Mat(struct MGraph_Mat g) {
	int i, j, u1, v1, sn1, sn2, k, sum = 0;
	int vest[VEXNUM];
	struct Edge E[ARCNUM];
	k = 0;
	for (i = 0; i <= g.vexnum - 1; i++)
		for (j = 0; j <= i - 1; j++)
			if (g.arcs[i][j] != INF) {
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.arcs[i][j];
				k++;
			}
	Bubblesort(E, k);
	for (i = 0; i < g.vexnum; i++)
		vest[i] = i;
	k = 1;
	j = 0;
	while (k <= g.vexnum - 1) {
		u1 = E[j].u;
		v1 = E[j].v;
		sn1 = vest[u1];
		sn2 = vest[v1];
		if (sn1 != sn2) {
			printf("%d->%d=%d\n", u1, v1, E[j].w);
			sum = sum + E[j].w;
			k++;
			for (i = 0; i < g.vexnum; i++)
				if (vest[i] == sn2)
					vest[i] = sn1;
		}
		j++;
	}
	return sum;
}
int krskl_Adj(struct MGraph_Adj g) {
	int i, j, k, u1, v1, sn1, sn2, sum = 0;
	int vest[VEXNUM];
	struct Edge E[ARCNUM];
	struct arcnode* p = NULL;
	k = 0;

	for (i = 0; i <= g.vexnum - 1; i++) {
		p = g.vexarr[i].firstarc;
		while (p) {
			for (j = 0; j <= k - 1; j++)
				if (E[j].u == p->adjvex && E[j].v == i)
					break;
			if (j == k) {
				E[k].u = i;
				E[k].v = p->adjvex;
				E[k].w = p->weight;
				k++;
			}
			p = p->nextarc;
		}
	}
	Bubblesort(E, k);
	for (i = 0; i < g.vexnum; i++)
		vest[i] = i;
	k = 1;
	j = 0;
	while (k < g.vexnum) {
		u1 = E[j].u;
		v1 = E[j].v;
		sn1 = vest[u1];
		sn2 = vest[v1];
		if (sn1 != sn2) {
			printf("%d->%d=%d\n", u1, v1, E[j].w);
			sum = sum + E[j].w;
			k++;
			for (i = 0; i < g.vexnum; i++)
				if (vest[i] == sn2)
					vest[i] == sn1;
		}
		j++;
	}
	return sum;
}

void fun(char s[]) {
	/*time(NULL)��ȡ��ǰʱ��(��s��ʾ)��localtime(time_t* )��time_tת��Ϊһ���ṹ�壬
	asctime(struct tm* )��struct tmת��Ϊһ���ַ�������*/
	printf("\n%s\n", s);
	time_t currentTm = time(NULL);
	puts(asctime(localtime(&currentTm)));
}

void main() {
	int sq;
	struct MGraph_Mat g;
	struct MGraph_Adj g1;
	create_Mat(&g);
	print_Mat(g);
	printf("����ķ");
	sq = prim_Mat(g, 0);
	printf(" \n%d", sq);
	printf(" \n��³˹����");
	sq = krskl_Mat(g);
	printf("%d", sq);
	create_Adj(&g1);
	print_Adj(g1);
	printf("����ķ");
	sq = prim_Adj(g1, 0);
	printf(" \n%d", sq);
	printf(" \n��³˹����\n");
	sq = krskl_Adj(g1);
	printf("%d\n", sq);
	fun("������ 202107074202");
}
