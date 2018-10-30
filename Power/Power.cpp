// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
//方法一
#include <iostream>
using namespace std;
class Solution {
public:
	double Power(double base, int exponent) {
		if (equal(base, 0.0) && exponent<0)
		{
			cout << "Invalid input\n";
			return 0.0;
		}
		double result = 1;
		double absExponent = exponent;
		if (exponent<0)
			absExponent = -exponent;
		for (int n = 1; n <= absExponent; n++)
		{
			result *= base;
		}
		if (exponent<0)
			result = 1 / result;
		return result;
	}
	bool equal(double num1, double num2)
	{
		if ((num1 - num2>-0.0000001) && (num1 - num2<0.0000001))
			return true;
		else
			return false;
	}
};