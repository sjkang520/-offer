//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
//断链法，此方法不正确，因为无环时返回的是链表最后一个元素
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

//方法二：用关联容器set，将每个结点加入关联容器中
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
//思路三
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