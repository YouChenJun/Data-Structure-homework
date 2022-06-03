#include "stdio.h"
#include "stdlib.h"
#include <time.h>
int fun_hx(int x)//哈希函数
{
	return x%13;
}
int gy(int fm,int fz)//求成功比较次数分子分母的最大公约数
{
	int i;
    for(i=fm;i>=1;i--)
		if(fz%i==0&&fm%i==0)
			return i;
		return 1;
}
void fun_gzhxb_xxtc(int a[],int n,int b[],int len)//构造哈希表-线性探测
{
	int i,dz;
	for(i=0;i<=n-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==0)//如果计算位置空，直接填入数
		{
			printf("%d%%%d=%d\n",a[i],13,dz);
			b[dz]=a[i];
		}
		else//如果计算位置有值-冲突
		{
			int d=1;//地址增量
			printf("%d%%%d=%d--冲突\n",a[i],13,dz);//显示计算冲突
			while (b[(dz+d)%len]!=0)//计算下一地址，若还有值-冲突
			{
				printf("  (%d+%d)%%%d=%d--再冲突\n",dz,d,len,(dz+d)%len);//显示冲突
				d++;//为下一次计算做准备，循环计算下一地址
			}
			printf("  (%d+%d)%%%d=%d\n",dz,d,len,(dz+d)%len);//循环结束-找到了空位置，显示填入成功
			b[(dz+d)%len]=a[i];//填入数值
		}
	}
}
void print_hxb(int b[],int n)//显示构造的哈希表
{
	int i;
	printf("\n哈希表\n     下标:");
	for(i=0;i<=n-1;i++)
		printf("%-3d",i);
	printf("\n    数值:");
	for(i=0;i<=n-1;i++)
	{
		if(b[i])
			printf("%-3d",b[i]);
		else
			printf("   ");
	}
	printf("\n");
}
void cz_hxb_xxtc(int b[],int len,int a[],int m)//计算并显示
{
	int fz=0,i,dz,cs[15]={0};//cs为比较次数数组
	for(i=0;i<=m-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==a[i])
		{
			cs[dz]=1;
			fz++;//比较次数分子+1
		}
		else//冲突
		{
			int d=1,t=2;//d为地址增量，t为比较次数
			while(b[(dz+d)%len]!=a[i])
			{
				d++;
				t++;
			}
			cs[(dz+d)%len]=t;
			fz+=t;//比较次数分子+t
		}
	}
	printf("比较次数:");
	for(i=0;i<=len-1;i++)
	{
		if(cs[i])
			printf("%-3d",cs[i]);
		else
			printf("   ");
	}
	printf("\n");
	if(fz%m==0)//如果比较次数fz是fm的整数倍，直接显示整数
		printf("\n平均比较次数: %d\n",fz/m);
	else//如果不是整数,约分成最简分式
	{
		int gys=gy(m,fz);
		printf("\n平均比较次数: %d/%d\n\n",(fz/gys),(m/gys));
	}
}
void fun_gzhxb_ectc(int a[],int n,int b[],int len)//构造哈希表-二次探测
{
	int i,dz;
	for(i=0;i<=n-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==0)//如果计算位置空，直接填入数
		{
			printf("%d%%%d=%d\n",a[i],13,dz);
			b[dz]=a[i];
		}
		else//如果计算位置有值-冲突
		{
			int d=1;//地址增量
			printf("%d%%d=%d--冲突\n",a[i],13,dz);//显示计算冲突
			while((b[(dz+d*d)%len]!=0)&&(b[(dz-d*d+(d*d/len+1)*len)%len]!=0))//计算下一地址，若还有值-冲突
			{
				printf("  (%d+%d)%%%d=%d--再冲突\n",dz,d*d,len,(dz+d*d)%len);//显示冲突
				printf("  (%d-%d)%%%d=%d--再冲突\n",dz,d*d,len,(dz-d*d+(d*d/len+1)*len)%len);//显示冲突
				d++;//为下一次计算做准备，循环计算下一地址
			}
			if (b[(dz+d*d)%len]==0)
			{
				printf("  (%d+%d)%%%d=%d\n",dz,d*d,len,(dz+d*d)%len);//循环结束-找到了空位置，显示填入成功
				b[(dz+d*d)%len]=a[i];//填入数值
			}
			else
			{
				printf("  (%d+%d)%%%d=%d--再冲突\n",dz,d*d,len,(dz+d*d)%len);//显示冲突
				printf("  (%d-%d)%%%d=%d\n",dz,d*d,len,(dz-d*d+(d*d/len+1)*len)%len);//循环结束-找到了空位置，显示填入成功
				b[(dz-d*d+(d*d/len+1)*len)%len]=a[i];//填入数值
			}
		}
	}
}
void cz_hxb_ectc(int b[],int len,int a[],int m)//计算并显示哈希查找比较次数
{
	int fz=0,i,dz,cs[15]={0};//cs为比较次数数组
	for(i=0;i<=m-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==a[i])
		{
			cs[dz]=1;
			fz++;
		}
		else//冲突
		{
			int d=1,t=2;
			while((b[(dz+d*d)%len]!=a[i])&&(b[(dz-d*d+(d*d/len+1)*len)%len]!=a[i]))
			{
				d++;
				t+=2;
			}
			if(b[(dz+d*d)%len]==a[i])
			{
				cs[(dz+d*d)%len]=t;//次数数组填入数值
			}
			else
			{
				t+=1;
				cs[(dz-d*d+(d*d/len+1)*len)%len]=t;
			}
			fz+=t;
		}
	}
	printf("比较次数:");
	for(i=0;i<=len-1;i++)
	{
		if(cs[i])
			printf("%-3d",cs[i]);
		else
			printf("   ");
	}
	printf("\n");
	if(fz%m==0)//如果比较次数fz是fm的整数倍，直接显示整数
		printf("\n平均比较次数: %d\n",fz/m);
	else//如果不是整数,约分成最简分式
	{
		int gys=gy(m,fz);
		printf("\n平均比较次数: %d/%d\n\n",(fz/gys),(m/gys));
	}
}
struct hxnode         //邻接表-边节点
{
	int data; //邻接表、 权值
	struct hxnode *next;//下一边表指 针
};
void fun_gzhxb_1dz(int a[],int len,struct hxnode *b[],int n)//构造哈希表-链地址
{
	int i,dz;
	struct hxnode *p=NULL,*q=NULL;
	for(i=0;i<=n-1;i++)
		b[i]=NULL;
	for(i=0;i<=len-1;i++)
	{
		dz=fun_hx(a[i]);
		p=(struct hxnode *)(malloc(sizeof(struct hxnode))); //申请边表空 间
		p->data=a[i]; //边结 点-边下标
		p->next=NULL;
		if(b[dz]==NULL)//如果计算位置空，直接填入数
		{
			printf("%d%%%d=%d\n",a[i],13,dz);
			b[dz]=p;
		}
		else//如果计算位置有值-冲突
		{
			printf("%d%%%d=%d--冲突\n",a[i],13,dz);//显示计算冲突
			q=b[dz];
			while(q->next!=NULL)
				q=q->next;
			q->next=p;//将p尾插在边表中
		}
	}
}
void print_1dz(struct hxnode *b[],int n)//显示构造的哈希表
{
	int i;
	struct hxnode *p=NULL;
	printf("\n哈希表\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%2d",i);
		p=b[i];
		while(p!=NULL)
		{
			printf("->%d",p->data);
			p=p->next;
		}
		printf("\n");
	}
	printf("\n");
}
void free_1dz(struct hxnode *b[],int n)//显示构造的哈希表
{
	int i;
	struct hxnode *p=NULL;
	for(i=0;i<=n-1;i++)
	{
		p=b[i];
		while(p!=NULL)
		{
			b[i]=p->next;
			free(p);
			p=b[i];
		}
	}
}

void cz_hxb_1dz(struct hxnode *b[],int n,int a[],int len)//计算并显示哈希查找比较次数
{
	int fz=0,i,dz,*cs=(int*)malloc(sizeof(int)*len);
	struct hxnode *p=NULL;
	for(i=0;i<=len-1;i++) 
		cs[i]=0;
	for(i=0;i<=len-1;i++)
	{
		dz=fun_hx(a[i]);
		p=b[dz];
		while(p!=NULL)
		{
			cs[i]++;
			if(p->data==a[i])
				break;
			p=p->next;
		}
		fz+=cs[i];
	}
	printf("    数值:");
	for(i=0;i<=len-1;i++)
		printf("%-3d",a[i]);
	printf("\n比较次数:");
	for(i=0;i<=len-1;i++)
	{
		if(cs[i]) 
			printf("%-3d",cs[i]);
		else
			printf("   ");
	}
	printf("\n");
	if(fz%len==0)//如果比较次数fz是fm的整数倍，直接显示整数
		printf("\n平均比较次数: %d\n",fz/len);
	else//如果不是整数,约分成最简分式
	{
		int gys=gy(len,fz);
		printf("\n平均比较次数: %d/%d\n",(fz/gys),(len/gys));
	}
	free(cs);
}


void main()
{

	//
	int a1[12]={19,1,23,14,55,20,84,27,68,11,10,77};
	int b1[15]={0};//构造的哈希表1
	int a2[9]={19,1,14,55,84,27,68,18,28};
	int b2[15]={0};//构造的哈希表2
	int a3[15]={87,25,31,38,27,64,74,94,20,22,51,59,3,33,77};
	struct hxnode *b3[13];//构造的哈希 表3
	//
	fun_gzhxb_xxtc(a1,12,b1,15);//构造哈希表-线性 探测
	print_hxb(b1,15);//显示构造的哈希表
	cz_hxb_xxtc(b1,15,a1,12);//计算并 显示哈希表查找成功比较次数-线性探测
	//
	fun_gzhxb_ectc(a2,9,b2,15);//构造哈希表-二次探 测
	print_hxb(b2,15);//显示构造的哈希表
	cz_hxb_ectc(b2,15,a2,9);//计算并显示哈希表查找成功比较次数-二次探测
	//
	fun_gzhxb_1dz(a3,15,b3,13);//构造哈希表-链地址法
	print_1dz(b3,13);//显示构造的哈希表
	cz_hxb_1dz(b3,13,a3,15);//计算并显示哈希表查找成功比较次数-链地址法
	free_1dz(b3,13);

	printf("\n");
}
