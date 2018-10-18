
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��

#include <iostream>
int getCount(int numbers[], int length, int start, int end);
// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
// ����ֵ:             
//        ����  - ������Ч�����������д����ظ������֣�����ֵΪ�ظ�������
//        ����  - ������Ч������������û���ظ�������
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
	//����1������ظ�����
	int numbers1[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplication1[] = { 2,3 };
	//	std::cout << sizeof(numbers1) / sizeof(int) << std::endl;
	result = Getduplication(numbers1, sizeof(numbers1) / sizeof(int));
	contain = contains(duplication1, sizeof(duplication1) / sizeof(int), result);
	if (contain)
		std::cout << "test1 success\n";
	else
		std::cout << "test1 failed\n";
	//����2���ظ��������������������
	int numbers2[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplication2[] = { 8 };
	result = Getduplication(numbers2, sizeof(numbers2) / sizeof(int));
	contain = contains(duplication2, sizeof(duplication2) / sizeof(int), result);
	if (contain)
		std::cout << "test2 success\n";
	else
		std::cout << "test2 failed\n";
	//����3���ظ�����������������С������
	int numbers3[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplication3[] = { 1 };
	result = Getduplication(numbers3, sizeof(numbers3) / sizeof(int));
	contain = contains(duplication3, sizeof(duplication3) / sizeof(int), result);
	if (contain)
		std::cout << "test3 success\n";
	else
		std::cout << "test3 failed\n";
	//����4��������ֻ����������
	int numbers4[] = { 1,1 };
	int duplication4[] = { 1 };
	result = Getduplication(numbers4, sizeof(numbers4) / sizeof(int));
	contain = contains(duplication4, sizeof(duplication4) / sizeof(int), result);
	if (contain)
		std::cout << "test4 success\n";
	else
		std::cout << "test4 failed\n";
	//����5����Ч����
	int *numbers5 = nullptr;
	int duplication5[] = { -1 };
	result = Getduplication(numbers5, sizeof(numbers5) / sizeof(int));
	if (result==-1)
		std::cout << "test5 success\n";
	else
		std::cout << "test5 failed/n";
	//����6��û���ظ�����
	int numbers6[] = { 1, 2, 6, 4, 5, 3 };
	int duplication6[] = { -1 };
	result = Getduplication(numbers6, sizeof(numbers6) / sizeof(int));
	contain = contains(duplication6, sizeof(duplication6) / sizeof(int), result);
	if (contain)
		std::cout << "test6 success\n";
	else
		std::cout << "test6 failed\n";
	//����7��һ�������ظ�����
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