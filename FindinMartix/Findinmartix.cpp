// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
#include <vector>
//思路一：对每一行使用二分法查找，遍历每一行
using namespace std;
bool Find1(int target, vector<vector<int> > array)
{
	for (size_t n = 0; n < array.size(); n++)
	{
		//int length = array[n].size();
		int start = 0;
		int end = array[n].size()-1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (target < array[n][mid])
				end = mid - 1;
			else if (target>array[n][mid])
				start = mid + 1;
			else
				return true;
		}
	}
	return false;
}

//思路二：首先取数组中右上角数字，如果该数字等于要查找的数字，则查找结束，如果该数字大于要查找的数字，则剔除
//该数字所在的列，如果该数字小于要查找的数字，则剔除该数字所在的行
bool Find2(int target, vector<vector<int> > array)
{
	int col = array[0].size()-1;
	int raw = 0;
	if (array.empty())
		return false;
	while (raw<array.size()&&col>=0)
	{
		if (target < array[raw][col])
			col--;
		else if (target > array[raw][col])
			raw++;
		else
			return true;
	}
	return false;
}