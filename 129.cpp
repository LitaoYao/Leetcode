// https://leetcode.cn/problems/sum-root-to-leaf-numbers/
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
	void dfs(TreeNode* node, int now_num, int& ans)
	{
		if(node == nullptr)
		{
			return;
		}
		now_num = now_num * 10 + node->val;
		if(node->left == nullptr && node->right == nullptr)
		{
			ans += now_num;
		}
		dfs(node->left, now_num, ans);
		dfs(node->right, now_num, ans);
	}
	int sumNumbers(TreeNode* root) {
		int ans = 0;
		int now_num = 0;
		dfs(root, now_num, ans);
		return ans;
	}
};
