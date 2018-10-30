// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#include <exception>
#include <cstdio>
#include "test.h"
#include <iostream>
bool Increment(char* number);//���ַ���ģ��ӷ�
bool Increment2(char* number);//�ַ���ģ��ӷ�
void PrintNumber(char *number);//��ӡ�ַ���
void Print1ToMaxOfDigits(int n);//��ӡ��1������nλʮ������
void Print1ToMaxOfDigitsRecursively(char*number,int length,int index);//�������ݹ�
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
//���ַ�����������ģ��ӷ�
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
	int nTakeOver = 0;//��λ
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