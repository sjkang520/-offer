// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
#include <vector>
using namespace std;
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows<1 || cols<1 || str == NULL)
			return false;
		vector<bool> marked(rows*cols, false);
		int pathlength = 0;
		for (int row = 0; row<rows; row++)
		{
			for (int col = 0; col<cols; col++)
			{
				if (hasPathCore(matrix, row, rows, col, cols, str, pathlength, marked))
					return true;
			}
		}
		return false;
	}

	bool hasPathCore(char* matrix, int row, int rows, int col, int cols, char* str, int& length, vector<bool>& marked)
	{
		if (str[length] == '\0')
			return true;
		bool haspath = false;
		if (row >= 0 && row<rows&&col >= 0 && col<cols&&matrix[row*cols + col] == str[length] && !marked[row*cols + col])
		{
			length++;
			marked[row*cols + col] = true;
			haspath = hasPathCore(matrix, row - 1, rows, col, cols, str, length, marked)
				|| hasPathCore(matrix, row + 1, rows, col, cols, str, length, marked)
				|| hasPathCore(matrix, row, rows, col - 1, cols, str, length, marked)
				|| hasPathCore(matrix, row, rows, col + 1, cols, str, length, marked);
			if (!haspath)
			{
				length--;
				marked[row*cols + col] = false;
			}
		}
		return haspath;
	}
};