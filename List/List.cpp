//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
//思路一：利用栈
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
       }
  };

vector<int> printListFromTailToHead(ListNode* head) 
{
	stack<int> List;
	ListNode *node = head;
	vector<int> printList;
	while (node != NULL)
	{
		List.push(node->val);
		node = node->next;
	}
	while (!List.empty())
	{
		printList.push_back(List.top());
		List.pop();
	}
	return printList;
}

//思路二;递归
class Solution {
public:
	vector<int> printList;
	vector<int> printListFromTailToHead(ListNode* head) {
		print(head);
		return printList;
	}
	void print(ListNode *head)
	{
		if (head == NULL)
			return;
		print(head->next);
		printList.push_back(head->val);
	}
};