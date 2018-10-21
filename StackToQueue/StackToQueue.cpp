//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
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