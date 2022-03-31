/*
2022年03月30日 09:51:18
这道题的想法
二叉树在k层上最大节点数是2次方(k-1)
反正就是下一层的节点数是上一层的2倍，当然也是从第二个节点开始算起
那么满二叉树前k层的节点总数是(2次方k)-1
二叉树根节点从1开始，父节点为i，左儿子2i，右儿子2i+1

*/
#include<stdio.h>
#include<string.h>
#include<math.h>//pow()函数的头文件 
typedef long long ll;
//#define ll long long 这里的longlong，怕长度不够
int main() {
	ll n, maxx = -1000000;
	scanf("%lld", &n);//输入节点个数
	ll i, j, a[100010];
	for (i = 1; i <= n; i++) //存入节点
		scanf("%lld", &a[i]);
	ll m = n, k = 0, flag;
	while (m) { //求二叉树的深度（高度
		m = m / 2;
		k++;
	}
	ll sum;
	for (i = 1; i < k; i++) { //每一层的节点数最大多少
		sum = 0;
		ll t1 = pow(2, i - 1), t2 = pow(2, i);
		for (j = t1; j <= t2 - 1; j++)
			sum += a[j];
		if (sum > maxx) {
			maxx = sum;//最大权值
			flag = i;
		}
	}
	sum = 0;
	for (i = pow(2, k - 1); i <= n; i++)//计算最后一层节点
		sum += a[i];
	if (sum > maxx)
		flag = k;
	printf("\n%lld\n", flag);
	return 0;
}
