// https://leetcode.cn/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <vector>
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
	void levelOrderDfs(vector<vector<int>>& ans, TreeNode* root, int level)
	{
		if(root == nullptr)
		{
			return;
		}
		int ans_size = ans.size();
		if(level >= ans_size)
		{
			ans.push_back(vector<int>());
		}
		ans[level].push_back(root->val);
		levelOrderDfs(ans, root->left, level + 1);
		levelOrderDfs(ans, root->right, level + 1);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		levelOrderDfs(ans, root, 0);
		return ans;
	}
};

int main()
{
	return 0;
}
