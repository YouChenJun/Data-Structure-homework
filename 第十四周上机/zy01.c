#include "stdio.h"
#include "stdlib.h"
#include <time.h>
int fun_hx(int x)//��ϣ����
{
	return x%13;
}
int gy(int fm,int fz)//��ɹ��Ƚϴ������ӷ�ĸ�����Լ��
{
	int i;
    for(i=fm;i>=1;i--)
		if(fz%i==0&&fm%i==0)
			return i;
		return 1;
}
void fun_gzhxb_xxtc(int a[],int n,int b[],int len)//�����ϣ��-����̽��
{
	int i,dz;
	for(i=0;i<=n-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==0)//�������λ�ÿգ�ֱ��������
		{
			printf("%d%%%d=%d\n",a[i],13,dz);
			b[dz]=a[i];
		}
		else//�������λ����ֵ-��ͻ
		{
			int d=1;//��ַ����
			printf("%d%%%d=%d--��ͻ\n",a[i],13,dz);//��ʾ�����ͻ
			while (b[(dz+d)%len]!=0)//������һ��ַ��������ֵ-��ͻ
			{
				printf("  (%d+%d)%%%d=%d--�ٳ�ͻ\n",dz,d,len,(dz+d)%len);//��ʾ��ͻ
				d++;//Ϊ��һ�μ�����׼����ѭ��������һ��ַ
			}
			printf("  (%d+%d)%%%d=%d\n",dz,d,len,(dz+d)%len);//ѭ������-�ҵ��˿�λ�ã���ʾ����ɹ�
			b[(dz+d)%len]=a[i];//������ֵ
		}
	}
}
void print_hxb(int b[],int n)//��ʾ����Ĺ�ϣ��
{
	int i;
	printf("\n��ϣ��\n     �±�:");
	for(i=0;i<=n-1;i++)
		printf("%-3d",i);
	printf("\n    ��ֵ:");
	for(i=0;i<=n-1;i++)
	{
		if(b[i])
			printf("%-3d",b[i]);
		else
			printf("   ");
	}
	printf("\n");
}
void cz_hxb_xxtc(int b[],int len,int a[],int m)//���㲢��ʾ
{
	int fz=0,i,dz,cs[15]={0};//csΪ�Ƚϴ�������
	for(i=0;i<=m-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==a[i])
		{
			cs[dz]=1;
			fz++;//�Ƚϴ�������+1
		}
		else//��ͻ
		{
			int d=1,t=2;//dΪ��ַ������tΪ�Ƚϴ���
			while(b[(dz+d)%len]!=a[i])
			{
				d++;
				t++;
			}
			cs[(dz+d)%len]=t;
			fz+=t;//�Ƚϴ�������+t
		}
	}
	printf("�Ƚϴ���:");
	for(i=0;i<=len-1;i++)
	{
		if(cs[i])
			printf("%-3d",cs[i]);
		else
			printf("   ");
	}
	printf("\n");
	if(fz%m==0)//����Ƚϴ���fz��fm����������ֱ����ʾ����
		printf("\nƽ���Ƚϴ���: %d\n",fz/m);
	else//�����������,Լ�ֳ�����ʽ
	{
		int gys=gy(m,fz);
		printf("\nƽ���Ƚϴ���: %d/%d\n\n",(fz/gys),(m/gys));
	}
}
void fun_gzhxb_ectc(int a[],int n,int b[],int len)//�����ϣ��-����̽��
{
	int i,dz;
	for(i=0;i<=n-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==0)//�������λ�ÿգ�ֱ��������
		{
			printf("%d%%%d=%d\n",a[i],13,dz);
			b[dz]=a[i];
		}
		else//�������λ����ֵ-��ͻ
		{
			int d=1;//��ַ����
			printf("%d%%d=%d--��ͻ\n",a[i],13,dz);//��ʾ�����ͻ
			while((b[(dz+d*d)%len]!=0)&&(b[(dz-d*d+(d*d/len+1)*len)%len]!=0))//������һ��ַ��������ֵ-��ͻ
			{
				printf("  (%d+%d)%%%d=%d--�ٳ�ͻ\n",dz,d*d,len,(dz+d*d)%len);//��ʾ��ͻ
				printf("  (%d-%d)%%%d=%d--�ٳ�ͻ\n",dz,d*d,len,(dz-d*d+(d*d/len+1)*len)%len);//��ʾ��ͻ
				d++;//Ϊ��һ�μ�����׼����ѭ��������һ��ַ
			}
			if (b[(dz+d*d)%len]==0)
			{
				printf("  (%d+%d)%%%d=%d\n",dz,d*d,len,(dz+d*d)%len);//ѭ������-�ҵ��˿�λ�ã���ʾ����ɹ�
				b[(dz+d*d)%len]=a[i];//������ֵ
			}
			else
			{
				printf("  (%d+%d)%%%d=%d--�ٳ�ͻ\n",dz,d*d,len,(dz+d*d)%len);//��ʾ��ͻ
				printf("  (%d-%d)%%%d=%d\n",dz,d*d,len,(dz-d*d+(d*d/len+1)*len)%len);//ѭ������-�ҵ��˿�λ�ã���ʾ����ɹ�
				b[(dz-d*d+(d*d/len+1)*len)%len]=a[i];//������ֵ
			}
		}
	}
}
void cz_hxb_ectc(int b[],int len,int a[],int m)//���㲢��ʾ��ϣ���ұȽϴ���
{
	int fz=0,i,dz,cs[15]={0};//csΪ�Ƚϴ�������
	for(i=0;i<=m-1;i++)
	{
		dz=fun_hx(a[i]);
		if(b[dz]==a[i])
		{
			cs[dz]=1;
			fz++;
		}
		else//��ͻ
		{
			int d=1,t=2;
			while((b[(dz+d*d)%len]!=a[i])&&(b[(dz-d*d+(d*d/len+1)*len)%len]!=a[i]))
			{
				d++;
				t+=2;
			}
			if(b[(dz+d*d)%len]==a[i])
			{
				cs[(dz+d*d)%len]=t;//��������������ֵ
			}
			else
			{
				t+=1;
				cs[(dz-d*d+(d*d/len+1)*len)%len]=t;
			}
			fz+=t;
		}
	}
	printf("�Ƚϴ���:");
	for(i=0;i<=len-1;i++)
	{
		if(cs[i])
			printf("%-3d",cs[i]);
		else
			printf("   ");
	}
	printf("\n");
	if(fz%m==0)//����Ƚϴ���fz��fm����������ֱ����ʾ����
		printf("\nƽ���Ƚϴ���: %d\n",fz/m);
	else//�����������,Լ�ֳ�����ʽ
	{
		int gys=gy(m,fz);
		printf("\nƽ���Ƚϴ���: %d/%d\n\n",(fz/gys),(m/gys));
	}
}
struct hxnode         //�ڽӱ�-�߽ڵ�
{
	int data; //�ڽӱ� Ȩֵ
	struct hxnode *next;//��һ�߱�ָ ��
};
void fun_gzhxb_1dz(int a[],int len,struct hxnode *b[],int n)//�����ϣ��-����ַ
{
	int i,dz;
	struct hxnode *p=NULL,*q=NULL;
	for(i=0;i<=n-1;i++)
		b[i]=NULL;
	for(i=0;i<=len-1;i++)
	{
		dz=fun_hx(a[i]);
		p=(struct hxnode *)(malloc(sizeof(struct hxnode))); //����߱�� ��
		p->data=a[i]; //�߽� ��-���±�
		p->next=NULL;
		if(b[dz]==NULL)//�������λ�ÿգ�ֱ��������
		{
			printf("%d%%%d=%d\n",a[i],13,dz);
			b[dz]=p;
		}
		else//�������λ����ֵ-��ͻ
		{
			printf("%d%%%d=%d--��ͻ\n",a[i],13,dz);//��ʾ�����ͻ
			q=b[dz];
			while(q->next!=NULL)
				q=q->next;
			q->next=p;//��pβ���ڱ߱���
		}
	}
}
void print_1dz(struct hxnode *b[],int n)//��ʾ����Ĺ�ϣ��
{
	int i;
	struct hxnode *p=NULL;
	printf("\n��ϣ��\n");
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
void free_1dz(struct hxnode *b[],int n)//��ʾ����Ĺ�ϣ��
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

void cz_hxb_1dz(struct hxnode *b[],int n,int a[],int len)//���㲢��ʾ��ϣ���ұȽϴ���
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
	printf("    ��ֵ:");
	for(i=0;i<=len-1;i++)
		printf("%-3d",a[i]);
	printf("\n�Ƚϴ���:");
	for(i=0;i<=len-1;i++)
	{
		if(cs[i]) 
			printf("%-3d",cs[i]);
		else
			printf("   ");
	}
	printf("\n");
	if(fz%len==0)//����Ƚϴ���fz��fm����������ֱ����ʾ����
		printf("\nƽ���Ƚϴ���: %d\n",fz/len);
	else//�����������,Լ�ֳ�����ʽ
	{
		int gys=gy(len,fz);
		printf("\nƽ���Ƚϴ���: %d/%d\n",(fz/gys),(len/gys));
	}
	free(cs);
}


void main()
{

	//
	int a1[12]={19,1,23,14,55,20,84,27,68,11,10,77};
	int b1[15]={0};//����Ĺ�ϣ��1
	int a2[9]={19,1,14,55,84,27,68,18,28};
	int b2[15]={0};//����Ĺ�ϣ��2
	int a3[15]={87,25,31,38,27,64,74,94,20,22,51,59,3,33,77};
	struct hxnode *b3[13];//����Ĺ�ϣ ��3
	//
	fun_gzhxb_xxtc(a1,12,b1,15);//�����ϣ��-���� ̽��
	print_hxb(b1,15);//��ʾ����Ĺ�ϣ��
	cz_hxb_xxtc(b1,15,a1,12);//���㲢 ��ʾ��ϣ����ҳɹ��Ƚϴ���-����̽��
	//
	fun_gzhxb_ectc(a2,9,b2,15);//�����ϣ��-����̽ ��
	print_hxb(b2,15);//��ʾ����Ĺ�ϣ��
	cz_hxb_ectc(b2,15,a2,9);//���㲢��ʾ��ϣ����ҳɹ��Ƚϴ���-����̽��
	//
	fun_gzhxb_1dz(a3,15,b3,13);//�����ϣ��-����ַ��
	print_1dz(b3,13);//��ʾ����Ĺ�ϣ��
	cz_hxb_1dz(b3,13,a3,15);//���㲢��ʾ��ϣ����ҳɹ��Ƚϴ���-����ַ��
	free_1dz(b3,13);

	printf("\n");
}
