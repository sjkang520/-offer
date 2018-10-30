// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
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