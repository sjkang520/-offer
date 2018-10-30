// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��
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