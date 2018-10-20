// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
//思路一：先找到根节点，再进行中序遍历，找到该结点的下一个结点。
//注意：判断其是否是中序遍历的最后一个结点，即是否有下一个结点
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

//思路2：分别判断其是否有右子树
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)
		return NULL;
	TreeLinkNode* pNext = NULL;
	if (pNode->right != NULL)//有右子树
	{
		TreeLinkNode* node = pNode->right;
		while (node->left != NULL)
		{
			node = node->left;
		}
		pNext = node;
	}
	else  //没有右子树
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