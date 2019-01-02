//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
#include <cstdlib>
#include <set>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//���������˷�������ȷ����Ϊ�޻�ʱ���ص����������һ��Ԫ��
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return NULL;
	ListNode* front = pHead->next;
	ListNode* behind = pHead;
	while (front != NULL)
	{
		behind->next = NULL;
		behind = front;
		front = front->next;
	}
	return behind;
}

//���������ù�������set����ÿ�����������������
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return NULL;
	ListNode* pNode = pHead;
	set<ListNode*> lists;
	while (pNode != NULL)
	{
		if (lists.find(pNode) == lists.end())
		{
			lists.insert(pNode);
			pNode = pNode->next;
		}
		else
			return pNode;
	}
	return NULL;
}
//˼·��
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return NULL;
	bool hascrcle = false;
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			hascrcle = true;
			break;
		}
	}
	if (hascrcle)
	{
		fast = pHead;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
	else
		return NULL;
}