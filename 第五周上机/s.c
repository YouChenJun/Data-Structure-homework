//time:2022��03��30�� 17:06:00
#include<stdio.h>
#include<math.h>
#define pi 3.141
int main()
{
	float r,h,c,s1,s2,v1,v2;//cΪ�ܳ� s1Բ��� s2������ v1����� s2�����
	printf("������뾶�͸�//�ո�ָ�\n");
	scanf("%f %f",&r,&h);
	c=2*pi*r;
	s1=pi*pow(r,2);
	s2=4*pi*pow(r,2);
	v1=4.0/3.0*pi*pow(r,3);
	v2=s1*h;
	printf("�ܳ�:%.2f\nԲ���:%.2f\n���:%.2f\n�����:%.2f\n�����:%.2f\n",c,s1,s2,v1,v2);
}
