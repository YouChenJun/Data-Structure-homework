#include<stdio.h>
int search(int a[], int y, int x); 
int main(void)
{
    int  x, n; 
    int a[11]={15,13,19,21,37,56,64,75,80,88,92};

    printf("������Ҫ���ҵ�����");
    scanf("%d", &x); 
    n = search(a, 10, x); 
    if(n < 0) 
        {
            printf("û�ҵ���Ҫ�ҵ�����\n");
        }
    else
        {
            printf("��Ҫ�ҵ���%d�������е�%d��Ԫ�ء�\n", x, n);
        }
}

int search(int a[], int y, int x) 
{
    int i, f = -1;
    for(i = 0; i < 10; i++)
        {
            if(x == a[i])
                {
                    f = i + 1;
                    break;
                }
        }
    return(f);
}
