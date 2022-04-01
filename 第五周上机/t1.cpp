#include <stdio.h>
#include <math.h>
int main() {
	int n, depth, maxweight, maxweight_depth, diff;
	maxweight = (1 << 31);
	scanf("%d", &n);
	depth = ceil(log((double)(1 + n)) / log(2));//二叉树的层数，完全二叉树其实不需要ceiling函数
	diff = ((1 << depth) - 1) - n;//满二叉树的节点数和这个实际二叉树的节点数之差，这样最后一层需要少输入一些内容
	for (int i = 1; i <= depth; ++i) { //按层数遍历
		int sum = 0;//这一层的和
		int a;//一个节点的值
		for (int j = 1; j <= (1 << (i - 1))/*在第i=2层，循环2次；在第i=3层，循环4次…*/ - ((i == depth) ? diff : 0)/*最后一层时，少输入一些由于不是满二叉树而空缺的节点*/; ++j) { //在这一层中"遍历"节点
			scanf("%d", &a);//然而实际上是遍历的时候才输入具体数据
			sum += a;
		}
		if (sum > maxweight) { //当这一层的和比记录的更大时……
			maxweight = sum;
			maxweight_depth = i;//因为是从根节点开始遍历，所以存储的层数总是最小的
		}
	}
	printf("%d\n", maxweight_depth);
	return 0;
}
