
#include <exception>
#include <cstdio>
#include "test.h"
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <functional>
using namespace std;
int LongestStringWithoutDuplication(const string& str)
{
	int length = str.size();
	if (length == 0)
		return 0;
	vector<int> maxlength(length, 0);
	int index;
	for (int i = 0; i<length; i++)
	{
		bool flag = false;
		if (i == 0)
			maxlength[i] = 1;
		else
		{
			for (index = i - 1; index >= 0; index--)
			{
				if (str[i] == str[index])
				{
					flag = true;
					break;
				}
			}
			cout << flag << " ";
			if (!flag)
				maxlength[i] = maxlength[i - 1] + 1;
			else
			{
				if (i - index>maxlength[i - 1])
					maxlength[i] = maxlength[i - 1] + 1;
				else
					maxlength[i] = i - index;
			}
		}
	}
	int max = maxlength[0];
	for (int i = 1; i<length; i++)
	{
		//	cout<<maxlength[i]<<" ";
		if (maxlength[i]>max)
			max = maxlength[i];
	}
	return max;
}
void int2Hex(int x)
{
	char a[8];                                  //程序功能：将十进制整数转换为补码输出
	if (x < 0)
	{
		x = 256 + x;                                             //x为输入的整数
		for (int i = 0; i < 8; i++)
		{
			a[i] = 'f';
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			a[i] = '0';
		}
	}
	int n = 0;                                                //n为每次x%2取得的余数 
	int i = 7;                                                 //i为整型数组长度减一                           
	char b[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	while (x > 0)
	{
		n = x % 16;
		x = x / 16;
		a[i] = b[n];
		i = i - 1;
	}

	for (int k = 6; k < 8; k++)
	{
		std::cout << a[k];
	}
	std::cout << std::endl;

}
void prnt(char* b)
{
	cout << b << endl;
}

class A
{
public:
	static int arr[3][2];
};
int A::arr[3][2] = { 1, 2, 3, 3, 2, 3 };
bool isUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return number==1;
}
int GetUglyNumber_Solution(int index)
{
	if (index <= 0)
		return 0;
	int UglyNum = 0;
	int num = 1;
	while (UglyNum<index)
	{
		if (isUgly(num))
			UglyNum++;
		num++;
	}
	return num;
}
#define JH(a,b,t) t=a;a=b;b=t;
class _Student
{
public:
	int a;
	char b;
protected:
	int c;
};
//选择排序
void sort1(vector<int> numbers)
{
	int length = numbers.size();
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i + 1;j<length; j++)
			if(numbers[j] < numbers[min])
				min = j;
		int temp = numbers[i];
		numbers[i] = numbers[min];
		numbers[min] = temp;
	}
}
//插入排序
void sort2(vector<int>& numbers)
{
	int length = numbers.size();
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0 && numbers[j] < numbers[j - 1]; j--)
		{
			int temp = numbers[j-1];
			numbers[j - 1] = numbers[j];
			numbers[j] = temp;
		}
	}
}
int main(int argc, char* argv[])
{	
	_Student st;
	st.a = 'a';
	st.b = "a";
	st.c = 1;
	return 0;
}
