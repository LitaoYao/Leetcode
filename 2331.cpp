// https://leetcode.cn/problems/evaluate-boolean-binary-tree/
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
	bool evaluateTree(TreeNode* root) {
		if (root->val == 0)
		{
			return false;
		}
		if (root->val == 1)
		{
			return true;
		}
		if (root->val == 2)
		{
			return evaluateTree(root->left) || evaluateTree(root->right);
		}
		if (root->val == 3)
		{
			return evaluateTree(root->left) && evaluateTree(root->right);
		}
		return true;
	}
};

int main()
{
	// root = [2,1,3,null,null,0,1]
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);
	bool ans = Solution().evaluateTree(root);
	cout << ans << endl;
	return 0;
}

