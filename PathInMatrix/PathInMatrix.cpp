// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
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