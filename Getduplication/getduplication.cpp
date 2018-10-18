
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

#include <iostream>
int getCount(int numbers[], int length, int start, int end);
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字
int Getduplication(int numbers[],int length)
{
	if (numbers == nullptr || length <= 0)
	{
		std::cout << "the numbers is nullpstr or length<=0\n";
		return -1;
	}
	int start = 1;
	int end = length - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		int counts = getCount(numbers, length, start, mid);
		if (start == end)
		{
			if (counts > 1)
				return start;
			else
				break;
		}
		if (counts > mid - start + 1)
		{
			end = mid;
		}
		else
			start = mid + 1;
	}
	return -1;
		
}
int getCount(int numbers[], int length,int start,int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start&&numbers[i] <= end)
			count++;
	}
	return count;
}

bool contains(int duplications[], int dup_length, int number)
{
	for (int i = 0; i < dup_length; i++)
		if (number == duplications[i])
			return true;
	return false;
}
int main()
{
	int result;
	bool contain;
	//测试1：多个重复数字
	int numbers1[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplication1[] = { 2,3 };
	//	std::cout << sizeof(numbers1) / sizeof(int) << std::endl;
	result = Getduplication(numbers1, sizeof(numbers1) / sizeof(int));
	contain = contains(duplication1, sizeof(duplication1) / sizeof(int), result);
	if (contain)
		std::cout << "test1 success\n";
	else
		std::cout << "test1 failed\n";
	//测试2：重复数字是数组中最大数字
	int numbers2[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplication2[] = { 8 };
	result = Getduplication(numbers2, sizeof(numbers2) / sizeof(int));
	contain = contains(duplication2, sizeof(duplication2) / sizeof(int), result);
	if (contain)
		std::cout << "test2 success\n";
	else
		std::cout << "test2 failed\n";
	//测试3：重复的数字是数组中最小的数字
	int numbers3[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplication3[] = { 1 };
	result = Getduplication(numbers3, sizeof(numbers3) / sizeof(int));
	contain = contains(duplication3, sizeof(duplication3) / sizeof(int), result);
	if (contain)
		std::cout << "test3 success\n";
	else
		std::cout << "test3 failed\n";
	//测试4：数组中只有两个数字
	int numbers4[] = { 1,1 };
	int duplication4[] = { 1 };
	result = Getduplication(numbers4, sizeof(numbers4) / sizeof(int));
	contain = contains(duplication4, sizeof(duplication4) / sizeof(int), result);
	if (contain)
		std::cout << "test4 success\n";
	else
		std::cout << "test4 failed\n";
	//测试5：无效输入
	int *numbers5 = nullptr;
	int duplication5[] = { -1 };
	result = Getduplication(numbers5, sizeof(numbers5) / sizeof(int));
	if (result==-1)
		std::cout << "test5 success\n";
	else
		std::cout << "test5 failed/n";
	//测试6：没有重复数字
	int numbers6[] = { 1, 2, 6, 4, 5, 3 };
	int duplication6[] = { -1 };
	result = Getduplication(numbers6, sizeof(numbers6) / sizeof(int));
	contain = contains(duplication6, sizeof(duplication6) / sizeof(int), result);
	if (contain)
		std::cout << "test6 success\n";
	else
		std::cout << "test6 failed\n";
	//测试7：一个数字重复三次
	int numbers7[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplication7[] = { 2 };
	result = Getduplication(numbers7, sizeof(numbers7) / sizeof(int));
	contain = contains(duplication7, sizeof(duplication7) / sizeof(int), result);
	if (contain)
		std::cout << "test7 success\n";
	else
		std::cout << "test7 failed\n";
	system("pause");
}