// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
//����һ
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