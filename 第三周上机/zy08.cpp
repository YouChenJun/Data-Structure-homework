#include<stdio.h>
#include<stack>
using namespace std;
void conversion(stack<int>z,int n,int jz,char s[])
{
	int e,i=0;
	while(n){
		z.push(n%jz);
		n=n/jz;
	}
	while(!z.empty()){
		e=z.top();
		z.pop();
		if(e<=9){
			s[i]=e+'0';
		}
		else
			s[i]='A'+e-10;
		i++;
	}
	s[i]='\0';
}
int main()
{
	char c[20];
	int n;
	stack<int>z;
	scanf("%d",&n);
	printf("�������10������:%d\n",n);
	conversion(z,n,8,c);
	printf("�˽���:%s\n",c);
	conversion(z,n,2,c);
	printf("������:%s\n",c);
	conversion(z,n,16,c);
	printf("ʮ������:%s\n",c);
}
