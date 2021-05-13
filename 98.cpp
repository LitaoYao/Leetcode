// https://leetcode-cn.com/problems/validate-binary-search-tree/
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
	bool isValidSubBST(TreeNode* root, long long lower, long long upper)
	{
		if(root == nullptr)
		{
			return true;
		}
		if(root->val <= lower || upper <= root->val)
		{
			return false;
		}
		return isValidSubBST(root->left, lower, root->val) && isValidSubBST(root->right, root->val, upper);
	}
	bool isValidBST(TreeNode* root) {
		return isValidSubBST(root, (long long)(INT_MIN) - 1, (long long)(INT_MAX) + 1);
	}
};

int main()
{
	return 0;
}
