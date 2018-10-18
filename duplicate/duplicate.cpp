// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
#include <cstdio>
#include <iostream>
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length,int *duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		printf("number is nullptr or length <=0\n");
		return false;
	}
	for (int n = 0; n < length; n++)
	{
		if (numbers[n] < 0 || numbers[n] >= length)
		{
			printf("the number is not in range 0 to n-1\n");
			return false;
		}	
	}
	for (int n = 0; n < length; n++)
	{
		while (n!=numbers[n])
		{
			if (numbers[n] == numbers[numbers[n]])
			{
				*duplication = numbers[n];
				return true;
			}
			else
			{
				int temp = numbers[n];
				numbers[n] = numbers[temp];
				numbers[temp] = temp;
			}
		}
	}
	return false;
}

bool contains(int duplications[],int dup_length, int number)
{
	for (int i = 0; i < dup_length; i++)
		if (number == duplications[i])
			return true;
	return false;
}
//测试程序
int main()
{
	int duplication;
	bool flag;
	bool contain;
	//测试1：重复数字是最小数字
	int numbers1[] = { 2, 1, 3, 1, 4 };
	int duplication1[] = { 1 };
//	std::cout << sizeof(numbers1) / sizeof(int) << std::endl;
	flag = duplicate(numbers1, sizeof(numbers1) / sizeof(int), &duplication);
	contain = contains(duplication1, sizeof(duplication1) / sizeof(int), duplication);
	if (flag&&contain)
		std::cout << "test1 success\n";
	else
		std::cout << "test1 failed\n";
	//测试2：重复数字是数组中最大数字
	int numbers2[] = { 2, 4, 3, 1, 4 };
	int duplication2[] = { 4 };
	flag = duplicate(numbers2, sizeof(numbers2) / sizeof(int), &duplication);
	contain = contains(duplication2, sizeof(duplication2) / sizeof(int), duplication);
	if (flag&&contain)
		std::cout << "test2 success\n";
	else
		std::cout << "test2 failed\n";
	//测试3：有多个重复数字
	int numbers3[] = { 2, 4, 2, 1, 4 };
	int duplication3[] = { 2,4 };
	flag = duplicate(numbers3, sizeof(numbers3) / sizeof(int), &duplication);
	contain = contains(duplication3, sizeof(duplication3) / sizeof(int), duplication);
	if (flag&&contain)
		std::cout << "test3 success\n";
	else
		std::cout << "test3 failed\n";
	//测试4：数字超出范围
	int numbers4[] = { 2, 1, 3, 5, 4 };
	int duplication4[] = { -1 };
	flag = duplicate(numbers4, sizeof(numbers4) / sizeof(int), &duplication);
	if (!flag)
		std::cout << "test4 success\n";
	else
		std::cout << "test4 failed\n";
	//测试5：无效输入
	int *numbers5 = nullptr;
	int duplication5[] = { -1 };
	flag = duplicate(numbers5, sizeof(numbers5) / sizeof(int), &duplication);
	if (!flag)
		std::cout << "test5 success\n";
	else
		std::cout << "test5 failed/n";
	system("pause");
}