#include <iostream>
#include <cstdint>
#include <cmath>
int main()
{
	int n, maxweight, maxweight_depth;
	maxweight = INT32_MIN;
	std::cin >> n;
	int depth = std::ceil(std::log2(double(n) + 1));//�������Ĳ���
	for (int i = 1; i <= depth; ++i)
	{
		int sum = 0;//��һ��ĺ�
		int a;//һ���ڵ��ֵ
		for (int j = 1; j <= (1 << (i - 1))/*�ڵ�i=2�㣬ѭ��2�Σ��ڵ�i=3�㣬ѭ��4�Ρ�*/; ++j)
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
