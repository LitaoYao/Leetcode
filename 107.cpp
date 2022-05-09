// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
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
	void levelOrderDFS(vector<vector<int>>& ans, TreeNode* root, int level)
	{
		if(root == nullptr)
		{
			return;
		}
		if(level >= ans.size())
		{
			ans.push_back(vector<int>());
		}
		ans[level].push_back(root->val);
		levelOrderDFS(ans, root->left, level + 1);
		levelOrderDFS(ans, root->right, level + 1);
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		levelOrderDFS(ans, root, 0);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main()
{
	return 0;
}
