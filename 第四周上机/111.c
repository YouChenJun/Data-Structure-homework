#include "stdio.h"
#define maxsize 100
#define MAXRC 10
typedef struct
{
    int i, j;
    int e;
} triple;
typedef struct
{
    triple data[maxsize + 1];
    int rpos[MAXRC];
    int mu, nu, tu;
} RLtsmat;
void cjsyzRL(RLtsmat *s, int a[], int h, int l)
{
    int i, j, k = 1, num[MAXRC];
    s->mu = h;
    s->nu = l;
    for (i = 0; i <= h - 1; i++)
        for (j = 0; j <= l - 1; j++)
            if (a[i * l + j] != 0)
            {
                s->data[k].i = i + 1;
                s->data[k].j = j + 1;
                s->data[k].e = a[i * l + j];
                k++;
            }
    s->tu = k - 1;
    for (i = 1; i <= s->mu; i++)
        num[i] = 0;
    for (i = 1; i <= s->tu; i++)
        num[s->data[i].i]++;
    s->rpos[1] = 1;
    for (i = 2; i <= s->mu; i++)
        s->rpos[i] = s->rpos[i - 1] + num[i - 1];
}
void psyzRL(RLtsmat s)
{
    int i;
    printf(" \nhs : %d ls: %d flgs : %d\n", s.mu, s.nu, s.tu);
    printf(" syz : \n");
    for (i = 1; i <= s.tu; i++)
        printf(" %d %d %d\n", s.data[i].i, s.data[i].j, s.data[i].e);
    printf("rpos: \n");
    for (i = 1; i <= s.mu; i++)
        printf(" %d   %d \n", i, s.rpos[i]);
}
int MultSmatrix(RLtsmat M, RLtsmat N, RLtsmat *Q)
{
    int ctemp[MAXRC], arow, tp, p, q, ccol, t, brow, i;
    if (M.nu != N.mu)
        return 0;
    if (M.tu * N.tu == 0)
        return 0;
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    for (arow = 1; arow <= M.mu; arow++)
    {
        for (i = 1; i <= M.nu; i++)
            ctemp[i] = 0;
        Q->rpos[arow] = Q->tu + 1;
        if (arow < M.mu)
            tp = M.rpos[arow + 1];
        else
            tp = M.tu + 1;
        for (p = M.rpos[arow]; p < tp; p++)
        {
            brow = M.data[p].j;
            if (brow < N.mu)
                t = N.rpos[brow + 1];
            else
                t = N.tu + 1;
            for (q = N.rpos[brow]; q < t; q++)
            {
                ccol = N.data[q].j;
                ctemp[ccol] += M.data[p].e * N.data[q].e;
            }
        }
        for (ccol = 1; ccol <= Q->nu; ccol++)//Ñ¹Ëõ
        {
            if (ctemp[ccol] != 0)
            {
                if (++Q->tu > maxsize)
                    return 0;
                Q->data[Q->tu].i = arow;
                Q->data[Q->tu].j = ccol;
                Q->data[Q->tu].e = ctemp[ccol];
            }
        }
    }
    return 1;
}
int main()
{
    int s1[12] = {3, 0, 0, 5, 0, -1, 0, 0, 2, 0, 0, 0}, s2[8] = {0, 2, 1, 0, -2, 4, 0, 0};
    RLtsmat c, d, e;
    cjsyzRL(&c, s1, 3, 4);
    cjsyzRL(&d, s2, 4, 2);
    MultSmatrix(c, d, &e);
    psyzRL(c);
    psyzRL(d);
    psyzRL(e);
}
