#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VEXNUM 6
#define INF 9999 //�����

struct Graph
{
    int vexnum, arcnum, kind; //��������������ͼ���ͣ�1234-����ͼ������ͼ����������������
    char vexs[VEXNUM + 1];    //�����ַ�����
    int arcs[30];             //����ֹ���±꼰Ȩ ֵ����
} graph = {6, 10, 4, "abcdef", {0, 1, 2, 0, 2, 5, 1, 2, 1, 1, 3, 3, 2, 3, 3, 2, 4, 4, 2, 5, 1, 3, 4, 1, 3, 5, 4, 4, 5, 1}};
// 6�����㣬10���ߣ�����������������ΪABCDEF��A-B:6/A-C:1/A-D:5/B-C:5/B-E:3/C-E:6/C-F:4/C-D:5/D-F:2/E-F:6
struct MGraph_Mat //ͼ���ڽӾ���洢���ݶ���
{
    int vexnum, arcnum;       //������������
    char vexs[VEXNUM];        //��������
    int arcs[VEXNUM][VEXNUM]; //�ڽӾ���
    int kind;                 //ͼ������
};

void create_Mat(struct MGraph_Mat *g) //����ͼ���ڽӾ���
{
    int i, j;
    g->vexnum = graph.vexnum; //������
    g->arcnum = graph.arcnum; //����
    g->kind = graph.kind;     //ͼ�����ͣ�1234-����ͼ������ͼ����������������
    for (i = 0; i <= g->vexnum - 1; i++)
        g->vexs[i] = graph.vexs[i]; //�����ֵ�����ַ�
    for (i = 1; i <= g->vexnum; i++)
    {
        for (j = 1; j <= g->vexnum; j++)
        {
            if (g->kind == 1 || g->kind == 2) //���������ͼ�Ļ�����ͼ
                g->arcs[i - 1][j - 1] = 0;    //�ڽӾ���ȫ����ʼֵΪ0
            else
                g->arcs[i - 1][j - 1] = INF; //�ڽӾ���ȫ����ʼֵΪ����
        }
    }
    //{0��1��6��0��2��1��0��3��5��1��2��5��1��4��3��2��4��6��2��5��4��2��3��5��3��5��2��4��5��6}
    for (i = 0; i <= g->arcnum - 1; i++) //����ߴ�����Ȩֵ��1
    {
        if (g->kind == 1) //���������ͼ��һ���ߴ����������Ԫ�أ���1
        {
            g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = 1;
            g->arcs[graph.arcs[i * 3 + 1]][graph.arcs[i * 3]] = i; //�ԳƵ�
        }
        else if (g->kind == 2) //���������ͼ��һ���ߴ������һ��Ԫ�أ���1
        {
            g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = 1;
        }
        else if (g->kind == 3) //�������������һ���ߴ����������Ԫ�أ���Ȩֵ
        {
            g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = graph.arcs[i * 3 + 2];
            g->arcs[graph.arcs[i * 3 + 1]][graph.arcs[i * 3]] = graph.arcs[i * 3 + 2];
        }
        else if (g->kind == 4) //�������������һ���ߴ������һ��Ԫ�أ���Ȩֵ
        {
            g->arcs[graph.arcs[i * 3]][graph.arcs[i * 3 + 1]] = graph.arcs[i * 3 + 2];
        }
    }
}

void print_Mat(struct MGraph_Mat g) //��ʾ�ڽӾ���
{
    int i, j;
    printf("  ");
    for (i = 0; i <= g.vexnum - 1; i++)
        printf("%2c", g.vexs[i]); //��ʾ��һ�У����ڵ��ַ�
    printf("\n");

    for (i = 0; i <= g.vexnum - 1; i++) //����
    {
        printf(" %c", g.vexs[i]);      //����ʾ�ַ�
        for (j = 0; j <= g.vexnum - 1; j++) //����
        {
            if (g.kind == 1 || g.kind == 2)  //�����ͼ
                printf("%d", g.arcs[i][j]); //��ʾ1��0
            else                             //�������
            {
                if (g.arcs[i][j] == INF)
                    printf(" ��"); //��ʾ����
                else
                    printf(" %d", g.arcs[i][j]); //��Ȩֵ
            }
        }
        printf("\n");
    }
}

struct arcnode //�ڽӱ�-�߽��
{
    int adjvex, weight;      //�ڽӱ��±꣬Ȩֵ
    struct arcnode *nextarc; //��һ�߱�ָ��
};

struct vexnode //������
{
    char vexdata;             //�����ַ�����
    struct arcnode *firstarc; //��һ���߱�ָ��
};

struct MGraph_Adj //ͼ���ڽӱ������ݶ���
{
    int vexnum, arcnum;            //������������
    struct vexnode vexarr[VEXNUM]; //����ڵ�����
    int kind;                      //ͼ����
};

void create_Adj(struct MGraph_Adj *g) //����ȫ��ͨ��ͼ�ζ���graph������ͼ���ڽӱ�
{
    int i;
    struct arcnode *p = NULL;
    g->vexnum = graph.vexnum; //������
    g->arcnum = graph.arcnum; //����
    g->kind = graph.kind;     //ͼ�����ͣ�1234-����ͼ������ͼ����������������
    for (i = 0; i <= g->vexnum - 1; i++)
    {
        g->vexarr[i].vexdata = graph.vexs[i]; //��һ���㸳ֵ-�����ַ�
        g->vexarr[i].firstarc = NULL;         //��һ���߳�ʼֵ�ÿ�
    }

    for (i = 0; i <= g->arcnum - 1; i++) //�����ߴ����߱���
    {
        p = (struct arcnode *)(malloc(sizeof(struct arcnode))); //����߱�ռ�
        p->adjvex = graph.arcs[i * 3 + 1];                      //�߽��-���±�
        p->weight = graph.arcs[i * 3 + 2];                      //�߽��-Ȩֵ

        p->nextarc = g->vexarr[graph.arcs[i * 3]].firstarc;
        g->vexarr[graph.arcs[i * 3]].firstarc = p; //��p��������ָ������֮��-ǰ��
        if (g->kind == 1 || g->kind == 3)          //����������ͼ�������������ٴ���һ�����
        {
            p = (struct arcnode *)(malloc(sizeof(struct arcnode)));
            p->adjvex = graph.arcs[i * 3];     //�߽��-���±�
            p->weight = graph.arcs[i * 3 + 2]; //�߽��-Ȩֵ

            p->nextarc = g->vexarr[graph.arcs[i * 3 + 1]].firstarc;
            g->vexarr[graph.arcs[i * 3 + 1]].firstarc = p; //��p��������ָ������֮��
        }
    }
}

void print_Adj(struct MGraph_Adj g) //��ʾ�ڽӱ�
{
    int i;
    struct arcnode *p = NULL;
    printf("\n\n");
    for (i = 0; i <= g.vexnum - 1; i++) //������ڵ�
    {
        printf(" %d %c ", i, g.vexarr[i].vexdata); //�±꣬�����ַ�
        p = g.vexarr[i].firstarc;                 // pָ���һ���߱���
        while (p)                                 //����߱���ʾ
        {
            if (g.kind == 1 || g.kind == 2) //�����ͼֻ��ʾ�����
                printf("->%d", p->adjvex);
            else //���������Ҫͬʱ��ʾ����ţ�Ȩֵ
                printf("->%d|%d", p->adjvex, p->weight);
            p = p->nextarc; //��һ�߱�
        }
        printf("\n");
    }
}


void main()
{
    struct MGraph_Mat g;
    struct MGraph_Adj g1;
    create_Mat(&g);
    print_Mat(g);

    create_Adj(&g1);
    print_Adj(g1);
    printf("\n");

}
