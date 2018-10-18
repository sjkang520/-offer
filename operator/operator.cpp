#include<iostream>
#include "CMyString.h"
using namespace std;
void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.print();
	printf(".\n");
}
int main()
{
	Test1();
	Test2();
	Test3();
	system("pause");
}