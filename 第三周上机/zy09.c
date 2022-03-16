#include<stdio.h>
double fun(long n)
{
	double s=0;
	int i;
	for(i=1;i<=n;i++){
		s=s+(double)i/(i+1);
	}
	return s;
}
double fundg(long n)
{
	if(n==1){
		return 0.5;
	}
	else
		return (double)n/(n+1)+fundg(n-1);
}
void main()
{
	printf("%f\n",fun(10000));
	printf("%f\n",fundg(100000));
}
