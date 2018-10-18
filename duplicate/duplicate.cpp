// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��
#include <cstdio>
#include <iostream>
// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
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
//���Գ���
int main()
{
	int duplication;
	bool flag;
	bool contain;
	//����1���ظ���������С����
	int numbers1[] = { 2, 1, 3, 1, 4 };
	int duplication1[] = { 1 };
//	std::cout << sizeof(numbers1) / sizeof(int) << std::endl;
	flag = duplicate(numbers1, sizeof(numbers1) / sizeof(int), &duplication);
	contain = contains(duplication1, sizeof(duplication1) / sizeof(int), duplication);
	if (flag&&contain)
		std::cout << "test1 success\n";
	else
		std::cout << "test1 failed\n";
	//����2���ظ��������������������
	int numbers2[] = { 2, 4, 3, 1, 4 };
	int duplication2[] = { 4 };
	flag = duplicate(numbers2, sizeof(numbers2) / sizeof(int), &duplication);
	contain = contains(duplication2, sizeof(duplication2) / sizeof(int), duplication);
	if (flag&&contain)
		std::cout << "test2 success\n";
	else
		std::cout << "test2 failed\n";
	//����3���ж���ظ�����
	int numbers3[] = { 2, 4, 2, 1, 4 };
	int duplication3[] = { 2,4 };
	flag = duplicate(numbers3, sizeof(numbers3) / sizeof(int), &duplication);
	contain = contains(duplication3, sizeof(duplication3) / sizeof(int), duplication);
	if (flag&&contain)
		std::cout << "test3 success\n";
	else
		std::cout << "test3 failed\n";
	//����4�����ֳ�����Χ
	int numbers4[] = { 2, 1, 3, 5, 4 };
	int duplication4[] = { -1 };
	flag = duplicate(numbers4, sizeof(numbers4) / sizeof(int), &duplication);
	if (!flag)
		std::cout << "test4 success\n";
	else
		std::cout << "test4 failed\n";
	//����5����Ч����
	int *numbers5 = nullptr;
	int duplication5[] = { -1 };
	flag = duplicate(numbers5, sizeof(numbers5) / sizeof(int), &duplication);
	if (!flag)
		std::cout << "test5 success\n";
	else
		std::cout << "test5 failed/n";
	system("pause");
}