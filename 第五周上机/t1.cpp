#include <stdio.h>
#include <math.h>
int main() {
	int n, depth, maxweight, maxweight_depth, diff;
	maxweight = (1 << 31);
	scanf("%d", &n);
	depth = ceil(log((double)(1 + n)) / log(2));//�������Ĳ�������ȫ��������ʵ����Ҫceiling����
	diff = ((1 << depth) - 1) - n;//���������Ľڵ��������ʵ�ʶ������Ľڵ���֮��������һ����Ҫ������һЩ����
	for (int i = 1; i <= depth; ++i) { //����������
		int sum = 0;//��һ��ĺ�
		int a;//һ���ڵ��ֵ
		for (int j = 1; j <= (1 << (i - 1))/*�ڵ�i=2�㣬ѭ��2�Σ��ڵ�i=3�㣬ѭ��4�Ρ�*/ - ((i == depth) ? diff : 0)/*���һ��ʱ��������һЩ���ڲ���������������ȱ�Ľڵ�*/; ++j) { //����һ����"����"�ڵ�
			scanf("%d", &a);//Ȼ��ʵ�����Ǳ�����ʱ��������������
			sum += a;
		}
		if (sum > maxweight) { //����һ��ĺͱȼ�¼�ĸ���ʱ����
			maxweight = sum;
			maxweight_depth = i;//��Ϊ�ǴӸ��ڵ㿪ʼ���������Դ洢�Ĳ���������С��
		}
	}
	printf("%d\n", maxweight_depth);
	return 0;
}
