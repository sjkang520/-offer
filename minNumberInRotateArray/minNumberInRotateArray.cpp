// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
#include <vector>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int p1 = 0;
		int p2 = rotateArray.size() - 1;
		int mid;
		if (rotateArray[0]<rotateArray[p2])
			return rotateArray[0];
		else
		{
			while (p2 - p1 != 1)
			{
				mid = p1 + (p2 - p1) / 2;
				if (rotateArray[p1] == rotateArray[p2] && rotateArray[p1] == rotateArray[mid])
					return MinInOrder(rotateArray);
				if (rotateArray[p1] <= rotateArray[mid])
					p1 = mid;
				else if (rotateArray[mid] <= rotateArray[p2])
					p2 = mid;
			}
			return rotateArray[p2];
		}

	}
	int MinInOrder(vector<int>& rotateArray)
	{
		int min = rotateArray[0];
		for (int n = 0; n<rotateArray.size(); n++)
		{
			if (min>rotateArray[n])
				min = rotateArray[n];
		}
		return min;
	}
};