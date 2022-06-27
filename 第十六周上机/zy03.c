#include <stdio.h>
#include "stdlib.h"
#include <time.h>
int getDigit(int i,int d)//d��ֵΪ1,2,3...,��ʾҪ��ȡ����Ӧλ��ֵ��1��ʾ��ȡ��λ��
{
                         //2��ʾʮλ��3��ʾ��λ������
	int val;
	while (d--)
	{
		val=i%10;
		i/=10;
	}
	return val;
}
void RadixSort(int *list,int n,int digit)//�� �������㷨�ľ���ʵ��
{
	int radix=10; //����
	int i=0,j=0,d;
	int *count=(int*)malloc(radix*sizeof(int));//��Ÿ�����λ�����ݸ���
	int *bucket=(int*)malloc(n*sizeof(int)) ;
	for(d=1;d<=digit;d++)//d��ֵΪ1,2,3...�ֱ��ʾ��λʮλ��λ
	{
		for(i=0;i<radix;i++)
			count[i]=0;//�ÿ�ĳλ��0-9���ֵ�ͳ������
		for(i=0;i<=n-1;i++)//ͳ��ĳλ��0-9���ָ���

		{
			j=getDigit(list[i],d);
			count[j]++;
		}
		for(i=1;i<radix;i++) //count[i]��ʾ������λ���ұ߽�������ĩλλ��
			count [i]=count[i]+count[i-1];
		for(i=n-1;i>=0;i--)//����
		{
			j=getDigit(list[i],d);
			bucket[count[j]-1]=list[i];
			count[j]--;
		}
		for(i=0,j=0;i<=n-1;i++,j++)//�ռ�
			list[i]=bucket[j];
	}
	free(count);
	free(bucket) ;
}


void main()
{
	int i,a[10]={278,109,63,930,589,184,565,269,8,83};
	RadixSort(a,10,3);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);

	printf("\n");

}
