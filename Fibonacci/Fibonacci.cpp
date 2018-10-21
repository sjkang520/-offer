//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
#include <vector>
using namespace std;
class Solution {
public:
	int Fibonacci(int n) {
		vector<int> F;
		F.push_back(0);
		F.push_back(1);
		if (n<2)
			return F[n];
		int Firstone = 0;
		int Secondone = 1;
		int Fib = 0;
		for (int i = 2; i <= n; i++)
		{
			Fib = Firstone + Secondone;
			Firstone = Secondone;
			Secondone = Fib;
		}
		return Fib;
	}
};