//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
//˼·һ������ջ
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

//˼·��;�ݹ�
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