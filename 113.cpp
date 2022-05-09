// https://leetcode.cn/problems/path-sum-ii/
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
	void dfs(vector<vector<int>>& ans, vector<int>& path, TreeNode* node, int targetSum)
	{
		if(node == nullptr)
		{
			return;
		}
		if(node->left == nullptr && node->right == nullptr)
		{
			if(targetSum == node->val)
			{
				path.push_back(node->val);
				ans.push_back(path);
				path.pop_back();
			}
			return;
		}
		path.push_back(node->val);
		if(node->left != nullptr)
		{
			dfs(ans, path, node->left, targetSum - node->val);
		}
		if(node->right != nullptr)
		{
			dfs(ans, path, node->right, targetSum - node->val);
		}
		path.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> ans;
		vector<int> path;
		dfs(ans, path, root, targetSum);
		return ans;
	}
};

int main()
{
	return 0;
}
