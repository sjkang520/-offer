//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
// ��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�
#include <cstdio>
#include <stack>
using namespace std;
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int Top;
		if (stack1.empty() && stack2.empty())
		{
			printf("queue is empty\n");
			exit(0);
		}
		if (!stack2.empty())
		{
			Top = stack2.top();
			stack2.pop();
		}
		else
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			Top = stack2.top();
			stack2.pop();
		}
		return Top;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};