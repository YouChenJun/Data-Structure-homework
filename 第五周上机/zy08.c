/*
2022��03��30�� 09:51:18
�������뷨
��������k�������ڵ�����2�η�(k-1)
����������һ��Ľڵ�������һ���2������ȻҲ�Ǵӵڶ����ڵ㿪ʼ����
��ô��������ǰk��Ľڵ�������(2�η�k)-1
���������ڵ��1��ʼ�����ڵ�Ϊi�������2i���Ҷ���2i+1

*/
#include<stdio.h>
#include<string.h>
#include<math.h>//pow()������ͷ�ļ� 
typedef long long ll;
//#define ll long long �����longlong���³��Ȳ���
int main() {
	ll n, maxx = -1000000;
	scanf("%lld", &n);//����ڵ����
	ll i, j, a[100010];
	for (i = 1; i <= n; i++) //����ڵ�
		scanf("%lld", &a[i]);
	ll m = n, k = 0, flag;
	while (m) { //�����������ȣ��߶�
		m = m / 2;
		k++;
	}
	ll sum;
	for (i = 1; i < k; i++) { //ÿһ��Ľڵ���������
		sum = 0;
		ll t1 = pow(2, i - 1), t2 = pow(2, i);
		for (j = t1; j <= t2 - 1; j++)
			sum += a[j];
		if (sum > maxx) {
			maxx = sum;//���Ȩֵ
			flag = i;
		}
	}
	sum = 0;
	for (i = pow(2, k - 1); i <= n; i++)//�������һ��ڵ�
		sum += a[i];
	if (sum > maxx)
		flag = k;
	printf("\n%lld\n", flag);
	return 0;
}
