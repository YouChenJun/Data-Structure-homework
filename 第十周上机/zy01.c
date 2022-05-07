#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VEXNUM 8
#define INF 9999 //无穷大

struct Graph {
	int vexnum, arcnum, kind; //顶点数，边数，图类型：1234-无向图，有向图，无向网，有向网
	char vexs[VEXNUM + 1];    //顶点字符数组
	int arcs[30];             //边起止点下标及权 值数组
} graph = {8, 10, 1, "ABCDEFGH", {0, 1, 0, 0, 2, 0, 0, 5, 0, 1, 3, 0, 2, 6, 0, 5, 6, 0, 5, 7, 0, 6, 7, 0, 3, 4, 0, 3, 6}};
// 6个顶点，10条边，无向网，顶点依次为ABCDEF，A-B:6/A-C:1/A-D:5/B-C:5/B-E:3/C-E:6/C-F:4/C-D:5/D-F:2/E-F:6
struct MGraph_Mat { //图的邻接矩阵存储数据定义
	int vexnum, arcnum;       //顶点数，边数
	char vexs[VEXNUM];        //顶点数组
	int arcs[VEXNUM][VEXNUM]; //邻接矩阵
	int kind;                 //图的类型
};

void create_Mat(struct MGraph_Mat *g) { //创建图的邻接矩阵
	int i, j;
	g->vexnum = graph.vexnum; //顶点数
	g->arcnum = graph.arcnum; //边数
	g->kind = graph.kind;     //图的类型：1234-无向图，有向图，无向网，有向网
	for (i = 0; i <= g->vexnum - 1; i++)
		g->vexs[i] = graph.vexs[i]; //逐个赋值顶点字符
	for (i = 1; i <= g->vexnum; i++) {
		for (j = 1; j <= g->vexnum; j++) {
			if (g->kind == 1 || g->kind == 2) //如果是无向图的或有向图
				g->arcs[i - 1][j - 1] = 0;    //邻接矩阵全部初始值为0
			else
				g->arcs[i - 1][j - 1] = INF; //邻接矩阵全部初始值为无穷
		}
	}
	//{0，1，6，0，2，1，0，3，5，1，2，5，1，4，3，2，4，6，2，5，4，2，3，5，3，5，2，4，5，6}
	for (i = 0; i <= g->arcnum - 1; i++) { //逐个边处理，赋权值或1
		if (g->kind == 1) { //如果是无向图，一条边处理矩阵两个元素，放1
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = 1;
			g->arcs[graph.arcs[i * 3 + 1]][graph.arcs[i * 3]] = i; //对称点
		} else if (g->kind == 2) { //如果是有向图，一条边处理矩阵一个元素，放1
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = 1;
		} else if (g->kind == 3) { //如果是无向网，一条边处理矩阵两个元素，放权值
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = graph.arcs[i * 3 + 2];
			g->arcs[graph.arcs[i * 3 + 1]][graph.arcs[i * 3]] = graph.arcs[i * 3 + 2];
		} else if (g->kind == 4) { //如果是有向网，一条边处理矩阵一个元素，放权值
			g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = graph.arcs[i * 3 + 2];
		}
	}
}

void print_Mat(struct MGraph_Mat g) { //显示邻接矩阵
	int i, j;
	printf("  ");
	for (i = 0; i <= g.vexnum - 1; i++)
		printf("%2c", g.vexs[i]); //显示第一行，各节点字符
	printf("\n");

	for (i = 0; i <= g.vexnum - 1; i++) { //各行
		printf(" %c", g.vexs[i]);      //先显示字符
		for (j = 0; j <= g.vexnum - 1; j++) { //各列
			if (g.kind == 1 || g.kind == 2)  //如果是图
				printf(" %d", g.arcs[i][j]); //显示1，0
			else {                           //如果是网
				if (g.arcs[i][j] == INF)
					printf(" ∞"); //显示无穷
				else
					printf(" %d", g.arcs[i][j]); //或权值
			}
		}
		printf("\n");
	}
}

struct arcnode { //邻接表-边界点
	int adjvex, weight;      //邻接边下标，权值
	struct arcnode *nextarc; //下一边表指针
};

struct vexnode { //顶点结点
	char vexdata;             //顶点字符数据
	struct arcnode *firstarc; //第一个边表指针
};

struct MGraph_Adj { //图的邻接表储存数据定义
	int vexnum, arcnum;            //顶点数，边数
	struct vexnode vexarr[VEXNUM]; //定点节点数组
	int kind;                      //图类型
};

void create_Adj(struct MGraph_Adj *g) { //根据全局通用图形定义graph，创建图的邻接表
	int i;
	struct arcnode *p = NULL;
	g->vexnum = graph.vexnum; //顶点数
	g->arcnum = graph.arcnum; //边数
	g->kind = graph.kind;     //图的类型：1234-无向图，有向图，无向网，有向网
	for (i = 0; i <= g->vexnum - 1; i++) {
		g->vexarr[i].vexdata = graph.vexs[i]; //逐一顶点赋值-顶点字符
		g->vexarr[i].firstarc = NULL;         //第一条边初始值置空
	}

	for (i = 0; i <= g->arcnum - 1; i++) { //逐条边创建边表结点
		p = (struct arcnode *)(malloc(sizeof(struct arcnode))); //申请边表空间
		p->adjvex = graph.arcs[i * 3 + 1];                      //边界点-边下标
		p->weight = graph.arcs[i * 3 + 2];                      //边结点-权值

		p->nextarc = g->vexarr[graph.arcs[i * 3]].firstarc;
		g->vexarr[graph.arcs[i * 3]].firstarc = p; //将p结点插入在指定顶点之后-前插
		if (g->kind == 1 || g->kind == 3) {        //若果是无向图或无向网，需再创建一个结点
			p = (struct arcnode *)(malloc(sizeof(struct arcnode)));
			p->adjvex = graph.arcs[i * 3];     //边结点-边下标
			p->weight = graph.arcs[i * 3 + 2]; //边结点-权值

			p->nextarc = g->vexarr[graph.arcs[i * 3 + 1]].firstarc;
			g->vexarr[graph.arcs[i * 3 + 1]].firstarc = p; //将p结点插入在指定顶点之后
		}
	}
}

void print_Adj(struct MGraph_Adj g) { //显示邻接表
	int i;
	struct arcnode *p = NULL;
	printf("\n\n");
	for (i = 0; i <= g.vexnum - 1; i++) { //处理各节点
		printf(" %d %c ", i, g.vexarr[i].vexdata); //下标，顶点字符
		p = g.vexarr[i].firstarc;                 // p指向第一个边表结点
		while (p) {                               //逐个边表显示
			if (g.kind == 1 || g.kind == 2) //如果是图只显示边序号
				printf("->%d", p->adjvex);
			else //如果是网，要同时显示边序号，权值
				printf("->%d|%d", p->adjvex, p->weight);
			p = p->nextarc; //下一边表
		}
		printf("\n");
	}
}

int visited[VEXNUM];//是否访问过数组，用法语图的深度广度优先搜索
void DFS_Mat(struct MGraph_Mat g, int v) { //深度优先搜索-邻接矩阵存储
	int i;
	printf("%c ", g.vexs[v]); //访问结点v
	visited[v] = 1; //记录v点已经访问过
	for (i = 0; i <= g.vexnum - 1; i++) {
		if (g.arcs[v][i] != 0 && g.arcs[v][i] != INF && visited[i] == 0) {
			//取出矩阵v行各列，未被访问过的，而且有边的
			DFS_Mat(g, i); //递归调用
		}
	}
}


void DFSTraveres_Mat(struct MGraph_Mat g, int v) { //升读优先搜索-邻接矩阵存储
	int i;
	for (i = 0; i <= g.vexnum - 1; i++) {
		visited[i] = 0; //初始是否访问过标志，辅助数组
	}
	printf("\n邻接矩阵深度优先搜索序列");
	for (i = v; i <= g.vexnum - 1; i++) {
		if (visited[i % g.vexnum] == 0) {
			DFS_Mat(g, i); //非连通时dfs_mat可能调用几次，连通递归调用一次
		}
	}
}


void BFS_Mat(struct MGraph_Mat g, int v) { //广度优先搜索-邻接矩阵存储
	int Lq[VEXNUM];//队列
	int i, j, f = 0, r = 0;
	printf("%c ", g.vexs[v]); //访问结点v
	visited[v] = 1; //记录v点已经访问过了
	Lq[r] = v;	//v点进队列
	r++;
	while (r != f) { //队列不空
		i = Lq[f]; //出队元素i
		f++;
		for (j = 0; j <= g.vexnum - 1; j++) { //访问与出队i相邻的违背访问过的结点
			if (g.arcs[i][j] != 0 && g.arcs[i][j] != INF && visited[j] == 0) { //
				printf("%c ", g.vexs[j]); //依次显示
				visited[j] = 1; //标记已访问
				Lq[r] = j; //进
				r++;
			}
		}
	}
}

void BFSTraverse_Mat(struct MGraph_Mat g, int v) {
	int i, j;
	for (i = 0; i <= g.vexnum - 1; i++) {
		visited[i] = 0; //初始是否访问过标志辅助数组
	}
	printf("\n邻接矩阵广度优先搜索序列");
	for (i = v; i < g.vexnum + v; i++) { //从顶点v开始
		if (visited[i % g.vexnum] == 0) { //取模是为了到最大，从头开始
			BFS_Mat(g, i % g.vexnum);
		}
	}
}
void DFS_Adj(struct MGraph_Adj g, int v) { //深度优先搜索—邻接矩阵存储
	struct arcnode *p = NULL;
	printf("%c ", g.vexarr[v].vexdata); //访问结点v
	visited[v] = 1;

	p = g.vexarr[v].firstarc; //第一条边
	while (p) { //若右边或边表为结束
		if (visited[p->adjvex] == 0) { //p->dajvex;点v的邻接表
			DFS_Adj(g, p->adjvex); //进入新的点
		}
		p = p->nextarc;
	}
}

//void DFSTraverse_Adj(struct MGraph_Adj g,int v)//深度优先搜索-邻接表存储
//{
//	int i;
//	for(i=0;i<=g.vexnum-1;i++){
//		visited[i]=0;
//	}
//	printf("\n邻接表深度优先搜索序列");
//	for(i=v;i<=g.vexnum+v-1;i++){//从v顶点开始
//		if(visited[i%g.vexnum]!=1){//取模为了到最大，从头开始
//			DFS_Adj(g,i%g.vexnum);//非连通时dfs_max可能调用几次，连用递归调用一次
//		}
//	}
//}
void DFSTraverse_Adj(struct MGraph_Adj g, int v) {
	int i;
	for (i = 0; i <= g.vexnum - 1; i++) {
		visited[i] = 0;
	}
	printf("\n邻接表的深度优先搜索序列：");
	for (i = v; i <= g.vexnum + v - 1; i++) {
		if (visited[i % g.vexnum] != 1) {
			DFS_Adj(g, i % g.vexnum);
		}
	}
}


void BFS_Adj(struct MGraph_Adj g, int v) {
	int Lq[VEXNUM];
	int i, f = 0, r = 0;
	struct arcnode *p = NULL;
	printf("%c ", g.vexarr[v].vexdata);
	visited[v] = 1;
	Lq[r] = v;
	r++;
	while (r != f) {
		i = Lq[f];
		f++;
		p = g.vexarr[i].firstarc;
		while (p) {
			if (visited[p->adjvex] == 0) {
				printf("%c ", g.vexarr[p->adjvex].vexdata);
				visited[p->adjvex] = 1;
				Lq[r] = p->adjvex;
				r++;
			}
			p = p->nextarc;
		}
	}
}
void BFSTraverse_Adj(struct MGraph_Adj g, int v) { //广度优先——邻接表存储
	int i;
	for (i = 0; i <= g.vexnum - 1; i++) {
		visited[i] = 0;
	}
	printf("\n邻接表广度优先搜索序列：");
	for (i = v; i < g.vexnum + v; i++) {
		if (visited[i % g.vexnum] == 0) {
			BFS_Adj(g, i % g.vexnum);
		}
	}
}
void fun(char s[]) {
	/*time(NULL)获取当前时间(以s表示)，localtime(time_t* )将time_t转化为一个结构体，
	asctime(struct tm* )将struct tm转化为一个字符串返回*/
	printf("\n%s\n", s);
	time_t currentTm = time(NULL);
	puts(asctime(localtime(&currentTm)));


}
void main() {
	struct MGraph_Mat g;
	struct MGraph_Adj g1;
	create_Mat(&g);
	print_Mat(g);
	create_Adj(&g1);
	print_Adj(g1);
	printf("\n邻接矩阵的深度优先搜索序列：");
	DFS_Mat(g, 3);//从d开始？那么我们改吧ww
	BFSTraverse_Mat(g, 3);
	//DFSTraverse_Adj(g1,4);
	//BFSTraverse_Adj(g1,4);
	fun("黄钰翔 202107074202");
	printf("\n");

}
