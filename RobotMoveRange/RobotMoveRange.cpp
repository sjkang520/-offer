// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
#include <vector>
using namespace std;
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold<0 || rows <= 0 || cols <= 0)
			return 0;
		vector<bool> marked(rows*cols, false);
		movingCountCore(threshold, rows, cols, 0, 0, marked);
		int sum = 0;
		for (int i = 0; i<marked.size(); i++)
		{
			if (marked[i] == true)
				sum++;
		}
		return sum;
	}
	void movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool>& marked)
	{
		if (GetSum(row) + GetSum(col)>threshold)
			return;
		marked[row*cols + col] = true;
		if (row - 1 >= 0 && !marked[(row - 1)*cols + col])
			movingCountCore(threshold, rows, cols, row - 1, col, marked);
		if (row + 1<rows&&!marked[(row + 1)*cols + col])
			movingCountCore(threshold, rows, cols, row + 1, col, marked);
		if (col - 1 >= 0 && !marked[row*cols + col - 1])
			movingCountCore(threshold, rows, cols, row, col - 1, marked);
		if (col + 1 >= 0 && !marked[row*cols + col + 1])
			movingCountCore(threshold, rows, cols, row, col + 1, marked);
	}
	int GetSum(int num)
	{
		int sum = 0;
		while (num != 0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};