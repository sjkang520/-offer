//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������10��쳲���������
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
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