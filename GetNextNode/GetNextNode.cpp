// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������8������������һ�����
// ��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
// ���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣
//˼·һ�����ҵ����ڵ㣬�ٽ�������������ҵ��ý�����һ����㡣
//ע�⣺�ж����Ƿ���������������һ����㣬���Ƿ�����һ�����
#include <vector>
#include <cstdio>
using namespace std;
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
class Solution {
public:
	vector<TreeLinkNode*> Inorder;
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode *root = pNode;
		TreeLinkNode *pNext;
		while (root->next != NULL)
			root = root->next;
		InorderTravel(root);
		for (auto it = Inorder.begin(); it != Inorder.end(); it++)
		{
			if (*it == pNode)
			{
				if (it != Inorder.end() - 1)
				{
					pNext = *(it + 1);
					break;
				}
				else
					pNext = NULL;
			}
		}
		return pNext;
	}
	void InorderTravel(TreeLinkNode* node)
	{
		if (node == NULL)
			return;
		InorderTravel(node->left);
		Inorder.push_back(node);
		InorderTravel(node->right);
	}
};

//˼·2���ֱ��ж����Ƿ���������
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)
		return NULL;
	TreeLinkNode* pNext = NULL;
	if (pNode->right != NULL)//��������
	{
		TreeLinkNode* node = pNode->right;
		while (node->left != NULL)
		{
			node = node->left;
		}
		pNext = node;
	}
	else  //û��������
	{
		TreeLinkNode* ParentNode = pNode->next;
		TreeLinkNode* node = pNode;
		while (ParentNode != NULL&&ParentNode->left != node)
		{
			node = ParentNode;
			ParentNode = ParentNode->next;
		}
		pNext = ParentNode;
	}
	return pNext;
}