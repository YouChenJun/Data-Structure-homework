#include <iostream>
#include <cstdint>
#include <cmath>
int main()
{
	int n, maxweight, maxweight_depth;
	maxweight = INT32_MIN;
	std::cin >> n;
	int depth = std::ceil(std::log2(double(n) + 1));//二叉树的层数
	for (int i = 1; i <= depth; ++i)
	{
		int sum = 0;//这一层的和
		int a;//一个节点的值
		for (int j = 1; j <= (1 << (i - 1))/*在第i=2层，循环2次；在第i=3层，循环4次…*/; ++j)
		{
			std::cin >> a;
			sum += a;
		}
		if (sum > maxweight)
		{
			maxweight = sum;
			maxweight_depth = i;
		}
	}
	std::cout << maxweight_depth << std::endl;
	return 0;
}
