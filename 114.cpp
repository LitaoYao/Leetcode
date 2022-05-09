// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if(root == nullptr)
		{
			return;
		}
		TreeNode* r = root->right;
		TreeNode* l = root->left;
		root->left = root->right = nullptr;
		flatten(l);
		if(l != nullptr)
		{
			root->right = l;
		}
		l = root;
		while(l->right != nullptr)
		{
			l = l->right;
		}
		l->right = r;
		flatten(r);
	}
};
