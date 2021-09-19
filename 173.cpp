// https://leetcode-cn.com/problems/binary-search-tree-iterator/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		pushTreeNode(root);
	}

	void pushTreeNode(TreeNode* pNode)
	{
		if(nullptr == pNode)
		{
			return;
		}
		s.push(pNode);
		while(pNode->left)
		{
			s.push(pNode->left);
			pNode = pNode->left;
		}
	}

	int next() {
		TreeNode* pNode = s.top();
		s.pop();
		pushTreeNode(pNode->right);
		return pNode->val;
	}

	bool hasNext() {
		return !s.empty();
	}
private:
	stack<TreeNode*> s;
};

int main()
{
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(2);
	BSTIterator* obj = new BSTIterator(root);
	cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
	cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
	cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
	cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

