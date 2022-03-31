//time:2022年03月30日 17:06:00
#include<stdio.h>
#include<math.h>
#define pi 3.141
int main()
{
	float r,h,c,s1,s2,v1,v2;//c为周长 s1圆面积 s2球表面积 v1球体积 s2柱体积
	printf("请输入半径和高//空格分隔\n");
	scanf("%f %f",&r,&h);
	c=2*pi*r;
	s1=pi*pow(r,2);
	s2=4*pi*pow(r,2);
	v1=4.0/3.0*pi*pow(r,3);
	v2=s1*h;
	printf("周长:%.2f\n圆面积:%.2f\n面积:%.2f\n球体积:%.2f\n柱体积:%.2f\n",c,s1,s2,v1,v2);
}
