// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
// �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
// �������ж��������Ƿ��и�������
#include <vector>
//˼·һ����ÿһ��ʹ�ö��ַ����ң�����ÿһ��
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

//˼·��������ȡ���������Ͻ����֣���������ֵ���Ҫ���ҵ����֣�����ҽ�������������ִ���Ҫ���ҵ����֣����޳�
//���������ڵ��У����������С��Ҫ���ҵ����֣����޳����������ڵ���
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