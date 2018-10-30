// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <exception>
#include <cstdio>
#include "test.h"
#include <iostream>
bool Increment(char* number);//在字符串模拟加法
bool Increment2(char* number);//字符串模拟加法
void PrintNumber(char *number);//打印字符串
void Print1ToMaxOfDigits(int n);//打印从1到最大的n位十进制数
void Print1ToMaxOfDigitsRecursively(char*number,int length,int index);//方法二递归
void Print1ToMaxOfDigits2(int n);
using namespace std;
int main()
{

	Print1ToMaxOfDigits2(4);
	cout << endl;
	system("pause");
}
void Print1ToMaxOfDigits(int n)
{
	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number))
		PrintNumber(number);
	delete []number;
}
void PrintNumber(char *number)
{
	int length = strlen(number);
	bool isNotFirstNumber0 = false;
	for (int n = 0; n < length; n++)
	{
		if (!isNotFirstNumber0&&number[n] != '0')
			isNotFirstNumber0 = true;
		if (isNotFirstNumber0)
			printf("%c", number[n]);
	}
	cout << " ";
}
//在字符串的数字上模拟加法
bool Increment(char* number)
{
	int length = strlen(number);
	bool isOverflow = false;
	int i = length - 1;
	while (true)
	{
		if (i == length - 1)
			number[i]++;
		if (number[i] == ':')
		{
			if (i == 0)
			{
				number[i] = '0';
				isOverflow = true;
				break;
			}
			number[i] = '0';
			number[--i]++;
		}
		else
			break;
	}
	return isOverflow;
}
bool Increment2(char* number)
{
	int length = strlen(number);
	//int Sumnum;
	bool isOverflow=false;
	int nTakeOver = 0;//进位
	for (int n = length - 1; n >= 0; n--)
	{
		int Sumnum = number[n] - '0' + nTakeOver;
		if (n == length - 1)
			Sumnum++;
		if (Sumnum >= 10)
		{
			if (n == 0)
			{
				isOverflow = true;
			}
			else
			{
				Sumnum -= 10;
				number[n] = '0'+Sumnum;
				nTakeOver = 1;
			}				
		}
		else
		{
			number[n]='0'+Sumnum;
			break;
		}
	}
	return isOverflow;
}
void Print1ToMaxOfDigits2(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n+1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfDigitsRecursively(number, n, 0);
	}
}
void Print1ToMaxOfDigitsRecursively(char*number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index+1] = i + '0';
		Print1ToMaxOfDigitsRecursively(number, length, index + 1);
	}
}