#include<stdio.h>
#define M 10
#define N 10
int start1=1,start2=1;
int end1=8,end2=8;
int success=0;
int maza[M][N]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,1,1,0,1},
	{1,0,1,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,1,1,1},
	{1,0,1,0,1,0,0,0,0,1},
	{1,0,0,0,1,0,1,1,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int visit(int i,int j)
{
	maza[i][j]=2;
	if(i==end1&&j==end2){
		success=1;
	}
	if(success!=1&&maza[i][j+1]==0){
		visit(i,j+1);//右
	}
	if(success!=1&&maza[i+1][j]==0){
		visit(i+1,j);//下
	}
	if(success!=1&&maza[i][j-1]==0){
		visit(i,j-1);//左
	}
	if(success!=1&&maza[i-1][j]==0){
		visit(i-1,j);//上
	}
	if(success!=1)
		maza[i][j]=0;
	return success;
		
}
int print(int i,int j)
{
	if(maza[i][j]==2){
		printf("(%d,%d)\n",i,j);
		maza[i][j]=3;
		if(i==end1&&j==end2){
			return ;
		}
		print(i,j+1);
		print(i+1,j);
	}
}
int main()
{
	if(visit(start1,start2)==0){
		printf("\n没有找到出口！\n");
	}
	else
	{
		print(start1,start2);
	}
}
